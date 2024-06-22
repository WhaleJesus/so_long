# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/18 22:19:15 by sklaps            #+#    #+#              #
#    Updated: 2024/06/22 16:16:48 by sklaps           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = mlx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz
SRC = \
	  src/so_long.c \
	  src/draw.c \
	  src/draw_map.c \
	  src/draw_map2.c \
	  src/error.c \
	  src/move.c \
	  src/close.c \
	  src/init_game.c \
	  src/init_check_map.c \
	  src/init_check_map2.c \
	  src/flood.c \
	  src/flood2.c
EXT_LIB = libft/libft.a
OBJ = $(SRC:.c=.o)
NAME = so_long

all: $(NAME)

$(NAME): $(OBJ)
	cd libft && make all clean && cd ../ && $(CC) $(OBJ) $(EXT_LIB) -Lmlx_linux -g -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -g -O3 -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
