CLIENT = client
CSRC = client.c
COBJS = $(CSRC:.c=.o)

SERVER = server
SSRC = server.c
SOBJS = $(SSRC:.c=.o)

HEADERS = ./headers
UTILS = libutils.a
UTILS_DIR = ./utils

CFLAGS = -Wall -Werror -Wextra
CC = gcc
FLAGS = $(CFLAGS) -I$(HEADERS)/headers

all: $(UTILS) $(SERVER) $(CLIENT)

$(UTILS):
	@make -C $(UTILS_DIR)
	@echo "Utils Ready!"

$(SERVER): $(SOBJS)
	@$(CC) $(FLAGS) ./$(UTILS_DIR)/$(UTILS) -o $(SERVER) $(SOBJS)
	@echo "Server Ready!"

$(CLIENT): $(COBJS)
	@$(CC) $(FLAGS) ./$(UTILS_DIR)/$(UTILS) -o $(CLIENT) $(COBJS)
	@echo "Client Ready!"

clean:
	@make clean -C $(UTILS_DIR)

fclean: clean
	@make fclean -C $(UTILS_DIR)
	@rm -f $(SERVER) $(CLIENT) $(SOBJS) $(COBJS)
	@echo "Server, Client and the utils Directories Cleaned Successfully"

re: fclean all

.PHONY: all $(SERVER) $(CLIENT) clean fclean re