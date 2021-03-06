#ifndef _BIN_TREE_MIN_HEAP_
#define _BIN_TREE_MIN_HEAP_

#include <stdio.h>
#include <stdlib.h>

typedef struct MinHeapNodeType
{
	int	fromVertexID;
	int toVertexID; // vertexID
	int	key; // weight
} MinHeapNode;

typedef struct MinHeapType
{
	int	currentElementCount;
	int	maxElementCount;
	struct MinHeapNodeType* pElement;
} MinHeap;

MinHeap *makeMinHeap(int max_size);
int insertMinHeap(MinHeap *heap, MinHeapNode element);
MinHeapNode *deleteMinHeap(MinHeap *heap);
void deleteMinHeapALL(MinHeap** heap);

int isMinHeapEmpty(MinHeap *heap);
int	isMinHeapFull(MinHeap *heap);
void minHeapSortPrint();

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

#endif