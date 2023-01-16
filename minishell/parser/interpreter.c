/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@42.student.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:27:11 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/13 15:27:11 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//checks for $ and expands to a env variable
void	expand(t_token *token)
{
	if (token)
		return ;
}

int	syntax_error(char *token)
{
	char	*str;

	str = ft_strndup("minishell: syntax error near unexpected token '%s'\n", -1);
	if (!token)
		printf(str, "newline");
	else
		printf(str, token);
	free(str);
	return (1);
}

int	interpreter(t_token *token)
{
	int	type;

	if (token->type == END)
		return (syntax_error(token->token));
	while (token->next->type != END)
	{
		expand(token);
		type = token->type;
		token = token->next;
		if (type == REDIR && token->type != WORD)
			return (syntax_error(token->token));
	}
	expand(token);
	if (token->type != WORD)
		return (syntax_error(token->next->token));
	return (0);
}
