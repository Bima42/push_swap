#include "push_swap.h"

int	get_pos_data(int min_data, t_node *node)
{
	int	pos;

	pos = 0;
	if (node == NULL)
		exit(0);
	while (node != NULL)
	{
		if (node->data == min_data)
			return (pos);
		pos++;
		node = node->next;
	}
	exit(0);
}

int	get_next_min_data(int min_data, t_node *node)
{
	int	next_min_data;

	next_min_data = 2147483647;
	while (node != NULL)
	{
		if (node->data < next_min_data && node->data != min_data)
			next_min_data = node->data;
		node = node->next;
	}
	return (next_min_data);
}

void	init_data(t_data_push *data)
{
	data->data_1 = 0;
	data->pos_1 = 0;
	data->flag_1 = 0;
	data->data_2 = 0;
	data->pos_2 = 0;
	data->flag_2 = 0;
}
