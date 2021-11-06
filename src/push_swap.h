#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct  s_node
{
    int data;
    struct s_node *next;
}               t_node;

typedef struct   s_stack
{
    t_node  *front;
}               t_stack;

void    clear(char **array, int i);
void    display(t_stack *a);
t_stack     *parsing_string(char **argv);
t_stack     *parsing_multi_args(char **argv);
t_stack     *parsing_args(int argc, char **argv);

void    swap(int *stack);

#endif
