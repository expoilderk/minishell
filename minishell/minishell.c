/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:33:28 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/15 20:46:02 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// char	**copy_env(char **envp)
// {
// 	char	**env;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	while (envp[i])
// 		i++;
// 	env = malloc(sizeof(char *) * i + 1);
// 	j = 0;
// 	while (j < i)
// 	{
// 		env[j] = ft_strndup(envp[j], -1);
// 		printf("Copiou: %d %s\n", j, env[j]);
// 		j++;
// 	}
// 	return (env);
// }

int main(int argc, char **argv, char **envp)
{
	char *line;
	t_cmd *cmd;
	char **env;

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
			executor(cmd, env);
		}
	}
	arrfree(env);
	if (!cmd)
		return (1);
	return (0);
}
