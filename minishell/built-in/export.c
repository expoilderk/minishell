/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:50:35 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/17 21:50:08 by mreis-me         ###   ########.fr       */
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


char *ft_strfind(char *str, char c)
{
	char *res;
	int len;
	int size;

	len = 0;
	while (str[len])
	{
		if (str[len] == c)
			break;
		len++;
	}
	len++;
	res = malloc(sizeof(char) * len+1);
	size = 0;
	while (size < len)
	{
		res[size] = str[size];
		size++;
	}
	res[size] = '\0';
	return (res);
}

int	export(t_cmd *cmd)
{
	char	**export;
	int		len;

	if (!is_valid(cmd->args[1]))
	{
		printf("export: '%s': não é um identificador válido\n", cmd->args[1]);
		return (EXIT_FAILURE);
	}

	// Atualiza variavel de ambiente
	char *str = ft_strfind(cmd->args[1], '=');
	if(get_env(str, cmd->env))
	{
		len = 0;
		export = envdup(cmd->env);
		while (export[len])
		{
			if (!ft_strncmp(ft_strfind(export[len], '='), str, -1))
				export[len] = ft_strndup(cmd->args[1], -1);
			len++;
		}
		len = envlen(export);
		memcpy(cmd->env, export, sizeof(char*) * (len + 1)); //Usar minha memcpy
	}
	else // Cria variavel de ambiente
	{
		len = envlen(cmd->env);
		export = envdup(cmd->env);
		export[len] = ft_strndup(cmd->args[1], -1);
		export[len+1] = NULL;
		len = envlen(export);
		memcpy(cmd->env, export, sizeof(char*) * (len + 1)); //Usar minha memcpy
	}
	free(str);
	return (EXIT_SUCCESS);
}
