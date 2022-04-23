#include	"linkedstack.h"

StackNode	*popLS(LinkedStack* pStack)
{
	StackNode	*rtn;

	if (NULLCHECK(pStack))
		return (NULL);
	rtn = NULL;
	if (pStack->pTopElement == NULL)
		printf("the LinkedStack is empty\n");
	else
	{
		rtn = pStack->pTopElement;
		pStack->pTopElement = rtn->pLink;
		pStack->currentElementCount--;
	}
	return (rtn);
}
