/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:33:25 by gguedes           #+#    #+#             */
/*   Updated: 2023/01/19 21:01:47 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/wait.h>
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
	int				in;
	int				out;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_shell {
	char	*line;
	char	**env;
	t_cmd	*cmd;
}	t_shell;

//utils
void	*arrfree(char **arr);
int		arrlen(char	**arr);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isspace(int c);
char	**ft_split(char *str, char *set);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2, int option);
int		ft_strlen(char *str);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strndup(char *str, size_t len);
char	*ft_strrchr(char *s, int c);
void	*ft_memmove(void *dst, void *src, size_t len);
int		quotes_len(char *str);
char	*whitespaces(char *str);

//env
char	**get_environ(void);
char	**envdup(char **env);
char	*get_env(char *name, char **env);
int		set_env(char **env, char *var, char *value);
char	*get_value(char *name, char **env);
char	*get_var(char *str, char c, int option);
int		envlen(char **env);
int		env_namelen(char *env);

//builtin
int		builtin(t_cmd *cmd, char **env);
int		bt_pwd(char **args);
int		bt_echo(char **args);
int		bt_env(char **args, char **env);
int		bt_export(char **args, char **env);
int		bt_unset(char **args, char **env);
int		bt_cd(char **args, char **env);
int		bt_exit(char *name, char **env);

//signals
void	signals(void);
void	sighandler(int sig);

//prompt
char	*prompt(char **env);

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
int		add_cmd(t_cmd **cmd, t_cmd *new);
int		redirect(t_cmd *cmd, t_token *token);

//executor
int		executor(t_cmd *cmd, char **env);
int		run_cmd(t_cmd *cmd, char **env);

//test functions
void	arrprint(char **arr);
void	print_tokens(t_token *token);
void	print_cmd(t_cmd *cmd);

#endif
