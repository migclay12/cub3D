NAME = cub3D
SRC_DIRS = src
INC_DIR = src/includes

NAME_BONUS = cub3D_bonus
SRC_DIRS_BONUS = bonus
INC_DIR_BONUS = bonus/includes

SRCS =	src/coordenadas.c \
		src/coordenadas_utils.c \
		src/draw_ray.c \
		src/errors.c \
		src/free.c \
		src/hooks.c \
		src/hooks_utils.c \
		src/init_graphics.c \
		src/init_player.c \
		src/load_immages.c \
		src/main.c \
		src/map_check.c \
		src/map_check_utils.c \
		src/raycasting.c \
		src/ray_utils.c \
		src/rgb.c \
		src/rgb_utils.c \
		src/utils.c \
		src/val_path.c


SRCS_BONUS =	bonus/coordenadas.c \
				bonus/coordenadas_utils.c \
				bonus/draw_ray.c \
				bonus/errors.c \
				bonus/free.c \
				bonus/hooks.c \
				bonus/hooks_utils.c \
				bonus/init_graphics.c \
				bonus/init_player.c \
				bonus/load_immages.c \
				bonus/main.c \
				bonus/map_check.c \
				bonus/map_check_utils.c \
				bonus/minimap.c \
				bonus/minimap_utils.c \
				bonus/raycasting.c \
				bonus/ray_utils.c \
				bonus/rgb.c \
				bonus/rgb_utils.c \
				bonus/utils.c \
				bonus/val_path.c \

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

FLAGS = -Wall -Wextra -Werror -O3 -g3
FLAGS += -I includes
FLAGS_MLX =  -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

MLX_PATH	= minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

LIB = libft

all: $(NAME)

$(NAME): $(OBJS) | $(LIB)/libft.a
	@gcc $(FLAGS) $^ -o $@ -L $(LIB) -lft $(MLX) $(FLAGS_MLX)
	@echo "✅ cub3D compiled successfully!"

help:
	@echo "Available targets:"
	@echo "  all      - Build the main cub3D executable"
	@echo "  bonus    - Build the bonus version with minimap"
	@echo "  clean    - Remove object files"
	@echo "  fclean   - Remove all generated files"
	@echo "  re       - Rebuild everything"
	@echo "  help     - Show this help message"

$(LIB)/libft.a:
	@make -C $(LIB) > /dev/null
	@echo "Libft compiled!"

$(MLX)/libmlx.a:
	@make -C $(MLX) > /dev/null
	@echo "MLX compiled!"

%.o: %.c
	@echo "Compiling $<..."
	@gcc $(FLAGS) $(FLAGS_MLX) -c $< -o $@ -I includes

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) | $(LIB)/libft.a
	@gcc $(FLAGS) $^ -o $@ -L $(LIB) -lft $(MLX) $(FLAGS_MLX)
	@echo "✅ cub3D bonus compiled successfully!"

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS) $(DEPS)
	@echo "cub3D cleaned!"
	@make -C $(LIB) clean > /dev/null
	@echo "Libft cleaned!"

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS) 
	@make -C $(LIB) fclean > /dev/null

re: fclean all

.PHONY: all clean fclean re