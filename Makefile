# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 11:50:00 by gromero-          #+#    #+#              #
#    Updated: 2023/01/09 12:51:30 by gromero-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	source/push_swap.c	source/ft_check_error.c source/ft_swap.c \
				source/ft_push.c source/ft_rotate.c source/ft_reverse.c \
				source/ft_order_selection.c source/ft_utils.c source/ft_lis.c \
				source/ft_moves.c source/ft_utils_2.c

OBJ_SRC		=	 $(SRC:.c = .o)

INC			=	./libft

LIB			=	libft.a

EXEC		=	push_swap

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

all:		$(EXEC)

$(NAME):	all

$(LIB):
	make -C $(INC)

$(EXEC):	$(LIB)	$(OBJ_SRC)
	$(CC)	$(CFLAGS)	$(OBJ_SRC)	-o	$(EXEC)	$(INC)/$(LIB)

clean:
	rm -f $(EXEC)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re:	fclean all

.PHONY: all clean fclean re
