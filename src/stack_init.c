#include "push_swap.h"

int	initialize_indexes(t_stack *list)
{
	int	index;

	index = 0;
	while (list)
	{
		list->index = index;
		index++;
		list = list->next;
	}
	return (index);
}

t_stack	*stack_init(char **nbrs, int n)
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

t_stack	*parse_input(int argc, char **argv)
{
	t_stack *list_a;
	int f;
	int	n;
	char **array;

	f = 0;
	n = argc;
	if (argc == 2)
	{
		array = ps_split(argv[1], ' ');
		f = 1;
	}
	else
		array = argv;
	n = calculate_array_size(array);
	ps_input_validate(n, array);
	list_a = stack_init(array, n);
	if (f == 1)
		free_array(array);
	return (list_a);
}
