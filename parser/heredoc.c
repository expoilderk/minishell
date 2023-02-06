/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:24:33 by gguedes           #+#    #+#             */
/*   Updated: 2023/02/04 23:51:35 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	syntax_error(char *token)
{
	write(STDERR_FILENO, "minishell: syntax error near unexpected token \"", 47);
	if (!token)
		write(STDERR_FILENO, "newline\"\n", 9);
	else
	{
		write(STDERR_FILENO, token, ft_strlen(token));
		write(STDERR_FILENO, "\"\n", 2);
	}
	g_status_code = 2;
	return (EXIT_FAILURE);
}

static void	heredoc_pid(int pid, char *end, int pipefd[2])
{
	char	*str;

	if (!pid)
	{
		signal(SIGINT, sighandler_heredoc);
		close(pipefd[1]);
		while (1)
		{
			str = readline(">");
			if (!ft_strncmp(str, end, -1) || !str)
			{
				close(pipefd[0]);
				exit(0);
			}
			write(pipefd[0], str, ft_strlen(str));
		}
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		close(pipefd[0]);
	}
}

int	open_heredoc(char *end)
{
	int		pid;
	int		pipefd[2];
	int		status;

	if (pipe(pipefd) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		return (-1);
	}
	heredoc_pid(pid, end, pipefd);
	if (waitpid(pid, &status, 0) == -1)
	{
		close(pipefd[1]);
		return (-1);
	}
	signals();
	if (status)
		return (-1);
	return (pipefd[1]);
}

int	heredocs(t_token *token, t_heredoc **heredoc)
{
	g_status_code = 0;
	if (token->type == END)
		return (syntax_error(token->token));
	while (token->next)
	{
		if (token->type == REDIR)
		{
			if (token->next->type != WORD)
				return (syntax_error(token->next->token));
			else if (!ft_strncmp("<<", token->token, -1))
			{
				if (add_heredoc(new_heredoc(token->next), heredoc))
					return (EXIT_FAILURE);
			}
		}
		else if (token->type == END && token->next->type == END)
			return (syntax_error(token->next->token));
		token = token->next;
	}
	if (token->type != WORD)
		return (syntax_error(NULL));
	return (EXIT_SUCCESS);
}
