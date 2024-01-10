CLIENT = client
SERVER = server

CC = cc
FLAGS = -Wall -Wextra -Werror

all:

	@$(CC) $(FLAGS) client.c  -o $(CLIENT)

	@$(CC) $(FLAGS) server.c  -o $(SERVER)

%.o:%.c 
	@$(CC) $(FLAGS)

clean:
	@rm -f $(CLIENT) $(SERVER)

fclean: clean
	@rm -f $(CLIENT) $(SERVER)
	
re: fclean all