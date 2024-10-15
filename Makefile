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

exe: all
	@./$(NAME) maps/map0.cub

leaks: all
	valgrind --leak-check=full --track-origins=yes ./$(NAME) maps/map0.cub

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