# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anoury <anoury@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 16:50:45 by anoury            #+#    #+#              #
#    Updated: 2023/07/19 16:50:48 by anoury           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_memset.c ft_split.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_memccpy.c ft_putchar.c ft_putstr.c ft_realloc.c ft_strcat.c ft_strchr_freq.c ft_strisdigit.c ft_strncat.c ft_strcmp.c ft_strcpy.c ft_strncpy.c get_next_line.c reverse_arr.c

OBJS = ${SRCS:.c=.o}


NAME = libft.a

INCS = libft.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra -c

RM = rm -f

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME} :   ${OBJS}
	ar rc ${NAME} ${OBJS}

all : ${NAME}

clean :
	${RM} ${OBJS}
	
fclean :    clean
	${RM} ${NAME}

bonus: ${OBJS}
	ar rc ${NAME} ${OBJS}

re : fclean all

.PHONY : all .c.o clean fclean re bonus
