/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:33:22 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/19 18:55:56 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*read_fd(int fd, char *set)
{
	int		bytes;
	char	buffer[2];
	char	*output;

	output = NULL;
	while (1)
	{
		bytes = read(fd, buffer, 1);
		if (bytes == -1)
			return (NULL);
		buffer[bytes] = '\0';
		if (buffer[0] == '\0' || ft_strchr(set, buffer[0]))
			break ;
		output = ft_strjoin(output, buffer, 1);
		if (!output)
			return (NULL);
	}
	return (output);
}

static char	*get_cmd(char *str, char **env)
{
	int		pipefd[2];
	char	*output;
	t_cmd	cmd;

	cmd.args = ft_split(str, " ");
	if (!cmd.args)
		return (NULL);
	if (pipe(pipefd))
		return (arrfree(cmd.args));
	cmd.in = 0;
	cmd.out = pipefd[1];
	cmd.next = NULL;
	if (run_cmd(&cmd, env) == -1)
		return (arrfree(cmd.args));
	arrfree(cmd.args);
	output = read_fd(pipefd[0], "\n");
	close(pipefd[0]);
	return (output);
}

static char	*get_prompt(char **env)
{
	char	*str;
	char	*aux;

	str = get_cmd("/usr/bin/whoami", env);
	if (!str)
		return (NULL);
	str = ft_strjoin(str, "@", 1);
	if (!str)
		return (NULL);
	aux = get_cmd("/bin/hostname", env);
	if (!aux)
		return (NULL);
	str = ft_strjoin(str, aux, 3);
	if (!str)
		return (NULL);
	return (ft_strjoin(str, "$ ", 1));
}

char	*prompt(char **env)
{
	char	*str;
	char	*line;

	str = get_prompt(env);
	if (!str)
		return (NULL);
	line = readline(str);
	free(str);
	if (!line)
		bt_exit("prompt", env);
	if (line[0])
		add_history(line);
	return (line);
}
