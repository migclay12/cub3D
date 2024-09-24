NAME = cub3d
SRC_DIRS = .
INC_DIR = includes

SRCS = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror #-g3  -fsanitize=address,leak
FLAGS += -I includes

LIB = libft

.PHONY: all clean fclean re

all: $(NAME)
$(NAME): $(OBJS) | $(LIB)/libft.a
	@gcc $(FLAGS) $^ -o $@ -L $(LIB) -lft
	@echo "cube3D compiled!"

$(LIB)/libft.a:
	@make -C $(LIB) > /dev/null
	@echo "Libft compiled!"

%.o: %.c
	@echo "Compiling $<..."
	@gcc $(FLAGS) -c $< -o $@ -I includes

exe: all
	@./$(NAME)

clean:
	@$(RM) $(OBJS) $(DEPS)
	@echo "cube3D cleaned!"
	@make -C $(LIB) clean > /dev/null
	@echo "Libft cleaned!"

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIB) fclean > /dev/null

re: fclean all