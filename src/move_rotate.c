/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:17:09 by wlin              #+#    #+#             */
/*   Updated: 2023/11/22 19:27:47 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

		//return(head);
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
