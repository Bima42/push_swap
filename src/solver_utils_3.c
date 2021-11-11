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
