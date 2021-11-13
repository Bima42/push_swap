#include "push_swap.h"

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
