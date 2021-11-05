#include "push_swap.h"

void	clear(char **array, int i)
{
        while (i-- > 0)
                free(array[i]);
        free(array);
        return ;
}

int	*parsing_string(char **argv)
{
        char    **tmp;
        int             i;
        int             j;
        int             *swap_a;

        i = 0;
        j = -1;
        tmp = ft_split(argv[1], ' ');
        if (!tmp)
                return (0);
        while (tmp[i])
                i++;
        swap_a = malloc(sizeof(int) * i);
        if (!swap_a)
                return (0);
        while (++j < i)
                swap_a[j] = ft_atoi(tmp[j]);
        clear(tmp, i);
        return (swap_a);
}

int	*parsing_multi_args(char **argv)
{
        int     i;
        int     index_a;
        int     index_args;
        int     *swap_a;

        i = 0;
        index_a = 0;
        index_args = 1;
        while (argv[i])
                i++;
        i -= 1;
        swap_a = malloc(sizeof(int) * i);
        if (!swap_a)
                return (0);
        while (index_a < i)
                swap_a[index_a++] = ft_atoi(argv[index_args++]);
        return (swap_a);
}

int	*parsing_args(int argc, char **argv)
{
        int     *a;

        if (argc == 2)
                a = parsing_string(argv);
        else if (argc > 2)
                a = parsing_multi_args(argv);
        else
                write (1, "error", 5);
        return (a);
}
