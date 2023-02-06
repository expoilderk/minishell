/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@42.student.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:51:02 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/17 12:39:13 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	copy(char *s1, char *s2, char *dest)
{
	if (s1)
	{
		while (*s1)
			*dest++ = *s1++;
	}
	if (s2)
	{
		while (*s2)
			*dest++ = *s2++;
	}
	*dest = '\0';
}

char	*ft_strjoin(char *s1, char *s2, int option)
{
	char	*new_str;

	new_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_str)
		return (NULL);
	copy(s1, s2, new_str);
	if (option == 1 || option == 3)
		free(s1);
	if (option == 2 || option == 3)
		free(s2);
	return (new_str);
}
