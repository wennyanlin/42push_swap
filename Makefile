NAME = push_swap

CC := gcc
CFLAGS := -Wall -Wextra -Werror -MMD -g
EXTRAFLAGS = -Iinclude -I$(SRC_DIR)/ft_printf
LDFLAGS = -L$(SRC_DIR)/ft_printf
LDLIBS := -lftprintf #-fsanitize=address
SRC_DIR		:=	src

SRC_FILES	:=	$(SRC_DIR)/push_swap.c \
				$(SRC_DIR)/move_swap.c \
				$(SRC_DIR)/move_rotate.c \
				$(SRC_DIR)/move_reverse_rotate.c \
				$(SRC_DIR)/move_push.c \
				$(SRC_DIR)/input_validate.c \
				$(SRC_DIR)/find_move.c \
				$(SRC_DIR)/stack_init.c \
				$(SRC_DIR)/stack_sort.c \
				$(SRC_DIR)/stack_move.c \
				$(SRC_DIR)/utils_array.c \
				$(SRC_DIR)/utils_stack.c \
				$(SRC_DIR)/ft_atoi.c \
				$(SRC_DIR)/ft_split.c

OBJ_FILES	=	$(SRC_FILES:.c=.o)
DEP_FILES	=	$(SRC_FILES:.c=.d)

# Regla/metodo implicito
%.o:%.c 	src/push_swap.h Makefile
			$(CC) $(CFLAGS) -c $< -o $@

# Mis reglas mis metodos
all: FT_PRINTF $(NAME)

-include $(DEP_FILES)
$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(EXTRAFLAGS) $(LDFLAGS) $(LDLIBS) $(OBJ_FILES) -o $@

clean:
		rm -f $(OBJ_FILES) $(DEP_FILES)
		make -C $(SRC_DIR)/ft_printf fclean

fclean:	clean
		rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re FT_PRINTF

FT_PRINTF:
	make -C $(SRC_DIR)/ft_printf --no-print-directory
