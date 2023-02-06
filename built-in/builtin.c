/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@42.student.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:05:11 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/16 20:05:11 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	builtin(t_shell *shell)
{
	if (!ft_strncmp(shell->cmd->args[0], "cd", -1))
		return (bt_cd(shell));
	else if (!ft_strncmp(shell->cmd->args[0], "echo", -1))
		return (bt_echo(shell));
	else if (!ft_strncmp(shell->cmd->args[0], "env", -1))
		return (bt_env(shell));
	else if (!ft_strncmp(shell->cmd->args[0], "exit", -1))
		return (bt_exit(shell));
	else if (!ft_strncmp(shell->cmd->args[0], "export", -1))
		return (bt_export(shell));
	else if (!ft_strncmp(shell->cmd->args[0], "pwd", -1))
		return (bt_pwd());
	else if (!ft_strncmp(shell->cmd->args[0], "unset", -1))
		return (bt_unset(shell));
	else if (!ft_strncmp(shell->cmd->args[0], "?", -1)) // Remover, apenas para teste
		return (printf("%d\n", g_status_code));
	return (1);
}
