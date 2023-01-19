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

int	executor(t_cmd *cmd, char **env)
{
	cmd->env = env;
	int (*built_in)(t_cmd *) = get_builtin(cmd->args[0]);
	if (built_in)
		built_in(cmd);
	return (EXIT_SUCCESS);
}
