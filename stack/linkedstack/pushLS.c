#include	"linkedstack.h"

int	pushLS(LinkedStack* pStack, StackNode element)
{
	StackNode* new_node;

	if (NULLCHECK(pStack))
		return (ERROR);
	new_node = calloc(1, sizeof(StackNode));
	if (NULLCHECK(new_node))
		return (ERROR);
	new_node->data = element.data;
	new_node->pLink = pStack->pTopElement;
	pStack->pTopElement = new_node;
	return (pStack->currentElementCount++);
}