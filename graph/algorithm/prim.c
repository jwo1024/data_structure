#include	"./graphlinkedlist/linkedgraph.h"
#include	"./min_heap/min_heap.h"
#include	<stdio.h>
#include	<stdlib.h>

/* 무방향 그래프 전제 */
LinkedGraph *prim(LinkedGraph *graph);
int	prim_insert_heap(LinkedGraph *graph, MinHeap *heap, int vertexID);

LinkedGraph *prim(LinkedGraph *graph)
{
	LinkedGraph	*T;
	MinHeap *heap;
	MinHeapNode	*heap_node;
	int	vertexID;

	/* 초기화 */
	T = createLinkedGraph(graph->maxVertexCount);
	heap = makeMinHeap(graph->maxVertexCount);
	for (int i = 0; i < graph->maxVertexCount; i++)
	{
		if (checkVertexValid(graph, i))
		{
			vertexID = i;
			break;
		}
	}
	addVertexAG(T, vertexID);
	prim_insert_heap(graph, heap, vertexID);

	while (!isMinHeapEmpty(heap))
	{
		heap_node = deleteMinHeap(heap);
	
		if (!checkVertexValid(T, heap_node->toVertexID))
		{				
			vertexID = heap_node->toVertexID;
			addVertexAG(T, vertexID);
			addEdgewithWeightAG(T, heap_node->fromVertexID, vertexID, heap_node->key);
			prim_insert_heap(graph, heap, vertexID);
			free(heap_node);
		}
		else if (heap_node)
			free(heap_node);
	}

	return (T);
}

int	prim_insert_heap(LinkedGraph *graph, MinHeap *heap, int vertexID)
{
	MinHeapNode element;
	LinkedList	*list;
	ListNode	*node;

	list = graph->ppAdjEdge[vertexID];
	element.fromVertexID = vertexID;
	for (int i = 0; i < list->currentElementCount; i++)
	{
		node = getLLElement(list, i); //
		element.toVertexID = node->data.vertexID;
		element.key = node->data.weight;
		// 겹치는 edge 가 있는지? // 나중에 빼올때 신경써보자
		insertMinHeap(heap, element);
	}
	return (TRUE);
}

int	main(void)
{
	LinkedGraph *graph;
	LinkedGraph *graph2;


	graph2 = createLinkedDirectedGraph(10);

	addVertexAG(graph2, 1);
	addVertexAG(graph2, 2);
	addVertexAG(graph2, 3);
	addVertexAG(graph2, 4);
	addVertexAG(graph2, 5);
	addVertexAG(graph2, 6);


	addEdgewithWeightAG(graph2, 1, 2, 3);
//	addEdgewithWeightAG(graph2, 2, 1, 10); // linked에서 이중으로 쓰여지는것 고치기

//	addEdgewithWeightAG(graph2, 2, 3, 10);
	addEdgewithWeightAG(graph2, 3, 2, 2);
///	addEdgewithWeightAG(graph2, 3, 4, 10);
	addEdgewithWeightAG(graph2, 4, 3, 1);
	addEdgewithWeightAG(graph2, 4, 5, 10);
	addEdgewithWeightAG(graph2, 5, 6, 9);
	addEdgewithWeightAG(graph2, 6, 3, 8);

	displayLinkedGraph(graph2);

	graph = prim(graph2);

	displayLinkedGraph(graph);
	
	return (0);
}