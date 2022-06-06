#include	"./graphlinkedlist/linkedgraph.h"
#include	"./min_heap/min_heap.h"
#include	<stdio.h>
#include	<stdlib.h>

#define		INF 200000000

void 	floyd(LinkedGraph *pGraph, int start);
void	floyd_display_path(int **path, int start, int end);

void floyd(LinkedGraph *pGraph, int start)
{
	int	**dist;
	int	**path; // 최단경로
	ListNode *tmp;

	if (!pGraph || !checkVertexValid(pGraph, start))
		return ;
	/* 초기화 */
	dist = (int **)malloc(sizeof(int *) * pGraph->maxVertexCount);
	path = (int **)calloc(pGraph->maxVertexCount, sizeof(int *));
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		dist[i] = (int *)malloc(sizeof(int) * pGraph->maxVertexCount);
		path[i] = (int *)calloc(pGraph->maxVertexCount, sizeof(int));
		if (checkVertexValid(pGraph, i))
		{
			for (int k = 0; k < pGraph->maxVertexCount; k++)
			{
				tmp = getLLElementGID(pGraph->ppAdjEdge[i], k);
				if (tmp)
				{
					dist[i][k] = tmp->data.weight;
				}
				else
					dist[i][k] = INF;
			}
		}
		else
		{
			for (int k = 0; k < pGraph->maxVertexCount; k++)
			{
				dist[i][k] = INF;
			}
		}

	}

	/* 모든 정점 거리 계산 */
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		for (int k = 0; k < pGraph->maxVertexCount; k++) // 시작점
		{
			for (int j = 0; j < pGraph->maxVertexCount; j++) // 끝점
			{
				if (dist[k][i] != INF && dist[i][j] != INF \
					&& dist[k][i] + dist[i][j] < dist[k][j])
				{
					dist[k][j] = dist[k][i] + dist[i][j];
					path[k][j] = i;
				}
			}
		}
	}

	// 모든 노드의 번호 i에 대해 dist[i][i]가 0인지를 확인하여 음의 사이클 탐지

	/* dist 출력 */
	printf("-----dist-----\n");
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		for (int k = 0; k < pGraph->maxVertexCount; k++)
		{
			if (dist[i][k] != INF)
				printf("%3d ", dist[i][k]);
			else
				printf("%3d ", -1);
		}
		printf("\n");
	}	
	getchar();


	/* 경로 출력 */
	printf("-----path-----\n");
	printf("%d ", start);
	floyd_display_path(path, start, 6); //
	printf("%d\n", 6);
	
	// free()
}


 /* 최단 경로 출력 */
void	floyd_display_path(int **path, int start, int end)
{
	if (path[start][end])
	{
		floyd_display_path(path, start, path[start][end]);
		printf("%d ", path[start][end]);
		//printf("s %d e %d p %d \n", start, end, path[start][end]);
		floyd_display_path(path, path[start][end], end);
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

	floyd(graph2, 1);

//	graph = prim(graph2);

//	displayLinkedGraph(graph);
	
	return (0);
}