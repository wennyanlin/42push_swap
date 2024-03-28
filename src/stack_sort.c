#include "push_swap.h"

void sort_3(t_stack **list)
{
	int max_nbr;

	max_nbr = find_max_nbr(*list);
	if ((*list)->data == max_nbr)
		move_ra(list);
	else if ((*list)->next->data == max_nbr)
		move_rra(list);
	if ((*list)->data > (*list)->next->data)
		move_swap(list);
}

void sort(t_stack **list_a)
{
	t_stack	*list_b;

	list_b = NULL;
	push_a_to_b(list_a, &list_b, find_target_node_in_b, 3);
	sort_3(list_a);
	initialize_indexes(*list_a);
	initialize_indexes(list_b);
	push_a_to_b(&list_b, list_a, find_target_node_in_a, 0);
	rotate_smallest_to_top(list_a);
}

int	is_stack_sorted(t_stack **list)
{
	t_stack	*list_cpy;

	list_cpy = *list;
	while (list_cpy && list_cpy->next)
	{
		if (list_cpy->data > list_cpy->next->data)
			return (0);
		list_cpy = list_cpy->next;
	}
	return (1);
}

void	perform_sort(t_stack **list_a)
{
	if (!is_stack_sorted(list_a))
	{
		if (stack_size(*list_a) == 2)
			move_swap(list_a);
		else if (stack_size(*list_a) == 3)
			sort_3(list_a);
		else
			sort(list_a);
	}
}
