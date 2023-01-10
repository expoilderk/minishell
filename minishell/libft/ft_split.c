/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:52:52 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/09 16:31:20 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_subs(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (*s)
	{
		if (!ft_isspace(*s))
				i++;
		s += skip_quotes(s);
		while (*s && !ft_isspace(*s))
			s++;
		while (*s && ft_isspace(*s))
			s++;
	}
	return (i);
}

static int	wordlen(char *s)
{
	int	len;

	len = 0;
	while (s[len] && !ft_isspace(s[len]))
	{
		len += skip_quotes(&s[len]);
		len++;
	}
	return (len);
}

char	**ft_split(char *s)
{
	int		i;
	int		len;
	int		n_subs;
	char	**split;

	if (!s)
		return (NULL);
	n_subs = count_subs(s);
	split = malloc(sizeof(char *) * (n_subs + 1));
	if (!split)
		return (NULL);
	i = -1;
	while (++i < n_subs)
	{
		while (*s && ft_isspace(*s))
			s++;
		len = wordlen(s);
		split[i] = ft_substr(s, 0, len);
		//split[i] = ft_strtrim(split[i]);
		if (!split[i])
			return (arrfree(split));
		s += len;
	}
	split[i] = NULL;
	return (split);
}
