/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:50:33 by mreis-me          #+#    #+#             */
/*   Updated: 2023/02/05 01:23:34 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	cd_error(char *str, int status)
{
	if (status == 1)
	{
		write(STDERR_FILENO, "minishell: cd: ", 15);
		write(STDERR_FILENO, str, ft_strlen(str));
		write(STDERR_FILENO, ": No such file or directory\n", 28);
	}
	else if (status == 2)
	{
		write(STDERR_FILENO, "minishell: cd: ", 15);
		write(STDERR_FILENO, str, ft_strlen(str));
		write(STDERR_FILENO, ": not set\n", 10);
	}
	return (EXIT_FAILURE);
}

static int	cd_case(t_shell *shell)
{
	char	*dir;
	char	*last_dir;

	dir = shell->cmd->args[1];
	if (!dir && chdir(get_value(get_env("HOME", shell->env))) != 0)
		return (cd_error("HOME", 2));
	else if (!ft_strncmp(dir, "\'\'", -1) || !ft_strncmp(dir, "\"\"", -1))
		chdir(".");
	else if (!ft_strncmp(dir, "-", -1))
	{
		last_dir = get_value(get_env("OLDPWD", shell->env));
		if (chdir(last_dir) != 0)
			return (cd_error("OLDPWD", 2));
		printf("%s\n", last_dir);
	}
	else if (chdir(dir) != 0)
	{
		cd_error(dir, 1);
		if (dir[0] == '$')
			chdir(get_value(get_env("HOME", shell->env)));
		else
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	bt_cd(t_shell *shell)
{
	char	*cwd;

	cwd = ft_strjoin("OLDPWD=", getcwd(NULL, 0), 2);
	if (!cwd)
		return (EXIT_FAILURE);
	if (cd_case(shell))
	{
		free(cwd);
		g_status_code = 1;
		return (EXIT_FAILURE);
	}
	set_env(cwd, &shell->env);
	free(cwd);
	cwd = ft_strjoin("PWD=", getcwd(NULL, 0), 2);
	if (!cwd)
		return (EXIT_FAILURE);
	set_env(cwd, &shell->env);
	free(cwd);
	g_status_code = 0;
	return (EXIT_SUCCESS);
}
