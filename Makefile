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
CFLAGS := -Wall -Wextra -Werror -Iinclude -Ilibft/libft_0/include -Ilibft/Ft_printf/include

# Paths
SRC_DIR := srcs
MLX_DIR := MLX42
MLX_BUILD := $(MLX_DIR)/build

# Libft setup
LIBFT_REPO := https://github.com/Yuxin29/Mini_C_Library.git
LIBFT_DIR := libft
LIBFT_A := $(LIBFT_DIR)/libft_0/libft.a
PRINTF_A := $(LIBFT_DIR)/Ft_printf/libftprintf.a
GNL_A := $(LIBFT_DIR)/Get_next_line/get_next_line.a

# Final linked libs
LIBS := $(LIBFT_A) $(PRINTF_A) $(GNL_A)

# Sources
GNL_SRC := $(LIBFT_DIR)/Get_next_line/get_next_line.c $(LIBFT_DIR)/Get_next_line/get_next_line_utils.c
SRCS := \
	$(wildcard $(SRC_DIR)/*.c) \
	$(GNL_SRC)
OBJS := $(SRCS:.c=.o)

# Includes
CFLAGS += -I$(MLX_DIR)/include -Iinclude -Ilibft -I$(LIBFT_DIR)/Get_next_line

all: $(MLX_DIR) $(LIBS) $(NAME)

$(NAME): $(OBJS) $(LIBS) $(MLX_DIR)/build/libmlx42.a
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -L$(MLX_DIR)/build -lmlx42 -ldl -lglfw -pthread -lm -o $(NAME)

# Ensure objects wait for libs to be built
$(OBJS): | $(LIBS)

# Clone and make libft libs if needed
$(LIBS):
	if [ ! -d $(LIBFT_DIR) ]; then \
		echo "Cloning Mini_C_Library..."; \
		git clone $(LIBFT_REPO) $(LIBFT_DIR); \
	fi
	$(MAKE) -C $(LIBFT_DIR)

# Clone MLX42 if not exists
$(MLX_DIR):
	git clone https://github.com/codam-coding-college/MLX42.git $(MLX_DIR)

# Build MLX42
$(MLX_DIR)/build/libmlx42.a: | $(MLX_DIR)
	cmake -B $(MLX_BUILD) -S $(MLX_DIR)
	make -C $(MLX_BUILD) -j4

clean:
	rm -f $(OBJS)
	rm -f $(LIBFT_DIR)/Get_next_line/*.o
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(MLX_DIR)/build

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -rf $(MLX_DIR)
	rm -rf $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
