/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:13:27 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/09 15:47:26 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	skip_quotes(char *str)
{
	int	len;

	len = 0;
	if (str[len] == '\'')
	{
		len++;
		while (str[len] && str[len] != '\'')
			len++;
		len++;
	}
	if (str[len] == '"')
	{
		len++;
		while (str[len] && str[len] != '"')
			len++;
		len++;
	}
	return (len);
}
