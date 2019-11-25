NAME = fdf

SRC =	main.c \
		ft_read_map.c \
		chack_map.c \
		give_mem.c \
		give_tot_mem.c \
		key_press.c \
		iso.c \
		paint_iso.c \
		line_put.c \
		convert_color.c
SRC_DIR = ./src/
OBJ_DIR = ./obj/
LIB_DIR = ./libft/
MLX_DIR = ./minilibx_macos/
LIB = $(LIB_DIR)libft.a
FLAGS = -Wall -Wextra -Werror

FLAGMLX = -lmlx -framework OpenGL -framework AppKit

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
		make -C $(LIB_DIR)
		make -C $(MLX_DIR)
		clang -g $(FLAGS) $(OBJ) $(LIB) $(FLAGMLX) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
		mkdir -p $(OBJ_DIR)
		clang -g $(FLAGS) -o $@ -c $<

clean:
		make -C $(LIB_DIR) clean
		make -C $(MLX_DIR) clean
		rm -rf $(OBJ_DIR)

fclean: clean
		make -C $(LIB_DIR) fclean
		rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
