/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:33:28 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/17 19:21:38 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	char *line;
	t_cmd *cmd;
	char **env;
	int flag = 0;

	(void)argc;
	(void)argv;
	env = envdup(envp);

	signals();
	while (42)
	{
		line = prompt();
		if (!line)
			sighandler(-1);
		if (ft_whitespace(line) == 0)
		{
			if (!ft_strncmp(line, "exit", -1))
				return (0);
			cmd = parser(line);
			executor(cmd, env, flag);
		}
	}
	arrfree(env);
	if (!cmd)
		return (1);
	return (0);
}
