NAME = so_long
CFLAGS = -Wall -Werror -Wextra -g
CC = gcc
FLAGS = $(CFLAGS) -I$(HEADERS_DIR)/headers
CONFIG_DIR = ./config
UTILS_DIR = ./utils
GNL_DIR = ./utils/getnextline
HEADERS_DIR = ./headers
SRCS = so_long.c $(GNL_DIR)/get_next_line_utils.c $(GNL_DIR)/get_next_line.c $(UTILS_DIR)/utils.c $(UTILS_DIR)/ft_printf.c $(UTILS_DIR)/subs.c $(UTILS_DIR)/get_conversion.c $(UTILS_DIR)/my_memory_tracker.c $(UTILS_DIR)/print_numbers.c $(UTILS_DIR)/printf_characters.c $(CONFIG_DIR)/constraints.c $(CONFIG_DIR)/controls.c $(CONFIG_DIR)/envirment.c 
OBJ = $(SRCS:%.c=%.o)

LIBRARY := -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX := minilibx/

GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[1;33m
RESET = \033[0m

# Define the progress bar function
define progress_bar
    $(eval __pbar_done=$(shell echo "$(1) / $(2) * 100 / 1" | bc))
    $(eval __pbar_remain=$(shell echo "100 - $(__pbar_done)" | bc))
    printf "\r[${3}%s${RESET}%s] %d%%" "$(shell printf '%*s' $(__pbar_done) | tr ' ' '#')" "$(shell printf '%*s' $(__pbar_remain) | tr ' ' '-')" "$(__pbar_done)"
endef

all: $(NAME)

$(NAME) : $(OBJ)
	@echo "$(YELLOW)Compiling $(NAME)...$(RESET)"
	@make -C $(MINILIBX)
	@$(CC) $(FLAGS) $(OBJ) $(LIBRARY) -o $(NAME)\
        $(call progress_bar,5,5,$(GREEN))

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@echo "$(YELLOW)cleaning $(NAME)...$(RESET)"
	@rm -f $(OBJ)

fclean: clean
	make clean -C $(MINILIBX)
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
