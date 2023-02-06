/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:09:32 by mreis-me          #+#    #+#             */
/*   Updated: 2023/02/04 22:51:40 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	exit_error(char *str, int status)
{
	if (status == 255)
	{
		write(STDERR_FILENO, "minishell: exit: ", 17);
		write(STDERR_FILENO, str, ft_strlen(str));
		write(STDERR_FILENO, ": numeric argument required\n", 28);
	}
	else if (status == 1)
	{
		write(STDERR_FILENO, "minishell: exit: ", 17);
		write(STDERR_FILENO, "too many arguments\n", 19);
	}
	return (status);
}

static int	llong_check(char *value, int index, int sign)
{
	if (value[index] == '-' && value[index +1] != '\0')
	{
		index++;
		sign = 1;
	}
	while (value[index] && ft_isdigit(value[index]))
		index++;
	if (value[index] != '\0' && !ft_isdigit(value[index]))
		return (EXIT_FAILURE);
	if (!sign && ft_strlen(value) > LEN_MAX)
		return (EXIT_FAILURE);
	else if (sign && ft_strlen(value) > LEN_MIN)
		return (EXIT_FAILURE);
	else if (ft_strlen(value) == LEN_MIN || ft_strlen(value) == LEN_MAX)
	{
		index = -1;
		while (value[++index])
		{
			if (!sign && value[index] > LLONG_MAX[index])
				return (EXIT_FAILURE);
			if (sign && value[index] > LLONG_MIN[index])
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

static int	validate(char **args, int len)
{
	long long int	status;

	while (args[++len])
	{
		if (len > 1)
			return (exit_error(args[len], 1));
		status = ft_atoll(args[len]);
		if (llong_check(args[len], 0, 0))
			return (exit_error(args[len], 255));
	}
	if (len > 1)
		return (status % 256);
	return (0);
}

int	bt_exit(t_shell *shell)
{
	printf("exit\n");
	if (shell->cmd != NULL)
		g_status_code = validate(shell->cmd->args, 0);
	arrfree(shell->env);
	exit(g_status_code);
}
