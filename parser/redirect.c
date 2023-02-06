/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@42.student.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:23:56 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/16 16:23:56 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	void	redir_type2(int *in, t_heredoc **heredoc)
{
	t_heredoc	*tmp;

	safe_close(*in, 1);
	*in = (*heredoc)->fd;
	tmp = *heredoc;
	*heredoc = (*heredoc)->next;
	free(tmp);
}

static int	redir_type(t_cmd *cmd, t_token *token, t_heredoc **heredoc)
{
	if (!ft_strncmp(token->token, "<<", 2))
		redir_type2(&cmd->in, heredoc);
	else if (!ft_strncmp(token->token, "<", 1))
	{
		safe_close(cmd->in, 1);
		cmd->in = open(token->next->token, O_RDONLY);
	}
	if (cmd->in == -1)
		return (error(token->next->token));
	if (!ft_strncmp(token->token, ">>", 2))
	{
		safe_close(0, cmd->out);
		cmd->out = open(token->next->token, O_APPEND | O_CREAT, 0644);
	}
	else if (!ft_strncmp(token->token, ">", 1))
	{
		safe_close(0, cmd->out);
		cmd->out = open(token->next->token, O_RDWR | O_TRUNC | O_CREAT, 0644);
	}
	if (cmd->out == -1)
		return (error(token->next->token));
	return (EXIT_SUCCESS);
}

int	redirect(t_cmd *cmd, t_token *token, t_heredoc **heredoc)
{
	cmd->in = 0;
	cmd->out = 1;
	while (token && token->type != END)
	{
		if (token->type == REDIR)
		{
			if (redir_type(cmd, token, heredoc))
				return (EXIT_FAILURE);
			token = token->next;
		}
		token = token->next;
	}
	return (EXIT_SUCCESS);
}
