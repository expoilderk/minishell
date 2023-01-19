/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@42.student.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:55:09 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/15 12:55:09 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	envlen(char **env)
{
	int	i;

	if (!env)
		return (0);
	i = 0;
	while (env[i])
		i++;
	return (i);
}

int	env_namelen(char *env)
{
	int	i;

	if (!env)
		return (0);
	i = 0;
	while (!ft_isalnum(env[i]) && env[i] != '_')
		i++;
	return (i);
}

char	**envdup(char **env)
{
	int		i;
	char	**new_env;

	new_env = malloc(sizeof(char *) * (envlen(env) + 1));
	if (!new_env)
		return (NULL);
	i = -1;
	while (env[++i])
	{
		new_env[i] = ft_strndup(env[i], -1);
		if (!new_env[i])
			return (arrfree(new_env));
	}
	new_env[i] = NULL;
	return (new_env);
}
