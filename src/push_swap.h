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

typedef struct  s_data_push
{
    int data_1;
    int pos_1;
    int flag_1;
    int data_2;
    int pos_2;
    int flag_2;
}               t_data_push;

//Create elements
void    display(t_stack *a, t_stack *b);
int     list_size(t_node *node);
t_node  *new_node(int data);
t_stack  *new_stack(void);

//Parsing
int         only_whitespace(char **argv);
t_stack     *parsing_string(char **argv);
t_stack     *parsing_multi_args(char **argv);
t_stack     *parsing_args(int argc, char **argv);

//Parsing utils
int     count_args(char **tmp);
int     more_than_one(t_node *check, int data, int count);
int     check_error_args(char **argv);
void    clear(char **array);
void    check_for_dup(t_stack *a);

//Command A
void    sa(t_stack *a);
void    ra(t_stack *a);
void    rra(t_stack *a);
void    pa(t_stack *a, t_stack *b);

//Command B
void    sb(t_stack *b);
void    rb(t_stack *);
void    rrb(t_stack *b);
void    pb(t_stack *b, t_stack *a);

//Command Both
void    front_tail_null(t_stack *a);
void    swap_both(t_stack *a, t_stack *b);
void    rotate_both(t_stack *a, t_stack *b);
void    reverse_rotate_both(t_stack *a, t_stack *b);

//Solver
int     is_sorted(t_stack *a);
int     is_empty(t_stack *a);
int     is_reverse_sorted(t_stack *a);
void    solver(t_stack *a, t_stack *b);
void    solver_short(t_stack *a);
void    solver_med(t_stack *a, t_stack *b);
void    solver_long(t_stack *a, t_stack *b);

//Solver Utils
int     get_min_data(t_node *node);
int     get_max_data(t_node *node);

//Solver Utils 2
int     get_median_data(t_stack *a, int median, int max, int loop);
int     yvan_recursive(int data, int count, t_node *current_node);
void    sort_stack_b(t_stack *b, t_stack *a);

//Solver Utils 2
int     get_pos_data(int min_data, t_node *node);
int     get_next_min_data(int min_data, t_node *node);
void    init_data(t_data_push *data);

//Backup
/*void    sort_stack(t_stack *a, t_stack *b);
void    send_small_data(t_stack *a, t_stack *b);*/

#endif
