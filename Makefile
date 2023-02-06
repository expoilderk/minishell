NAME			=	minishell

UTILS_SRC		=	$(addprefix utils/, arrfree.c arrlen.c error.c ft_isalnum.c ft_isspace.c ft_split.c ft_strchr.c \
					ft_strjoin.c ft_strlen.c ft_strncmp.c ft_strndup.c ft_strrchr.c quotes_len.c whitespaces.c \
					ft_atoll.c safe_close.c)

ENV_SRC			=	$(addprefix env/, envlen.c expand.c get_env.c get_environ.c get_value.c \
					get_var.c set_env.c unset_env.c)

BUILTIN_SRC		=	$(addprefix built-in/, builtin.c cd.c echo.c env.c exit.c \
					export.c pwd.c unset.c)

SIGNALS_SRC		=	$(addprefix signals/, signals.c sighandler.c)

PROMPT_SRC		=	$(addprefix prompt/, prompt.c)

LEXER_SRC		=	$(addprefix lexer/, lexer.c lst_token.c tokenize.c)

PARSER_SRC		=	$(addprefix parser/, cmd_args.c expansor.c interpreter.c lst_cmd.c parser.c \
					redirect.c lst_heredoc.c heredoc.c)

EXECUTOR_SRC	=	$(addprefix executor/, executor.c run_cmd.c)

TEST_SRC		=	$(addprefix test/, test.c)

MINISHELL_SRC	=	minishell.c

OBJ				=	$(BUILTIN_SRC:.c=.o) $(PROMPT_SRC:.c=.o) $(PARSER_SRC:.c=.o) \
					$(LEXER_SRC:.c=.o) $(EXECUTOR_SRC:.c=.o) $(MINISHELL_SRC:.c=.o) \
					$(UTILS_SRC:.c=.o) $(SIGNALS_SRC:.c=.o) $(ENV_SRC:.c=.o) \
					$(TEST_SRC:.c=.o)

CC				=	cc

CFLAGS			=	-Wall -Werror -Wextra -g

#READLINEFLAGS	=	-lreadline -L /usr/local/Cellar/readline/8.2.1/lib -I /usr/local/Cellar/readline/8.2.1/include
READLINEFLAGS	=	-lreadline -L ~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include

RM				=	rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(READLINEFLAGS)

.c.o:
#	$(CC) $(CFLAGS) -I /usr/local/Cellar/readline/8.2.1/include -c $< -o $(<:.c=.o)
	$(CC) $(CFLAGS) -I ~/.brew/opt/readline/include -c $< -o $(<:.c=.o)
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

leaks:
	rm -f valgrind-out.txt*
	valgrind --suppressions=valgrind_readline.txt --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./minishell

.PHONY: all clean fclean re test
