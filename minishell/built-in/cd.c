/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:50:33 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/19 21:58:43 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	bt_cd(char **args, char **env)
{
	char	*cwd;
	char	*last_dir;

	if (args[1] == NULL || (!ft_strncmp(args[1], "~", -1)))
	{
		if (chdir(get_value("HOME", env)) != 0)
		{
			perror("cd");
			return (EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	else if (!ft_strncmp(args[1], "-", -1))
	{
		last_dir = get_value("OLDPWD", env);
		if (chdir(last_dir) != 0)
		{
			perror("cd");
			return (EXIT_FAILURE);
		}
		printf("%s\n", last_dir);
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("cd");
			return (EXIT_FAILURE);
		}
	}
	cwd = getcwd(NULL, 0);
	set_env(env, "OLDPWD=", get_value("PWD", env));
	set_env(env, "PWD=", cwd);
	return (EXIT_SUCCESS);
}
