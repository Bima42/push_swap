#include "../push_swap.h"

void   init_long(t_long *data, t_stack *a, int chunk)
{
	data->size = list_size(a->front);
	data->min = get_min_data(a->front);
	data->max = get_max_data(a->front);
	data->low = 0;
	data->high = 0;
	data->front = 0;
	data->tail = 0;
	data->mult = chunk - 1;
	data->zone = 0;
	data->to_front = 0;
}

int	get_by(t_node *node, int lower_bound, int higher_bound, int from)
{
	int	i;

	i = 1;
	while (node != NULL && from == 1)
	{
		if (node->data >= lower_bound && node->data <= higher_bound)
			return (i);
		i++;
		node = node->next;
	}
	while (node != NULL && from == -1)
	{
		if (node->data >= lower_bound && node->data <= higher_bound)
			return (i);
		i++;
		node = node->prev;
	}
	return (0);
}

void   set_median_low(t_long *data, t_stack *a, int nb_chunk)
{
	if (data->high != data->max)
		data->to_front = get_next_min_data(data->high, a->front);
	if (data->mult == 0)
	{
		data->low = data->min;
		return ;
	}
	data->low = get_median_data(a, data->min, data->max, (data->size / nb_chunk) * data->mult);
	data->mult -= 1;
}

int   smart_way_long(t_stack *a, t_long data, int *step)
{
	data.front = get_by(a->front, data.low, data.high, 1);
	data.tail = get_by(a->tail, data.low, data.high, -1);
	if (data.front < data.tail)
	{
		*step = data.front;
		return (1);
	}
	else if (data.front > data.tail)
	{
		*step = data.tail;
		return (-1);
	}
	else if (data.front == 0 && data.front == 0)
	{
		*step = 0;
		return (0);
	}
	else
	{
		*step = data.front;
		return (1);
	}
}

void collect(t_stack *a, t_stack *b, t_long data)
{
	int     way;
	int     step;

	way = 1;
	step = 0;
	while (way)
	{
		way = smart_way_long(a, data, &step);
		if (way == 1 && step != 0)
		{
			while (--step)
				ra(a);
			pb(a, b);
			if (list_size(b->front) > 1 && (b->front->data == data.max || b->front->data == data.min
					|| b->front->data == data.low || b->front->data == data.high))
				rb(b);
		}
		else if (way == -1 && step != 0)
		{
			while (step--)
				rra(a);
			pb(a, b);
			if (list_size(b->front) > 1 && (b->front->data == data.max || b->front->data == data.min
					|| b->front->data == data.low || b->front->data == data.high))
				rb(b);
		}
	}
}
