/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:43:32 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/27 22:27:43 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	handle_flag_n(char **args, int j, int flag_n, int flag_err)
{
	int	i;

	while (args[j] != NULL)
	{
		if (args[j][0] == '-' && args[j][1] == 'n')
		{
			i = 2;
			while (args[j][i] != '\0')
			{
				if (args[j][i] != 'n')
					flag_err = 1;
				i++;
			}
			if (flag_err)
				break ;
			flag_n++;
		}
		else
			break ;
		j++;
	}
	if (flag_n != 1)
		return (flag_n);
	return (1);
}

static void	print_handle(char *arg, int j)
{
	if (arg[j] == '\\' && arg[j -1] != '\\')
		return ;
	if (arg[j] == '\"' || arg[j] == '\'')
	{
		if (arg[j - 1] != '\\')
		{
			j++;
			return ;
		}
		else
		{
			if (arg[j] == '\"')
			{
				printf("\"");
				return ;
			}
			else if (arg[j] == '\'')
			{
				printf("\'");
				return ;
			}
		}
	}
	printf("%c", arg[j]);
}

static void	print_args(int start, char **argv)
{
	char	*arg;
	int		len;
	int		j;

	while (argv[start])
	{
		arg = argv[start];
		len = ft_strlen(arg);
		j = 0;
		while (j < len)
			print_handle(arg, j++);
		if (argv[start + 1])
			printf(" ");
		start++;
	}
}

int	bt_echo(t_shell *shell)
{
	int	newline;
	int	start;

	newline = 1;
	start = handle_flag_n(shell->cmd->args, 1, 1, 0);
	if (start >= 2)
		newline = 0;
	print_args(start, shell->cmd->args);
	if (newline)
		printf("\n");
	return (EXIT_SUCCESS);
}
