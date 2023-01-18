/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:50:35 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/18 20:10:37 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	validate(char *str)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[0]))
		return (0);
	while (str[i])
	{
		if (!ft_isalnum(str[i]))
		{
			if (str[i] == '=')
				break ;
			return (0);
		}
		i++;
	}
	if (str[i] != '=')
		return (-1);
	return (1);
}

int	export(t_cmd *cmd)
{
	char	**export;
	int		len;
	int		i;

	i = 1;
	while (cmd->args[i])
	{
		// Faz a validação
		if (!validate(cmd->args[i]))
			printf("export: '%s': não é um identificador válido\n", cmd->args[i]);
		else if (validate(cmd->args[i]) == 1)
		{
			// Atualiza variavel de ambiente, criar func menor
			char *str = get_var(cmd->args[i], '=', 1);
			if(get_env(str, cmd->env))
			{
				len = 0;
				export = envdup(cmd->env);
				while (export[len])
				{
					if (!ft_strncmp(get_var(export[len], '=', 1), str, -1))
						export[len] = ft_strndup(cmd->args[i], -1);
					len++;
				}
				len = envlen(export);
				memcpy(cmd->env, export, sizeof(char*) * (len + 1)); //Usar minha memcpy
			}
			else // Cria variavel de ambiente, criar func menor
			{
				len = envlen(cmd->env);
				export = envdup(cmd->env);
				export[len] = ft_strndup(cmd->args[i], -1);
				export[len+1] = NULL;
				len = envlen(export);
				memcpy(cmd->env, export, sizeof(char*) * (len + 1)); //Usar minha memcpy
			}
			free(str);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
