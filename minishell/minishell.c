/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:33:28 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/20 22:39:20 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	t_shell	shell;

	shell.env = get_environ();
	signals();
	while (42)
	{
		shell.line = prompt(shell.env);
		shell.cmd = parser(shell.line);
		// executor(shell.cmd, shell.env);
	}
	return (0);
}
