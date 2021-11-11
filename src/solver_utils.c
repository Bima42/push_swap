#include "push_swap.h"

int    is_sorted(t_stack *a)
{
	t_node  *check;

	check = a->front;
	if (a->front == NULL || a->tail == NULL)
			return (1);
	while (check->next != NULL)
	{
		if (check->data < check->next->data)
				check = check->next;
		else
				return (0);
	}
	return (1);
}

int     is_reverse_sorted(t_stack *a)
{
	t_node  *check;

	check = a->front;
	if (a->front == NULL || a->tail == NULL)
			return (1);
	while (check->next != NULL)
	{
		if (check->data > check->next->data)
			check = check->next;
		else
			return (0);
	}
	return (1);
}

int     is_empty(t_stack *a)
{
        if (!a->front && !a->tail)
                return (1);
        return (0);
}
