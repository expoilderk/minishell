NAME			=	minishell

UTILS_SRC		=	$(addprefix utils/, ft_strncmp.c ft_strndup.c ft_strlen.c ft_strchr.c ft_strjoin.c ft_isspace.c ft_whitespace.c arrfree.c ft_isalnum.c)

BUILTIN_SRC		=	$(addprefix built-in/, built_in.c pwd.c echo.c cd.c env.c exit.c export.c unset.c)

SIGNALS_SRC		=	$(addprefix signals/, signals.c sighandler.c)

PROMPT_SRC		=	$(addprefix prompt/, prompt.c)

PARSER_SRC		=	$(addprefix parser/, parser.c interpreter.c cmd.c)

LEXER_SRC		=	$(addprefix lexer/, lexer.c lst_token.c create_token.c)

EXECUTOR_SRC	=	$(addprefix executor/, executor.c)

ENV_SRC			=	$(addprefix env/, environ.c)

MINISHELL_SRC	=	minishell.c

OBJ				=	$(BUILTIN_SRC:.c=.o) $(PROMPT_SRC:.c=.o) $(PARSER_SRC:.c=.o) \
					$(LEXER_SRC:.c=.o) $(EXECUTOR_SRC:.c=.o) $(MINISHELL_SRC:.c=.o) \
					$(UTILS_SRC:.c=.o) $(SIGNALS_SRC:.c=.o) $(ENV_SRC:.c=.o)

CC				=	cc

CFLAGS			=	-Wall -Werror -Wextra -g

RM				=	rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lreadline -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
