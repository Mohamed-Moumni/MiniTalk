SRC_CLIENT = client.c ft_atoi.c ft_putnbr.c ft_putchar.c

SRC_SERVER = ft_atoi.c  server.c ft_putnbr.c ft_putchar.c

OBG_CLIENT = $(SRC_CLIENT:.c=.o)

OBG_SERVER = $(SRC_SERVER:.c=.o)

SRC_CLIENT_BONUS = client_bonus.c ft_atoi.c ft_putnbr.c ft_putchar.c

SRC_SERVER_BONUS = ft_atoi.c  server_bonus.c ft_putnbr.c ft_putchar.c

OBG_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)

OBG_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)

GCC_FLAGS = -Wall -Wextra -Werror

CC = cc

CLIENT = client

SERVER = server

NAME = client_server

all : $(NAME)

$(NAME) : $(OBG_CLIENT) $(OBG_SERVER)
	$(CC) $(GCC_FLAGS) -o $(CLIENT) $(OBG_CLIENT) 
	$(CC) $(GCC_FLAGS) -o $(SERVER) $(OBG_SERVER)

%.o : %.c
	$(CC) $(GCC_FLAGS) -c $<

bonus : $(OBG_CLIENT_BONUS) $(OBG_SERVER_BONUS)
	$(CC) $(GCC_FLAGS) -o $(CLIENT) $(OBG_CLIENT_BONUS) 
	$(CC) $(GCC_FLAGS) -o $(SERVER) $(OBG_SERVER_BONUS)

clean :
	rm -f $(OBG_SERVER) $(OBG_CLIENT) $(OBG_CLIENT_BONUS) $(OBG_SERVER_BONUS)

fclean : clean
	rm -f $(CLIENT) $(SERVER)

re : fclean all
