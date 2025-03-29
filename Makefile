NAME    = Philosophers
CC      = cc
CFLAGS  = -Wall -Werror -Wextra
RM      = rm -rf

INCLUDE = philo.h

SRC     = main.c ft_parsing.c init.c ft_utils.c

OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all