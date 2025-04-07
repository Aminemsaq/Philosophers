NAME    = Philosophers
CC      = cc
CFLAGS  = -Wall -Werror -Wextra -fsanitize=thread
RM      = rm -rf

INCLUDE = philo.h

SRC     = main.c ft_parsing.c ft_init.c ft_free.c ft_simulation.c ft_time.c

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