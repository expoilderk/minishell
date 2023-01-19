/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:50:35 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/19 17:18:34 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	validate(char *str)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[0]))
		return (0);
	while (str[i])
	{
		if (!ft_isalnum(str[i]))
		{
			if (str[i] == '=')
				break ;
			return (0);
		}
		i++;
	}
	if (str[i] != '=')
		return (-1);
	return (1);
}

int	export(t_cmd *cmd)
{
	char	*var;
	char	*value;
	int		i;

	i = 1;
	while (cmd->args[i])
	{
		if (!validate(cmd->args[i]))
			printf("export: '%s': not a valid identifier\n", cmd->args[i]);
		else if (validate(cmd->args[i]) == 1)
		{
			var = get_var(cmd->args[i], '=', 1);
			value = ft_strchr(cmd->args[i], '=');
			set_env(cmd, var, ++value);
			free(var);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
