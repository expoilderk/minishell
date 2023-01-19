/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:50:35 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/18 21:36:12 by mreis-me         ###   ########.fr       */
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

static void	insert_env(char **env, char **args, int i)
{
	char	**export;
	int		len;

	len = envlen(env);
	export = envdup(env);
	export[len] = ft_strndup(args[i], -1);
	export[len +1] = NULL;
	len = envlen(export);
	memcpy(env, export, sizeof(char *) * (len +1)); //Usar minha memcpy
}

static void	update_env(char **env, char **args, int i)
{
	char	**export;
	char	*var;
	int		len;

	len = 0;
	export = envdup(env);
	var = get_var(args[i], '=', 1);
	while (export[len])
	{
		if (!ft_strncmp(get_var(export[len], '=', 1), var, -1))
			export[len] = ft_strndup(args[i], -1);
		len++;
	}
	len = envlen(export);
	memcpy(env, export, sizeof(char *) * (len +1)); //Usar minha memcpy
	free(var);
}

int	export(t_cmd *cmd)
{
	char	*var;
	int		i;

	i = 1;
	while (cmd->args[i])
	{
		if (!validate(cmd->args[i]))
			printf("export: '%s': não é um identificador \
			válido\n", cmd->args[i]);
		else if (validate(cmd->args[i]) == 1)
		{
			var = get_var(cmd->args[i], '=', 1);
			if (get_env(var, cmd->env))
				update_env(cmd->env, cmd->args, i);
			else
				insert_env(cmd->env, cmd->args, i);
			free(var);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
