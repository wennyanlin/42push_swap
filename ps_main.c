/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:15:32 by wlin              #+#    #+#             */
/*   Updated: 2023/11/23 11:31:51 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *list)
{
	while (list)
	{
		printf("\nnode: %d - %d", list->data, list->index);
		list = (list)->next;
	}
}

int	calculate_array_size(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i++]);
	}
	free(array);
}

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

t_stack	*parse_input(int argc, char **argv)
{
	t_stack *list_a;
	int f;

	f = 0;
	if (argc == 2)
	{
		argv = ps_split(argv[1], ' ');
		f = 1;
	}
	argc = calculate_array_size(argv);
	ps_input_validate(argc, argv);

	list_a = ps_stack_init(argv, argc);
	if (f == 1)
		free_array(argv);
	return (list_a);
}

int	main(int argc, char **argv)
{
	t_stack *list_a;
	t_stack *list_b;

	if (argc > 1)
	{
		list_a = parse_input(argc, argv);
		if (!list_a)
			return (EXIT_FAILURE);
		argv = NULL;
		list_b = NULL;
		if (is_stack_sorted(&list_a) == true)
		{
			return (0);
		}
		else
		{
			if (stack_size(list_a) == 2)
			{
				move_swap(&list_a);
				return (0);
			}
			else if (stack_size(list_a) == 3)
			{
				sort_3(&list_a);
				return (0);
			}
			else
				sort(&list_a, &list_b);
		}
		free_stack(list_a);

		// printf("\n\n------- STACK A -------\n\n");
		// print_stack(list_a);
		// printf("\n\n------- STACK B -------\n\n");
		// print_stack(list_b);
	}
	return (0);
}

