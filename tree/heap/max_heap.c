#include	"max_heap.h"

MaxHeap* makeMaxHeap(int max_size)
{
	MaxHeap *newHeap;

	newHeap = (MaxHeap *)calloc(1, sizeof(MaxHeap));
	newHeap->pElement = (MaxHeapNode *)calloc(max_size + 1, sizeof(MaxHeapNode));
	newHeap->maxElementCount = max_size;
	return (newHeap);
}

int insertMaxHeap(MaxHeap *heap, MaxHeapNode element)
{
	int	i;

	if (!heap || isMaxHeapFull(heap))
		return (0);
	heap->currentElementCount++;
	i = heap->currentElementCount;
	while((i != 1) && (element.key > heap->pElement[i/2].key))
	{
		heap->pElement[i] = heap->pElement[i/2];
		i = i / 2;
	}
	heap->pElement[i] = element;
	return (1);
}

MaxHeapNode *deleteMaxHeap(MaxHeap *heap)
{
	MaxHeapNode	*result;
	MaxHeapNode	tmp;
	int i, parent, child;

	if (!heap || isMaxHeapEmpty(heap))
		return (NULL);
	result = (MaxHeapNode *)calloc(1, sizeof(MaxHeapNode));
	*result = heap->pElement[1];
	i = heap->currentElementCount;
	tmp = heap->pElement[i];
	heap->currentElementCount--;
	parent = 1;
	child = 2;
	while (child <= heap->currentElementCount)
	{
		if ((child < heap->currentElementCount) 
			&& heap->pElement[child].key < heap->pElement[child + 1].key)
			child++;
		if (tmp.key >= heap->pElement[child].key)
			break;
		heap->pElement[parent] = heap->pElement[child];
		parent = child;
		child *= 2;
	}
	heap->pElement[parent] = tmp;
	return (result);
}

void deleteMaxHeapALL(MaxHeap** heap)
{
	MaxHeapNode node;

	if (!heap || !(*heap))
		return ;
	free((*heap)->pElement);
	free(*heap);
	*heap = NULL;
}

void MaxHeapSortPrint()
{
	int	cnt;
	int	key;
	char data;
	MaxHeapNode node;
	MaxHeapNode	*pNode;
	MaxHeap *heap;

	/*insert 입력*/
	printf("the number of data : ");
	scanf(" %d", &cnt);
	heap = makeMaxHeap(cnt);
	for (int i = 1; i <= cnt; i++)
	{	
		printf("\ninsert %d\n", i);
		printf("key(num) : ");
		scanf(" %d", &key);
		printf("data(char) : ");
		scanf(" %c", &data);
		node.key = key;
		node.data = data;
		insertMaxHeap(heap, node);
	}

	/*(정렬된 순서로) 삭제 및 출력*/
	while (!isMaxHeapEmpty(heap))
	{
		pNode = deleteMaxHeap(heap);
		printf("key %d data %c \n", pNode->key, pNode->data);
		free(pNode);
	}
	deleteMaxHeapALL(&heap);
}

int isMaxHeapEmpty(MaxHeap *heap)
{
	if (heap && heap->currentElementCount == 0)
		return (1);
	return (0);
}

int	isMaxHeapFull(MaxHeap *heap)
{
	if (heap && heap->currentElementCount == heap->maxElementCount)
	{
		printf("Max heap is full\n");
		return (1);
	}
	return (0);
}

int	main(void)
{
/*
	MaxHeap *heap;
	MaxHeapNode	node;
	MaxHeapNode	*tmp;

	node.data = 'a';
	node.key = 3;
	heap = makeMaxHeap(10);
	insertMaxHeap(heap, node);
	node.key = 2;
	insertMaxHeap(heap, node);
	node.key = 6;
	insertMaxHeap(heap, node);
	node.key = 1;
	insertMaxHeap(heap, node);
	node.key = 2; // 0
	insertMaxHeap(heap, node);


	printf("print heap array\n");
	for (int i = 1; i <= heap->currentElementCount; i++)
	{
		printf("i[%d] heap key %d\n", i, (heap->pElement[i]).key);
	}

	deleteMaxHeapALL(&heap);
*/

	/*
	for (int i = 1; heap->currentElementCount; i++)
	{
		tmp = deleteMaxHeap(heap);
		printf("i[%d] delete node %d\n", i, tmp->key);
	}/*/

	MaxHeapSortPrint();

//	system("leaks a.out");
	
	return (0);
}