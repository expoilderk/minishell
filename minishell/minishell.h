/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:33:25 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/14 16:20:39 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

# define WORD 1
# define REDIR 2
# define END 3

typedef struct s_token {
	char			*token;
	int				type;
	struct s_token	*next;
}	t_token;

typedef struct s_cmd {
	char			**args;
	int				(*built_in)(struct s_cmd *);
	int				in;
	int				out;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_builtin {
	char	*name;
	int		(*func)(t_cmd *);
}	t_builtin;

//utils
char	*ft_strchr(char *s, int c);
int		ft_strlen(char *str);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strndup(char *str, size_t len);
char	*ft_strjoin(char *s1, char *s2, int option);
int		ft_isspace(int c);
int		ft_whitespace(char *str);

//builtin
int		pwd(t_cmd *cmd);
int		echo(t_cmd *cmd);
int		env(t_cmd *cmd);
int		export(t_cmd *cmd);
int		unset(t_cmd *cmd);
int		cd(t_cmd *cmd);
int		b_exit(t_cmd *cmd);
int		(*get_builtin(char *str))(t_cmd *cmd);

//signals
void	signals(void);
void	sighandler(int sig);

//prompt
char	*prompt(void);

//lexer
t_token	*lexer(char *line);
void	add_token(t_token **token, t_token *new);
int		token_type(char *str);
char	*get_token(char *str);
t_token	*new_token(char *token);

//parser
t_cmd	*parser(char *line);
int		interpreter(t_token *token);
void	next_cmd(t_token **token);
t_cmd	*create_cmd(t_token *token);

//executor

#endif
