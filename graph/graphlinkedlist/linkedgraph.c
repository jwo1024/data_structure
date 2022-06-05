#include	"linkedgraph.h"
#include	<stdlib.h>
#include	<stdio.h>

LinkedGraph* createLinkedGraph(int maxVertexCount)
{
	LinkedGraph *newLinkedGraph;

	newLinkedGraph = (LinkedGraph *)malloc(sizeof(LinkedGraph));
	newLinkedGraph->maxVertexCount = maxVertexCount;
	newLinkedGraph->currentVertexCount = 0;
	newLinkedGraph->graphType = 1;
	newLinkedGraph->ppAdjEdge = (LinkedList **)calloc(maxVertexCount, sizeof(LinkedList *));
	newLinkedGraph->pVertex = (int *)calloc(maxVertexCount, sizeof(int));
	return (newLinkedGraph);
}

LinkedGraph* createLinkedDirectedGraph(int maxVertexCount)
{
	LinkedGraph *newLinkedGraph;

	newLinkedGraph = (LinkedGraph *)malloc(sizeof(LinkedGraph));
	newLinkedGraph->maxVertexCount = maxVertexCount;
	newLinkedGraph->currentVertexCount = 0;
	newLinkedGraph->graphType = 1;
	newLinkedGraph->ppAdjEdge = (LinkedList **)calloc(maxVertexCount, sizeof(LinkedList *));
	newLinkedGraph->pVertex = (int *)calloc(maxVertexCount, sizeof(int));
	return (newLinkedGraph);
}

void deleteLinkedGraph(LinkedGraph** pGraph)
{
	if (!pGraph || !(*pGraph))
		return ;
	for (int i = 0; i < (*pGraph)->maxVertexCount; i++)
	{
		if (checkVertexValid(*pGraph, i))
			deleteLinkedList(&((*pGraph)->ppAdjEdge[i]));
	}
	free((*pGraph)->ppAdjEdge);
	free((*pGraph)->pVertex);
	free(*pGraph);
	(*pGraph) = NULL;
}

int isEmptyAG(LinkedGraph* pGraph)
{
	if (!pGraph)
		return (ERROR);
	if (pGraph->currentVertexCount == 0)
		return (TRUE);
	return (FALSE);
}

int addVertexAG(LinkedGraph* pGraph, int vertexID)
{
	if (!pGraph || checkVertexValid(pGraph, vertexID)) // 이미 존재한다면 
		return (ERROR);
	pGraph->ppAdjEdge[vertexID] = createLinkedList();
	pGraph->pVertex[vertexID] = 1;
	pGraph->currentVertexCount++;
	return (TRUE);
}


int addEdgeAG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	ListNode	element;

	if (!pGraph || !checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (ERROR);
	if (pGraph->graphType != 1)
		return (ERROR);
	element.data.vertexID = toVertexID;
	element.data.weight = 1;
	addLLElement(pGraph->ppAdjEdge[fromVertexID], pGraph->ppAdjEdge[fromVertexID]->currentElementCount, element);// position을 어디로 주어야하나?
	if (pGraph->graphType == 1)
	{
		element.data.vertexID = fromVertexID;
		element.data.weight = 1;
		addLLElement(pGraph->ppAdjEdge[toVertexID], pGraph->ppAdjEdge[toVertexID]->currentElementCount, element);
	}
	return (TRUE);
}

int addEdgewithWeightAG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	LinkedList	*pLList;
	ListNode	element;

	if (!pGraph || !checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID)) // + 두 vertex 가 존재한느지
		return (ERROR);
	if (pGraph->graphType != 2)
		return (ERROR);
	pLList = pGraph->ppAdjEdge[fromVertexID];
	element.data.vertexID = toVertexID;
	element.data.weight = weight;
	addLLElement(pLList, pLList->currentElementCount, element);// position을 어디로 주어야하나?
	if (pGraph->graphType == 1)
	{
		pLList = pGraph->ppAdjEdge[toVertexID];
		element.data.vertexID = fromVertexID;
		element.data.weight = weight;
		addLLElement(pLList, pLList->currentElementCount, element);
	}
	return (TRUE);
}

int checkVertexValid(LinkedGraph* pGraph, int vertexID)
{
	if (!pGraph)
		return (ERROR);
	if (pGraph->pVertex[vertexID] == 1)
		return (TRUE);
	return (FALSE);
}

int removeVertexAG(LinkedGraph* pGraph, int vertexID)
{
	if  (!pGraph || !checkVertexValid(pGraph, vertexID))
		return (ERROR);
	pGraph->pVertex[vertexID] = 0;
	deleteLinkedList(&(pGraph->ppAdjEdge[vertexID]));
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (checkVertexValid(pGraph, i))
			removeLLElementGID(pGraph->ppAdjEdge[i], vertexID);
	}
	pGraph->currentVertexCount--;
	return (TRUE);
}

int removeEdgeAG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (!pGraph || !checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (ERROR);
	removeLLElementGID(pGraph->ppAdjEdge[fromVertexID], toVertexID);
	if (pGraph->graphType == 1)
	{
		removeLLElementGID(pGraph->ppAdjEdge[toVertexID], fromVertexID);
	}
	return (TRUE);
}

void displayLinkedGraph(LinkedGraph* pGraph)
{
	ListNode	*node;

	if (!pGraph)
		return ;
	printf("valid vertex : ");
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (checkVertexValid(pGraph, i)) // vertex
			printf("%d ", i);
	}
	printf("\n---------------------------------------\n");

/*
	printf("     ");
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		printf("%3d", i);
	printf("\n---------------------------------------\n");
*/
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		printf("%2d | ", i);
		if (checkVertexValid(pGraph, i))
		{
			node = pGraph->ppAdjEdge[i]->headerNode.pLink;
			while (node)
			{
				printf("%d ", node->data.vertexID);
				node = node->pLink;
			}
		}
		printf("\n");
	}
}

int	main(void)
{
	LinkedGraph *graph;
	LinkedGraph *graph2;

/*
// 방향
	graph2 = createArrayDirectedGraph(10);

	addVertexAG(graph2, 1);
	addVertexAG(graph2, 2);
	addVertexAG(graph2, 3);
	addVertexAG(graph2, 4);
	addVertexAG(graph2, 5);
	addVertexAG(graph2, 6);


	addEdgewithWeightAG(graph2, 1, 2, 10);
	addEdgewithWeightAG(graph2, 2, 1, 10);

	addEdgewithWeightAG(graph2, 2, 3, 10);
	addEdgewithWeightAG(graph2, 3, 2, 10);
	addEdgewithWeightAG(graph2, 3, 4, 10);
	addEdgewithWeightAG(graph2, 4, 3, 10);
	addEdgewithWeightAG(graph2, 4, 5, 10);
	addEdgewithWeightAG(graph2, 5, 6, 10);
	addEdgewithWeightAG(graph2, 6, 3, 10);

*/

//	removeVertexAG(graph2, 5);

//	traversal_DFS(graph2, 3);

// 무방향
	graph = createLinkedGraph(10);

	addVertexAG(graph, 0);
	addVertexAG(graph, 1);
	addVertexAG(graph, 2);
	addVertexAG(graph, 3);
	addVertexAG(graph, 4);
	addVertexAG(graph, 5);
	addVertexAG(graph, 6);
	addVertexAG(graph, 7);
	addVertexAG(graph, 8);
	addVertexAG(graph, 9);


	addEdgeAG(graph, 0, 1);
	addEdgeAG(graph, 1, 3);
	addEdgeAG(graph, 1, 2);
	addEdgeAG(graph, 2, 3);
	addEdgeAG(graph, 2, 4);
	addEdgeAG(graph, 3, 4);
	addEdgeAG(graph, 3, 5);
	addEdgeAG(graph, 5, 7);
	addEdgeAG(graph, 5, 6);
	addEdgeAG(graph, 6, 8);
	addEdgeAG(graph, 6, 9);


// removeVertexAG(graph, 3);	

//	removeEdgeAG(graph, 2, 3);

//	traversal_DFS(graph, 0);
//	traversal_BFS(graph, 0);

	displayLinkedGraph(graph);

//	removeEdgeAG(graph, 2, 3);
	removeVertexAG(graph, 3);
//	printf("cc %d\n\n", graph->pVertex[2]);

	displayLinkedGraph(graph);
//	displayArrayGraph(graph2);

	deleteLinkedGraph(&graph);

//	system("leaks a.out");
	return (0);
}