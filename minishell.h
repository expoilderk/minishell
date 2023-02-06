/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:33:25 by gguedes           #+#    #+#             */
/*   Updated: 2023/02/05 00:04:43 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*   Updated: 2023/02/01 14:27:46 by gguedes          ###   ########.fr       */
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

# define LLONG_MAX "9223372036854775807"
# define LLONG_MIN "-9223372036854775807"

# define LEN_MAX 19
# define LEN_MIN 20

typedef struct s_token {
	char			*token;
	int				type;
	struct s_token	*next;
}	t_token;

typedef struct s_heredoc {
	int					fd;
	t_token				*token;
	struct s_heredoc	*next;
}	t_heredoc;

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
void			*arrfree(char **arr);
int				arrlen(char	**arr);
int				error(char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isspace(int c);
char			**ft_split(char *str, char *set);
char			*ft_strchr(char *s, int c);
char			*ft_strjoin(char *s1, char *s2, int option);
int				ft_strlen(char *str);
int				ft_strncmp(char *s1, char *s2, size_t n);
char			*ft_strndup(char *str, size_t len);
char			*ft_strrchr(char *s, int c);
int				quotes_len(char *str);
char			*whitespaces(char *str);
long long int	ft_atoll(char *str);
int				safe_close(int fd1, int fd2);

//env
int				envlen(char *env);
char			*get_env(char *name, char **env);
char			**get_environ(void);
char			*get_value(char *str);
char			*get_var(char *str);
int				set_env(char *str, char ***env);
int				unset_env(char *str, char ***env);
char			*expand(char *str, char **env);

//builtin
int				builtin(t_shell *shell);
int				bt_pwd(void);
int				bt_echo(t_shell *shell);
int				bt_env(t_shell *shell);
int				bt_export(t_shell *shell);
int				bt_unset(t_shell *shell);
int				bt_cd(t_shell *shell);
int				bt_exit(t_shell *shell);

//signals
int				signals(void);
void			sighandler(int sig);
void			sighandler_heredoc(int sig);

//prompt
char			*prompt(t_shell *shell);

//lexer
t_token			*lexer(char *line);
void			*free_tokens(t_token *token);
t_token			*last_token(t_token *token);
t_token			*new_token(char *line);
int				add_token(t_token *new, t_token **token);
char			*get_token(char *line);
int				token_type(char *token);

//parser
int				expansor(t_token *token, char **env);
t_cmd			*parser(t_shell *shell);
int				heredoc(char *end);
int				call_heredoc(t_token *token);
int				heredocs(t_token *token, t_heredoc **heredoc);
void			*free_cmds(t_cmd *cmd);
t_cmd			*last_cmd(t_cmd *cmd);
t_cmd			*new_cmd(t_token *token, t_heredoc **heredoc);
int				add_cmd(t_cmd *new, t_cmd **cmd);
char			**cmd_args(t_token *token);
int				redirect(t_cmd *cmd, t_token *token, t_heredoc **heredoc);
t_cmd			*interpreter(t_token *token);
int				add_heredoc(t_heredoc *new, t_heredoc **heredoc);
t_heredoc		*new_heredoc(t_token *end);
t_heredoc		*last_heredoc(t_heredoc *heredoc);
void			*free_heredocs(t_heredoc *heredoc);
int				open_heredoc(char *end);

//executor
int				executor(t_shell *shell);
int				run_cmd(t_cmd *cmd, char **env);

//test functions
void			arrprint(char **arr);
void			print_tokens(t_token *token);
void			print_cmd(t_cmd *cmd);

extern int		g_status_code;

#endif
