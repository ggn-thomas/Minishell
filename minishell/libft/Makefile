# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thomas <thomas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 14:16:03 by thgaugai          #+#    #+#              #
#    Updated: 2024/10/17 16:44:24 by thomas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS =  ft_atoi.c\
        ft_isalnum.c\
        ft_isalpha.c\
        ft_isascii.c\
        ft_isdigit.c\
        ft_isprint.c\
        ft_strlcat.c\
        ft_strlen.c\
        ft_toupper.c\
        ft_tolower.c\
        ft_strchr.c\
        ft_strdup.c\
        ft_strlcpy.c\
        ft_memcmp.c\
        ft_strncmp.c\
        ft_memset.c\
        ft_memchr.c\
        ft_strrchr.c\
        ft_calloc.c\
        ft_bzero.c\
        ft_memcpy.c\
        ft_memmove.c\
        ft_strnstr.c\
        ft_substr.c\
        ft_strjoin.c\
        ft_strtrim.c\
        ft_itoa.c\
        ft_strmapi.c\
        ft_striteri.c\
        ft_putchar_fd.c\
        ft_putstr_fd.c\
        ft_putendl_fd.c\
        ft_putnbr_fd.c\
        ft_split.c\

SRCS_BONUS =    ft_lstnew_bonus.c\
                ft_lstadd_front_bonus.c\
                ft_lstsize_bonus.c\
                ft_lstlast_bonus.c\
                ft_lstadd_back_bonus.c\
                ft_lstdelone_bonus.c\
                ft_lstclear_bonus.c\
                ft_lstiter_bonus.c\
                ft_lstmap_bonus.c\

OBJS := $(SRCS:.c=.o)
OBJS_BONUS := $(SRCS_BONUS:.c=.o)

CC := cc 
FLAGS := -Wall -Werror -Wextra

NAME := libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

bonus : $(OBJS_BONUS)
	ar -rc $(NAME) $(OBJS_BONUS)

%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all