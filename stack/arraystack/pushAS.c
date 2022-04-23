#include	"arraystack.h"

int 		pushAS(ArrayStack *pStack, StackNode element)
{
	if (NULLCHECK(pStack))
		return (ERROR);
	if (isArrayStackFull(pStack))
	{
		printf("the ArrayStack is full\n");
		return (FALSE); //
	}
	pStack->pElement[pStack->currentElementCount] = element;
	return (pStack->currentElementCount++);
}

// maxElementCount 넘었을때 어떻게 할것인지?
// 우선 안되도록 막음