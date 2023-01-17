/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:43:32 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/16 20:54:32 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	handle_flag_n(char **argv)
{
	int	flag_n;
	int	j;

	flag_n = 0;
	if (argv[1] != NULL && argv[1][0] == '-')
	{
		flag_n = 1;
		j = 1;
		while (argv[1][j] != '\0')
		{
			if (argv[1][j] != 'n')
			{
				flag_n = 0;
				break ;
			}
			j++;
		}
	}
	if (flag_n)
		return (2);
	return (1);
}

static void	handle_backslash(char *arg, int j)
{
	char	c;

	c = arg[j];
	if (c == '\"' || c == '\'')
	{
		if (arg[j - 1] != '\\')
			j++;
	}
	if (c == '\\')
	{
		j++;
		c = arg[j];
		if (c == '\"')
			printf("\"");
		else if (c == '\'')
			printf("\'");
		else if (c == '\\')
			printf("\\");
		else
			printf("%c", c);
		j++;
	}
	printf("%c", c);
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
		{
			handle_backslash(arg, j);
			j++;
		}
		if (argv[start + 1])
			printf(" ");
		start++;
	}
}

int	echo(t_cmd *cmd)
{
	int	newline;
	int	start;

	newline = 1;
	start = handle_flag_n(cmd->args);
	if (start == 2)
		newline = 0;
	print_args(start, cmd->args);
	if (newline)
		printf("\n");
	return (EXIT_SUCCESS);
}
