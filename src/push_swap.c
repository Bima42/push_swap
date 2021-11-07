#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = parsing_args(argc, argv);
	b = parsing_args(argc, argv);
	swap_both(a, b);
	display(a);
	display(b);
}
