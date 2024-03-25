#include "push_swap.h"
/*
int	find_min_nbr(t_stack *list)
{
	int	min_nbr;

	min_nbr = list->data;
	while (list)
	{
		if (list->data < min_nbr)
			min_nbr = list->data;
		list = list->next;
	}
	return (min_nbr);
}*/

int	find_max_nbr(t_stack *list)
{
	int max_nbr;

	max_nbr = list->data;
	while (list)
	{
		if (list->data > max_nbr)
			max_nbr = list-> data;
		list = list->next;
	}
	return (max_nbr);
}

int	stack_size(t_stack *list_a)
{
	int	i;

	i = 0;
	while (list_a)
	{
		i++;
		list_a = (list_a)->next;
	}
	return (i);
}

void	initialize_indexes(t_stack *list)
{
	int	index;

	index = 0;
	while (list)
	{
		list->index = index;
		index++;
		list = list->next;
	}
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

t_stack	*stack_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	stack_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!lst)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = stack_last(*lst);
		last->next = new;
	}
}