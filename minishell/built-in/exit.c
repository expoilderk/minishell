/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:09:32 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/19 20:11:45 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	bt_exit(char *name, char **env)
{
	arrfree(env);
	if (errno)
	{
		write(STDERR_FILENO, "minishell: ", 11);
		perror(name);
	}
	else
		printf("exit\n");
	exit(errno);
}

// Verificar se essa é a melhor implementação
