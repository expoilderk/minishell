/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testenv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@42.student.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:21:42 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/16 19:21:42 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	arrprint(char **arr)
{
	while (*arr)
		printf("%s\n", *arr++);
}

void	print_tokens(t_token *token)
{
	while (token)
	{
		printf("%s$ == %i\n", token->token, token->type);
		token = token->next;
	}
}

void	print_cmd(t_cmd *cmd)
{
	int	i;

	if (!cmd)
		printf("NULL\n");
	i = 1;
	while (cmd)
	{
		printf("CMD: %i\n", i);
		arrprint(cmd->args);
		printf("i/o: %i / %i\n", cmd->in, cmd->out);
		cmd = cmd->next;
		i++;
	}
}
