NAME = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror

SOURCES  = 	DSA.c \
		   inputs_checker.c \

OBJECTS = $(SOURCES:.c=.o)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(SOURCES) -Iheaders -o $(NAME)

all: $(NAME)

clean:
	@rm -rf *.o
	@rm -rf ./operations/*.o
	@echo "cleaning the .o files"

fclean: clean
	@rm -rf $(NAME)

re: fclean all