/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@42.student.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:24:29 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/11 22:24:29 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_token(char *line)
{
	int	len;

	if (!ft_strncmp(line, ">>", 2) || !ft_strncmp(line, "<<", 2))
		return (ft_strndup(line, 2));
	if (line[0] == '>' || line[0] == '<' || line[0] == '|')
		return (ft_strndup(line, 1));
	len = 0;
	while (line[len] && !ft_strchr(" \n\t|><", line[len]))
	{
		len += quotes_len(line + len);
		len++;
	}
	return (ft_strndup(line, len));
}

int	token_type(char *token)
{
	if (token[0] == '>' || token[0] == '<')
		return (REDIR);
	if (token[0] == '|')
		return (END);
	return (WORD);
}
