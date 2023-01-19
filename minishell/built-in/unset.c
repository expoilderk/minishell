/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:50:36 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/19 16:58:04 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Modificar lógica para ficar de acordo com o padrão da unset
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

static void	unset_env(char **env, char **args, int i)
{
	char	**unset;
	int		len;
	int		flag;

	len = 0;
	flag = 0;
	unset = envdup(env);
	while (unset[len])
	{
		if (ft_strncmp(get_var(unset[len], '=', 0), args[i], -1) && !flag)
			env[len] = ft_strndup(unset[len], -1);
		else
		{
			if (unset[len +1] == NULL)
				env[len] = 0;
			else
			{
				env[len] = ft_strndup(unset[len +1], -1);
				flag = 1;
			}
		}
		len++;
	}
}

int	unset(t_cmd *cmd)
{
	int		i;

	i = 1;
	while (cmd->args[i])
	{
		if (!validate(cmd->args[i]))
			printf("unset: '%s': not a valid identifier\n", cmd->args[i]);
		else if (validate(cmd->args[i]))
			unset_env(cmd->env, cmd->args, i);
		i++;
	}
	return (EXIT_SUCCESS);
}
