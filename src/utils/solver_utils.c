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
