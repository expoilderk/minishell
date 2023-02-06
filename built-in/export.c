/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:50:35 by mreis-me          #+#    #+#             */
/*   Updated: 2023/02/06 15:17:01 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	export_error(char *str)
{
	write(STDERR_FILENO, "minishell: export: \"", 20);
	write(STDERR_FILENO, str, ft_strlen(str));
	write(STDERR_FILENO, "\": not a valid identifier\n", 26);
	return (EXIT_FAILURE);
}

static int	validate(char *var)
{
	int	i;

	if (!var || (!ft_isalpha(var[0]) && var[0] != '_'))
		return (export_error(var));
	i = 0;
	while (var[++i])
	{
		if (!ft_isalnum(var[i]) && var[i] != '_')
		{
			if (var[i] == '=')
				break ;
			if (!ft_strchr(var, '='))
				return (EXIT_FAILURE);
			else
				return (export_error(var));
		}
	}
	return (EXIT_SUCCESS);
}

int	bt_export(t_shell *shell)
{
	int		i;
	char	*var;

	i = 0;
	g_status_code = 0;
	while (shell->cmd->args[++i])
	{
		var = shell->cmd->args[i] + quotes_len(shell->cmd->args[i]);
		if (!validate(var))
			set_env(var, &shell->env);
		else
			g_status_code = 1;
	}
	return (EXIT_SUCCESS);
}
