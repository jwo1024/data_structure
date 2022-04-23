#include	"arraystack.h"

int	isArrayStackEmpty(ArrayStack* pStack)
{
	if (NULLCHECK(pStack))
		return (ERROR);
	if (pStack->currentElementCount == 0)
		return (TRUE);
	else
		return (FALSE);
}
