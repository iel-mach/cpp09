# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iel-mach <iel-mach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 03:34:38 by iel-mach          #+#    #+#              #
#    Updated: 2023/03/23 03:39:49 by iel-mach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

CC = c++

FLAGS =  -Wall -Wextra -Werror #-fsanitize=address

SRC = main.cpp RPN.cpp


all : $(NAME)

$(NAME) : $(SRC)
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean :
	@rm -f $(NAME)

fclean : clean

re : fclean all