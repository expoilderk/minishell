/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@42.student.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:26:18 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/13 15:26:18 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	next_cmd(t_token **token)
{
	t_token	*tmp;

	while ((*token)->type != END)
	{
		tmp = *token;
		*token = (*token)->next;
		free(tmp->token);
		free(tmp);
	}
	tmp = *token;
	*token = (*token)->next;
	free(tmp->token);
	free(tmp);
}

//create the cmd struct, opening redirects or heredocs
t_cmd	*create_cmd(t_token *token)
{
	if (!token)
		return (NULL);
	return (NULL);
}
