/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:19:13 by wlin              #+#    #+#             */
/*   Updated: 2023/11/22 21:36:35 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_reverse_rotate(t_stack **list)
{
	t_stack	*head;
	t_stack	*tmp;

	head = *list;
	while ((*list)->next->next != NULL)
		*list = (*list)->next;
	tmp = (*list)->next;
	(*list)->next = NULL;
	tmp->next = head;
	*list = tmp;
}

void	move_rra(t_stack **list)
{
	move_reverse_rotate(list);
	write(1, "rra\n", 4);
}

void	move_rrb(t_stack **list)
{
	move_reverse_rotate(list);
	write(1, "rrb\n", 4);
}

void	move_rrr(t_stack **list_a, t_stack **list_b)
{
	move_reverse_rotate(list_a);
	move_reverse_rotate(list_b);
	write(1, "rrr\n", 4);
}
