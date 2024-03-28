/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:17:09 by wlin              #+#    #+#             */
/*   Updated: 2024/03/27 19:10:50 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_rotate(t_stack **list)
{
		t_stack	*tmp;
		t_stack	*head;

		tmp = *list;
		head = (*list)->next;
		while ((*list)->next != NULL)
			*list = (*list)->next;
		tmp->next = NULL;
		(*list)->next = tmp;
		*list = head;
}

void	move_ra(t_stack **list)
{
	move_rotate(list);
	write(1, "ra\n", 3);
}

void	move_rb(t_stack **list)
{
	move_rotate(list);
	write(1, "rb\n", 3);
}

void	move_rr(t_stack **list_a, t_stack **list_b)
{
	move_rotate(list_a);
	move_rotate(list_b);
	write(1, "rr\n", 3);
}

void	execute_rotate(t_move *move, t_stack **list_a, t_stack **list_b, int push_until)
{
	while (move->ra > 0)
	{
		if (push_until == 3)
			move_ra(list_a);
		else if (push_until == 0)
			move_rb(list_a);
		move->ra--;
	}
	while (move->rb > 0)
	{
		if (push_until == 3)
			move_rb(list_b);
		else if (push_until == 0)
			move_ra(list_b);
		move->rb--;
	}
	while (move->rr > 0)
	{
		move_rr(list_a, list_b);
		move->rr--;
	}
}
