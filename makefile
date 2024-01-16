# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andefern <andefern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 13:19:22 by andefern          #+#    #+#              #
#    Updated: 2024/01/16 17:07:37 by andefern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Definitions
NAME = minitalk
SERVER = server
CLIENT = client

FLAGS = -Wall -Wextra -Werror
CC = gcc

# MAKEFILE ART #
# COLORS #
BLACK=\033[0;30m
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
MAG=\033[0;35m
CYAN=\033[0;36m
WHITE=\033[0;37m
PAPYRUS=\033[38;5;223m
END=\033[0m

define MINITALK
$(CYAN)
███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗  ██╗
████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║     ██║ ██╔╝
██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝ 
██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗ 
██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗
╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝                                     
$(END)
endef
export MINITALK

#Compilation rules
.SILENT:
all: $(NAME)

$(SERVER): $(SERVER).c
	$(CC) $(FLAGS) -o $(SERVER) $(SERVER).c
	echo "$$MINITALK"

$(CLIENT): $(CLIENT).c
	$(CC) $(FLAGS) -o $(CLIENT) $(CLIENT).c

$(NAME): $(SERVER) $(CLIENT)

clean:
	rm -f server.o client.o
	
fclean: clean
	rm -f $(SERVER) $(CLIENT)
	
re: fclean all

.PHONY: all clean fclean re