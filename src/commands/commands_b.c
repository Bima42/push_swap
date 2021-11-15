#include "../push_swap.h"

void   sb(t_stack *b)
{
        int     tmp;

        tmp = 0;
        if (b->front == b->tail || b->front == NULL)
                return ;
        else if (b->front && b->front->next)
        {
                tmp = b->front->data;
                b->front->data = b->front->next->data;
                b->front->next->data = tmp;
        }
		write(1, "sb\n", 3);
}

void    rb(t_stack *b)
{
        if (b->front != b->tail && b->front != NULL && b->tail != NULL)
        {
                b->front->prev = b->tail;
                b->tail->next = b->front;
                b->front = b->front->next;
                b->front->prev->next = NULL;
                b->front->prev = NULL;
                b->tail = b->tail->next;
				write(1, "rb\n", 3);
        }
        else
                return ;
}

void    rrb(t_stack *b)
{
        if (b->front != b->tail && b->front != NULL && b->tail != NULL)
        {
                b->tail->next = b->front;
                b->front->prev = b->tail;
                b->tail = b->tail->prev;
                b->tail->next->prev = NULL;
                b->tail->next = NULL;
                b->front = b->front->prev;
				write(1, "rrb\n", 4);
        }
        else
                return ;
}

void   pb(t_stack *a, t_stack *b)
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
                front_tail_null(a);
        }
        write(1, "pb\n", 3);
}
