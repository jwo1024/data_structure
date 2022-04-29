#include "Maze.h"

Stack	*createStack()
{
	Stack	*newStack;

	newStack = calloc(1, sizeof(Stack));
	if (NULLCHECK(newStack))
		return (NULL);
	newStack->pTopElement = NULL;
	newStack->currentElementCount = 0;
	return (newStack);
}

int	isStackEmpty(Stack *stack)
{
	return (stack->currentElementCount == 0 ? TRUE : FALSE);
}

int	pushLS(Stack *stack, MapNode node) // 노드 복사, 스택에 넣음
{
	MapNode	*newNode;

	newNode = calloc(1, sizeof(MapNode));
	if (NULLCHECK(newNode))
		return (ERROR);
	newNode->x = node.x;
	newNode->y = node.y;
	newNode->dist = node.dist;
	newNode->func = node.func;
	newNode->next = stack->pTopElement;
	if (stack->currentElementCount == 0)
		newNode->next = NULL;
	stack->pTopElement = newNode;
	stack->currentElementCount++;
	return (TRUE);
}

MapNode	*popLS(Stack *stack) // 노드 꺼내서 stack 의 탑노드 변경
{
	MapNode *popNode;

	if (NULLCHECK(stack))
		return (NULL);
	if (stack->currentElementCount == 0)
		return (NULL);
	popNode = stack->pTopElement;
	stack->pTopElement = popNode->next;
	stack->currentElementCount--;
	if (stack->currentElementCount == 0)
		popNode->next = NULL;
	return (popNode);
}

void	deleteLS(Stack *stack)
{
	int		idx;
	MapNode	*delNode;
	MapNode	*nextNode;

	if (NULLCHECK(stack))
		return ;
	idx = stack->currentElementCount;
	delNode = stack->pTopElement;
	while (idx-- && delNode)
	{
		nextNode = delNode->next;
		free(delNode);
		delNode = nextNode;
	}
	free(stack);
}

Stack	*dupStack()
{
	return (NULL);
}