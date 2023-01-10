/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 22:49:55 by gguedes           #+#    #+#             */
/*   Updated: 2022/12/05 12:54:03 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!n || !s1 || !s2)
		return (0);
	i = -1;
	n--;
	while (++i < n && s1[i] && s2[i])
		if (s1[i] != s2[i])
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
	return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
}
