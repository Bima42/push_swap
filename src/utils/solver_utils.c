/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpauvret <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:59:40 by tpauvret          #+#    #+#             */
/*   Updated: 2021/11/16 18:09:39 by tpauvret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	solver_shorter(t_stack *a, int flag)
{
	if (flag == 1)
	{
		sa(a);
		rra(a);
	}
	else if (flag == 0)
	{
		ra(a);
		sa(a);
		rra(a);
	}
}

int	collect_decision(t_stack *b, t_long data)
{
	if (list_size(b->front) > 1 && (b->front->data == data.max
			|| b->front->data == data.min || b->front->data == data.low
			|| b->front->data == data.high))
		return (1);
	return (0);
}

void	free_elements(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (a->front != NULL)
	{
		while (a->front->next != NULL)
		{
			tmp = a->front;
			a->front = a->front->next;
			free(tmp);
		}
		free(a->front);
	}
	if (b->front != NULL)
	{
		while (b->front->next != NULL)
		{
			tmp = b->front;
			b->front = b->front->next;
			free(tmp);
		}
		free(b->front);
	}
}

int	determine_chunk(t_stack *a)
{
	int	size;
	int	chunk;

	chunk = 1;
	size = list_size(a->front);
	if (size < 25)
		return (chunk);
	else if (size <= 50)
		return (++chunk);
	else if (size <= 100)
		return (4);
	else if (size <= 200)
		return (5);
	else if (size <= 300)
		return (6);
	else if (size <= 400)
		return (7);
	else if (size <= 500)
		return (8);
	else if (size <= 1000)
		return (12);
	else if (size >= 1000)
		return (16);
	exit(0);
}
