/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@42.student.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:55:11 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/31 16:22:38 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	bt_pwd(void)
{
	char	*str;

	str = getcwd(NULL, 0);
	printf("%s\n", str);
	free(str);
	return (EXIT_SUCCESS);
}
