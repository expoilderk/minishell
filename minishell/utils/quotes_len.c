/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quoteslen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@42.student.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:22:56 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/17 12:22:56 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	quotes_len(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	if (str[len] == '\'')
	{
		len++;
		while (str[len] && str[len] != '\'')
			len++;
	}
	else if (str[len] == '"')
	{
		len++;
		while (str[len] && str[len] != '"')
			len++;
	}
	return (len);
}
