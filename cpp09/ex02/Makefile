# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iel-mach <iel-mach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/25 01:01:21 by iel-mach          #+#    #+#              #
#    Updated: 2023/03/25 01:03:13 by iel-mach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp PmergeMe.cpp


all : $(NAME)

$(NAME) : $(SRC)
		@$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean : 
		@rm -f $(NAME)

fclean : clean

re : fclean all