/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:43:23 by wlin              #+#    #+#             */
/*   Updated: 2023/11/23 11:57:13 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_push(t_stack **list_a, t_stack **list_b)
{
	t_stack	*tmp;
	if (*list_a)
	{
		tmp = *list_a;
		*list_a = (*list_a)->next;
		tmp->next = *list_b;
		*list_b = tmp;
	}
}

void execute_push(t_stack **list_a, t_stack **list_b, int push_until)
{
	move_push(list_a, list_b);
	if (push_until == 3)
		write(1, "pb\n", 3);
	else if (push_until == 0)
		write(1, "pa\n", 3);
}
