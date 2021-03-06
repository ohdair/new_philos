# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/15 16:08:53 by jaewpark          #+#    #+#              #
#    Updated: 2022/04/15 16:10:40 by jaewpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
THREAD = -pthread

SRC_DIR = ./
OBJ_DIR = ./obj/
INC_DIR = ./

SRC_FILES = init.c \
			monitor.c \
			parsing.c \
			philo.c \
			print.c \
			routine.c \
			tools.c \
			utils.c \

OBJ_FILES = $(SRC_FILES:.c=.o)

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

# all rule
all : obj $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@gcc $(FLAGS) $(THREAD) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ)
	@clear
	@echo "\033[32m║▌│█║▌│ \033[0m\033[73m█║▌│█│║▌║▌│█║▌│█║▌│█│║▌║ \
	\n𝙨𝙘𝙖𝙣𝙣𝙞𝙣𝙜 𝙘𝙤𝙙𝙚..."
	@sleep 0.3
	@clear
	@echo "\033[32m║▌│█║▌│ █║▌│█│║▌\033[0m\033[73m║▌│█║▌│█║▌│█│║▌║ \
	\n𝙨𝙘𝙖𝙣𝙣𝙞𝙣𝙜 𝙘𝙤𝙙𝙚..."
	@sleep 0.3
	@clear
	@echo "\033[32m║▌│█║▌│ █║▌│█│║▌║▌│█║▌│█\033[0m\033[73m║▌│█│║▌║ \
	\n𝙨𝙘𝙖𝙣𝙣𝙞𝙣𝙜 𝙘𝙤𝙙𝙚..."
	@sleep 0.3
	@clear
	@echo "\033[32m║▌│█║▌│ █║▌│█│║▌║▌│█║▌│█║▌│█│║▌║\033[0m\033[73m \
	\n𝙨𝙘𝙖𝙣𝙣𝙞𝙣𝙜 𝙘𝙤𝙙𝙚..."
	@sleep 0.3
	@clear
	@echo "\033[32m║▌│█║▌│ █║▌│█│║▌║▌│█║▌│█║▌│█│║▌║ \033[0m\033[33m \
	\n𝙨𝙘𝙖𝙣𝙣𝙞𝙣𝙜 𝙘𝙤𝙙𝙚..."
	@sleep 0.3
	@clear
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ)
	@echo "═════════•°• $(NAME) generated •°•═════════"
	@clear
	@echo
	@echo "\033[01;31m⎹⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴\
	⎴⎴⎴⎴⎴⎴⎴⎴⎴⎸"
	@echo "\033[01;31m⎹ \033[0m\033[07;37m    Subject Name              \
	 \033[0m\033[01;31m ⎸"
	@echo "\033[01;31m⎹ \033[0m\033[01;32m    Philosophers              \
	 \033[0m\033[01;31m ⎸"
	@echo "\033[01;31m⎹⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵\
	⎵⎵⎵⎵⎵⎵⎵⎵⎵⎸"

# clean rule
clean:
	@rm -Rf $(OBJ_DIR)
	@echo "═════════•°• Objects removed •°•═════════"

# fclean rule
fclean: clean
	@rm -f $(NAME)
	@echo "═════════•°• $(NAME) removed •°•═════════"

# re rule
re: fclean all

# phony
.PHONY: all clean fclean re
