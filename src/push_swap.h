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
    struct s_node *prev;
}               t_node;

typedef struct   s_stack
{
    t_node  *front;
    t_node  *tail;
}               t_stack;

//Create elements
void    display(t_stack *a, t_stack *b);
t_node  *new_node(int data);
t_stack  *new_stack(void);
int     list_size(t_stack *a);

//Parsing
t_stack     *parsing_string(char **argv);
t_stack     *parsing_multi_args(char **argv);
t_stack     *parsing_args(int argc, char **argv);
void    clear(char **array);
int     count_args(char **tmp);

//Command A
void    sa(t_stack *a);
void    ra(t_stack *a);
void    rra(t_stack *a);

//Command B
void    sb(t_stack *b);
void    rb(t_stack *);
void    rrb(t_stack *b);

//Command Both
void    push(t_stack *a, t_stack *b);
void    swap_both(t_stack *a, t_stack *b);
void    rotate_both(t_stack *a, t_stack *b);
void    reverse_rotate_both(t_stack *a, t_stack *b);

int     is_sorted(t_stack *a);
int     is_empty(t_stack *a);
int     is_reverse_sorted(t_stack *a);
void    sort_stack(t_stack *a, t_stack *b);

#endif
