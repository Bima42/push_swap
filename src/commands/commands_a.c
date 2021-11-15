#include "../push_swap.h"

void   sa(t_stack *a)
{
	int     tmp;

	tmp = 0;
	if (a->front == a->tail || a->front == NULL)
		return ;
	else if (a->front && a->front->next)
	{
		tmp = a->front->data;
		a->front->data = a->front->next->data;
		a->front->next->data = tmp;
	}
	write(1, "sa\n", 3);
}

void    ra(t_stack *a)
{
	if (a->front != a->tail && a->front != NULL && a->tail != NULL)
	{
		a->front->prev = a->tail;
		a->tail->next = a->front;
		a->front = a->front->next;
		a->front->prev->next = NULL;
		a->front->prev = NULL;
		a->tail = a->tail->next;
		write(1, "ra\n", 3);
	}
	else
		return ;
}

void	rra(t_stack *a)
{
	if (a->front != a->tail && a->front != NULL && a->tail != NULL)
	{
		a->tail->next = a->front;
		a->front->prev = a->tail;
		a->tail = a->tail->prev;
		a->tail->next->prev = NULL;
		a->tail->next = NULL;
		a->front = a->front->prev;
		write(1, "rra\n", 4);
	}
	else
		return ;
}

void   pa(t_stack *b, t_stack *a)
{
        if (b->front == NULL)
                return ;
        if (a->front == NULL && a->tail == NULL)
        {
                a->front = b->front;
                a->tail = b->front;
                b->front = b->front->next;
                b->front->prev = NULL;
                a->front->next = NULL;
        }
        else if (a->front && a->tail && b->front->next)
        {
                a->front->prev = b->front;
                b->front = b->front->next;
                b->front->prev = NULL;
                a->front->prev->next = a->front;
                a->front = a->front->prev;
        }
        else if (!b->front->next)
        {
                a->front->prev = b->front;
                b->front->next = a->front;
                a->front = a->front->prev;
                front_tail_null(b);
        }
        write(1, "pa\n", 3);
}
