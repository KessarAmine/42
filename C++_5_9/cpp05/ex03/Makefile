# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/04 14:58:39 by kmohamed          #+#    #+#              #
#    Updated: 2023/11/26 14:20:21 by kmohamed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:= c++

NAME:= run

FLAGS+= -Wall -Werror -Wextra -std=c++98

SRC:=	Bureaucrat.cpp \
		Form.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp \
		Intern.cpp \
		main.cpp

OBJECTS:=  $(SRC:.cpp=.o)

$(NAME): $(OBJECTS)
	@$(CC) $(OBJECTS) $(FLAGS) -o $(NAME) 

all: $(NAME)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)
	@rm -f *_shrubbery

re: fclean
	@make all

.PHONY: clean fclean re
