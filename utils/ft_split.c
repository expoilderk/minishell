/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@42.student.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:39:02 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/18 13:39:02 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	subs(char *str, char *set)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (*str)
	{
		if (!ft_strchr(set, *str))
			i++;
		while (*str && !ft_strchr(set, *str))
			str++;
		while (*str && ft_strchr(set, *str))
			str++;
	}
	return (i);
}

static int	wordlen(char *str, char *set)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && !ft_strchr(set, str[i]))
		i++;
	return (i);
}

char	**ft_split(char *str, char *set)
{
	int		i;
	int		len;
	int		size;
	char	**split;

	if (!str)
		return (NULL);
	size = subs(str, set);
	split = malloc(sizeof(char *) * (size + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (i < size)
	{
		while (*str && ft_strchr(set, *str))
			str++;
		len = wordlen(str, set);
		split[i] = ft_strndup(str, len);
		if (!split[i])
			return (arrfree(split));
		str += len;
		i++;
	}
	split[i] = NULL;
	return (split);
}
