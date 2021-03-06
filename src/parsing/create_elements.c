/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpauvret <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:21:30 by tpauvret          #+#    #+#             */
/*   Updated: 2021/11/16 16:24:51 by tpauvret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*new_stack(void)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->front = NULL;
	new->tail = NULL;
	return (new);
}

t_node	*new_node(int data)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

/*void	display(t_stack *a, t_stack *b)
{
	char    *stack_a;
	char    *stack_b;
	t_node  *node_a;
	t_node  *node_b;

    node_a = a->front;
    node_b = b->front;
    stack_a = "---A---";
    stack_b = "---B---";
    printf("%7s ||| %7s\n", stack_a, stack_b);
    while (node_a != NULL && node_b != NULL)
    {
		printf("%7i ||| %7i\n", node_a->data, node_b->data);
		node_a = node_a->next;
		node_b = node_b->next;
    }
    while (node_a)
    {
		printf("%7i ||| XXXXXXX\n", node_a->data);
		node_a = node_a->next;
    }
    while (node_b)
    {
		printf("XXXXXXX ||| %7i\n", node_b->data);
		node_b = node_b->next;
    }
}*/

int	list_size(t_node *node)
{
	int	i;

	i = 0;
	while (node != NULL)
	{
		i++;
		node = node->next;
	}
	return (i);
}
