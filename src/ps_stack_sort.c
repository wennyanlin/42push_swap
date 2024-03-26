#include "push_swap.h"

// add a parameter to differ/invert the 'move prints' when is executing from b to a
void execute_move(t_move move, t_stack **list_a, t_stack **list_b, int push_until)
{
	while (move.ra > 0)
	{
		if (push_until == 3)
			move_ra(list_a);
		else if (push_until == 0)
			move_rb(list_a);
		move.ra--;
	}
	while (move.rb > 0)
	{
		if (push_until == 3)
			move_rb(list_b);
		else if (push_until == 0)
			move_ra(list_b);
		move.rb--;
	}
	while (move.rr > 0)
	{
		move_rr(list_a, list_b);
		move.rr--;
	}
	while (move.rra > 0)
	{
		if (push_until == 3)
			move_rra(list_a);
		else if (push_until == 0)
			move_rrb(list_a);
		move.rra--;
	}
	while (move.rrb > 0)
	{
		if (push_until == 3)
			move_rrb(list_b);
		else if (push_until == 0)
			move_rra(list_b);
		move.rrb--;
	}
	while (move.rrr > 0)
	{
		move_rrr(list_a, list_b);
		move.rrr--;
	}
}

void push_a_to_b(t_stack **list_a, t_stack **list_b, int(f)(int, t_stack *), int push_until)
{
	t_move lowercost_node_moves;
	int list_a_size;
	int list_b_size;

	if (!*list_b)
	{
		move_push(list_a, list_b);
		write(1, "pb\n", 3);
	}
	list_a_size = initialize_indexes(*list_a);
	list_b_size = initialize_indexes(*list_b);
	while (list_a_size > push_until)
	{
		lowercost_node_moves = find_lowercost_node(*list_a, *list_b, list_a_size, list_b_size, f);
		execute_move(lowercost_node_moves, list_a, list_b, push_until);
		move_push(list_a, list_b);
		if (push_until == 3)
			write(1, "pb\n", 3);
		else if (push_until == 0)
			write(1, "pa\n", 3);
		list_a_size = initialize_indexes(*list_a);
		list_b_size = initialize_indexes(*list_b);
	}
}

/**
 * Possible refactors:
 * 1. initialize_indexes can return the size
 * 		- this means we don't need to increment/decrement size on every push
 * 2. make move_push part of the execute_move functions
 * 		- this means execute move handles all moves
 * 3. handle first move_push b move in the find_lowercost_node
 * 		- this means find_lowercost_node handles all moves, including the first move
 *
*/

t_move find_lowercost_node(t_stack *list_a, t_stack *list_b, int list_a_size, int list_b_size, int(f)(int, t_stack *))
{
	t_move lowercosts;
	t_move costs;
	int target_node_index;

	lowercosts.total = -1;
	initialize_indexes(list_a);
	initialize_indexes(list_b);

	while (list_a)
	{
		target_node_index = f(list_a->data, list_b); // find the target node
		costs = calculate_moving_cost(list_a_size, list_b_size, list_a->index, target_node_index);
		if (lowercosts.total == -1 || costs.total < lowercosts.total)
			lowercosts = costs;
		list_a = list_a->next;
	}
	return (lowercosts);
}

void print_moves(t_move test_move)
{
	printf("Total move: %d, ra: %d, rra: %d, rb: %d, rrb: %d\n", test_move.total, test_move.ra, test_move.rra, test_move.rb, test_move.rrb);
}

int find_target_node_in_a(int b_node, t_stack *list_a)
{
	t_stack *target_a_node;
	t_stack *curr_a_node;

	target_a_node = list_a;
	curr_a_node = list_a;
	while (curr_a_node)
	{
		if (curr_a_node->data > b_node) // close bigger node
		{
			if (curr_a_node->data < target_a_node->data || target_a_node->data < b_node)
				target_a_node = curr_a_node;
		}
		else // smallest node
		{
			if (curr_a_node->data < target_a_node->data && target_a_node->data < b_node)
				target_a_node = curr_a_node;
		}
		curr_a_node = curr_a_node->next;
	}
	return (target_a_node->index);
}

int find_target_node_in_b(int a_node, t_stack *list_b)
{
	t_stack *target_node;
	t_stack *curr_node;

	target_node = list_b;
	while (list_b)
	{
		curr_node = list_b;
		if (curr_node->data < a_node)
		{
			// 1)if we have a biggest node and we find a small node
			// 2) if we have a small and find even bigger small node.
			if (target_node->data > a_node || curr_node->data > target_node->data)
				target_node = curr_node;
		}
		else
		{
			// if we find the the node is biggest than target and a_node, which is the biggest node.
			if (target_node->data > a_node && curr_node->data > target_node->data)
				target_node = curr_node;
		}
		list_b = list_b->next;
	}
	return (target_node->index);
}

t_move calculate_moving_cost(int list_a_size, int list_b_size, int a_index, int b_index)
{
	int middle_line_a;
	int middle_line_b;
	t_move move;

	move.ra = 0;
	move.rb = 0;
	move.rr = 0;
	move.rra = 0;
	move.rrb = 0;
	move.rrr = 0;

	middle_line_a = list_a_size / 2;
	middle_line_b = list_b_size / 2;
	if (a_index <= middle_line_a)
		move.ra = a_index;
	else
		move.rra = list_a_size - a_index;
	if (b_index <= middle_line_b)
		move.rb = b_index;
	else
		move.rrb = list_b_size - b_index;
	move = optimize_moving_cost(move);
	move.total = move.ra + move.rb + move.rr + move.rra + move.rrb + move.rrr;
	return (move);
}

t_move optimize_moving_cost(t_move move)
{
	while (move.ra > 0 && move.rb > 0)
	{
		move.ra--;
		move.rb--;
		move.rr++;
	}
	while (move.rra > 0 && move.rrb > 0)
	{
		move.rra--;
		move.rrb--;
		move.rrr++;
	}
	return (move);
}

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

void rotate_smallest_to_top(t_stack **list_a)
{
	int i;
	t_stack *tmp;

	i = 1;
	tmp = *list_a;

	while (tmp && tmp->next && tmp->data < tmp->next->data)
	{
		i++;
		tmp = tmp->next;
	}
	if (tmp && tmp->next && tmp->data > tmp->next->data)
	{
		while (i > 0)
		{
			move_ra(list_a);
			i--;
		}
	}
}
