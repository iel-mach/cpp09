# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iel-mach <iel-mach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 15:04:47 by iel-mach          #+#    #+#              #
#    Updated: 2023/03/16 16:58:19 by iel-mach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp BitcoinExchange.cpp


all : $(NAME)

$(NAME) : $(SRC)
		@$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean : 
		@rm -f $(NAME)

fclean : clean

re : fclean all