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

int	syntax_error(char *token)
{
	printf("minishell: syntax error near unexpected token ");
	if (!token)
		printf("newline\n");
	else
		printf("%s\n", token);
	return (1);
}

int	interpreter(t_token *token)
{
	int	type;

	if (token->type == END)
		return (syntax_error(token->token));
	while (token->next->type != END)
	{
		type = token->type;
		token = token->next;
		if (type == REDIR && token->type != WORD)
			return (syntax_error(token->token));
	}
	if (token->type != WORD)
		return (syntax_error(token->next->token));
	return (0);
}
