#include "push_swap.h"

t_stack *new_stack(void)
{
        t_stack *new;

        new = malloc(sizeof(t_stack));
        new->front = NULL;
        new->tail = NULL;
        return (new);
}

t_node  *new_node(int data)
{
        t_node  *new;

        new = malloc(sizeof(t_node));
        if (!new)
                return (NULL);
        new->data = data;
        new->next = NULL;
        new->prev = NULL;
        return (new);
}

void    display(t_stack *a, t_stack *b)
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
}

t_stack *parsing_string(char **argv)
{
	t_stack *a;
	t_node  *temp;
	int             i;
	char    **tmp;

	a = new_stack();
	i = 0;
	tmp = ft_split(argv[1], ' ');
	if (!tmp)
		return (0);
	while (tmp[i])
		i++;
	i -= 1;
	while (i >= 0)
	{
		temp = new_node(ft_atoi(tmp[i]));
		if (a->front == NULL)
			a->tail = temp;
		else
		{
			temp->next = a->front;
			a->front->prev = temp;
		}
		a->front = temp;
		i--;
	}
	clear(tmp);
	return (a);
}

t_stack *parsing_multi_args(char **argv)
{
	t_stack *a;
	t_node  *temp;
	int     i;

	a = new_stack();
	i = 1;
	while (argv[i])
		i++;
	i -= 1;
	while (i > 0)
	{
		temp = new_node(ft_atoi(argv[i]));
		if (a->front == NULL)
			a->tail = temp;
		else
		{
			temp->next = a->front;
			a->front->prev = temp;
		}
		a->front = temp;
		i--;
	}
	return (a);
}

t_stack *parsing_args(int argc, char **argv)
{

        if (argc == 2)
                return (parsing_string(argv));
        else if (argc > 2)
                return (parsing_multi_args(argv));
        else
        {
                write(1, "error\n", 6);
                return (0);
        }
        return (0);
}

void	clear(char **array)
{
	int	i;
	i = 0;

	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
