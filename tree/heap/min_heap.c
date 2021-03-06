#include	"min_heap.h"

MinHeap* makeMinHeap(int max_size)
{
	MinHeap *newHeap;

	newHeap = (MinHeap *)calloc(1, sizeof(MinHeap));
	newHeap->pElement = (MinHeapNode *)calloc(max_size + 1, sizeof(MinHeapNode));
	newHeap->maxElementCount = max_size;
	return (newHeap);
}

int insertMinHeap(MinHeap *heap, MinHeapNode data)
{
	int	i;

	if (!heap || isMinHeapFull(heap))
		return (0);
	heap->currentElementCount++;
	i = heap->currentElementCount;
	while((i != 1) && (data.key < heap->pElement[i/2].key))
	{
		heap->pElement[i] = heap->pElement[i/2];
		i = i / 2;
	}
	heap->pElement[i] = data;
	return (1);
}

MinHeapNode *deleteMinHeap(MinHeap *heap)
{
	MinHeapNode	*result;
	MinHeapNode	tmp;
	int i, parent, child;

	if (!heap || isMinHeapEmpty(heap))
		return (NULL);
	result = (MinHeapNode *)calloc(1, sizeof(MinHeapNode));
	*result = heap->pElement[1];
	i = heap->currentElementCount;
	tmp = heap->pElement[i];
	heap->currentElementCount--;
	parent = 1;
	child = 2;
	while (child <= heap->currentElementCount)
	{
		if ((child < heap->currentElementCount) 
			&& heap->pElement[child].key > heap->pElement[child + 1].key)
			child++;
		if (tmp.key <= heap->pElement[child].key)
			break;
		heap->pElement[parent] = heap->pElement[child];
		parent = child;
		child *= 2;
	}
	heap->pElement[parent] = tmp;
	return (result);
}

void deleteMinHeapALL(MinHeap** heap)
{
	MinHeapNode node;

	if (!heap || !(*heap))
		return ;
	free((*heap)->pElement);
	free(*heap);
	*heap = NULL;
}


void minHeapSortPrint()
{
	int	cnt;
	int	key;
	char data;
	MinHeapNode node;
	MinHeapNode	*pNode;
	MinHeap *heap;

	/*insert 입력*/
	printf("the number of data : ");
	scanf(" %d", &cnt);
	heap = makeMinHeap(cnt);
	for (int i = 1; i <= cnt; i++)
	{	
		printf("\ninsert %d\n", i);
		printf("key(num) : ");
		scanf(" %d", &key);
		printf("data(char) : ");
		scanf(" %c", &data);
		node.key = key;
		node.data = data;
		insertMinHeap(heap, node);
	}

	/*(정렬된 순서로) 삭제 및 출력*/
	printf("\n-----print sort------\n");
	while (!isMinHeapEmpty(heap))
	{
		pNode = deleteMinHeap(heap);
		printf("key %d data %c \n", pNode->key, pNode->data);
		free(pNode);
	}
	deleteMinHeapALL(&heap);
}

int isMinHeapEmpty(MinHeap *heap)
{
	if (heap && heap->currentElementCount == 0)
		return (1);
	return (0);
}

int	isMinHeapFull(MinHeap *heap)
{
	if (heap && heap->currentElementCount == heap->maxElementCount)
	{
		printf("min heap is full\n");
		return (1);
	}
	return (0);
}

int	main(void)
{
/*
	MinHeap *heap;
	MinHeapNode	node;
	MinHeapNode	*tmp;

	node.data = 'a';
	node.key = 3;
	heap = makeMinHeap(10);
	insertMinHeap(heap, node);
	node.key = 2;
	insertMinHeap(heap, node);
	node.key = 6;
	insertMinHeap(heap, node);
	node.key = 1;
	insertMinHeap(heap, node);
	node.key = 2; // 0
	insertMinHeap(heap, node);


	printf("print heap array\n");
	for (int i = 1; i <= heap->currentElementCount; i++)
	{
		printf("i[%d] heap key %d\n", i, (heap->pElement[i]).key);
	}

	deleteMinHeapALL(&heap);
*/

	/*
	for (int i = 1; heap->currentElementCount; i++)
	{
		tmp = deleteMinHeap(heap);
		printf("i[%d] delete node %d\n", i, tmp->key);
	}/*/

	minHeapSortPrint();


	return (0);
}