# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 19:52:32 by fduque-a          #+#    #+#              #
#    Updated: 2023/08/10 00:51:40 by fduque-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

NAME = so_long

SRCS = srcs/clean_and_exit.c srcs/file_check.c srcs/game_action.c srcs/game_start.c srcs/main.c srcs/map_check.c srcs/map_read.c srcs/map_utils.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I include
LIBFT_PATH = lib/libft_curr
LIBFT = -L ${LIBFT_PATH} -lft
MLX_PATH = lib/mlx
MLX = -L ${MLX_PATH} -lmlx -Ilmlx -lXext -lX11 -lm 

%.o : %.c 
	@ echo "$(YELLOW)Turning $< into $@$(DEF_COLOR)"
	@ cc ${CFLAGS} ${INCLUDE} -c $< -o $@
	@ echo "$(GREEN)Compiled $< with sucess$(DEF_COLOR)"

$(NAME): ${OBJS}
	@ make -C ${LIBFT_PATH}
	@ make -C ${MLX_PATH}
	@ cc ${OBJS} ${LIBFT} ${MLX} -o ${NAME}
	@ echo "$(GRAY)*------------------------------------------*$(DEF_COLOR)"
	@ echo "$(GRAY)| $(BLUE)! Compiled so_long program with sucess ! $(GRAY)|$(DEF_COLOR)"
	@ echo "$(GRAY)*------------------------------------------*$(DEF_COLOR)"

all: ${NAME}

clean:
	@ make -C ${LIBFT_PATH} clean
	@ make -C ${MLX_PATH} clean
	@ rm -f ${OBJS}
	@ echo "$(GRAY)*----------------------------------*$(DEF_COLOR)"
	@ echo "$(GRAY)| $(RED)Removed X so_long object files X $(GRAY)|$(DEF_COLOR)"
	@ echo "$(GRAY)*----------------------------------*$(DEF_COLOR)"

fclean: clean
	@ make -C ${LIBFT_PATH} fclean
	@ rm -f ${NAME}
	@ echo "$(GRAY)*-------------------------------------------*$(DEF_COLOR)"
	@ echo "$(GRAY)| $(RED)Removed X 'so_long' program X with sucess $(GRAY)|$(DEF_COLOR)"
	@ echo "$(GRAY)*-------------------------------------------*$(DEF_COLOR)"

re: fclean all
	@ echo "$(GRAY)*----------------------------------------------------*$(DEF_COLOR)"
	@ echo "$(GRAY)| $(RED)X Cleaned X $(YELLOW)and $(GREEN)! Rebuilt ! $(YELLOW)everything for so_long $(GRAY)|$(DEF_COLOR)"
	@ echo "$(GRAY)*----------------------------------------------------*$(DEF_COLOR)"

check_leaks:
	@ for map in ../so_long_invalidator/maps/*/*; do \
		echo "$(YELLOW)Checking for leaks in $$map$(DEF_COLOR)"; \
		if valgrind --leak-check=full --show-leak-kinds=all ./so_long $$map 2>&1 | grep -q "no leaks are possible"; then \
			echo "$(GREEN)No leaks found in $$map$(DEF_COLOR)"; \
		else \
			echo "$(RED)Leaks found in $$map$(DEF_COLOR)"; \
		fi \
	done

.PHONY: all clean fclean re 