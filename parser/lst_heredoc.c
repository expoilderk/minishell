/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:42:45 by gguedes           #+#    #+#             */
/*   Updated: 2023/02/03 11:43:17 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*free_heredocs(t_heredoc *heredoc)
{
	t_heredoc	*tmp;

	while (heredoc)
	{
		tmp = heredoc;
		heredoc = heredoc->next;
		free(tmp);
	}
	return (NULL);
}

t_heredoc	*last_heredoc(t_heredoc *heredoc)
{
	while (heredoc->next)
		heredoc = heredoc->next;
	return (heredoc);
}

t_heredoc	*new_heredoc(t_token *end)
{
	t_heredoc	*new;

	new = malloc(sizeof(t_heredoc));
	if (!new)
		return (NULL);
	new->fd = open_heredoc(end->token);
	if (new->fd == -1)
	{
		free(new);
		return (NULL);
	}
	new->token = end;
	new->next = NULL;
	return (new);
}

int	add_heredoc(t_heredoc *new, t_heredoc **heredoc)
{
	if (!new)
		return (EXIT_FAILURE);
	if (!(*heredoc))
	{
		*heredoc = new;
		return (EXIT_SUCCESS);
	}
	last_heredoc(*heredoc)->next = new;
	return (EXIT_SUCCESS);
}
