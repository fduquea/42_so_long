# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 17:49:20 by fduque-a          #+#    #+#              #
#    Updated: 2023/05/29 10:37:58 by fduque-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

NAME = libft.a
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
HDR = -I include
SRC_DIR = srcs
OBJ_DIR = objs
SUBDIRS = ctype extra lst math stdlib string strings printf gnl

SRCS_DIRS	= $(foreach dir, $(SUBDIRS), $(addprefix $(SRC_DIR)/, $(dir)))
OBJS_DIRS	= $(foreach dir, $(SUBDIRS), $(addprefix $(OBJ_DIR)/, $(dir)))
SRCS	= $(foreach dir, $(SRCS_DIRS), $(wildcard $(dir)/*.c))
OBJS	= $(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o))

# pattern rule that specifies how to create an object file using a source file
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c 
	@ mkdir -p $(OBJ_DIR) $(OBJS_DIRS)
	@ echo "$(YELLOW)Turning $< into $@$(DEF_COLOR)"
	@ cc ${CFLAGS} ${HDR} -c $< -o $@
	@ echo "$(GREEN)Compiled $< with sucess$(DEF_COLOR)"

$(NAME) : ${OBJS}
	@ ar rcs ${NAME} $(OBJS)
	@ echo "$(GRAY)*----------------------------------*$(DEF_COLOR)"
	@ echo "$(GRAY)| $(BLUE)! Compiled libft.a with sucess ! $(GRAY)|$(DEF_COLOR)"
	@ echo "$(GRAY)*----------------------------------*$(DEF_COLOR)"

all : ${NAME}

clean :
	@ $(RM) -rf $(OBJ_DIR)
	@ echo "$(GRAY)*--------------------------------*$(DEF_COLOR)"
	@ echo "$(GRAY)| $(RED)Removed X libft object files X $(GRAY)|$(DEF_COLOR)"
	@ echo "$(GRAY)*--------------------------------*$(DEF_COLOR)"

fclean : clean
	@ ${RM} ${NAME}
	@ echo "$(GRAY)*-----------------------------------*$(DEF_COLOR)"
	@ echo "$(GRAY)| $(RED)Removed X 'libft.a' X with sucess $(GRAY)|$(DEF_COLOR)"
	@ echo "$(GRAY)*-----------------------------------*$(DEF_COLOR)"

re : fclean all
	@ echo "$(GRAY)*--------------------------------------------------*$(DEF_COLOR)"
	@ echo "$(GRAY)| $(RED)X Cleaned X $(YELLOW)and $(GREEN)! Rebuilt ! $(YELLOW)everything for LIBFT $(GRAY)|$(DEF_COLOR)"
	@ echo "$(GRAY)*--------------------------------------------------*$(DEF_COLOR)"
	
.PHONY : all clean fclean re bonus
