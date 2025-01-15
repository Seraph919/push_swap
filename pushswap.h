#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_stack{
    int n;
    struct s_stack *next;
    int index;
    int total;
}   t_stack;

int	ft_atoi(const char *str);
void rb(t_stack **b);
void ra(t_stack **a);
void rra(t_stack **a);
void rrr(t_stack **a, t_stack **b);
void rr(t_stack **a, t_stack **b);
void pa(t_stack **a, t_stack **b);
void pb(t_stack **a, t_stack **b);
void sb(t_stack *b);
void rrb(t_stack **b);
void find_and_push(t_stack **from ,t_stack **to);
void sa(t_stack *a);
void ss(t_stack *a, t_stack *b);
int smallest_index(t_stack **a);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void push(t_stack **from, t_stack **to);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_before_last(t_stack *lst);
void print(t_stack *a);
// void push_given(t_stack *given ,t_stack **to);
int	ft_lstsize(t_stack *lst);
t_stack *find_smallest(t_stack *a);
t_stack	*ft_lstnew(int n);
void	ft_lstadd_front(t_stack **lst, int n);

#endif