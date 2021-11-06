#include "push_swap.h"

void   display(t_stack *a)
{
        t_node  *temp;

        if (a->front == NULL)
        {
                write(1, "\nStack Overflow", 15);
        }
        else
        {
                temp = a->front;
                while (temp != NULL)
                {
                        printf("%d\n", temp->data);
                        temp = temp->next;
                }
        }
}

t_stack *parsing_string(char **argv)
{
        t_stack *a;
        t_node  *temp;
        int             i;
        char    **tmp;

        a = malloc(sizeof(t_stack));
        a->front = NULL;
        i = 0;
        tmp = ft_split(argv[1], ' ');
        if (!tmp)
                        return (0);
        while (tmp[i])
                        i++;
        i -= 1;
        while (i >= 0)
        {
                temp = malloc(sizeof(t_node));
                temp->data = ft_atoi(tmp[i]);
                if (a->front == NULL)
                        temp->next = NULL;
                else
                        temp->next = a->front;
                a->front = temp;
                i--;
        }
        return (a);
}

t_stack *parsing_multi_args(char **argv)
{
        t_stack *a;
        t_node  *temp;
        int     i;

        i = 1;
        a = malloc(sizeof(t_stack));
        a->front = NULL;
		while (argv[i])
			i++;
		i -= 1;
        while (i > 0)
        {
                temp = malloc(sizeof(t_node));
                temp->data = ft_atoi(argv[i]);
                if (a->front == NULL)
                        temp->next = NULL;
                else
                        temp->next = a->front;
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
