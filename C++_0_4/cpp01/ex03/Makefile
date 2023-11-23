# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/08 16:20:06 by kmohamed          #+#    #+#              #
#    Updated: 2023/07/08 20:53:32 by kmohamed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:= c++

NAME:= war

FLAGS+= -Wall -Werror -Wextra -std=c++98

SRC:=	main.cpp \
		HumanA.cpp \
		HumanB.cpp \
		Weapon.cpp \

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