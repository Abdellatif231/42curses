#include "push_swap.h"
#include <stdio.h>

int	main(void)
{
	int	size_a;
	int	size_b;
	int	a[10];
	int	b[10];
	int	i;

	size_a = 5;
	size_b = 4;
	a[10] = {5, 3, 4, 1, 6};
	b[10] = {4, 3, 2, 1};
	i = 0;
	printf("stack a >>>\n");
	while (i < size_a)
		printf("%d\n", a[i++]);
	i = 0;
	printf("stack b >>>\n");
	while (i < size_b)
		printf("%d\n", b[i++]);
	printf("==================\n");
	rr(a, size_a, b, size_b);
	i = 0;
	printf("stack a >>>\n");
	while (i < size_a)
		printf("%d\n", a[i++]);
	i = 0;
	printf("stack b >>>\n");
	while (i < size_b)
		printf("%d\n", b[i++]);
	return (0);
}
