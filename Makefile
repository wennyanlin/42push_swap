NAME = push_swap

CC := gcc
CFLAGS := -Wall -Wextra -Werror -MMD -g
EXTRAFLAGS = -Iinclude -I$(SRC_DIR)/libft -I$(SRC_DIR)/ft_printf
LDFLAGS = -L$(SRC_DIR)/ft_printf
LDLIBS := -framework OpenGL -framework AppKit -lftprintf -fsanitize=address
SRC_DIR		:=	src

SRC_FILES	:=	$(SRC_DIR)/ps_main.c \
				$(SRC_DIR)/move_swap.c \
				$(SRC_DIR)/move_rotate.c \
				$(SRC_DIR)/move_reverse_rotate.c \
				$(SRC_DIR)/move_push.c \
				$(SRC_DIR)/ps_input_validate.c \
				$(SRC_DIR)/ps_stack_init.c \
				$(SRC_DIR)/ps_stack_sort.c \
				$(SRC_DIR)/utils.c \
				$(SRC_DIR)/ft_atoi.c \
				$(SRC_DIR)/ps_split.c

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

MLX:
	make -C $(SRC_DIR)/libft --no-print-directory

FT_PRINTF:
	make -C $(SRC_DIR)/ft_printf --no-print-directory

#-g -fsanitize=address
#leaks --atExit -- ./so_long maps/map1.ber
#mlx/libmlx.a -E
