/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:33:22 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/13 23:02:02 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*gethost(void)
{
	return (ft_strndup("hostname", -1));
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
	aux = readline(str);
	if (ft_whitespace(aux) == 0)
		add_history(aux);
	return (aux);
}
