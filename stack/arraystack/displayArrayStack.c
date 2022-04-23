#include	"arraystack.h"

void	displayArrayStack(ArrayStack *pStack)
{
	int	idx;

	if (NULLCHECK(pStack))
		return ;
	for (idx = 0; idx < pStack->currentElementCount; idx++)
		printf("Element[%d] : %c\n", idx, (pStack->pElement[idx]).data);
}
