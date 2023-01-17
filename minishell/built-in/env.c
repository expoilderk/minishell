/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:50:25 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/17 00:02:51 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int env(t_cmd *cmd)
{
	int	i;
	if (!cmd || !cmd->env)
		return (EXIT_FAILURE);
	i = 0;
	while (cmd->env[i] != NULL)
		printf("%s\n", cmd->env[i++]);
	return (EXIT_SUCCESS);
}
