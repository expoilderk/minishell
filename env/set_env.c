/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@42.student.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:15:54 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/31 12:18:47 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	**create_env(char *str, char **env)
{
	int		i;
	char	**new_env;

	new_env = malloc(sizeof(char *) * (arrlen(env) + 2));
	if (!new_env)
		return (NULL);
	i = -1;
	while (env[++i])
	{
		new_env[i] = ft_strndup(env[i], -1);
		if (!new_env[i])
			return (arrfree(new_env));
	}
	new_env[i] = ft_strndup(str, -1);
	if (!new_env[i])
		return (arrfree(new_env));
	new_env[++i] = NULL;
	return (new_env);
}

int	set_env(char *str, char ***env)
{
	char	*var;
	char	**new_env;

	if (str[envlen(str)] != '=')
		return (EXIT_FAILURE);
	var = get_var(str);
	if (!var)
		return (EXIT_FAILURE);
	unset_env(var, env);
	free(var);
	new_env = create_env(str, *env);
	if (!new_env)
		return (EXIT_FAILURE);
	arrfree(*env);
	*env = new_env;
	return (EXIT_SUCCESS);
}
