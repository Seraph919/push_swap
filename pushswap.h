#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_stack{
    int n;
    struct s_stack *next;
    struct s_stack *prev;
    int index;
    int total;
}   t_stack;

int	ft_atoi(const char *str);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_before_last(t_stack *lst);
void push_given(t_stack *given ,t_stack **to);
int	ft_lstsize(t_stack *lst);
t_stack *find_smallest(t_stack *a);
t_stack	*ft_lstnew(int n);
void	ft_lstadd_front(t_stack **lst, int n);

#endif