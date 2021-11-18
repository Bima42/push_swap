/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpauvret <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:34:54 by tpauvret          #+#    #+#             */
/*   Updated: 2021/11/16 18:34:16 by tpauvret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_stack
{
	t_node	*front;
	t_node	*tail;
}				t_stack;

typedef struct s_chunk
{
	int	min;
	int	max;
	int	size;
	int	pos;
}				t_chunk;

typedef struct s_long
{
	int	min;
	int	max;
	int	size;
	int	front;
	int	tail;
	int	low;
	int	high;
	int	mult;
	int	zone;
	int	to_front;
}				t_long;

//Create elements
//void    display(t_stack *a, t_stack *b);
int		list_size(t_node *node);
t_node	*new_node(int data);
t_stack	*new_stack(void);

//Parsing
int		only_whitespace(char **argv);
t_stack	*parsing_string(char **argv);
t_stack	*parsing_multi_args(char **argv);
t_stack	*parsing_args(int argc, char **argv);

//Parsing utils
void	clear(char **array);
void	check_for_dup(t_stack *a);
int		count_args(char **tmp);
int		more_than_one(t_node *check, int data, int count);
int		check_error_args(char **argv);

//Command A
void	sa(t_stack *a);
void	ra(t_stack *a);
void	rra(t_stack *a);
void	pa(t_stack *a, t_stack *b);
void	push_empty(t_stack *b, t_stack *a);

//Command B
void	sb(t_stack *b);
void	rb(t_stack *b);
void	rrb(t_stack *b);
void	pb(t_stack *b, t_stack *a);

//Command Both
void	front_tail_null(t_stack *a);
void	ss(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);

//Solver
void	solver(t_stack *a, t_stack *b);
void	solver_short(t_stack *a);
void	solver_med(t_stack *a, t_stack *b);
void	solver_long(t_stack *a, t_stack *b, int nb_chunk);

//List Utils
int		is_sorted(t_stack *a);
int		is_reverse_sorted(t_stack *a);
int		is_empty(t_stack *a);
int		get_min_data(t_node *node);
int		get_max_data(t_node *node);

//List Utils 2
void	sort_stack_b(t_stack *b, t_stack *a);
int		get_median_data(t_stack *a, int min_data, int max, int loop);
int		yvan_recursive(int data, int count, t_node *current_node);
int		get_pos_data(int min_data, t_node *node);
int		get_next_min_data(int min_data, t_node *node);

//utils_long
void	init_long(t_long *data, t_stack *a, int chunk);
void	set_median_low(t_long *data, t_stack *a, int nb_chunk);
void	collect(t_stack *a, t_stack *b, t_long data);
int		get_by(t_node *node, t_long data, int from);
int		smart_way_long(t_stack *a, t_long data, int *step);

//Utils_long_2
void	init_chunk(t_stack *b, t_chunk *chunk);
void	resolve_chunk(t_stack *a, t_stack *b);
int		shortest_pos(t_node *node, int min, int max);
void	side_decision(t_stack *b, t_chunk chunk);
void	rr_decision(t_stack *a, t_stack *b, t_chunk chunk);

//Solver_utils
void	solver_shorter(t_stack *a, int flag);
int		collect_decision(t_stack *b, t_long data);
int     determine_chunk(t_stack *a);
void	free_elements(t_stack *a, t_stack *b);

#endif
