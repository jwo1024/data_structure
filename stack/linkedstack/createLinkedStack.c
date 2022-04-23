#include	"linkedstack.h"

LinkedStack	*createLinkedStack()
{
	LinkedStack *pStack;

	pStack = calloc(1, sizeof(LinkedStack));
	if (NULLCHECK(pStack))
		return (NULL);
	pStack->currentElementCount = 0;
	pStack->pTopElement = NULL;
	return (pStack);
}