#include	"linkedstack.h"

void 		deleteLinkedStack(LinkedStack* pStack)
{
	StackNode	*node;
	StackNode	*next_node;

	if (NULLCHECK(pStack))
		return ;
	node = pStack->pTopElement;
	while (node != NULL)
	{
		next_node = node->pLink;
		free(node);
		node = next_node;
	}
	free(pStack);
}
