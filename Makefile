# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yamarach < yamarach@student.42.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 14:22:35 by yamarach          #+#    #+#              #
#    Updated: 2023/03/11 13:33:33 by yamarach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	parsing.c parsing_utils.c get_next_line.c get_next_line_utils.c \
				ft_strlen.c ft_split.c flood.c window.c check.c \
				ft_free.c utils.c ft_putnbr.c ft_itoa.c so_long.c window_utils.c

OBJS		= $(SRCS:.c=.o)

CC		= cc
RM		= rm -rf

CFLAGS = -Wall -Wextra -Werror -g3 

NAME=	so_long

%.o: %.c
		$(CC) $(CFLAGS) -I /usr/include -Imlx_linux -O3 -c $< -o $@

LINUX		= -I /usr/include -L /usr/lib -L mlx_linux -I mlx_linux -lXext -l X11 -lm -lz

$(NAME): $(OBJS)
		# make -C $(PATH_MLX) all
		$(CC) $(CFLAGS) $(OBJS) libmlx_Linux.a $(LINUX) -o $(NAME)

all:		$(NAME)

clean:
		rm -rf $(OBJS)

fclean:		clean
		# make -C $(PATH_MLX) clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re bonus