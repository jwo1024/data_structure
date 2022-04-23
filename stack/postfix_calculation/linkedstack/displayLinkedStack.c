#include	"linkedstack.h"

void		displayLinkedStack(LinkedStack *pStack)
{
	StackNode	*node;

	if (NULLCHECK(pStack))
		return ;
	if (pStack->pTopElement == NULL)
		printf("the LinkedStack is empty\n");
	node = pStack->pTopElement;
	while (node != NULL) 
	{
		if (node->pLink != NULL)
			printf("%d ", node->data);
		else
			printf("%d\n", node->data);
		node = node->pLink;
	}
}