/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:15:54 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/09 23:49:00 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int count_quotes(char const *s, int c)
{
	int i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			i++;
		s++;
	}
	return (i);
}

// char *ft_strtrim(char const *s)
// {
// 	int len;
// 	int quotes;
// 	int dquotes;
// 	char *new_str;

// 	if (!s)
// 		return (NULL);
// 	quotes = count_quotes(s, '\'');
// 	dquotes = count_quotes(s, '"');
// 	new_str = ft_strdup(new_str);
// 	while (*new_str && *new_str != '\'' && *new_str != '"')
// 		new_str++;
// 	while (quotes > 2)
// 	{
// 	}
// 	while (dquotes > 2)
// 	{
// 	}
// 	return (new_str);
// }

void ft_trim(char *str)
{
	// Encontra o primeiro e último caracter não-espaço da string
	int first;
	int last;
	int i;
	int single_count;
	int double_count;

	first = 0;
	last = ft_strlen(str) - 1;
	while (str[first] == ' ' || str[first] == '\t')
		first++;
	while (str[last] == ' ' || str[last] == '\t')
		last--;

	// Verifica se o primeiro ou último caracter é uma aspa simples ou dupla
	if (str[first] == '\'' || str[first] == '"')
		first++;
	if (str[last] == '\'' || str[last] == '"')
		last--;

	// Conta o número de aspas simples e duplas no meio da string
	single_count = 0;
	double_count = 0;
	i = first;
	while (i <= last)
	{
		if (str[i] == '\'')
			single_count++;
		if (str[i] == '"')
			double_count++;
		i++;
	}

	// Remove as aspas simples ou duplas no começo, durante ou no final da string,
	// desde que elas estejam equilibradas
	if (single_count % 2 == 0 && double_count % 2 == 0)
	{
		int j = 0;
		i = first;
		while (i <= last)
		{
			if (str[i] != '\'' && str[i] != '"')
			{
				str[j++] = str[i];
			}
			i++;
		}
	}
}