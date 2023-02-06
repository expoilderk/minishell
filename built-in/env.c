/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:50:25 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/27 22:41:25 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	bt_env(t_shell *shell)
{
	int	i;

	if (!shell->env)
		return (EXIT_FAILURE);
	i = -1;
	while (shell->env[++i])
		printf("%s\n", shell->env[i]);
	return (EXIT_SUCCESS);
}
