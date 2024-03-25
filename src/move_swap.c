/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:37:09 by wlin              #+#    #+#             */
/*   Updated: 2023/11/22 19:25:02 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_swap(t_stack **list)
{
	t_stack	*tmp;

	tmp = *list;
	if ((*list)->next != NULL)
	{
		*list = (*list)->next;
		tmp->next = (*list)->next;
		(*list)->next = tmp;
		write(1, "sa\n", 3);
	}
}
