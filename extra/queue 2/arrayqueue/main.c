#include	"arrayqueue.h"
#include	<stdio.h>
#include	<stdlib.h>

int	main(void)
{
	ArrayQueue	*pQueue;
	ArrayQueueNode	element;

	pQueue = createArrayQueue(10);

	for (int i = 0; i < 4; i++)
	{
		element.data = 'A' + i;
		enqueueAQ(pQueue, element);
	}
	displayArrayQueue(pQueue);

	dequeueAQ(pQueue);
	displayArrayQueue(pQueue);

	printf("peek %c\n", (peekAQ(pQueue))->data);

	element.data = 'E';
	enqueueAQ(pQueue, element);
	displayArrayQueue(pQueue);


	dequeueAQ(pQueue);
	displayArrayQueue(pQueue);


	for (int i = 0; i < 10; i++)
	{
		element.data += 1;
		enqueueAQ(pQueue, element);
	}
	displayArrayQueue(pQueue);


	while (isArrayQueueEmpty(pQueue) == FALSE)
		dequeueAQ(pQueue);
	dequeueAQ(pQueue);
	printf("front %d rear %d\n", pQueue->front, pQueue->rear);
	displayArrayQueue(pQueue);

	element.data = 'a';
	for (int i = 0; i < 11; i++)
	{
		element.data += 1;
		enqueueAQ(pQueue, element);
	}
	displayArrayQueue(pQueue);


	deleteArrayQueue(pQueue);
	pQueue = NULL;
	displayArrayQueue(pQueue);

	system("leaks a.out\n");
	return (0);
}