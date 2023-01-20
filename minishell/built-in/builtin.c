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

int	builtin(t_cmd *cmd, char **env)
{
	if (!ft_strncmp(cmd->args[0], "cd", -1))
		return (bt_cd(cmd->args, env));
	else if (!ft_strncmp(cmd->args[0], "echo", -1))
		return (bt_echo(cmd->args));
	else if (!ft_strncmp(cmd->args[0], "env", -1))
		return (bt_env(cmd->args, env));
	else if (!ft_strncmp(cmd->args[0], "exit", -1))
		return (bt_exit(NULL, env));
	else if (!ft_strncmp(cmd->args[0], "export", -1))
		return (bt_export(cmd->args, env));
	else if (!ft_strncmp(cmd->args[0], "pwd", -1))
		return (bt_pwd(cmd->args));
	else if (!ft_strncmp(cmd->args[0], "unset", -1))
		return (bt_unset(cmd->args, env));
	return (1);
}
