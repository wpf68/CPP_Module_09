# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pwolff <pwolff@student.42mulhouse.fr>>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 13:36:06 by pwolff            #+#    #+#              #
#    Updated: 2023/01/31 13:36:06 by pwolff           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	btc

SRCS		= 	main.cpp BitcoinExchange.cpp
				
OBJS				= $(SRCS:.cpp=.o)
OBJS_DIR			= objs/
OBJECTS_PREFIXED 	= $(addprefix $(OBJS_DIR), $(OBJS))

CC		= c++
#CC		= clang++
FLAGS	= -Wall -Wextra -Werror -std=c++98

RED		=	\033[1;31m
YELLOW	=	\033[1;33m
RESET	=	\033[0m
CLEAR	=	\x1B[2J\x1B[H
NONE	=	\033[0;37m
WHITE	=	\033[1;37m
RED		=	\033[1;31m
GREEN	=	\033[1;32m
CYANE	=	\033[1;36m
ORANGE	=	\033[1,38m
YELLOW	=	\033[1;33m
BLUE	=	\033[1,34m
GREY	=	\033[1,37m
ROSE	=	\033[1,35m

all: present $(NAME)
	@echo "$(CYANE)----------done------------$(RESET)"

present:
	clear

$(OBJS_DIR)%.o : %.cpp
	@mkdir -p $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@
#	@printf	"\033[2K\r${BLU}[BUILD]${RST} '$<' $(END)"
#	@mkdir -p $(OBJS_DIR)srcsi

$(NAME): $(SRCS) $(OBJECTS_PREFIXED)
	@$(CC) -o $(NAME) $(OBJECTS_PREFIXED) $(FLAGS)

clean:
	rm -rf $(OBJS_DIR)
	@echo "$(GREEN)Cleaned$(RESET)"

fclean: clean
	rm -rf $(NAME)

re: fclean all

test:	all
	./${NAME}

linux:	all
	valgrind ./${NAME}

.PHONY:		all clean fclean re test present linux