/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:50:36 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/18 22:51:00 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	validate(char *str) // Modificar lógica para ficar de acordo com o padrão da unset
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
	char	*var;

	len = 0;
	flag = 0;
	unset = envdup(env);
	var = get_var(args[i], '=', 0);
	while (unset[len])
	{
		if (ft_strncmp(get_var(unset[len], '=', 0), var, -1) && !flag)
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
	free(var);
}

int	unset(t_cmd *cmd)
{
	int		i;

	i = 1;
	while (cmd->args[i])
	{
		if (!validate(cmd->args[i]))
			printf("unset: '%s': não é um identificador válido\n", cmd->args[i]);
		else if (validate(cmd->args[i]))
			unset_env(cmd->env, cmd->args, i);
		i++;
	}
	return (EXIT_SUCCESS);
}
