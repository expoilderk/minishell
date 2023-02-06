/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@42.student.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:16:23 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/31 12:16:23 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*get_expansion(char **str, char **new_str, int *len, char **env)
{
	char	*var;
	char	*tmp;

	tmp = ft_strndup(*str, *len);
	if (!tmp)
		return (NULL);
	*str += *len + 1;
	var = ft_strndup(*str, envlen(*str));
	if (!var)
		return (NULL);
	*new_str = ft_strjoin(tmp, get_value(get_env(var, env)), 1);
	free(var);
	if (!*new_str)
		return (NULL);
	*len = 0;
	*str += envlen(*str);
	return (*new_str);
}

char	*expand(char *str, char **env)
{
	int		len;
	char	*new_str;

	if (!str)
		return (NULL);
	new_str = NULL;
	len = 0;
	while (str[len])
	{
		if (str[len] == '$')
			get_expansion(&str, &new_str, &len, env);
		else
			len++;
	}
	new_str = ft_strjoin(new_str, str, 1);
	return (new_str);
}
