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

	f = 0;
	if (argc == 2)
	{
		argv = ps_split(argv[1], ' ');
		f = 1;
	}
	argc = calculate_array_size(argv);
	ps_input_validate(argc, argv);

	list_a = stack_init(argv, argc);
	if (f == 1)
		free_array(argv);
	return (list_a);
}
