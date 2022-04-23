#include	"arraystack.h"

ArrayStack	*createArrayStack(int maxElementCount)
{
	ArrayStack	*new_stack;
	int			i;

	new_stack = calloc(1, sizeof(ArrayStack));
	if (NULLCHECK(new_stack))
		return (NULL);
	new_stack->pElement = calloc(maxElementCount, sizeof(StackNode));
	if (NULLCHECK(new_stack->pElement))
	{
		free(new_stack);
		return (NULL);
	}
	new_stack->currentElementCount = 0;
	new_stack->maxElementCount = maxElementCount;
	for (i = 0; i < new_stack->maxElementCount; i++) // memset
		(new_stack->pElement[i]).data = 0;
	return (new_stack);
}