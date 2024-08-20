# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/22 09:08:29 by arissane          #+#    #+#              #
#    Updated: 2024/08/06 10:56:21 by arissane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT = ./libft/libft.a

MLX =  minilibx-linux/libmlx.a

SRCS = \
       main.c validate.c render.c actions.c free.c fractal_sets.c \
       colours.c

OFILES = $(SRCS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OFILES)
	@$(MAKE) -C ./libft
	@$(MAKE) -C ./minilibx-linux
	@$(CC) $(CFLAGS) $(OFILES) $(MLX) $(LIBFT) -lXext -lX11 -lm -o $(NAME)

clean:
	@$(MAKE) -C ./libft clean
	@$(MAKE) -C ./minilibx-linux clean
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME) ./libft/libft.a

re: fclean all

.PHONY: all clean fclean re
