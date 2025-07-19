# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/03 16:36:29 by yuwu              #+#    #+#              #
#    Updated: 2025/07/13 13:13:25 by yuwu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH := ./libft/
LIBFT := $(LIBFT_PATH)libft.a

GNL_DIR = libft/get_next_line
GNL_SRC = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c

MLX_DIR := MLX42
MLX_INCLUDE := -I$(MLX_DIR)/include
MLX_LIB := -L$(MLX_DIR)/build -lmlx42 -ldl -lglfw -pthread -lm

NAME := so_long
CFLAGS := -Wall -Wextra -Werror $(MLX_INCLUDE) -Iinclude -Ilibft -Ilibft/get_next_line
CC := cc

SRC_DIR := srcs
SRCS := $(SRC_DIR)/init_map.c \
        $(SRC_DIR)/mapcheck.c \
        $(SRC_DIR)/accessibility_check.c \
        $(SRC_DIR)/init_mlx.c \
        $(SRC_DIR)/play_move.c \
        $(SRC_DIR)/utils.c \
        $(SRC_DIR)/main.c \
        $(GNL_SRC)
OBJS := $(SRCS:.c=.o)

$(MLX42_DIR):
	git clone https://github.com/codam-coding-college/MLX42.git $@;

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(MLX_INCLUDE) $(OBJS) $(LIBFT) $(MLX_LIB) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

all: $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re	
