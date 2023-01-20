/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envdup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:32:47 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/19 19:51:05 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
