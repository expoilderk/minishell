/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:58:23 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/14 16:19:36 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	init_builts(t_builtin *builtins)
{
	builtins[0].name = "pwd";
	builtins[0].func = pwd;
	builtins[1].name = "echo";
	builtins[1].func = echo;
	builtins[2].name = "cd";
	builtins[2].func = cd;
	builtins[3].name = "env";
	builtins[3].func = env;
	builtins[4].name = "unset";
	builtins[4].func = unset;
	builtins[5].name = "export";
	builtins[5].func = export;
	builtins[6].name = "b_exit";
	builtins[6].func = b_exit;
}

int	(*get_builtin(char *str))(t_cmd *cmd)
{
	int			i;
	t_builtin	builtins[7];

	i = 0;
	init_builts(builtins);
	while (i < 7)
	{
		if (!ft_strncmp(builtins[i].name, str, -1))
			return (builtins[i].func);
		i++;
	}
	return (NULL);
}
