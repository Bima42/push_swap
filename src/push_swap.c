#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = parsing_args(argc, argv);
	b = malloc(sizeof(t_stack));
	printf("---DISPLAY-A--\n");
	display(a);
	printf("---ROTATE-A---\n");
	rotate(a);
	display(a);
	printf("---PUSH-A-IN-B--\n");
	push(a, b);
	printf("---STACK-A--\n");
	display(a);
	printf("---STACK-B--\n");
	display(b);
	printf("---------------\n");
	printf("---PUSH-A-IN-B---\n");
	push(a, b);
	printf("----STACK-A---\n");
	display(a);
	printf("----STACK-B---\n");
	display(b);
	printf("--ROTATE-A-AND-B--\n");
	rotate_both(a, b);
	printf("----STACK-A---\n");
	display(a);
	printf("----STACK-B---\n");
	display(b);
	printf("----REVERSE-ROTATE-B---\n");
	reverse_rotate(b);
	display(b);
	printf("----REVERSE-ROTATE-A---\n");
	reverse_rotate(a);
	display(a);
	printf("----REVERSE-ROTATE-BOTH----\n");
	reverse_rotate_both(a, b);
	printf("---STACK-A--\n");
	display(a);
	printf("---STACK-B--\n");
	display(b);
	free(a);
	free(b);
}
