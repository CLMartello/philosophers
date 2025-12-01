
# Flags #

NAME = philo

HEADER = philosophers.h

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

# Files #

SRC = src/actions.c src/ft_atoi.c src/parse.c src/philo.c src/main.c src/free.c

OBJS = $(SRC:.c=.o)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Configuration #

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Compiled program"

# Phonies #

norm:
	@norminette -R CheckForbiddenSourceHeader $(HEADER) $(SRC)

clean:
	@rm -rf $(OBJS)
	@echo "Cleaned object files"

fclean: clean
	@rm -rf $(NAME)
	@echo "Removed program"

re: fclean all
