#include "push_swap.h"

void	write_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	is_duplicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				write_error();
			j++;
		}
	}
	return (0);
}

int	is_digit(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		if ((argv[i][j] == '-' || argv[i][j] == '+') && argv[i][j + 1] >= '0' \
				&& argv[i][j + 1] <= '9')
			j++;
		else if (argv[i][j] == '\0')
			write_error();
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				write_error();
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	is_integer(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) < -2147483648 || ft_atoi(argv[i]) > 2147483647)
			write_error();
		i++;
	}
	return (0);
}

void    ps_input_validate(int  n, char **nbrs)
{
    is_duplicate(n, nbrs);
	is_digit(n, nbrs);
	is_integer(n, nbrs);
}
