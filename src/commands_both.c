#include "push_swap.h"

void	swap_both(t_stack *a, t_stack *b)
{
	if (a->front && a->front->next
			&& b->front && b->front->next)
	{
		sa(a);
		sb(b);
	}
	else
		write(1, "Swap impossible\n", 16);
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

void	rotate_both(t_stack *a, t_stack *b)
{
	if (a->front != a->tail && b->front != b->tail)
	{
		ra(a);
		rb(b);
	}
	else
		write(1, "Rotate impossible\n", 18);
}

void	reverse_rotate_both(t_stack *a, t_stack *b)
{
	if (a->front != a->tail && b->front != b->tail)
	{
		rra(a);
		rrb(b);
	}
	else
		write(1, "Reverse rotate impossible\n", 26);
}
