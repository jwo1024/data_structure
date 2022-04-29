#include	"arrayqueue.h"
#include	<stdlib.h>

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
	ArrayQueueNode	*new_element;

	if (pQueue->currentElementCount == pQueue->maxElementCount)
	{
		printf("ArrayQueue is Full\n");
		return (FALSE);
	}
	new_element = calloc(1, sizeof(ArrayQueueNode));
	if (new_element == NULL)
		return (-1);
	*new_element = element;
	pQueue->;

	return (pQueue->currentElementCount);
}

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue)
{

}

ArrayQueueNode *peekAQ(ArrayQueue* pQueue)
{

}

void deleteArrayQueue(ArrayQueue* pQueue)
{

}