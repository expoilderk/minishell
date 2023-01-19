/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:25:29 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/19 16:28:58 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *get_value(char *name, char **env)
{
	int		len;
	char	*res;

	if (!name || !env)
		return (NULL);
	len = ft_strlen(name);
	while (*env)
	{
		if (!ft_strncmp(*env, name, len))
		{
			res = ft_strchr(*env, '=');
			return (++res);
		}
		env++;
	}
	return (NULL);
}
