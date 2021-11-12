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
	t_data_push data;
	int			size;
	int			i;

	while (list_size(a->front) > 6)
	{
		i = 1;
		init_data(&data);
		size = list_size(a->front);
		data.data_1 = get_min_data(a->front);
		data.data_2 = get_next_min_data(data.data_1, a->front);
		data.pos_1 = get_pos_data(data.data_1, a->front) + 1;
		data.pos_2 = get_pos_data(data.data_2, a->front) + 1;
        if (data.pos_1 >= size / 2)
            while (a->front->data != data.data_1)
			{
				if (a->front->data == data.data_2)
				{
					data.flag_2 = i++;
					pb(a, b);
				}
                rra(a);
			}
        if (data.pos_1 <= size / 2)
            while (a->front->data != data.data_1)
			{
				if (a->front->data == data.data_2)
				{
					data.flag_2 = i++;
					pb(a, b);
				}
                ra(a);
			}
        pb(a, b);
		if (data.flag_2 == 1)
			sb(b);
	}
	solver_med(a, b);
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
	else if (list_size(a->front) > 6)
		solver_long(a, b);
}
