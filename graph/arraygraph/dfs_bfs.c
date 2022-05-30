#include	"arraygraph.h"
#include	<stdio.h>
#include	<stdlib.h>

/*DFS 깊이 우선 탐색*/
int	traversal_DFS(ArrayGraph *pGraph, int vertexID)
{
	int	*stack;
	int	idx;
	int	vertex;

//	visited 배열을 만들어서 설정 
	if (!pGraph || !checkVertexValid(pGraph, vertexID))
		return (ERROR);
	idx = 0;
	stack = (int *)calloc(pGraph->maxVertexCount, sizeof(int));
	stack[idx] = vertexID;
	pGraph->pVertex[vertexID] = 2;
	printf("traversal_DFS : ");
	while (idx >= 0)
	{
		vertex = stack[idx]; //pop
		stack[idx--] = 0;
		// stack 넣을것 있는지 확인 및 넣기
 		for (int i = 0; i < pGraph->maxVertexCount; i++)
		{
			if (pGraph->ppAdjEdge[vertex][i] > 0 && pGraph->pVertex[i] == 1) // edge 가 존재한다면 + visited 가 아니라면
			{
				stack[++idx] = i; // push
				pGraph->pVertex[i] = 2; // 방문 pVertex = 2로 수정
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

/*BFS 너비우선 탐색*/
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
		vertex = queue[front]; // out
		queue[front++] = 0;
		for (int i = 0; i < pGraph->maxVertexCount; i++)
		{
			if (pGraph->ppAdjEdge[vertex][i] > 0 && pGraph->pVertex[i] == 1) // edge 가 존재한다면 + visited 가 아니라면
			{
				queue[rear++] = i; // insert
				pGraph->pVertex[i] = 2; // visited 는 2로
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
