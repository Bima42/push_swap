#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = parsing_args(argc, argv);
	b = malloc(sizeof(t_stack));
	display(a);
	printf("-----\n");
	rotate(a);
	display(a);
	printf("-----\n");
	push(a, b);
	display(a);
	printf("-----\n");
	display(b);
	printf("-----\n");
	printf("-----\n");
	push(a, b);
	display(a);
	printf("-----\n");
	display(b);
	printf("-----\n");
	printf("-----\n");
	rotate(a);
	rotate(b);
	display(a);
	printf("-----\n");
	display(b);
	printf("-----\n");
}
