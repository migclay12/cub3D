# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 16:21:27 by ablanco-          #+#    #+#              #
#    Updated: 2024/05/15 16:21:30 by ablanco-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
FUNCTIONS =	pf_strlen.c			\
			pf_putchar_fd.c		\
			pf_putstr_fd.c		\
			pf_putnbr_fd.c		\
			ft_printf.c				\
			pf_putnbr_base.c		\

#DFUNCTIONS = $(addprefix $(DIR), ${FUNCTIONS})
OBJS = ${FUNCTIONS:.c=.o}

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

all: $(NAME)

clean:
			rm -f $(OBJS) 

fclean: clean
			rm -f $(NAME)

re: fclean all
