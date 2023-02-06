/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:50:36 by mreis-me          #+#    #+#             */
/*   Updated: 2023/02/04 22:52:42 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	unset_error(char *str)
{
	write(STDERR_FILENO, "minishell: unset: \"", 19);
	write(STDERR_FILENO, str, ft_strlen(str));
	write(STDERR_FILENO, "\": not a valid identifier\n", 26);
	return (EXIT_FAILURE);
}

static int	validate(char *var)
{
	int	i;

	if (!var || (!ft_isalpha(var[0]) && var[0] != '_'))
		return (unset_error(var));
	i = 0;
	while (var[++i])
	{
		if (!ft_isalnum(var[i]) && var[i] != '_')
			return (unset_error(var));
	}
	return (EXIT_SUCCESS);
}

int	bt_unset(t_shell *shell)
{
	int		i;

	i = 0;
	g_status_code = 0;
	while (shell->cmd->args[++i])
	{
		if (!validate(shell->cmd->args[i]))
			unset_env(shell->cmd->args[i], &shell->env);
		else
			g_status_code = 1;
	}
	return (EXIT_SUCCESS);
}
