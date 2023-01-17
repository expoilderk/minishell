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

int executor(t_cmd *cmd, char **env, int flag)
{

	if (flag == 0)
		cmd->env = env;

	int (*built_in)(t_cmd *) = get_builtin(cmd->args[0]);
	if (built_in)
		built_in(cmd);

	// for (int i = 0; cmd->env[i] != NULL; i++)
	// {
	// 	printf("cmd->env[%d] : %s\n", i, cmd->env[i]);
	// }
	return (EXIT_SUCCESS);
}
