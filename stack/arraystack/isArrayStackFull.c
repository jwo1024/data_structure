#include	"arraystack.h"

int	isArrayStackFull(ArrayStack* pStack)
{
	if (NULLCHECK(pStack))
		return (ERROR);
	if (pStack->currentElementCount == pStack->maxElementCount)
		return (TRUE);
	else
		return (FALSE);
}