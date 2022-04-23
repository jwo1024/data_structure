#include	"linkedstack.h"

void		displayLinkedStack(LinkedStack *pStack)
{
	StackNode	*node;

	if (NULLCHECK(pStack))
		return ;
	if (pStack->currentElementCount == 0)//
		printf("empty");
	node = pStack->pTopElement;
	while (node != NULL)
	{
		if (node->pLink != NULL)
			printf("%c ", node->data);
		else
			printf("%c\n", node->data);
		node = node->pLink;
	}
}