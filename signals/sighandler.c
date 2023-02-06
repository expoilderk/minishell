/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:47:05 by mreis-me          #+#    #+#             */
/*   Updated: 2023/02/04 23:16:17 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sighandler(int sig)
{
	if (sig)
	{
		g_status_code = 130;
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	sighandler_heredoc(int sig)
{
	if (sig)
	{
		g_status_code = 130;
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		exit(1);
	}
}
