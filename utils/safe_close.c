/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:59:04 by gguedes           #+#    #+#             */
/*   Updated: 2023/02/03 12:00:54 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	safe_close(int fd1, int fd2)
{
	int	status;

	status = 0;
	if (fd1 != 0)
		status += close(fd1);
	if (fd2 != 1)
		status += close(fd2);
	return (status);
}
