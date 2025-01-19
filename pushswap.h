#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_stack{
    int n;
    struct s_stack *next;
    int index;
    int total;
}   t_stack;

typedef struct data
{
    t_stack *stack_a;
    t_stack *stack_b;
    int *tab;
} t_data;



long	ft_atol(const char *str);
int check_invalid(long n);
int error(t_stack **a);
void rb(t_stack **b);
int is_only_signs(char *s);
void split_arg (char *av, t_stack **a, int *index);
void ra(t_stack **a);
void rra(t_stack **a);
void algoes(int *tab, t_stack **a, t_stack **b, int size);
void indexed(int *tab, int size);
int *prep_index(t_stack *temp);
void fire_force(t_stack **a);
int check_repeat(t_stack *lst, t_stack **a);
int biggest_index(t_stack *a);
int in_range(int *tab, int end, int start, int n, int total);
char	*ft_strchr(const char *str, int search_str);
void rrr(t_stack **a, t_stack **b);
char	**ft_split(const char *s, char c);
void rr(t_stack **a, t_stack **b);
void pa(t_stack **a, t_stack **b);
char	**ft_split(const char *s, char c);
void pb(t_stack **a, t_stack **b);
void sb(t_stack *b);
void rrb(t_stack **b);
void find_and_push(t_stack **from ,t_stack **to);
void sa(t_stack *a);
void ss(t_stack *a, t_stack *b);
int smallest_index(t_stack **a);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void push(t_stack **from, t_stack **to);
int check_strings(char **s);
int check_sorted(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_before_last(t_stack *lst);
void ft_putstr(char *s);
void print(t_stack *a);
// void push_given(t_stack *given ,t_stack **to);
int	ft_lstsize(t_stack *lst);
t_stack *find_smallest(t_stack *a);
t_stack	*ft_lstnew(int n);
void	ft_lstadd_front(t_stack **lst, int n);

#endif