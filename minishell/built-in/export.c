/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:50:35 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/17 19:21:42 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int is_valid(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalpha(str[i]) && str[i] != '=')
			return (0);
		i++;
	}
	return (1);
}

int	export(t_cmd *cmd)
{
	char	**export;
	int		len;

	if (is_valid(cmd->args[1]))
	{
		len = envlen(cmd->env);
		export = envdup(cmd->env);
		export[len] = ft_strndup(cmd->args[1], -1);
		export[len+1] = NULL;
		len = envlen(export);
		memcpy(cmd->env, export, sizeof(char*) * (len + 1)); //Usar minha memcpy
	}
	else
		printf("export: '%s': não é um identificador válido\n", cmd->args[1]);
	return (EXIT_SUCCESS);
}
