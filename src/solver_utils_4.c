#include "push_swap.h"

void   smart_way_decision(t_stack *a, t_data *data, int zone)
{
	if (zone == 3)
	{
			data->front = get_by(a->front, data->min_data, data->median_low, 1);
			data->tail = get_by(a->tail, data->min_data, data->median_low, -1);
	}
	if (zone == 2)
	{
			data->front = get_by(a->front, data->median_low, data->median_high, 1);
			data->tail = get_by(a->tail, data->median_low, data->median_high, -1);
	}
	if (zone == 1)
	{
			data->front = get_by(a->front, data->median_high, data->max_data, 1);
			data->tail = get_by(a->tail, data->median_high, data->max_data, -1);
	}
}

int	shortest_pos(t_node *node, int min, int max)
{
	int	i;

	i = 1;
	while (node != NULL)
	{
		if (node->data == min || node->data == max)
			return (i);
		i++;
		node = node->next;
	}
	return (0);
}

void	init_chunk(t_stack *b, t_chunk *chunk)
{
	chunk->size = list_size(b->front);
	chunk->min = get_min_data(b->front);
	chunk->max = get_max_data(b->front);
	chunk->pos = 0;
}
