#include "push_swap.h"

static void	clear(char **array, int i)
{
	while (i-- > 0)
		free(array[i]);
	free(array);
	return ;
}


int main(int argc, char **argv)
{
	char	**ret;
	int	*tab_i;
	int	i = 0;
	int	j = 0;

	(void)ret;
	(void)tab_i;
	if (argc == 2)
	{
		ret = ft_split(argv[1], ' ');
		while (ret[i])
			i++;
		tab_i = malloc(sizeof(int) * i);
		if (!tab_i)
			return (0);
		while (j < i)
		{
			tab_i[j] = ft_atoi(ret[j]);
			printf("tab_i[%d] = %d\n", j, tab_i[j]);
			j++;
		}
		clear(ret, i);
	}
	else
		write (1, "error", 5);
	return (0);
}
