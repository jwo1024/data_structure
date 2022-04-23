#include	"arraystack.h"

StackNode	*peekAS(ArrayStack *pStack)
{
	StackNode	*peek_node;

	if (NULLCHECK(pStack))
		return (NULL);
	else if (isArrayStackEmpty(pStack))
	{
		printf("the ArrayStack is empty\n");
		return (NULL);
	}
	peek_node = calloc(1, sizeof(StackNode));
	if (NULLCHECK(peek_node))
		return (NULL);
	*peek_node = pStack->pElement[pStack->currentElementCount - 1];
	return (peek_node);
}

// peek 할때 arraystack 에 속해있는 stacknode 그대로를 주어야하는가?
// 아님 복사를 한 stacknode를 주어야하는 가? 일단 복사를 해서 리턴하자.