/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:57:59 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/18 18:26:37 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_var(char *str)
{
	int		i;
	int		len;
	char	*var;

	len = envlen(str);
	var = malloc(sizeof(char) * (len + 1));
	if (!var)
		return (NULL);
	i = -1;
	while (++i < len)
		var[i] = str[i];
	var[i] = '\0';
	return (var);
}
