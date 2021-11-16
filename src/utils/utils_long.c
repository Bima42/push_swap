/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpauvret <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:45:51 by tpauvret          #+#    #+#             */
/*   Updated: 2021/11/16 18:37:49 by tpauvret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_long(t_long *data, t_stack *a, int chunk)
{
	data->size = list_size(a->front);
	data->min = get_min_data(a->front);
	data->max = get_max_data(a->front);
	data->low = 0;
	data->high = 0;
	data->front = 0;
	data->tail = 0;
	data->mult = chunk - 1;
	data->zone = 0;
	data->to_front = 0;
}

int	get_by(t_node *node, t_long data, int from)
{
	int	i;

	i = 1;
	while (node != NULL && from == 1)
	{
		if (data.low == data.min)
			if (node->data >= data.low && node->data <= data.high)
				return (i);
		if (node->data > data.low && node->data <= data.high)
			return (i);
		i++;
		node = node->next;
	}
	while (node != NULL && from == -1)
	{
		if (data.low == data.min)
			if (node->data >= data.low && node->data <= data.high)
				return (i);
		if (node->data > data.low && node->data <= data.high)
			return (i);
		i++;
		node = node->prev;
	}
	return (0);
}

void	set_median_low(t_long *data, t_stack *a, int nb_chunk)
{
	if (data->high != data->max)
		data->to_front = get_next_min_data(data->high, a->front);
	if (data->mult == 0)
	{
		data->low = data->min;
		return ;
	}
	data->low = get_median_data(a, data->min, data->max,
			(data->size / nb_chunk) * data->mult);
	data->mult -= 1;
}

int	smart_way_long(t_stack *a, t_long data, int *step)
{
	data.front = get_by(a->front, data, 1);
	data.tail = get_by(a->tail, data, -1);
	if (data.front < data.tail)
	{
		*step = data.front;
		return (1);
	}
	else if (data.front > data.tail)
	{
		*step = data.tail;
		return (-1);
	}
	else if (data.front == 0 && data.front == 0)
	{
		*step = 0;
		return (0);
	}
	else
	{
		*step = data.front;
		return (1);
	}
}

void	collect(t_stack *a, t_stack *b, t_long data)
{
	int	way;
	int	step;

	way = 1;
	step = 0;
	while (way)
	{
		way = smart_way_long(a, data, &step);
		if (way == 1 && step != 0)
		{
			while (--step)
				ra(a);
			pb(a, b);
			if (collect_decision(b, data))
				rb(b);
		}
		else if (way == -1 && step != 0)
		{
			while (step--)
				rra(a);
			pb(a, b);
			if (collect_decision(b, data))
				rb(b);
		}
	}
}
