/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:33:28 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/09 15:49:54 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*line;
	char	**tokens;

	line = prompt();
	tokens = lexer(line);
	free(line);
	arrfree(tokens);
	return (0);
}
