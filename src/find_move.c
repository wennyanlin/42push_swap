#include "push_swap.h"

t_move find_lowercost_move(t_stack *list_a, t_stack *list_b, int list_a_size, int list_b_size, int(f)(int, t_stack *))
{
	t_move lowest_cost;
	t_move curr_node_cost;
	int target_node_index;

	lowest_cost.total = -1;
	initialize_indexes(list_a);
	initialize_indexes(list_b);
	if (!list_b) // no rotates needed, just push
		return (empty_move());
	while (list_a)
	{
		target_node_index = f(list_a->data, list_b); // find the target node
		curr_node_cost = calculate_moving_cost(list_a_size, list_b_size, list_a->index, target_node_index);
		if (lowest_cost.total == -1 || curr_node_cost.total < lowest_cost.total)
			lowest_cost = curr_node_cost;
		list_a = list_a->next;
	}
	return (lowest_cost);
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
			if (curr_a_node->data < target_a_node->data
				|| target_a_node->data < b_node)
				target_a_node = curr_a_node;
		}
		else // smallest node
		{
			if (curr_a_node->data < target_a_node->data
				&& target_a_node->data < b_node)
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
			if (target_node->data > a_node
				|| curr_node->data > target_node->data)
				target_node = curr_node;
		}
		else
		{
			// if we find the the node is biggest than target and a_node, which is the biggest node.
			if (target_node->data > a_node
				&& curr_node->data > target_node->data)
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

	move = empty_move();
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
