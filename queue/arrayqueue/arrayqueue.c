#include	"arrayqueue.h"
#include	<stdlib.h>
#include	<string.h>

ArrayQueue* createArrayQueue(int maxElementCount)
{
	ArrayQueue	*new_queue;

	new_queue = calloc(1, sizeof(ArrayQueue));
	if (new_queue == NULL)
		return (NULL);
	new_queue->pElement = calloc(maxElementCount, sizeof(ArrayQueueNode));
	if (new_queue->pElement == NULL)
	{
		free(new_queue);
		return (NULL);
	}
	new_queue->currentElementCount = 0;
	new_queue->maxElementCount = maxElementCount;
	new_queue->front = 0;
	new_queue->rear = 0;
	return (new_queue);
}

int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
	if (isArrayQueueFull(pQueue))
	{
		printf("ArrayQueue is Full\n");
		return (FALSE);
	}
	pQueue->pElement[pQueue->rear] = element;
	pQueue->rear = (pQueue->rear + 1) % pQueue->maxElementCount;
	pQueue->currentElementCount++;
	return (pQueue->currentElementCount);
}

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue)
{
	ArrayQueueNode *de_node;

	if (isArrayQueueEmpty(pQueue))
	{
		printf("ArrayQueue is Empty\n");
		return (FALSE);
	}
	de_node = calloc(1, sizeof(ArrayQueueNode));
	if (de_node == NULL)
		return (NULL);
	*de_node = pQueue->pElement[pQueue->front];
	memset(&pQueue->pElement[pQueue->front], 0, sizeof(ArrayQueueNode));
	pQueue->front = (pQueue->front + 1) % pQueue->maxElementCount;
	pQueue->currentElementCount--;
	return (de_node);
}

ArrayQueueNode *peekAQ(ArrayQueue* pQueue)
{
	ArrayQueueNode	*peek_node;

	if (isArrayQueueEmpty(pQueue))
	{
		printf("ArrayQueue is Empty\n");
		return (FALSE);
	}
	peek_node = calloc(1, sizeof(ArrayQueueNode));
	if (peek_node == NULL)
		return (NULL);
	*peek_node = pQueue->pElement[pQueue->front];
	return (peek_node);
}

void deleteArrayQueue(ArrayQueue* pQueue)
{
	if (pQueue == NULL)
		return;
	if (pQueue->pElement != NULL)
		free(pQueue->pElement);
	free(pQueue);
}

int isArrayQueueFull(ArrayQueue* pQueue)
{
	if (pQueue == NULL)
		return (-1);
	if (pQueue->currentElementCount == pQueue->maxElementCount)
		return (TRUE);
	return (FALSE);
}

int isArrayQueueEmpty(ArrayQueue* pQueue)
{
	if (pQueue == NULL)
		return (-1);
	if (pQueue->currentElementCount == 0)
		return (TRUE);
	return (FALSE);
}