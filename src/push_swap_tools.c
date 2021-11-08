#include "push_swap.h"

void	swap(t_stack *a)
{
	int	tmp;

	tmp = 0;
	if (a->front == a->tail || a->front == NULL)
		return ;
	else if (a->front && a->front->next)
	{
		tmp = a->front->data;
		a->front->data = a->front->next->data;
		a->front->next->data = tmp;
	}
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
	if (a->front == NULL)
		return ;
	if (b->front == NULL && b->tail == NULL)
	{
		b->front = a->front;
		b->tail = a->front;
		a->front = a->front->next;
		a->front->prev = NULL;
		b->front->next = NULL;
	}
	else if (b->front && b->tail && a->front->next)
	{
		b->front->prev = a->front;
		a->front = a->front->next;
		a->front->prev = NULL;
		b->front->prev->next = b->front;
		b->front = b->front->prev;
	}
	else if (!a->front->next)
	{
		b->front->prev = a->front;
		a->front->next = b->front;
		b->front = b->front->prev;
		a->front = NULL;
		a->tail = NULL;
	}
}


void	rotate(t_stack *a)
{
	if (a->front != a->tail && a->front != NULL && a->tail != NULL)
	{
		a->front->prev = a->tail;
		a->tail->next = a->front;
		a->front = a->front->next;
		a->front->prev->next = NULL;
		a->front->prev = NULL;
		a->tail = a->tail->next;
	}
	else
		return ;
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
	(void)a;
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
