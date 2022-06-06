#include	"./graphlinkedlist/linkedgraph.h"
#include	"./min_heap/min_heap.h"
#include	<stdio.h>
#include	<stdlib.h>

/*무방향 그래프일때를 가정하여 구현*/

LinkedGraph	*kruskal_set_graph(LinkedGraph *graph);
MinHeap *kruskal_set_heap(LinkedGraph *graph);
void	set_union_find(int **union_find, int max, int fromVertexID, int toVertexID);

LinkedGraph *kruskal(LinkedGraph *graph)
{
	LinkedGraph	*T;
	MinHeap *heap;
	MinHeapNode	*heap_node;
	int	**union_find;

	union_find = (int **)calloc(graph->maxVertexCount, sizeof(int *));
	T = kruskal_set_graph(graph);
	heap = kruskal_set_heap(graph);
	while (!isMinHeapEmpty(heap))
	{
		heap_node = deleteMinHeap(heap);
		/* 순환이 발생하지 않을때*/
		if (union_find[heap_node->fromVertexID] == NULL || union_find[heap_node->toVertexID] == NULL\
			|| *union_find[heap_node->fromVertexID] != *union_find[heap_node->toVertexID]) // 함수 하나로 묶어주기
		{
			set_union_find(union_find, graph->maxVertexCount, heap_node->fromVertexID, heap_node->toVertexID);
			addEdgewithWeightAG(T, heap_node->fromVertexID, heap_node->toVertexID, heap_node->key);
		}
	}
	return (T);
}

LinkedGraph	*kruskal_set_graph(LinkedGraph *graph)
{
	LinkedGraph	*T;

	if (!graph)
		return (NULL);
	T = createLinkedGraph(graph->maxVertexCount);
	for (int i = 0; i < graph->maxVertexCount; i++)
	{
		if (checkVertexValid(graph, i))
			addVertexAG(T, i);
	}
	return (T);
}

MinHeap *kruskal_set_heap(LinkedGraph *graph)
{
	MinHeap *heap;
	MinHeapNode	element;
	ListNode	*node;
	int	max;

	max = graph->currentVertexCount * (graph->currentVertexCount - 2);

	heap = makeMinHeap(max);
	for (int i = 0; i < graph->maxVertexCount; i++)
	{
		if (checkVertexValid(graph, i))
		{
			node = graph->ppAdjEdge[i]->headerNode.pLink;
			while (node)
			{
				if (node->data.vertexID > i)
				{
					element.key = node->data.weight;
					element.fromVertexID = i;
					element.toVertexID = node->data.vertexID;
					insertMinHeap(heap, element);
				}
				node = node->pLink;
			}
		}
	}
	return (heap);
}

void	set_union_find(int **union_find, int max, int fromVertexID, int toVertexID)
{
	int	*num;

	if (union_find[fromVertexID] == NULL && union_find[toVertexID] == NULL)
	{
		num = (int *)malloc(sizeof(int));
		*num = (fromVertexID < toVertexID ? fromVertexID : toVertexID);
		union_find[fromVertexID] = num;
		union_find[toVertexID] = num;
	}
	else if (union_find[fromVertexID] == NULL && union_find[toVertexID])
		union_find[fromVertexID] = union_find[toVertexID];
	else if (union_find[fromVertexID] && union_find[toVertexID] == NULL)
		union_find[toVertexID] = union_find[fromVertexID];
	else
	{
		if (union_find[fromVertexID] < union_find[toVertexID])
		{
			num = union_find[toVertexID];
			free(num);
			union_find[toVertexID] = union_find[fromVertexID];
		}
		else
		{
			num = union_find[fromVertexID];
			free(num);
			union_find[fromVertexID] = union_find[toVertexID];
		}
	}
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
	getchar();

	graph = kruskal(graph2);

//	graph = prim(graph2);

	displayLinkedGraph(graph);
	
	return (0);
}