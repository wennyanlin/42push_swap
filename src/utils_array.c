#include "push_swap.h"

// void print_moves(t_move test_move)
// {
// 	printf("Total move: %d, ra: %d, rra: %d, rb: %d, rrb: %d\n", test_move.total, test_move.ra, test_move.rra, test_move.rb, test_move.rrb);
// }

// void	print_stack(t_stack *list)
// {
// 	while (list)
// 	{
// 		printf("\nnode: %d - %d", list->data, list->index);
// 		list = (list)->next;
// 	}
// }

int	calculate_array_size(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(size * count);
	if (str == NULL)
		return (NULL);
	while (i < (count * size))
	{
		str[i] = '\0';
		i++;
	}
	return (str);
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (*str)
		while (str[i])
			i++;
	return (i);
}
