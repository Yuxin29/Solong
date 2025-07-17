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
CFLAGS := -Wall -Wextra -Werror -g $(MLX_INCLUDE)
CC := cc

SRCS := parsing.c mapcheck.c accessibility_check.c init_mlx.c play_move.c error.c main.c $(GNL_SRC)
OBJS := $(SRCS:%.c=%.o)

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
