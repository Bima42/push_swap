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
		return ;
}

void	front_tail_null(t_stack *a)
{
	a->front = NULL;
	a->tail = NULL;
}

void	rr(t_stack *a, t_stack *b)
{
	if (b->front->data != b->tail->data && b->front != NULL && b->tail != NULL)
	{
		b->front->prev = b->tail;
		b->tail->next = b->front;
		b->front = b->front->next;
		b->front->prev->next = NULL;
		b->front->prev = NULL;
		b->tail = b->tail->next;
	}
	if (a->front->data != a->tail->data && a->front != NULL && a->tail != NULL)
	{
		a->front->prev = a->tail;
		a->tail->next = a->front;
		a->front = a->front->next;
		a->front->prev->next = NULL;
		a->front->prev = NULL;
		a->tail = a->tail->next;
	}
	write(1, "rr\n", 3);
}
void    rrr(t_stack *a, t_stack *b)
{
	if (b->front != b->tail && b->front != NULL && b->tail != NULL)
	{
		b->tail->next = b->front;
		b->front->prev = b->tail;
		b->tail = b->tail->prev;
		b->tail->next->prev = NULL;
		b->tail->next = NULL;
		b->front = b->front->prev;
	}
	if (a->front != a->tail && a->front != NULL && a->tail != NULL)
	{
		a->tail->next = a->front;
		a->front->prev = a->tail;
		a->tail = a->tail->prev;
		a->tail->next->prev = NULL;
		a->tail->next = NULL;
		a->front = a->front->prev;
	}
	write(1, "rrr\n", 4);
}
