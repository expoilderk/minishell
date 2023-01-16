/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@42.student.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:20:40 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/11 21:20:40 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strndup(char *str, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*new_str;

	if (!str)
		return (NULL);
	slen = ft_strlen(str);
	if (slen > len)
		slen = len;
	new_str = malloc(sizeof(char) * (slen + 1));
	if (!new_str)
		return (NULL);
	i = -1;
	while (++i < slen)
		new_str[i] = str[i];
	new_str[i] = '\0';
	return (new_str);
}
