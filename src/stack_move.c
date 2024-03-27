#include "push_swap.h"

t_move	empty_move(void)
{
	t_move move;

	move.ra = 0;
	move.rb = 0;
	move.rr = 0;
	move.rra = 0;
	move.rrb = 0;
	move.rrr = 0;
	return (move);
}

void rotate_smallest_to_top(t_stack **list_a)
{
	t_stack	*tmp;
	int		i;
	int		middle_line;
	int		total;

	tmp = *list_a;
	total = initialize_indexes(*list_a);
	middle_line = total / 2;
	while (tmp && tmp->next && tmp->data < tmp->next->data)
		tmp = tmp->next;
	if (tmp && tmp->next && tmp->data > tmp->next->data)
	{
		if (tmp->index < middle_line)
		{
			i = tmp->index + 1;
			while (i-- > 0)
				move_ra(list_a);
		}
		else
		{
			i = total - tmp->index - 1;
			while (i-- > 0)
				move_rra(list_a);
		}
	}
}

void execute_move(t_move move, t_stack **list_a, t_stack **list_b, int push_until)
{
	execute_rotate(&move, list_a, list_b, push_until);
	execute_reverse_rotate(&move, list_a, list_b, push_until);
	execute_push(list_a, list_b, push_until);
}

void push_a_to_b(t_stack **list_a, t_stack **list_b, int(f)(int, t_stack *), int push_until)
{
	t_move lowest_cost_move;
	int list_a_size;
	int list_b_size;

	list_a_size = initialize_indexes(*list_a);
	list_b_size = initialize_indexes(*list_b);
	while (list_a_size > push_until)
	{
		lowest_cost_move = find_lowercost_move(*list_a, *list_b, list_a_size, list_b_size, f);
		execute_move(lowest_cost_move, list_a, list_b, push_until);
		list_a_size = initialize_indexes(*list_a);
		list_b_size = initialize_indexes(*list_b);
	}
}
