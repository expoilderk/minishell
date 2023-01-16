/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@42.student.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:24:29 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/11 22:24:29 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ismetachr(int c)
{
	if (ft_strchr(" \n\t|><", c))
		return (1);
	return (0);
}

static int	quotes_len(char *str)
{
	int	len;

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

int	token_type(char *str)
{
	if (!str)
		return (END);
	if (str[0] == '>' || str[0] == '<')
		return (REDIR);
	if (str[0] == '|')
		return (END);
	return (WORD);
}

char	*get_token(char *str)
{
	int	len;

	if (!ft_strncmp(str, ">>", 2) || !ft_strncmp(str, "<<", 2))
		return (ft_strndup(str, 2));
	if (str[0] == '>' || str[0] == '<' || str[0] == '|')
		return (ft_strndup(str, 1));
	len = 0;
	while (str[len] && !ismetachr(str[len]))
	{
		len++;
		len += quotes_len(str);
	}
	return (ft_strndup(str, len));
}
