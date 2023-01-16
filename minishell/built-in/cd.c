/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:50:33 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/15 12:39:10 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int cd(t_cmd *cmd)
{
	char cwd[1024];
	char *last_dir;

	if (cmd->args[1] == NULL || (ft_strncmp(cmd->args[1], "~", -1) == 0))
	{
		// handle "cd" and "cd ~"
		if (chdir(getenv("HOME")) != 0)
			perror("cd");
		return (EXIT_FAILURE);
	}
	else if (ft_strncmp(cmd->args[1], "-", -1) == 0)
	{
		// handle "cd -"
		last_dir = getenv("OLDPWD");
		if (chdir(last_dir) != 0)
		{
			perror("cd");
			return (EXIT_FAILURE);
		}
		printf("%s\n", last_dir);
	}
	else
	{
		// handle other arguments
		if (chdir(cmd->args[1]) != 0)
		{
			perror("cd");
			return (EXIT_FAILURE);
		}
	}
	getcwd(cwd, sizeof(cwd));
	setenv("OLDPWD", getenv("PWD"), 1); // Reescrever minha propria setenv e getenv
	setenv("PWD", cwd, 1);				// Reescrever minha propria setenv
	return (EXIT_SUCCESS);
}

/*
Este código é uma função chamada "cd" que recebe um ponteiro para uma estrutura
"t_cmd" como parâmetro. A função tem como objetivo mudar o diretório atual para o
especificado pelos argumentos passados para a função.

A função declara duas variáveis, "cwd" e "last_dir". "cwd" é uma string de 1024 c
aracteres que armazena o caminho atual do diretório e "last_dir" é uma string que
armazena o último diretório visitado.

A função começa verificando se o argumento passado para a função é nulo ou se é
igual a "~". Se for verdadeiro, a função muda o diretório para o diretório home do
usuário atual, usando a função getenv("HOME") para obter o caminho do diretório home.
Se houver algum erro ao mudar o diretório, a função usa a função perror("cd") para
imprimir uma mensagem de erro e retorna EXIT_FAILURE.

Se o argumento passado para a função for "-", a função muda o diretório para o último
diretório visitado, usando a função getenv("OLDPWD") para obter o caminho do último
diretório visitado. Se houver algum erro ao mudar o diretório, a função usa a
função perror("cd") para imprimir uma mensagem de erro e retorna EXIT_FAILURE.

Se o argumento passado para a função não for nulo, "~" ou "-", a função muda o
diretório para o diretório especificado pelo argumento. Se houver algum erro ao mudar
o diretório, a função usa a função perror("cd") para imprimir uma mensagem
de erro e retorna EXIT_FAILURE.

Finalmente, a função usa a função getcwd() para atualizar o caminho do diretório
atual e armazená-lo na variável "cwd". Em seguida, a função usa a função setenv()
para atualizar as variáveis de ambiente "OLDPWD" e "PWD" com os caminhos dos diretórios
atuais e anteriores. A função retorna EXIT_SUCCESS no final.
*/
