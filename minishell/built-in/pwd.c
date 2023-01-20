/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:55:11 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/19 20:09:05 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	bt_pwd(char **args)
{
	char	*str;

	(void)args;
	str = getcwd(NULL, 0);
	printf("%s\n", str);
	free(str);
	return (EXIT_SUCCESS);
}
