#include "push_swap.h"

void	init(t_data *data, t_stack *a)
{
	data->lst_size = list_size(a->front);
	data->min_data = get_min_data(a->front);
	data->max_data = get_max_data(a->front);
	data->median_low = get_median_data(a, data->min_data, data->max_data, (data->lst_size / 3));
	data->median_high = get_median_data(a, data->min_data, data->max_data, (data->lst_size / 3) * 2);
	data->front = 0;
	data->tail = 0;
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

int	smart_way(t_stack *a, t_data data, int zone, int *step)
{
        smart_way_decision(a, &data, zone);
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

void	collect(t_stack *a, t_stack *b, t_data data, int zone)
{
	int	way;
	int	step;

	way = 1;
	step = 0;
	while (way)
	{
		way = smart_way(a, data, zone, &step);
		if (way == 1 && step != 0)
		{
			while (--step)
				ra(a);
			pb(a, b);
			if (list_size(b->front) >= 1 && (b->front->data == data.max_data || b->front->data == data.min_data
					|| b->front->data == data.median_low || b->front->data == data.median_high))
				rb(b);
		}
		else if (way == -1)
		{
			while (step--)
				rra(a);
			pb(a, b);
			if (list_size(b->front) >= 1 && (b->front->data == data.max_data || b->front->data == data.min_data
					|| b->front->data == data.median_low || b->front->data == data.median_high))
				rb(b);
		}
	}
}

void	resolve_chunk(t_stack *a, t_stack *b)
{
	t_chunk chunk;

	while (!is_empty(b))
	{
		init_chunk(b, &chunk);
		chunk.pos = shortest_pos(b->front, chunk.min, chunk.max);
		if (chunk.pos <= chunk.size / 2)
			while (b->front->data != chunk.min && b->front->data != chunk.max)
				rb(b);
		else if (chunk.pos > chunk.size / 2)
			while (b->front->data != chunk.min && b->front->data != chunk.max)
				rrb(b);
		if (b->front->data == chunk.min)
		{
			pa(b, a);
			ra(a);
		}
		else if (b->front->data == chunk.max)
			pa(b, a);
	}
}
