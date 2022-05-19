#ifndef _BIN_TREE_MAX_HEAP_
#define _BIN_TREE_MAX_HEAP_

#include <stdio.h>
#include <stdlib.h>

typedef struct MaxHeapNodeType
{
	char data;
	int	key;
} MaxHeapNode;

typedef struct MaxHeapType
{
	int	currentElementCount;
	int	maxElementCount;
	struct MaxHeapNodeType* pElement;
} MaxHeap;

MaxHeap* makeMaxHeap(int max_size);
int insertMaxHeap(MaxHeap *heap, MaxHeapNode data);
MaxHeapNode *deleteMaxHeap(MaxHeap *heap);
void deleteMaxHeapALL(MaxHeap** heap);

int isMaxHeapEmpty(MaxHeap *heap);
int	isMaxHeapFull(MaxHeap *heap);
void MaxHeapSortPrint();

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

#endif