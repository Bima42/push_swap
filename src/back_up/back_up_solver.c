#include "push_swap.h"

void	send_small_data(t_stack *a, t_stack *b)
{
	if (a->front->data > a->front->next->data)
	{
		if (a->front->data > a->tail->data)
			rra(a);
		else
			sa(a);
	}
	if (a->front->data < a->front->next->data)
	{
		if (a->front->data > a->tail->data)
			rra(a);
		else
			pb(a, b);
	}
}

void	sort_stack_b(t_stack *b)
{
	int	search_pos;
	int	i;

	if (b->front->data < b->tail->data)
		rb(b);
	else
	{
		i = 0;
		search_pos = yvan_recursive(b->front->data, 0, b->front);
		while (i++ < search_pos)
		{
			sb(b);
			rb(b);
		}
		while (search_pos-- > 0)
			rrb(b);
	}
}

void	sort_stack(t_stack *a, t_stack *b)
{

	while (!is_sorted(a))
	{
		while (!is_empty(a))
		{
			if (a->front->next != NULL)
				send_small_data(a, b);
			else
				pb(a, b);
			if (!is_reverse_sorted(b) && b->front != NULL && b->tail != NULL)
				sort_stack_b(b);
		}
		while (!is_empty(b))
			pa(b, a);
	}
}
