#include "push_swap.h"

int    get_median_data(t_stack *a, int median, int max, int loop)
{
	t_node	*node;
	int     new_med;

	node = a->front;
	new_med = max;
	while (node != NULL)
	{
		if (node->data < max && node->data > median && node->data < new_med)
				new_med = node->data;
		node = node->next;
	}
	if (loop > 1)
		return (get_median_data(a, new_med, max, --loop));
	else
		return (new_med);
}

void   sort_stack_b(t_stack *b, t_stack *a)
{
	int     search_pos;
	int     i;

	if (b->front != NULL && b->tail != NULL)
	{
		if (b->front->data < b->tail->data)
			rb(b);
		else
		{
			i = 0;
			search_pos = yvan_recursive(b->front->data, 0, b->front);
			if (search_pos > 1)
				pa(b, a);
			while (i++ < search_pos)
			{
				if (search_pos <= 1)
					sb(b);
				rb(b);
			}
			if (search_pos > 1)
				pb(a, b);
			while (search_pos-- > 0)
				rrb(b);
		}
	}
}

int    yvan_recursive(int data, int count, t_node *current_node)
{
	if (current_node->next == NULL)
		return (count);
	if (data < current_node->next->data)
		return (yvan_recursive(data, count + 1, current_node->next));
	return (count);
}
