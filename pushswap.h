#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_stack{
    struct s_stack *prev;
    int n;
    struct s_stack *next;
}   t_stack;

int	ft_atoi(const char *str);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(int n);
void	ft_lstadd_front(t_stack **lst, int n);

#endif