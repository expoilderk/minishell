/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@42.student.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:31:59 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/25 00:31:59 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*free_cmds(t_cmd *cmd)
{
	t_cmd	*tmp;

	while (cmd)
	{
		tmp = cmd;
		cmd = cmd->next;
		arrfree(tmp->args);
		free(tmp);
	}
	return (NULL);
}

t_cmd	*last_cmd(t_cmd *cmd)
{
	while (cmd->next)
		cmd = cmd->next;
	return (cmd);
}

t_cmd	*new_cmd(t_token *token, t_heredoc **heredoc)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	if (redirect(cmd, token, heredoc))
	{
		free(cmd);
		return (NULL);
	}
	cmd->args = cmd_args(token);
	if (!cmd->args)
	{
		free(cmd);
		return (NULL);
	}
	cmd->next = NULL;
	return (cmd);
}

int	add_cmd(t_cmd *new, t_cmd **cmd)
{
	if (!new)
		return (EXIT_FAILURE);
	if (!(*cmd))
	{
		*cmd = new;
		return (EXIT_SUCCESS);
	}
	last_cmd(*cmd)->next = new;
	return (EXIT_SUCCESS);
}
