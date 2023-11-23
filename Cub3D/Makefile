NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_PATH = ./src
OBJ_PATH = ./obj

SRC = main.c \
	raycaster_h.c \
	raycaster_v.c \
	raycaster.c \
	render_walls1.c \
	render_walls2.c \
	render_components.c \
	link_part.c \
	ready_game_events.c \
	ready_game_others.c \
	ready_game_player.c \
	ready_game.c \
	render_game.c \
	update.c \
	utils_graph.c \
	utils_mem.c \
	utils_others1.c \
	utils_others2.c \
	utils_rays.c \
	ft_check.c \
	ft_check2.c \
	ft_check3.c \
	ft_error.c \
	ft_error2.c \
	ft_error3.c \
	ft_splitt.c \
	ft_utils1.c \
	ft_utils2.c

SRCS = $(addprefix $(SRC_PATH)/, $(SRC))
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH)/, $(OBJ))

LINKS = -framework OpenGL -framework AppKit
LIBFT = ./lib/libft/libft.a 
minilibx = ./lib/minilibx/libmlx.a
RM = rm -rf

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(NAME): $(OBJ_PATH) $(OBJS)
	make -C ./lib/libft
	make -C ./lib/minilibx
	$(CC) $(CFLAGS) -g $(OBJS) $(LIBFT) $(minilibx) $(LINKS) -o $(NAME)

clean:
	$(RM) $(OBJ_PATH)

fclean: clean
	$(RM) $(NAME)
	make clean -C ./lib/minilibx
	make fclean -C ./lib/libft

re: fclean all