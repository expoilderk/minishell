/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:33:22 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/27 23:38:05 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*read_fd(int fd)
{
	int		bytes;
	char	buffer[256];

	bytes = read(fd, buffer, 255);
	if (bytes == -1)
		return (NULL);
	buffer[bytes] = '\0';
	return (ft_strndup(buffer, ft_strlen(buffer) -1));
}

static char	*get_cmd(char *str, char **env)
{
	int		pipefd[2];
	char	*output;
	t_cmd	cmd;

	if (pipe(pipefd) == -1)
		return (NULL);
	cmd.args = ft_split(str, " ");
	if (!cmd.args)
		return (NULL);
	cmd.in = 0;
	cmd.out = pipefd[1];
	cmd.next = NULL;
	run_cmd(&cmd, env);
	arrfree(cmd.args);
	output = read_fd(pipefd[0]);
	close(pipefd[0]);
	return (output);
}

static char	*get_prompt(char **env)
{
	char	*str;
	char	*aux;

	str = get_cmd("/usr/bin/whoami", env);
	str = ft_strjoin(str, "@", 1);
	aux = get_cmd("/bin/hostname", env);
	str = ft_strjoin(str, aux, 3);
	return (ft_strjoin(str, "$ ", 1));
}

char	*prompt(t_shell *shell)
{
	char	*str;
	char	*line;

	str = get_prompt(shell->env);
	line = readline(str);
	free(str);
	if (!line)
		bt_exit(shell);
	if (line[0])
		add_history(line);
	return (line);
}
