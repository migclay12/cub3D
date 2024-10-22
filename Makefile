NAME = cub3d
SRC_DIRS = .
INC_DIR = includes

SRCS = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra #-Werror -o3 #-g3  -fsanitize=address,leak
FLAGS += -I includes
FLAGS_MLX =  -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
#FLAGS_MLX = -Iinclude -ldl -lglfw -pthread -lm


MLX_PATH	= minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

#MLX_PATH	= MLX42/build/
#MLX_NAME	= libmlx42.a
#MLX			= $(MLX_PATH)$(MLX_NAME)

LIB = libft

all: $(NAME)

$(NAME): $(OBJS) | $(LIB)/libft.a
	@gcc $(FLAGS) $^ -o $@ -L $(LIB) -lft $(MLX) $(FLAGS_MLX)
	@echo "cub3D compiled!"

$(LIB)/libft.a:
	@make -C $(LIB) > /dev/null
	@echo "Libft compiled!"

#$(MLX):
#	make -sC $(MLX_PATH)

$(MLX)/libmlx.a:
	@make -C $(MLX) > /dev/null
	@echo "MLX compiled!"

%.o: %.c
	@echo "Compiling $<..."
	@gcc $(FLAGS) $(FLAGS_MLX) -c $< -o $@ -I includes

#ive modified a bit the subject map
exe: all
	@./$(NAME) maps/good/sad_face.cub
#	@./$(NAME) maps/good/subject_map.cub
#	@./$(NAME) maps/bad/color_invalid_rgb.cub
#	@./$(NAME) maps/bad/color_missing_ceiling_rgb.cub
#	@./$(NAME) maps/bad/color_missing_floor_rgb.cub
#	@./$(NAME) maps/bad/color_missing.cub
#	@./$(NAME) maps/bad/color_none.cub
#	@./$(NAME) maps/bad/empty.cub
#	@./$(NAME) maps/bad/file_letter_end.cub
#	@./$(NAME) maps/bad/filetype_missing
#	@./$(NAME) maps/bad/filetype_wrong.buc
#	@./$(NAME) maps/bad/forbidden.cub
#	@./$(NAME) maps/bad/map_first.cub
#	@./$(NAME) maps/bad/map_middle.cub
#	@./$(NAME) maps/bad/map_missing.cub
#	@./$(NAME) maps/bad/map_only.cub
#	@./$(NAME) maps/bad/map_too_small.cub
#	@./$(NAME) maps/bad/player_multiple.cub
#	@./$(NAME) maps/bad/player_none.cub
#	@./$(NAME) maps/bad/player_on_edge.cub
#	@./$(NAME) maps/bad/textures_dir.cub
#	@./$(NAME) maps/bad/textures_duplicates.cub
#	@./$(NAME) maps/bad/textures_forbidden.cub
#	@./$(NAME) maps/bad/textures_invalid.cub
#	@./$(NAME) maps/bad/textures_missing.cub
#	@./$(NAME) maps/bad/textures_none.cub
#	@./$(NAME) maps/bad/textures_not_xpm.cub
#	@./$(NAME) maps/bad/wall_hole_east.cub
#	@./$(NAME) maps/bad/wall_hole_north.cub
#	@./$(NAME) maps/bad/wall_hole_south.cub
#	@./$(NAME) maps/bad/wall_hole_west.cub
#	@./$(NAME) maps/bad/wall_none.cub


#	@./$(NAME) maps/good/subject_map.cub
#	@./$(NAME) maps/good/cheese_maze.cub
#	@./$(NAME) maps/map0.cub

leaks: all
	valgrind --leak-check=full --track-origins=yes ./$(NAME) maps/good/subject_map.cub

#--track-origins=yes
#--show-leak-kinds=all

clean:
	@$(RM) $(OBJS) $(DEPS)
	@echo "cub3D cleaned!"
	@make -C $(LIB) clean > /dev/null
	@echo "Libft cleaned!"

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIB) fclean > /dev/null

re: fclean all

.PHONY: all clean fclean re