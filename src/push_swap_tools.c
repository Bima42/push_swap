#include "push_swap.h"

void	swap(int *stack)
{
	int	i;
	int tmp;

	i = 0;
	tmp = 0;
	while (stack[i])
		i++;
	if (i > 1)
	{
		tmp = stack[0];
		stack[0] = stack[1];
		stack[1] = tmp;
	}
}
