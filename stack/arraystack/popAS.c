#include	"arraystack.h"

StackNode	*popAS(ArrayStack *pStack)
{
	StackNode	*pop_node;
	
	if (NULLCHECK(pStack))
		return (NULL);
	else if (isArrayStackEmpty(pStack))
	{
		printf("the ArrayStack is empty\n");
		return (NULL);
	}
	pop_node = calloc(1, sizeof(StackNode));
	if (NULLCHECK(pop_node))
		return (NULL);
	*pop_node = pStack->pElement[pStack->currentElementCount - 1];
	(pStack->pElement[pStack->currentElementCount - 1]).data = 0;
	// memeset? 배열 초기화하도록 변경필요
	// data를 직접 초기하는 것보다 memset을 이용한다면 StackNode의 형태가 변하더라도 그대로 사용할수 있다.
	pStack->currentElementCount--;
	return (pop_node);
}