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

void	push(t_stack *a, t_stack *b)
{
	t_node	*node_push;

	node_push = malloc(sizeof(t_node));
	node_push->data = a->front->data;
	if (a->front)
	{
		if (b->front == NULL)
		{
			node_push->next = NULL;
			b->tail = node_push;
		}
		else if (b->front)
		{
			node_push->next = b->front;
		}
		b->front = node_push;
		a->front = a->front->next;
	}
	else
		write(1, "Push impossible\n", 16);
}


void	rotate(t_stack *a)
{
	t_node	*tmp;

	if (a->front != a->tail)
	{
		tmp = malloc(sizeof(t_node));
		tmp->data = a->front->data;
		tmp->next = NULL;
		tmp->prev = a->tail;
		a->front = a->front->next;
		a->tail->next = tmp;
		a->tail = tmp;
	}
	else
		write(1, "Rotate impossible\n", 18);
}

void	rotate_both(t_stack *a, t_stack *b)
{
	if (a->front != a->tail && b->front != b->tail)
	{
		rotate(a);
		rotate(b);
	}
	else
		write(1, "Rotate impossible\n", 18);
}

void	reverse_rotate(t_stack *a)
{
	t_node	*tmp;

	if (a->front != a->tail)
	{
		tmp = malloc(sizeof(t_node));
		tmp->data = a->tail->data;
		tmp->next = a->front;
		tmp->prev = NULL;
		a->tail = a->tail->prev;
		a->tail->next = NULL;
		a->front->prev = tmp;
		a->front = tmp;
	}
	else
		write(1, "Reverse rotate impossible\n", 26);
}

void	reverse_rotate_both(t_stack *a, t_stack *b)
{
	if (a->front != a->tail && b->front != b->tail)
	{
		rotate(a);
		rotate(b);
	}
	else
		write(1, "Reverse rotate impossible\n", 26);
}
