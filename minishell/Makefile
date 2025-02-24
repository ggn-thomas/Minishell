SRCS = 	main.c\
		./parsing/ft_split_operator.c\
		./parsing/tokenisation.c\
		./parsing/utils_parsing.c\
		./parsing/check_operator_glued.c\
		./parsing/check_syntax.c\
		./parsing/signal_handler.c\
		free.c\
		utils.c\

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
LDFLAGS = -lreadline
LIBFT = libft/libft.a

NAME = minishell

all : $(LIBFT) $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(LDFLAGS)
	@echo "\033[1;32mMINISHELL compiled successfully!\033[0m"

$(LIBFT):
	@make -C libft

clean:
	rm -f $(OBJS)
	@make -C libft clean

fclean:
	rm -f $(OBJS)
	rm -f $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re