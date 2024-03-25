#include "push_swap.h"

t_stack	*ps_stack_init(char **nbrs, int n)
{
    t_stack *tmp;
	t_stack	*list_a;
    int     i;

    i = 1;
	list_a = NULL;
    while (n >= 2)
    {
		tmp = ft_calloc(sizeof(t_stack), 1);
		tmp->data = ft_atoi(nbrs[i]);
		stack_add_back(&list_a, tmp);
		i++;
		n--;
    }
	return (list_a);
}
