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

NAME := so_long
CC := cc
CFLAGS := -Wall -Wextra -Werror

# Paths
SRC_DIR := srcs
LIBFT_PATH := ./libft/
GNL_DIR := libft/get_next_line
MLX_DIR := MLX42
MLX_BUILD := $(MLX_DIR)/build

# Includes & Libs
MLX_INCLUDE := -I$(MLX_DIR)/include
MLX_LIB_FILE := $(MLX_BUILD)/libmlx42.a
MLX_LIBS := -L$(MLX_BUILD) -lmlx42 -ldl -lglfw -pthread -lm
LIBFT := $(LIBFT_PATH)libft.a

# Sources
GNL_SRC := $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
SRCS := \
	$(SRC_DIR)/init_map.c \
	$(SRC_DIR)/mapcheck.c \
	$(SRC_DIR)/accessibility_check.c \
	$(SRC_DIR)/init_mlx.c \
	$(SRC_DIR)/play_move.c \
	$(SRC_DIR)/utils.c \
	$(SRC_DIR)/main.c \
	$(GNL_SRC)
OBJS := $(SRCS:.c=.o)

# Includes
CFLAGS += $(MLX_INCLUDE) -Iinclude -Ilibft -I$(GNL_DIR)

# Default rule
all: $(MLX_LIB_FILE) $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX_LIB_FILE)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_LIBS) -o $(NAME)

# Build libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

# Clone MLX42 if not present
$(MLX_DIR):
	git clone https://github.com/codam-coding-college/MLX42.git $(MLX_DIR)

# Build MLX42
$(MLX_LIB_FILE): | $(MLX_DIR)
	cmake -B $(MLX_BUILD) -S $(MLX_DIR)
	make -C $(MLX_BUILD) -j4

# Clean object files
clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_PATH)

# Clean everything
fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_PATH)

# Rebuild all
re: fclean all

.PHONY: all clean fclean re

