#include "push_swap.h"

void	free_stack(t_stack *list)
{
	t_stack	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
	list = NULL;
}

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
