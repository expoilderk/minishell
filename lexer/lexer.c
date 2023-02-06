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
	t_token	*token;

	token = NULL;
	line = whitespaces(line);
	while (*line)
	{
		if (add_token(new_token(line), &token))
			return (free_tokens(token));
		line += ft_strlen(last_token(token)->token);
		line = whitespaces(line);
	}
	return (token);
}
