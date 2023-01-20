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

int	add_cmd(t_cmd **cmd, t_cmd *new)
{
	t_cmd	*last;

	if (!new)
		return (1);
	if (!*cmd)
	{
		*cmd = new;
		return (0);
	}
	last = *cmd;
	while (last->next)
		last = last->next;
	last->next = new;
	return (0);
}

t_cmd	*create_cmd(t_token *token)
{
	int		i;
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->args = malloc(sizeof(char *) * (redirect(cmd, token) + 1));
	if (!cmd->args)
	{
		free(cmd);
		return (NULL);
	}
	i = 0;
	while (token->type != END)
	{
		if (token->type == REDIR)
			token = token->next;
		else
			cmd->args[i++] = ft_strndup(token->token, -1);
		token = token->next;
	}
	cmd->args[i] = NULL;
	cmd->next = NULL;
	return (cmd);
}
