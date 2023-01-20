/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:26:14 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/19 22:04:05 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_env(char *name, char **env)
{
	int		len;
	char	*tmp;

	if (!name || !env)
		return (NULL);
	if (!ft_strchr(name, '='))
	{
		tmp = ft_strjoin(name, "=", 0);
		if (!tmp)
			return (NULL);
	}
	else
		tmp = ft_strndup(name, -1);
	len = ft_strlen(tmp);
	while (*env)
	{
		if (!ft_strncmp(*env, tmp, len))
		{
			free(tmp);
			return (*env);
		}
		env++;
	}
	free(tmp);
	return (NULL);
}
