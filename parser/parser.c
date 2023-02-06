/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@42.student.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:50:23 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/07 15:50:23 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_cmd	*parser(t_shell *shell)
{
	t_token	*token;
	t_cmd	*cmd;

	token = lexer(shell->line);
	free(shell->line);
	if (!token)
	{
		if (errno)
			error("malloc");
		return (NULL);
	}
	if (expansor(token, shell->env))
	{
		error("malloc");
		return (free_tokens(token));
	}
	cmd = interpreter(token);
	free_tokens(token);
	return (cmd);
}
