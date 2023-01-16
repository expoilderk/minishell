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

/*
void	print_tokens(t_token *token)
{
	while (token)
	{
		printf("%s$ == %i\n", token->token, token->type);
		token = token->next;
	}
	printf("==============\n");
}

void	print_cmd(t_token *token)
{
	while (token->type != END)
	{
		printf("%s$ == %i\n", token->token, token->type);
		token = token->next;
	}
	printf("==============\n");
}
*/

t_cmd *parser(char *line)
{
	t_token *token;
	t_cmd *cmd;

	cmd = malloc(sizeof(t_cmd));
	cmd->args = malloc(sizeof(char *) * 10);

	token = lexer(line);
	free(line);

	// Copia os tokens para o array de comandos
	int i = 0;
	while (token)
	{
		cmd->args[i++] = token->token;
		token = token->next;
	}
	cmd->args[i] = NULL;

	// Busca e executa o built-in
	// int (*built_in)(t_cmd *) = get_builtin(cmd->args[0]);
	// if (built_in)
	// {
	// 	built_in(cmd);
	// }

	// while (token)
	// {
	// 	if (interpreter(token))
	// 		return (NULL);
	// 	create_cmd(token);
	// 	next_cmd(&token);
	// }
	return (cmd);
}
