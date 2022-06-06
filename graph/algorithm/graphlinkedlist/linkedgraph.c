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
	ListNode	element;

	if (!pGraph || !checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID)) // + 두 vertex 가 존재한느지
		return (ERROR);
	element.data.vertexID = toVertexID;
	element.data.weight = weight;
	addLLElement(pGraph->ppAdjEdge[fromVertexID], pGraph->ppAdjEdge[fromVertexID]->currentElementCount, element);// position을 어디로 주어야하나?
	if (pGraph->graphType == 1)
	{
		element.data.vertexID = fromVertexID;
		element.data.weight = weight;
		addLLElement(pGraph->ppAdjEdge[toVertexID], pGraph->ppAdjEdge[toVertexID]->currentElementCount, element);
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
		
		if (checkVertexValid(pGraph, i))
		{
			printf("%2d | ", i);
			node = pGraph->ppAdjEdge[i]->headerNode.pLink;
			while (node)
			{
				printf("%d[%d] ", node->data.vertexID, node->data.weight);
				node = node->pLink;
			}
			printf("\n");
		}
	}
}
