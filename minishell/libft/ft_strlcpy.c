/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:31:59 by gguedes           #+#    #+#             */
/*   Updated: 2022/12/05 12:55:19 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!src || !dst)
		return (ft_strlen(src));
	if (!size)
		return (ft_strlen(src));
	i = -1;
	size--;
	while (src[++i] && i < size)
		dst[i] = src[i];
	dst[i] = '\0';
	return (ft_strlen(src));
}
