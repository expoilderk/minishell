/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:15:54 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/19 21:44:54 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	insert_env(char **env, char *var, char *value)
{
	char	**export;
	int		len;

	len = envlen(env);
	export = envdup(env);
	export[len] = ft_strndup(ft_strjoin(var, value, 0), -1);
	export[len +1] = NULL;
	len = envlen(export);
	ft_memmove(env, export, sizeof(char *) * (len +1));
}

static void	update_env(char **env, char *var, char *value)
{
	char	**export;
	int		len;

	len = 0;
	export = envdup(env);
	while (export[len])
	{
		if (!ft_strncmp(get_var(export[len], '=', 1), var, -1))
			export[len] = ft_strndup(ft_strjoin(var, value, 0), -1);
		len++;
	}
	len = envlen(export);
	ft_memmove(env, export, sizeof(char *) * (len +1));
}

int	set_env(char **env, char *var, char *value)
{
	if (!var || !value)
		return (EXIT_FAILURE);
	if (get_env(var, env))
		update_env(env, var, value);
	else
		insert_env(env, var, value);
	return (EXIT_SUCCESS);
}
