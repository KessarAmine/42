# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 15:03:18 by kmohamed          #+#    #+#              #
#    Updated: 2023/03/04 13:05:38 by kmohamed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
CC= gcc
CFLAGS= -Wall -Wextra -Werror
SRCS= ft_printf.c \
	get_conversion.c \
	print_numbers.c \
	printf_characters.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -r $(NAME) $(OBJS)
	
%.o: %.c
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJS) 
fclean: clean
	rm -f $(NAME)
re: fclean all 