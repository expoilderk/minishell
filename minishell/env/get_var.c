/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:57:59 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/18 18:26:37 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_var(char *str, char c, int option)
{
	char	*res;
	int		len;
	int		size;

	len = 0;
	while (str[len])
	{
		if (str[len] == c)
			break ;
		len++;
	}
	if (option)
		len++;
	res = malloc(sizeof(char) * len +1);
	size = 0;
	while (size < len)
	{
		res[size] = str[size];
		size++;
	}
	res[size] = '\0';
	return (res);
}
