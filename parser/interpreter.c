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

static void	next_cmd(t_token **token)
{
	while (*token && (*token)->type != END)
		*token = (*token)->next;
	if (*token)
		*token = (*token)->next;
}

t_cmd	*interpreter(t_token *token)
{
	t_heredoc	*heredoc;
	t_cmd		*cmd;

	heredoc = NULL;
	if (heredocs(token, &heredoc))
		return (free_heredocs(heredoc));
	cmd = NULL;
	while (token)
	{
		if (add_cmd(new_cmd(token, &heredoc), &cmd))
		{
			error("malloc");
			return (free_cmds(cmd));
		}
		next_cmd(&token);
	}
	return (cmd);
}
