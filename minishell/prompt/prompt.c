/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@42.student.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:33:22 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/07 15:53:56 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*gethost(void)
{
	return (ft_strdup("hostname"));
}

char	*prompt(void)
{
	char	*aux;
	char	*str;

	str = getenv("USER");
	str = ft_strjoin(str, "@", 0);
	aux = gethost();
	str = ft_strjoin(str, aux, 3);
	str = ft_strjoin(str, "$ ", 1);
	return (readline(str));
}
