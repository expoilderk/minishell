/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:16:33 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/19 17:17:56 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:25:22 by mreis-me          #+#    #+#             */
/*   Updated: 2022/08/04 18:49:28 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	c;
	size_t	init;

	if (!dst && !src)
		return (0);
	c = 0;
	init = 0;
	if ((size_t)dst - (size_t)src < len)
	{
		c = len - 1;
		while (c >= init && c < len)
		{
			((unsigned char *)dst)[c] = ((unsigned char *)src)[c];
			c--;
		}
	}
	else
	{
		while (c < len)
		{
			((unsigned char *)dst)[c] = ((unsigned char *)src)[c];
			c++;
		}
	}
	return (dst);
}
