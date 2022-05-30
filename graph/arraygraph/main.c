#include	"arraygraph.h"
#include	<stdio.h>
#include	<stdlib.h>

int	traversal_DFS(ArrayGraph *pGraph, int vertexID)
{
	int	*stack;
	int	idx;
	int	vertex;

	if (!pGraph || !checkVertexValid(pGraph, vertexID))
		return (ERROR);
	idx = 0;
	stack = (int *)calloc(pGraph->maxVertexCount, sizeof(int));
	stack[idx] = vertexID;
	pGraph->pVertex[vertexID] = 2;
	printf("traversal_DFS : ");
	while (idx >= 0)
	{
		// 방문 표시를 어떻게? pVertex = 2로 수정
		vertex = stack[idx];
		stack[idx--] = 0;
		// stack 넣을것 있는지 확인 및 넣기
 		for (int i = 0; i < pGraph->maxVertexCount; i++)
		{
			if (pGraph->ppAdjEdge[vertex][i] > 0 && pGraph->pVertex[i] == 1) // edge 가 존재한다면 + visited 가 아니라면
			{
				stack[++idx] = i; // stack 에 넣기
				pGraph->pVertex[i] = 2;
			}
		}
		printf("%d ", vertex);
	}
	printf("\n");
	
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (pGraph->pVertex[i] == 2)
			pGraph->pVertex[i] = 1;
	}
	free (stack);
	return (TRUE);
}

int	traversal_BFS(ArrayGraph *pGraph, int vertexID)
{
	int	*queue;
	int	rear;
	int	front;
	int	vertex;

	if (!pGraph || !checkVertexValid(pGraph, vertexID))
		return (ERROR);
	rear = 0;
	front = 0;
	queue = (int *)calloc(pGraph->maxVertexCount, sizeof(int));
	queue[rear++] = vertexID;
	pGraph->pVertex[vertexID] = 2;
	printf("traversal_BFS : ");
	while (rear != front)
	{
		vertex = queue[front];
		queue[front++] = 0;
		// circular 큐로 할려면 mod 연산 추가
		for (int i = 0; i < pGraph->maxVertexCount; i++)
		{
			if (pGraph->ppAdjEdge[vertex][i] > 0 && pGraph->pVertex[i] == 1) // edge 가 존재한다면 + visited 가 아니라면
			{
				queue[rear++] = i; // stack 에 넣기
				pGraph->pVertex[i] = 2; // visited 는 2로 체크
			}
		}
		printf("%d ", vertex);
	}
	printf("\n");

	// visited 흔적 삭제
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (pGraph->pVertex[i] == 2)
			pGraph->pVertex[i] = 1;
	}
	free (queue);
	return (TRUE);
}

int	main(void)
{

	ArrayGraph *graph;
	ArrayGraph *graph2;

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
	graph = createArrayGraph(10);

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

// removeVertexAG(graph, 3);	

//	removeEdgeAG(graph, 2, 3);

	traversal_DFS(graph, 0);
	traversal_BFS(graph, 0);

	displayArrayGraph(graph);
//	displayArrayGraph(graph2);

	deleteArrayGraph(&graph);

//	system("leaks a.out");

	return (0);
}
