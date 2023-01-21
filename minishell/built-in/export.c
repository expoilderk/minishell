/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:50:35 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/20 20:30:37 by mreis-me         ###   ########.fr       */
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

int	bt_export(char **args, char **env)
{
	char	*var;
	char	*value;
	int		i;

	i = 1;
	while (args[i])
	{
		printf("args: %d %s\n", i, args[i]);
		if (!validate(args[i]))
			printf("export: '%s': not a valid identifier\n", args[i]);
		else if (validate(args[i]) == 1)
		{
			var = get_var(args[i], '=', 1);
			value = ft_strchr(args[i], '=');
			set_env(env, var, ++value);
			free(var);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
