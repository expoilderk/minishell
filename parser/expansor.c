/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:58:19 by gguedes           #+#    #+#             */
/*   Updated: 2023/02/03 11:23:13 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	expansor(t_token *token, char **env)
{
	char	*new_token;

	while (token)
	{
		new_token = expand(token->token, env);
		if (!new_token)
			return (EXIT_FAILURE);
		free(token->token);
		token->token = new_token;
		token = token->next;
	}
	return (EXIT_SUCCESS);
}
