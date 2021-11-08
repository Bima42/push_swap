#include "push_swap.h"

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
        }
        else
                return ;
}
