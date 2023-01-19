/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:50:33 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/19 16:26:28 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	cd(t_cmd *cmd)
{
	char	*cwd;
	char	*last_dir;

	if (cmd->args[1] == NULL || (!ft_strncmp(cmd->args[1], "~", -1)))
	{
		if (chdir(get_value("HOME", cmd->env)) != 0)
		{
			perror("cd");
			return (EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	else if (!ft_strncmp(cmd->args[1], "-", -1))
	{
		last_dir = get_value("OLDPWD", cmd->env);
		if (chdir(last_dir) != 0)
		{
			perror("cd");
			return (EXIT_FAILURE);
		}
		printf("%s\n", last_dir);
	}
	else
	{
		if (chdir(cmd->args[1]) != 0)
		{
			perror("cd");
			return (EXIT_FAILURE);
		}
	}
	cwd = getcwd(NULL, 0);
	set_env(cmd, "OLDPWD=", get_value("PWD", cmd->env));
	set_env(cmd, "PWD=", cwd);
	return (EXIT_SUCCESS);
}
