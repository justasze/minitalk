SERVER = server
CLIENT = client

FLAGS = -Wall -Wextra -Werror -Weverything

INCLUDES_PATH = libft/includes/

SERVER_FILE = server.c

CLIENT_FILE = client.c

OBJS_DIR = objs/

SERVER_OBJ = $(addprefix $(OBJS_DIR), $(SERVER_FILE:.c=.o))
CLIENT_OBJ = $(addprefix $(OBJS_DIR), $(CLIENT_FILE:.c=.o))

all: $(OBJS_DIR) $(SERVER) $(CLIENT)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(SERVER): $(SERVER_OBJ)
	make -C libft
	clang $(FLAGS) -o $(SERVER) $(SERVER_OBJ) libft/libft.a

$(CLIENT): $(CLIENT_OBJ)
	clang $(FLAGS) -o $(CLIENT) $(CLIENT_OBJ) libft/libft.a

$(OBJS_DIR)%.o:%.c
	clang $(FLAGS) -o $@ -c $< -I$(INCLUDES_PATH)

clean:
	make -C libft clean
	rm -rf $(OBJS_DIR)

fclean: clean
	make -C libft fclean
	rm -f $(SERVER)
	rm -f $(CLIENT)

re: fclean all

.PHONY: clean fclean re
