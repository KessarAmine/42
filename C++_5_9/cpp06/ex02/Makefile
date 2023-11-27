# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 01:32:50 by kmohamed          #+#    #+#              #
#    Updated: 2023/11/27 01:32:55 by kmohamed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:= c++

NAME:= run

FLAGS+= -Wall -Werror -Wextra -std=c++98

SRC:=	Base.cpp \
		main.cpp

OBJECTS:=  $(SRC:.cpp=.o)

$(NAME): $(OBJECTS)
	@$(CC) $(OBJECTS) $(FLAGS) -o $(NAME) 

all: $(NAME)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean
	@make all

.PHONY: clean fclean re