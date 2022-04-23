#include	"linkedstack.h"

int 		isLinkedStackEmpty(LinkedStack* pStack)
{
	if (NULLCHECK(pStack))
		return (ERROR);
	if (pStack->currentElementCount == 0)
		return (TRUE);
	else
		return (FALSE);
}