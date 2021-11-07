#include "push_swap.h"

void	swap(t_stack *a)
{
	t_node	*tmp;

	if (a->front && a->front->next)
	{
		tmp = malloc(sizeof(t_node));
		tmp->data = a->front->next->data;
		a->front->next->data = a->front->data;
		a->front->data = tmp->data;
		free(tmp);
	}
	else
		write(1, "Swap impossible\n", 16);
}

void	swap_both(t_stack *a, t_stack *b)
{
	if (a->front && a->front->next
			&& b->front && b->front->next)
	{
		swap(a);
		swap(b);
	}
	else
		write(1, "Swap impossible\n", 16);
}

int	list_size(t_stack *a)
{
	int	i;

	i = 0;
	while (a->front)
	{
		i++;
		a->front = a->front->next;
	}
	return (i);
}
