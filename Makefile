SRC = operations.c operations2.c  operations3.c utils2.c  utils.c utils1.c utils3.c cheker_functions.c alg.c

CFLAGS = -g
#! make with flags after tests
# * -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

NAME = push_swap

LIB = src.a

all : $(LIB)
	cc $(CFLAGS) push_swap.c $(LIB) -o $(NAME)

$(LIB) : $(OBJ)
	ar rcs $(LIB) $(OBJ)

clean :
	rm -f  $(OBJ) $(LIB)

fclean : clean
	rm -f $(NAME)
re : fclean all