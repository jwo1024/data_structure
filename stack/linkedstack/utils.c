#include "linkedstack.h"

int	NULLCHECK(void *ptr)
{
	if (!ptr)
	{
		printf("null pointer exception\n");
		system("leaks a.out > leaks_result; cat leaks_result | \
        grep leaked && rm -rf leaks_result"); //?
		return (1);
	}
	return (0);
}

int	SAME(int x, int y)
{
	return (x == y ? TRUE : FALSE);
}

int	ZERO(int x)
{
	return (x == 0 ? TRUE : FALSE);
}