# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 16:49:23 by wlin              #+#    #+#              #
#    Updated: 2023/11/22 22:42:09 by wlin             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

INCLUDES = push_swap.h

LIBFT = ./libft/libft.a

SRCS = ps_main.c move_swap.c move_rotate.c move_reverse_rotate.c \
		move_push.c ps_input_validate.c ps_stack_init.c ps_stack_sort.c utils.c\
		ps_split.c\

OBJS = $(SRCS:.c=.o)

COMPILER = gcc

CFLAGS = -Wall -Werror -Wextra

%.o: %.c Makefile $(INCLUDES)
	$(COMPILER) $(CFLAGS) -I $(INCLUDES) -c $< -o $(NAME)

$(NAME): lib $(LIBFT) $(OBJS) $(INCLUDES) Makefile
	$(COMPILER) $(CFLAGS) $(SRCS) -L./libft -lft -g -fsanitize=address -o $(NAME)

lib:
	$(MAKE) -C ./libft

all: lib $(NAME)

clean:
		rm -f $(OBJS)
		$(MAKE) -C ./libft fclean

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re
