/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_both.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpauvret <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:10:05 by tpauvret          #+#    #+#             */
/*   Updated: 2021/11/16 18:33:57 by tpauvret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ss(t_stack *a, t_stack *b)
{
	int	tmp;
	int	temp;

	tmp = 0;
	temp = 0;
	if ((a->front == a->tail || a->front == NULL)
		&& (b->front == b->tail || b->front == NULL))
		return ;
	else if (a->front && a->front->next && b->front && b->front->next)
	{
		tmp = a->front->data;
		a->front->data = a->front->next->data;
		a->front->next->data = tmp;
		temp = b->front->data;
		b->front->data = b->front->next->data;
		b->front->next->data = temp;
		write(1, "ss\n", 3);
	}
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

void	rrr(t_stack *a, t_stack *b)
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
