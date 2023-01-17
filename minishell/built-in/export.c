/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:50:35 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/17 00:09:34 by mreis-me         ###   ########.fr       */
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

int export(t_cmd *cmd) {
    char **export;
    int len;
    if (cmd->args[1] != NULL && is_valid(cmd->args[1])) {
        len = envlen(cmd->env);
        export = (char**)malloc((len + 2) * sizeof(char*));
        for (int i = 0; i < len; i++) {
            export[i] = ft_strndup(cmd->env[i], -1);
        }
        export[len] = ft_strndup(cmd->args[1], -1);
        export[len + 1] = NULL;
        arrfree(cmd->env);
        cmd->env = export;
    } else {
        printf("export: '%s': não é um identificador válido\n", cmd->args[1] ? cmd->args[1] : "");
    }
    // Adicione prints para verificar o tamanho do array cmd->env e o conteúdo de cada elemento
    printf("cmd->env size: %d\n", envlen(cmd->env));
    for (int i = 0; cmd->env[i]; i++) {
        printf("cmd->env[%d]: %s\n", i, cmd->env[i]);
    }
    // Adicione prints para verificar o endereço de memória de cada elemento do array
    for (int i = 0; cmd->env[i]; i++) {
        printf("cmd->env[%d] address: %p\n", i, (void *)cmd->env[i]);
    }
    return (EXIT_SUCCESS);
}



// int	export(t_cmd *cmd)
// {
// 	char **export;
// 	int len;


// // if (cmd->args[1] != NULL && is_valid(cmd->args[1])) {
// //     len = envlen(cmd->env);
// //     export = (char**)malloc((len + 2) * sizeof(char*));
// //     for (int i = 0; i < len; i++) {
// //         export[i] = ft_strndup(cmd->env[i], -1);
// //     }
// //     export[len] = ft_strndup(cmd->args[1], -1);
// //     export[len + 1] = NULL;
// //     arrfree(cmd->env);
// //     cmd->env = export;
// // } else {
// //     printf("export: '%s': não é um identificador válido\n", cmd->args[1] ? cmd->args[1] : "");
// // }



// 	if (is_valid(cmd->args[1]))
// 	{
// 			len = envlen(cmd->env);
// 			printf("%d\n", len);
// 			// len++;
// 			export = (char **)malloc(sizeof(char *) * len + 2);
// 		    for (int i = 0; i < len; i++) {
//         		export[i] = ft_strndup(cmd->env[i], -1);
//     		}

// 			export[len] = ft_strndup(cmd->args[1], -1);
// 			printf("%d %s\n", len, export[len]);

// 			export[len +1] = NULL;
// 			// int i = -1;
// 			// while (export[++i])
// 			// 	printf("%d : %s\n", i, export[i]);
// 			printf("%d\n", len);
// 			arrfree(cmd->env);
// 			cmd->env = (char **)malloc(sizeof(char *) * len + 2);
// 			for (int i = 0; i < len+1; i++) {
//         		cmd->env[i] = ft_strndup(export[i], -1);
//     		}

// 			// cmd->env = export;
// 			// printf("%s\n", cmd->env[len]);

// 	}
// 	else
// 		printf("export: '%s': não é um identificador válido\n", cmd->args[1]);
// 	return (EXIT_SUCCESS);
// }
