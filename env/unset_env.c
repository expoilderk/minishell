/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@42.student.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:08:48 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/31 12:08:48 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	**create_env(char *rm, char **env)
{
	int		i;
	char	**new_env;

	new_env = malloc(sizeof(char *) * (arrlen(env)));
	if (!new_env)
		return (NULL);
	i = 0;
	while (env[i])
	{
		if (env[i] == rm)
		{
			env++;
			continue ;
		}
		new_env[i] = ft_strndup(env[i], -1);
		if (!new_env[i])
			return (arrfree(new_env));
		i++;
	}
	new_env[i] = NULL;
	return (new_env);
}

int	unset_env(char *str, char ***env)
{
	char	*rm;
	char	**new_env;

	rm = get_env(str, *env);
	if (!rm)
		return (EXIT_SUCCESS);
	new_env = create_env(rm, *env);
	if (!new_env)
		return (EXIT_FAILURE);
	arrfree(*env);
	*env = new_env;
	return (EXIT_SUCCESS);
}
