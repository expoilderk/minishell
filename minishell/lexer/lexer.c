/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@42.student.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:50:12 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/07 15:50:12 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*skip_whitespaces(char *str)
{
	while (*str && ft_strchr(" \n\t", *str))
		str++;
	return (str);
}

t_token	*lexer(char *line)
{
	t_token	*new;
	t_token	*token;

	if (!line)
		return (NULL);
	token = NULL;
	line = skip_whitespaces(line);
	while (*line)
	{
		new = new_token(get_token(line));
		add_token(&token, new);
		line += ft_strlen(new->token);
		line = skip_whitespaces(line);
	}
	add_token(&token, new_token(NULL));
	return (token);
}

// int	main(int argc, char **argv)
// {
// 	t_token	*token;

// 	token = lexer(argv[1]);
// 	if (!token)
// 		printf("null\n");
// 	while (token)
// 	{
// 		printf("%s$ * %i$\n", token->token, token->type);
// 		token = token->next;
// 	}
// 	return (0);
// }
