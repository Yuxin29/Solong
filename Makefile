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
CFLAGS := -Wall -Wextra -Werror -g
CC := cc

SRCS := xxx.c xxx.c xxx.c
OBJS := $(SRCS:%.c=%.o)

LIBFT_PATH := ./get_next_line/
LIBFT := $(LIBFT_PATH)libft.a

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

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
