/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@42.student.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:26:14 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/31 12:38:34 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_env(char *name, char **env)
{
	int	len;

	len = ft_strlen(name);
	while (*env)
	{
		if (!ft_strncmp(name, *env, len))
		{
			if (len == envlen(*env))
				return (*env);
		}
		env++;
	}
	return (NULL);
}
