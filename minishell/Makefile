NAME			=	minishell

BUILTIN_SRC		=	$(addprefix built-in/, pwd.c)

PROMPT_SRC		=	$(addprefix prompt/, prompt.c)

PARSER_SRC		=	$(addprefix parser/, parser.c)

LEXER_SRC		=	$(addprefix lexer/, lexer.c)

EXECUTOR_SRC	=	$(addprefix executor/, executor.c)

MINISHELL_SRC	=	minishell.c

OBJ				=	$(BUILTIN_SRC:.c=.o) $(PROMPT_SRC:.c=.o) $(PARSER_SRC:.c=.o) \
					$(LEXER_SRC:.c=.o) $(EXECUTOR_SRC:.c=.o) $(MINISHELL_SRC:.c=.o)

LIBFT_PATH		=	libft

CC				=	cc

CFLAGS			=	-Wall -Werror -Wextra

RM				=	rm -f

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_PATH)/libft.a
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_PATH)/libft.a -lreadline -o $(NAME)

$(LIBFT_PATH)/libft.a:
	make -C $(LIBFT_PATH)

clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(LIBFT_PATH)/libft.a

re: fclean all

.PHONY: all clean fclean re
