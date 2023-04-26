# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 19:18:55 by mecauchy          #+#    #+#              #
#    Updated: 2023/04/26 15:55:17 by mecauchy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES			=	main.c singleton.c parsing.c free.c

SRC_DIR			=	srcs

DIR_OBJ			=	.objs

LIBFT_DIR		=	libft

SRCS 			=	$(addprefix $(SRC_DIR)/, $(FILES))

OBJS 			=	$(addprefix $(DIR_OBJ)/, $(FILES:.c=.o))

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror -fsanitize=address -g3

NAME 			=	so_long

HEADER			=	include/so_long.h

#LIBS			=	-lmlx -framework OpenGL -framework AppKit
LIBS			=  -lX11 -lXext -lbsd

all				:	MK_LIBFT $(NAME)

$(NAME)			:	$(OBJS)
					$(CC) $(OBJS) $(CFLAGS) $(LIBS) $(LIBFT_DIR)/libft.a mlx/libmlx_Linux.a -o $(NAME)

$(DIR_OBJ)/%.o	:	$(SRC_DIR)/%.c $(HEADER)
					mkdir -p $(@D)
					$(CC) $(CFLAGS) -Imlx -c $< -o $@

MK_LIBFT		:	
					make -j -C $(LIBFT_DIR)
					make -j -C $(LIBFT_DIR) bonus
					
clean			:
					rm -rf $(DIR_OBJ)
					make clean -C $(LIBFT_DIR)
					
fclean			:	clean
					rm -rf $(NAME)
					make fclean -C $(LIBFT_DIR)

re				:	fclean all

.PHONY			:	all clean fclean re
