/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_environ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@42.student.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:55:09 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/15 12:55:09 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern char	**environ;

char	**get_environ(void)
{
	int		i;
	char	**new_env;

	new_env = malloc(sizeof(char *) * (arrlen(environ) + 1));
	if (!new_env)
		return (NULL);
	i = -1;
	while (environ[++i])
	{
		new_env[i] = ft_strndup(environ[i], -1);
		if (!new_env[i])
			return (arrfree(new_env));
	}
	new_env[i] = NULL;
	unset_env("OLDPWD", &new_env);
	return (new_env);
}
