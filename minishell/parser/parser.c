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

	cmd = malloc(sizeof(t_cmd));
	cmd->args = malloc(sizeof(char *) * 10);
	token = lexer(line);
	free(line);

	/// Copia os tokens para o array de comandos
	int i = 0;
	while (token)
	{
		cmd->args[i++] = token->token;
		token = token->next;
	}
	cmd->args[i] = NULL;
	// Usado apenas para teste

	// while (token)
	// {
	// 	if (interpreter(token))
	// 		return (NULL);
	// 	create_cmd(token);
	// 	next_cmd(&token);
	// }
	return (cmd);
}
