#include "push_swap.h"

void   solver_short(t_stack *a)
{
	if (list_size(a->front) == 2 && !is_sorted(a))
			sa(a);
	else if (list_size(a->front) == 3 && !is_sorted(a))
	{
		if (is_reverse_sorted(a))
		{
			sa(a);
			rra(a);
		}
		else if (a->front->data > a->front->next->data && a->front->data > a->tail->data)
		{
			ra(a);
			if (!is_sorted(a))
				sa(a);
		}
		else if (a->front->data < a->front->next->data && a->front->data < a->tail->data)
		{
			ra(a);
			sa(a);
			rra(a);
		}
		else if (a->front->data > a->front->next->data && a->front->data < a->tail->data)
			sa(a);
		else if (a->front->data < a->front->next->data && a->front->data > a->tail->data)
			rra(a);
	}
}

void	move_to(t_stack *a, t_stack *b, int median)
{
	int	count;
	int	size;
	int	count_lower_med;

	count = 0;
	count_lower_med = 0;
	size = list_size(a->front);
	while (count < size && count_lower_med < size / 2)
	{
		if (a->front->data < median)
		{
			pb(a, b);
			sort_stack_b(b, a);
			count_lower_med++;
		}
		else
			ra(a);
		count++;
	}
}

void	solver_med(t_stack *a, t_stack *b)
{
	int min_data;
	int max_data;
	int median;

	min_data = get_min_data(a->front);
	max_data = get_max_data(a->front);
	median = get_median_data(a, min_data, max_data, (list_size(a->front) / 2));
	move_to(a, b, median);
	if (list_size(a->front) <= 3)
	{
		solver_short(a);
		while(!is_empty(b))
			pa(b, a);
	}
}

void	solver_long(t_stack *a, t_stack *b)
{
	t_data data;
	int		pos;

	init(&data, a);

	collect(a, b, data, 1);
	resolve_chunk(a, b);
	while (a->tail->data != data.max_data)
		ra(a);
	collect(a, b, data, 2);
	resolve_chunk(a, b);
	while (a->tail->data != data.max_data)
		rra(a);
	collect(a, b, data, 3);
	resolve_chunk(a, b);
	pos = get_pos_data(data.max_data, a->front);
	while (!is_sorted(a) && pos >= data.lst_size / 2)
		rra(a);
	while (!is_sorted(a) && pos < data.lst_size / 2)
		ra(a);
}

void	solver_turbo_long(t_stack *a, t_stack *b)
{
	t_long data;
	int		pos;

	pos = 0;
	init_long(&data, a);
	collect_long(a, b, data, 1);
	resolve_chunk(a, b);
	while (a->tail->data != data.max)
		ra(a);
	collect_long(a, b, data, 2);
	resolve_chunk(a, b);
	while (a->tail->data != data.max)
		ra(a);
	collect_long(a, b, data, 3);
	resolve_chunk(a, b);
	while (a->tail->data != data.max)
		ra(a);
	collect_long(a, b, data, 4);
	resolve_chunk(a, b);
	while (a->tail->data != data.max)
		ra(a);
	collect_long(a, b, data, 5);
	resolve_chunk(a, b);
	while (a->tail->data != data.max)
		ra(a);
	pos = get_pos_data(data.max, a->front);
	while (!is_sorted(a) && pos > data.size / 2)
	{
		write(1, "ici\n", 4);
		rra(a);
	}
	while (!is_sorted(a) && pos <= data.size / 2)
		ra(a);
}

void	solver(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	if (list_size(a->front) > 3 && is_reverse_sorted(a))
	{
		while (!is_empty(a))
			pb(a, b);
		while (!is_empty(b))
		{
			if (list_size(b->front) != 1)
				rrb(b);
			pa(b, a);
		}
	}
	else if (list_size(a->front) <= 3)
		solver_short(a);
	else if (list_size(a->front) <= 6)
		solver_med(a, b);
	else if (list_size(a->front) <= 100)
		solver_long(a, b);
	else if (list_size(a->front) > 100)
		solver_turbo_long(a, b);
}
