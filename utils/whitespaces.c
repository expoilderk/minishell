/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whitespaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@42.student.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:44:41 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/17 12:24:23 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*whitespaces(char *str)
{
	if (!str)
		return (NULL);
	while (*str && ft_strchr(" \n\t", *str))
		str++;
	return (str);
}
