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

static int	heredoc(char *end)
{
	(void)end;
	return (-1);
}

static void	redir_type(t_cmd *cmd, t_token *token)
{
	if (!ft_strncmp(token->token, "<<", -1))
		cmd->in = heredoc(token->next->token);
	else if (!ft_strncmp(token->token, "<", -1))
		cmd->in = open(token->next->token, O_RDONLY);
	else if (!ft_strncmp(token->token, ">>", -1))
		cmd->out = open(token->next->token, O_APPEND | O_CREAT, 777);
	else if (!ft_strncmp(token->token, ">", -1))
		cmd->out = open(token->next->token, O_RDWR | O_TRUNC | O_CREAT, 777);
}

int	redirect(t_cmd *cmd, t_token *token)
{
	int	i;

	cmd->in = 0;
	cmd->out = 1;
	i = 0;
	while (token->type != END)
	{
		if (token->type == REDIR)
		{
			redir_type(cmd, token);
			token = token->next;
		}
		else
			i++;
		token = token->next;
	}
	return (i);
}
