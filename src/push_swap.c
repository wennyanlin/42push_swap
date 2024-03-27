/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:15:32 by wlin              #+#    #+#             */
/*   Updated: 2024/03/27 19:07:27 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_error(char **array)
{
	write(2, "Error\n", 6);
	free_array(array);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_stack *list_a;

	if (argc > 1)
	{
		if (ft_strlen(argv[1]) == 0)
		{
			write(2, "Error\n", 6);
			return (EXIT_FAILURE);
		}
		list_a = parse_input(argc, argv);
		if (!list_a)
			return (EXIT_FAILURE);
		perform_sort(&list_a);
		free_stack(list_a);
	}
	exit (EXIT_SUCCESS);
}

