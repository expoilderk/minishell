/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:33:28 by gguedes           #+#    #+#             */
/*   Updated: 2023/02/05 00:04:21 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_status_code = 0;

int	main(void)
{
	t_shell	shell;

	shell.env = get_environ();
	if (!shell.env)
		return (error("cannot set variable"));
	if (signals())
		return (error("signal"));
	while (42)
	{
		shell.line = prompt(&shell);
		shell.cmd = parser(&shell);
		executor(&shell);
	}
	return (0);
}
