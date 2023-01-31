# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: liperman <liperman@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/18 15:47:23 by liperman          #+#    #+#              #
#    Updated: 2022/09/07 14:11:03 by liperman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CLIENT = client
CLIENT_SOURCE = client.c
CLIENT_BONUS = client_bonus
CLIENT_BONUS_SOURCE = client_bonus.c
SERVER = server
SERVER_SOURCE = server.c
SERVER_BONUS = server_bonus
SERVER_BONUS_SOURCE = server_bonus.c
RM = rm -rf
CC = cc
FLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

$(NAME): all

$(LIBFT):
	make -C libft

all: $(CLIENT) $(SERVER)

$(SERVER): $(LIBFT)
	$(CC) $(FLAGS) $(SERVER_SOURCE) $(LIBFT) -o $(SERVER)

$(CLIENT): $(LIBFT)
	$(CC) $(FLAGS) $(CLIENT_SOURCE) $(LIBFT) -o $(CLIENT)

bonus: $(LIBFT)
	$(CC) $(FLAGS) $(CLIENT_BONUS_SOURCE) $(LIBFT) -o $(CLIENT_BONUS)
	$(CC) $(FLAGS) $(SERVER_BONUS_SOURCE) $(LIBFT) -o $(SERVER_BONUS)

clean:
	$(RM) $(CLIENT) $(SERVER)
	make clean -C ./libft

fclean: clean
	$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re
