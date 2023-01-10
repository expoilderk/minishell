/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:58:16 by gguedes           #+#    #+#             */
/*   Updated: 2022/12/04 14:02:34 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	i;

	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	i = 0;
	if (n < 0)
	{
		i += ft_putchar_fd('-', fd);
		i += ft_putnbr_fd(-n, fd);
	}
	else if (n > 9)
		i += ft_putnbr_fd(n / 10, fd);
	if (n >= 0)
		i += ft_putchar_fd((n % 10) + '0', fd);
	return (i);
}
