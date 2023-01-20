NAME			=	minishell

UTILS_SRC		=	$(addprefix utils/, arrfree.c arrlen.c ft_isalnum.c ft_isspace.c ft_split.c ft_strchr.c \
					ft_strjoin.c ft_strlen.c ft_strncmp.c ft_strndup.c ft_strrchr.c quotes_len.c whitespaces.c \
					ft_memmove.c)

ENV_SRC			=	$(addprefix env/, get_environ.c envdup.c get_env.c get_var.c get_value.c set_env.c envlen.c \
					env_namelen.c)

BUILTIN_SRC		=	$(addprefix built-in/, builtin.c pwd.c echo.c cd.c env.c exit.c export.c unset.c)

SIGNALS_SRC		=	$(addprefix signals/, signals.c sighandler.c)

PROMPT_SRC		=	$(addprefix prompt/, prompt.c)

PARSER_SRC		=	$(addprefix parser/, parser.c interpreter.c cmd.c redirect.c)

LEXER_SRC		=	$(addprefix lexer/, lexer.c new_token.c add_token.c create_token.c)

EXECUTOR_SRC	=	$(addprefix executor/, executor.c run_cmd.c)

TEST_SRC		=	$(addprefix test/, test.c)

MINISHELL_SRC	=	minishell.c

OBJ				=	$(BUILTIN_SRC:.c=.o) $(PROMPT_SRC:.c=.o) $(PARSER_SRC:.c=.o) \
					$(LEXER_SRC:.c=.o) $(EXECUTOR_SRC:.c=.o) $(MINISHELL_SRC:.c=.o) \
					$(UTILS_SRC:.c=.o) $(SIGNALS_SRC:.c=.o) $(ENV_SRC:.c=.o) \
					$(TEST_SRC:.c=.o)

CC				=	cc

CFLAGS			=	-Wall -Werror -Wextra

READLINEFLAGS	=	-lreadline -L ~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include

RM				=	rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(READLINEFLAGS) $(OBJ) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I ~/.brew/opt/readline/include -c $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
