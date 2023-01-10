/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:33:25 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/09 15:08:42 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <readline/readline.h>

typedef struct s_cmd {
	char	**args;
	int		in;
	int		out;
}	t_cmd;

//built-in
void	pwd(void);

//prompt
char	*prompt(void);

//lexer
char	**lexer(char *line);

//parser

//executor

#endif
