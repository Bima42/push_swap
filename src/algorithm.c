#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node	*check;

	check = a->front;
	if (a->front == NULL || a->tail == NULL)
		return (0);
	while (check->next != NULL)
	{
		if (check->data < check->next->data)
			check = check->next;
		else
			return (0);
	}
	return (1);
}

int	is_reverse_sorted(t_stack *a)
{
	t_node	*check;

	check = a->front;
	if (a->front == NULL || a->tail == NULL)
		return (0);
	while (check->next != NULL)
	{
		if (check->data > check->next->data)
			check = check->next;
		else
			return (0);
	}
	return (1);
}

int	is_empty(t_stack *a)
{
	if (!a->front && !a->tail)
		return (1);
	return (0);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	int	max_data_b;
//	if (is_rev_sorted(a))
//		while (!is_sorted(a))
//			ra(a);
	while (!is_sorted(a))
	{
		while (!is_empty(a))
		{
			if (a->front->next != NULL)
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
						push(a, b);
				}
			}
			else
				push(a, b);
			if (!is_reverse_sorted(b))
			{
				if (b->front->data < b->tail->data)
					rrb(b);
				while (b->front->data < max_data_b && b->front->data > b->tail->data)
				{
					rb(b);
					if (is_reverse_sorted(b))
						break ;
					sb(b);
				}
				while (!is_reverse_sorted(b))
					rrb(b);
			}
			if (!is_empty(b))
				max_data_b = b->front->data;
		}
		while (!is_empty(b))
			push(b, a);
	}
}
