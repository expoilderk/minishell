/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:50:25 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/19 20:10:36 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	bt_env(char **args, char **env)
{
	(void)args; // Verificar se é necessário receber args
	while (*env)
		printf("%s\n", *env++);
	return (EXIT_SUCCESS);
}
