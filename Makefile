NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -Iincludes -Ilibft -Iincludes/minilibx-linux

SRC =	src/main.c \
		src/parsing/parse_file.c \
		src/parsing/parse_identifier.c \
		src/parsing/parse_texture.c \
		src/parsing/parse_color.c \
		src/parsing/parse_map.c \
		src/parsing/parser_utils.c \
		src/parsing/validate_map.c \
		src/parsing/free_config.c \
		src/parsing/validate_texture.c \
		src/parsing/validate_file_bytes.c \
		src/init/init_game.c \
		src/init/init_player.c \
		src/input/key_press.c \
		src/input/key_release.c \
		src/input/move_player.c \
		src/input/rotate_player.c \
		src/rendering/put_pixel.c \
		src/rendering/raycasting.c \
		src/rendering/draw_wall.c \
		src/texture/get_texture.c \
		src/texture/load_texture.c \
		src/cleanup/close_game.c

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

MLX_DIR = includes/minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(MLX):
	$(MAKE) -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C libft clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re