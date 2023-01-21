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

t_cmd	*parser(char *line)
{
	t_token	*token;
	t_cmd	*cmd;

	token = lexer(line);
	free(line);
	if (!token)
		return (NULL);
	cmd = NULL;
	while (token)
	{
		if (interpreter(token))
			return (NULL);
		if (add_cmd(&cmd, create_cmd(token)))
			return (NULL);
		next_cmd(&token);
	}
	print_cmd(cmd);
	return (cmd);
}
