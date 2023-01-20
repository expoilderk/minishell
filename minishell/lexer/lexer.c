/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@42.student.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:50:12 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/07 15:50:12 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*lexer(char *line)
{
	t_token	*new;
	t_token	*token;

	if (!line)
		return (NULL);
	token = NULL;
	line = whitespaces(line);
	while (*line)
	{
		new = new_token(get_token(line));
		add_token(&token, new);
		line += ft_strlen(new->token);
		line = whitespaces(line);
	}
	add_token(&token, new_token(NULL));
	return (token);
}
