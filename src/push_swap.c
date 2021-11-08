#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = parsing_args(argc, argv);
	b = new_stack();

	display(a, b);
	push(a, b);
	display(a, b);

	push(a, b);
	display(a, b);

	swap_both(a, b);
	display(a, b);

	reverse_rotate(a);
	reverse_rotate(b);
	display(a, b);

	reverse_rotate_both(a, b);
	display(a, b);
}
