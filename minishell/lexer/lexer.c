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

//"echo \"abcd efg\" >>   txt|rev | cat -e > test | grep a test"

//"echo" "abcd efg" ">>" "txt" "|" "rev" "|" "cat" "-e" "|" "grep" "a"

char **lexer(char *line)
{
	int i;
	char **split;

	split = ft_split(line);
	i = 0;
	while (split[i])
	{
		// split[i] = ft_strtrim(split[i], "'\"");
		ft_trim(split[i]);
		printf("%s$\n", split[i]);
		i++;
	}
	return (NULL);
}
