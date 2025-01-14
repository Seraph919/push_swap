#include "pushswap.h"

void push(t_stack **from, t_stack **to)
{
    if (*from && from)
    {
        t_stack *temp = *from;
        *from = (*from)->next;
        if (*to == NULL)
        {
            *to = temp;
            (*to)->next = NULL;
            (*to)->prev = NULL;
        }
        else
        {
            temp->next = *to;
            temp->next->prev = temp;
            *to = temp;
            (*to)->prev = NULL;
        }
        // (*from)->prev = NULL;
    }
}
void pa(t_stack **a, t_stack **b)
{
    push(b,a);
    write(1, "pa\n", 4);
}
void pb(t_stack **a, t_stack **b)
{
    push(a,b);
    write(1, "pb\n", 4);
}

void sb(t_stack *b)
{
    int temp;

    temp = b->n;
    b->n = b->next->n;
    b->next->n = temp;
    write(1, "sb\n", 4);
}
void sa(t_stack *a)
{
    int temp;

    temp = a->n;
    a->n = a->next->n;
    a->next->n = temp;
    write(1, "sa\n", 4);
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
    write(1, "ra\n", 4);
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
    write(1, "rb\n", 4);
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
    write(1, "rra\n", 4);
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
    write(1, "rrb\n", 4);
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
int smallest_index(t_stack *a)
{
    int smallest = a->n;
    int i = 0;
    while (a)
    {
        if (a->n < smallest)
        {
            smallest = a->n;
            i = a->index;
        }
        a = a->next;
    }
    return (i);
}

void three_alg(t_stack *a)
{
    if (a->n > a->next->n && a->n > a->next->next->n && a->next->n < a->next->next->n) // 15 2 13
        ra(&a);
    else if (a->n > a->next->n && a->n > a->next->next->n && a->next->n > a->next->next->n) // 15 13 2
    {
        ra(&a);
        sa(a);
    }
    else if (a->n < a->next->n && a->n < a->next->next->n && a->next->n > a->next->next->n) // 2 15 13
    {
        rra(&a);
        sa(a);
    }
    else if (a->n > a->next->n && a->n < a->next->next->n && a->next->n < a->next->next->n) // 13 2 15
        sa(a);
    else if (a->n < a->next->n && a->n > a->next->next->n && a->next->n > a->next->next->n) // 13 15 2
        rra(&a);
}
void four_alg(t_stack **a, t_stack **b)
{
    t_stack *temp;
    if (smallest_index(*a) >  2 && smallest_index(*a) != 3)
    {
        rra(a);
        rra(a);
    }
    else if (smallest_index(*a) < 2 && smallest_index(*a) != 0)
    {
        ra(a);
    }
    else
        rra(a);
    printf("............\n");
    temp = *a;
    while (temp)
    {
        printf("%d the index is : %d\n",temp->n, temp->index);
        temp = temp->next;
    }
    pb(a,b);
    printf("............\n");

    temp = *a;
    while (temp)
    {
        printf("%d the index is : %d\n",temp->n, temp->index);
        temp = temp->next;
    }

    printf(".............\n");
    three_alg(*a);
    temp = *a;
    while (temp)
    {
        printf("%d the index is : %d\n",temp->n, temp->index);
        temp = temp->next;
    }
    pa(a, b);
    printf(".............\n");
    temp = *a;
    while (temp)
    {
        printf("%d the index is : %d\n",temp->n, temp->index);
        temp = temp->next;
    }

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
        i = 0;
        temp = a;
        while (temp)
        {
            printf("%d is %d\n", ++i,temp->n);
            temp = temp->next;
        }
        a->total = i;
        if (a->total  <= 3)
        {
            if (a->total == 2)
            {
                if (a->n > a->next->n)
                    sa(a);
            }
            else
            {
                three_alg(a);
            }
        }
        else if (a->total == 4)
        {
            four_alg(&a, &b);
        }
        // temp = a;
        // while (temp)
        // {
        //     printf("%d the index is : %d\n",temp->n, temp->index);
        //     temp = temp->next;
        // }
    }
}
// }
// // printf("before pb :\na->n = %d\nthe last n is  = %d\n", a->n, ft_lstlast(a)->n);
//         rra(&a);
//         printf("after pb :\n");
//         i = 1;
//         temp = a;
//         while (temp)
//         {
//             printf("%d is %d\n", i++,temp->n);
//             temp = temp->next;
//         }
//         // printf("aftaa pb :\na->n = %d\nthe last n is = %d\n", a->n, ft_lstlast(a)->n);
// 