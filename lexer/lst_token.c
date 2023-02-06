/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@42.student.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:08:41 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/11 22:08:41 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*free_tokens(t_token *token)
{
	t_token	*tmp;

	while (token)
	{
		tmp = token;
		token = token->next;
		free(tmp->token);
		free(tmp);
	}
	return (NULL);
}

t_token	*last_token(t_token *token)
{
	while (token->next)
		token = token->next;
	return (token);
}

t_token	*new_token(char *line)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->token = get_token(line);
	if (!new->token)
	{
		free(new);
		return (NULL);
	}
	new->type = token_type(new->token);
	new->next = NULL;
	return (new);
}

int	add_token(t_token *new, t_token **token)
{
	if (!new)
		return (EXIT_FAILURE);
	if (!(*token))
	{
		*token = new;
		return (EXIT_SUCCESS);
	}
	last_token(*token)->next = new;
	return (EXIT_SUCCESS);
}
