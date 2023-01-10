/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:26:45 by gguedes           #+#    #+#             */
/*   Updated: 2022/12/02 19:35:50 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digits(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*new_str;

	if (!n)
		return (ft_strdup("0"));
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = digits(n);
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	new_str[len--] = '\0';
	if (n < 0)
	{
		new_str[0] = '-';
		n = -n;
	}
	while (n)
	{
		new_str[len--] = n % 10 + '0';
		n /= 10;
	}
	return (new_str);
}
