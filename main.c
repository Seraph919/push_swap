#include "pushswap.h"

void pa(t_stack **b, t_stack **a)
{
    if (*b)
    {
        t_stack *temp = *b;
        ft_lstadd_front(a, (*b)->n);
        if ((*b)->next)
            *b = (*b)->next;
        else
            *b = NULL;
        free(temp);
    }
}
void pb(t_stack **b, t_stack **a)
{
    if (*a)
    {
        t_stack *temp = *a;
        ft_lstadd_front(b, (*a)->n);
        *a = (*a)->next;
        free(temp);
    }
}
void sb(t_stack *b)
{
    int temp;

    temp = b->n;
    b->n = b->next->n;
    b->next->n = temp;
}
void sa(t_stack *a)
{
    int temp;

    temp = a->n;
    a->n = a->next->n;
    a->next->n = temp;
}
void ra(t_stack **a)
{
    t_stack *temp;
    t_stack *last;

    temp= (*a);
    *a = (*a)->next;
    last = ft_lstlast(temp);
    last->next = temp;
    temp->prev = last;
    (*a)->prev = NULL;
    temp->next = NULL;
}
void rb(t_stack **b)
{
    t_stack *temp;
    t_stack *last;

    temp= (*b);
    *b = (*b)->next;
    last = ft_lstlast(temp);
    last->next = temp;
    temp->prev = last;
    (*b)->prev = NULL;
    temp->next = NULL;
}

void rra(t_stack **a)
{
    t_stack *last;
    t_stack *sec;
    t_stack *temp;

    last = ft_lstlast(*a);
    sec = last->prev;
    last->prev = NULL;
    sec->next = NULL;
    temp = *a;
    *a = last;
    last->next = temp;
    temp->prev = last;
}
void rrb(t_stack **b)
{
    t_stack *last;
    t_stack *sec;
    t_stack *temp;

    last = ft_lstlast(*b);
    sec = last->prev;
    last->prev = NULL;
    sec->next = NULL;
    temp = *b;
    *b = last;
    last->next = temp;
    temp->prev = last;
}
void rr(t_stack **a, t_stack **b)
{
    ra(a);
    rb(b);
}
void ss(t_stack *a, t_stack *b)
{
    sa(a);
    sb(b);
}
void rrr(t_stack **a, t_stack **b)
{
    rra(a);
    rrb(b);
}

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;
    t_stack *temp;
    int     i;
    int     n;

    a = NULL;
    b = NULL;
    i = 1;
    if (ac >= 3)
    {
        while (av[i])
        {
            n = ft_atoi(av[i]);
            temp = ft_lstnew(n);
            ft_lstadd_back(&a, temp);
            i++;
        }
        printf("before pb :\n");
        i = 1;
        temp = a;
        while (temp)
        {
            printf("%d is %d\n", i++,temp->n);
            temp = temp->next;
        }
        // printf("before pb :\na->n = %d\nthe last n is  = %d\n", a->n, ft_lstlast(a)->n);
        rra(&a);
        printf("after pb :\n");
        i = 1;
        temp = a;
        while (temp)
        {
            printf("%d is %d\n", i++,temp->n);
            temp = temp->next;
        }
        // printf("aftaa pb :\na->n = %d\nthe last n is = %d\n", a->n, ft_lstlast(a)->n);

    }
}