# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/03 16:02:31 by kmohamed          #+#    #+#              #
#    Updated: 2023/08/04 14:41:34 by kmohamed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:= c++

NAME:= ex02

FLAGS+= -Wall -Werror -Wextra -std=c++98

SRC:=	main.cpp \
		Fixed.cpp \

OBJECTS:=  $(SRC:.cpp=.o)

$(NAME): $(OBJECTS)
	@$(CC) $(OBJECTS) $(FLAGS) -o $(NAME)

all: $(NAME)

clean:
	@rm -f $(OBJECTS)
	@clear

fclean: clean
	@rm -f $(NAME)

re: fclean
	@make all

.PHONY: clean fclean re