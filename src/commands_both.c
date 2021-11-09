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

void	rotate_both(t_stack *a, t_stack *b)
{
	if (a->front != a->tail && b->front != b->tail)
	{
		ra(a);
		rb(b);
	}
	else
		return ;
}

void	reverse_rotate_both(t_stack *a, t_stack *b)
{
	if (a->front != a->tail && b->front != b->tail)
	{
		rra(a);
		rrb(b);
	}
	else
		return ;
}
