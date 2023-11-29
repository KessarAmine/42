# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 21:42:51 by kmohamed          #+#    #+#              #
#    Updated: 2023/11/29 18:14:12 by kmohamed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC:= c++

NAME:= run

FLAGS+= -Wall -Werror -Wextra -std=c++98

SRC:=	RPN.cpp \
		main.cpp \

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