/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:33:13 by wlin              #+#    #+#             */
/*   Updated: 2024/03/27 19:08:26 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./ft_printf/ft_printf.h"
# include <stdio.h>

typedef struct s_move
{
	int	ra;
	int	rb;
    int	rr;
	int	rra;
	int	rrb;
	int	rrr;
    int total;
}	t_move;

typedef struct s_stack
{
	int				data;
	int				index;

	struct s_stack	*next;
	struct s_move	curr_move;
}	t_stack;

int		is_duplicate(int argc, char **str_b);
int		is_digit(int argc, char **argv);
int		is_integer(int argc, char **argv);
void	write_error(void);
void	move_swap(t_stack **list);
void	move_rotate(t_stack **list);
void	move_ra(t_stack **list);
void	move_rb(t_stack **list);
void	move_rr(t_stack **list_a, t_stack **list_b);
void	move_reverse_rotate(t_stack **list);
void	move_rra(t_stack **list);
void	move_rrb(t_stack **list);
void	move_rrr(t_stack **list_a, t_stack **list_b);
void	move_push(t_stack **list_a, t_stack **list_b);
void	ps_input_validate(int  n, char **nbrs);
t_stack	*stack_init(char **nbrs, int n);
int		find_max_nbr(t_stack *list);
void	sort_3(t_stack **list);
void	print_stack(t_stack *list);
int		stack_size(t_stack *list_a);
void	sort(t_stack **list_a);
int		initialize_indexes(t_stack *list);
t_move	calculate_moving_cost(int list_a_size, int list_b_size, int a_index, int b_index);
int		find_target_node_in_b(int a_node, t_stack *list_b);
int		find_target_node_in_a(int b_node, t_stack *list_a);
t_move	find_lowercost_move(t_stack *list_a, t_stack *list_b, int(f)(int, t_stack *));
void	print_moves(t_move test_move);
void	push_a_to_b(t_stack **list_a, t_stack **list_b, int(f)(int, t_stack *), int	push_until);
void	execute_move(t_move move, t_stack **list_a, t_stack **list_b, int push_until);
void	rotate_smallest_to_top(t_stack **list_a);
t_move	optimize_moving_cost(t_move move);
int		is_stack_sorted(t_stack **list);
char	**ps_split(char *array, char separator);
int		ps_count_words(char *array, char separator);
char	*get_next_word(char *array, char separator);
int		calculate_array_size(char **array);
void	stack_add_back(t_stack **lst, t_stack *new);
void	free_stack(t_stack *list);
long	ft_atoi(const char *str);
int		ft_isspace(char c);
void	*ft_calloc(size_t count, size_t size);
void	execute_rotate(t_move *move, t_stack **list_a, t_stack **list_b, int push_until);
void	execute_reverse_rotate(t_move *move, t_stack **list_a, t_stack **list_b, int push_until);
void	execute_push(t_stack **list_a, t_stack **list_b, int push_until);
int		ft_strlen(char *str);
int		has_too_many_digits(char *str);
t_move	empty_move(void);
t_stack	*parse_input(int argc, char **argv);
void	perform_sort(t_stack **list_a);
void	free_array(char **array);

#endif
