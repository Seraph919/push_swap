#include "pushswap.h"

t_stack	*ft_lstnew(int n)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = NULL;
	return (new);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_front(t_stack **lst, int n)
{
    t_stack *new;

    new = ft_lstnew(n);
	if (!new || !lst)
		return ;
    new->prev = NULL;
	new->next = *lst;
	*lst = new;
}

void	ft_lstdelone(t_stack *lst)
{
	if (!lst)
		return ;
	free(lst);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	static int	index = 0;
	t_stack	*last;

	if (!*lst)
	{
        new->prev = NULL;
		*lst = new;
        new->index = 0;
		return ;
	}
	if (lst)
	{
		last = ft_lstlast(*lst);
		last->next = new;
        new->prev = last;
        new->index = ++index;
	}
}