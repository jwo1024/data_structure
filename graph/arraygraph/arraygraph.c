#include	"arraygraph.h"
#include	<stdlib.h>
#include	<stdio.h>

ArrayGraph* createArrayGraph(int maxVertexCount)
{
	ArrayGraph *newArrayGraph;

	newArrayGraph = (ArrayGraph *)malloc(sizeof(ArrayGraph));
	newArrayGraph->maxVertexCount = maxVertexCount;
	newArrayGraph->currentVertexCount = 0;
	newArrayGraph->graphType = 1;
	newArrayGraph->ppAdjEdge = (int **)calloc(maxVertexCount, sizeof(int *));
	newArrayGraph->pVertex = (int *)calloc(maxVertexCount, sizeof(int));
	return (newArrayGraph);
}

ArrayGraph* createArrayDirectedGraph(int maxVertexCount)
{
	ArrayGraph *newArrayGraph;

	newArrayGraph = (ArrayGraph *)malloc(sizeof(ArrayGraph));
	newArrayGraph->maxVertexCount = maxVertexCount;
	newArrayGraph->currentVertexCount = 0;
	newArrayGraph->graphType = 2;
	newArrayGraph->ppAdjEdge = (int **)calloc(maxVertexCount, sizeof(int *));
	newArrayGraph->pVertex = (int *)calloc(maxVertexCount, sizeof(int));
	return (newArrayGraph);
}


void deleteArrayGraph(ArrayGraph** pGraph)
{
	if (!pGraph || !(*pGraph))
		return;
	for (int i = 0; i < (*pGraph)->maxVertexCount; i++)
	{
		if ((*pGraph)->ppAdjEdge[i])
			free((*pGraph)->ppAdjEdge[i]);
	}
	free((*pGraph)->ppAdjEdge);
	free((*pGraph)->pVertex);
	free(*pGraph);
	(*pGraph) = NULL;
}

int isEmptyAG(ArrayGraph* pGraph)
{
	if (!pGraph)
		return (ERROR);
	if (pGraph->currentVertexCount == 0)
		return (TRUE);
	return (FALSE);
}


int addVertexAG(ArrayGraph* pGraph, int vertexID)
{
	if (!pGraph || checkVertexValid(pGraph, vertexID)) // 이미 존재한다면 
		return (ERROR);
	pGraph->ppAdjEdge[vertexID] = (int *)calloc(pGraph->maxVertexCount, sizeof(int)); 
	pGraph->pVertex[vertexID] = 1;
	pGraph->currentVertexCount++;
	return (TRUE);
}


int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (!pGraph || !checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (ERROR);
	if (pGraph->graphType != 1)
		return (ERROR);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = 1;
	if (pGraph->graphType == 1)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = 1;
	return (TRUE); // 무엇을 반환해야하나
}

// 가중치랑 방향 그래프는 다른것임 혼동해서 처리한것 고치기
int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	if (!pGraph || !checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (ERROR);
	if (pGraph->graphType != 2)
		return (ERROR);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
	if (pGraph->graphType == 1)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
	return (TRUE);
}

int checkVertexValid(ArrayGraph* pGraph, int vertexID) // 유효성 검사,, 
{
	if (!pGraph)
		return (ERROR);
	if (pGraph->pVertex[vertexID] == 1)
		return (TRUE);
	return (FALSE);
}

int removeVertexAG(ArrayGraph* pGraph, int vertexID)
{
	if  (!pGraph || !checkVertexValid(pGraph, vertexID))
		return (ERROR);
	pGraph->pVertex[vertexID] = 0;
	free(pGraph->ppAdjEdge[vertexID]);
	pGraph->ppAdjEdge[vertexID] = NULL;
	// 해당 vertex로의 edge를 가지고 있는 노드의 edge도 지워주는것 추가
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (pGraph->ppAdjEdge[i])
			pGraph->ppAdjEdge[i][vertexID] = 0;
	}
	pGraph->currentVertexCount--;
	return (TRUE);
}


int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (!pGraph || !checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (ERROR);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = 0;
	if (pGraph->graphType == 1)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = 0;
	return (TRUE);
}

void displayArrayGraph(ArrayGraph* pGraph)
{
	if (!pGraph)
		return ;
	printf("valid vertex : ");
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (checkVertexValid(pGraph, i)) // vertex
			printf("%d ", i);
	}
	printf("\n---------------------------------------\n");
	printf("     ");
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		printf("%3d", i);
	printf("\n---------------------------------------\n");

	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		printf("%2d | ", i);
		if (checkVertexValid(pGraph, i))
		{
			for (int k = 0; k < pGraph->maxVertexCount; k++)
				printf("%3d", pGraph->ppAdjEdge[i][k]);
		}
		else
		{
			for (int k = 0; k < pGraph->maxVertexCount; k++)
				printf("%3d", 0);
		}
		printf("\n");
	}
}

