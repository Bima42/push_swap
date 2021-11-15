#include "../push_swap.h"

void	init_chunk(t_stack *b, t_chunk *chunk)
{
	chunk->size = list_size(b->front);
	chunk->min = get_min_data(b->front);
	chunk->max = get_max_data(b->front);
	chunk->pos = 0;
}

void   resolve_chunk(t_stack *a, t_stack *b)
{
	t_chunk chunk;

	init_chunk(b, &chunk);
	chunk.pos = shortest_pos(b->front, chunk.min, chunk.max);
	while (!is_empty(b))
	{
		if (chunk.pos <= chunk.size / 2)
			while (b->front->data != chunk.min && b->front->data != chunk.max)
				rb(b);
		else if (chunk.pos > chunk.size / 2)
			while (b->front->data != chunk.min && b->front->data != chunk.max)
				rrb(b);
		if (b->front->data == chunk.min)
		{
			pa(b, a);
			if (is_empty(b))
				break ;
			init_chunk(b, &chunk);
			chunk.pos = shortest_pos(b->front, chunk.min, chunk.max);
			if (chunk.pos <= chunk.size / 2 && chunk.pos != 1)
				rr(a, b);
			else
				ra(a);
		}
		else if (b->front->data == chunk.max)
		{
			pa(b, a);
			if (is_empty(b))
				break ;
			init_chunk(b, &chunk);
			chunk.pos = shortest_pos(b->front, chunk.min, chunk.max);
		}
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
