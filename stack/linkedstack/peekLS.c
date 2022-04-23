#include	"linkedstack.h"

StackNode	*peekLS(LinkedStack* pStack)
{
	if (NULLCHECK(pStack))
		return (NULL);
	if (pStack->pTopElement == NULL)
		printf("the LinkedStack is empty\n");
	return (pStack->pTopElement);
}