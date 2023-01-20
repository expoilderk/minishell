/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@42.student.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:11:19 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/18 13:11:19 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	close_fd(int in, int out)
{
	if (in != 0)
		if (close(in) == -1)
			return (-1);
	if (out != 1)
		if (close(out) == -1)
			return (-1);
	return (0);
}

static char	*get_path(char *cmd, char **env)
{
	int		i;
	char	*aux;
	char	**path;

	aux = get_env("PATH", env);
	if (!aux)
		return (NULL);
	path = ft_split(aux + 5, ":");
	if (!path)
		return (NULL);
	aux = ft_strjoin("/", cmd, 0);
	if (!aux)
		return (NULL);
	i = -1;
	while (path[++i])
	{
		path[i] = ft_strjoin(path[i], aux, 1);
		if (!access(path[i], F_OK | X_OK))
			return (path[i]);
	}
	arrfree(path);
	free(aux);
	return (NULL);
}

static int	call_execve(t_cmd *cmd, char **env)
{
	char	*path;

	if (dup2(cmd->in, STDIN_FILENO) == -1
		|| dup2(cmd->out, STDOUT_FILENO) == -1)
		return (-1);
	if (close_fd(cmd->in, cmd->out) == -1)
		return (-1);
	path = get_path(cmd->args[0], env);
	if (!path)
		path = ft_strndup(cmd->args[0], -1);
	if (execve(path, cmd->args, env) == -1)
	{
		free(path);
		return (-1);
	}
	free(path);
	return (0);
}

int	run_cmd(t_cmd *cmd, char **env)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid == -1)
	{
		close_fd(cmd->in, cmd->out);
		return (-1);
	}
	if (!pid)
	{
		call_execve(cmd, env);
		arrfree(env);
		arrfree(cmd->args);
		close_fd(cmd->in, cmd->out);
		exit(1);
	}
	close_fd(cmd->in, cmd->out);
	if (waitpid(pid, &status, 0) == -1)
		return (-1);
	return (status);
}
