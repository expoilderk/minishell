/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrfree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@42.student.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:00:13 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/15 13:00:13 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*arrfree(char **arr)
{
	int	i;

	if (!arr)
		return (NULL);
	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	return (NULL);
}
