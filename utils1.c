#include "pushswap.h"

char	*ft_strchr(const char *str, int search_str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)search_str)
			return (&((char *)str)[i]);
		i++;
	}
	if ((char)search_str == '\0')
		return (&((char *)str)[i]);
	return (NULL);
}
void split_arg (char *av, t_stack **a, int *index)
{
    t_stack *temp;
    int i;
    long n;
    char **s;
    
    s = ft_split(av, ' ');
    if (check_strings(s))
        return(ft_putstr("Error\n"), fire_force(a), exit(1));
    i = 0;
    while (s[i])
    {
        n = ft_atol(s[i]);
        if (check_invalid(n))
            return(ft_putstr("Error\n"), fire_force(a), exit(1));;
        temp = ft_lstnew(n);
        ft_lstadd_back(a, temp);
        i++;
    }
    *index += 1;
    i = 0;
    while (s[i])
        free(s[i++]);
    free(s);
}
void indexed(int *tab, int size)
{
    int  i = 0;
    int  j;
    int temp;
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (tab[j] < tab[i])
            {
                temp =  tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
            j++;
        }
        i++;
    }
}
int *prep_index(t_stack *temp)
{
    int total = temp->total + 1;
    int *tab = malloc(total * sizeof(int));
    int i = 0;
    while (i < total)
    {
        tab[i] = temp->n;
        temp = temp->next;
        i++;
    }
    return tab;
}