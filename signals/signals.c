/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@42.student.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:31:19 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/24 13:54:57 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	signals(void)
{
	if (signal(SIGINT, sighandler) == SIG_ERR)
		return (EXIT_FAILURE);
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
