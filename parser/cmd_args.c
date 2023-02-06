/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@42.student.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:50:38 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/25 00:50:38 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	args_size(t_token *token)
{
	int	i;

	i = 0;
	while (token && token->type != END)
	{
		if (token->type == WORD)
			i++;
		else
			token = token->next;
		token = token->next;
	}
	return (i);
}

char	**cmd_args(t_token *token)
{
	int		i;
	char	**args;

	args = malloc(sizeof(char *) * (args_size(token) + 1));
	if (!args)
		return (NULL);
	i = 0;
	while (token && token->type != END)
	{
		if (token->type == WORD)
		{
			args[i] = ft_strndup(token->token, -1);
			if (!args[i++])
				return (arrfree(args));
		}
		else
			token = token->next;
		token = token->next;
	}
	args[i] = NULL;
	return (args);
}
