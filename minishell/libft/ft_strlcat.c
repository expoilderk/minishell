/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:42:42 by gguedes           #+#    #+#             */
/*   Updated: 2022/12/05 12:55:07 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (!src || !dst)
		return (size + ft_strlen(src));
	i = ft_strlen(dst);
	if (size <= i)
		return (size + ft_strlen(src));
	j = -1;
	size--;
	while (src[++j] && i + j < size)
		dst[i + j] = src[j];
	dst[i + j] = 0;
	return (i + ft_strlen(src));
}
