/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@42.student.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:49:53 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/07 15:49:53 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	executor(t_shell *shell)
{
	t_cmd	*cmd;

	cmd = shell->cmd;
	while (shell->cmd)
	{
		if (!shell->cmd->args[0] || builtin(shell))
		{
			shell->cmd = shell->cmd->next;
			continue ;
		}
		shell->cmd = shell->cmd->next;
	}

	// Atualizar g_status_code;
	// Command not found status 127

	free_cmds(cmd);
	return (0);
}
