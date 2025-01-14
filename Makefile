SRC = push_swap.c  pushswap.h  operations.c  utils2.c  utils.c
CFLAGS = -g
#! make with flags after tests
# * -Wall -Wextra -Werror
NAME = push_swap

all :
	cc $(CFLAGS) $(SRC) -o $(NAME)
clean :
	rm -f $(NAME)
fclean : clean

re : fclean all