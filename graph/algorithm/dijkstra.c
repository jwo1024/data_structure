#include	"./graphlinkedlist/linkedgraph.h"
#include	<stdio.h>
#include	<stdlib.h>

#define	INF 200000000 

void dijkstra_display_path(int *path, int start);
void dijkstra(LinkedGraph *pGraph, int start);

void dijkstra(LinkedGraph *pGraph, int start)
{
	LinkedGraph *visited;
	ListNode	*list_node;
	int	*dist;
	int	*path;

	int	fromVertexID;
	int	toVertexID;
	int	*stack;
	int	idx;


	if (!pGraph || !checkVertexValid(pGraph, start))
		return ;
	/* 초기화 */
	idx = 0;
	stack = (int *)calloc(pGraph->maxVertexCount, sizeof(int));
	visited = createLinkedGraph(pGraph->maxVertexCount);
	dist = (int *)malloc(sizeof(int) * pGraph->maxVertexCount);
	path = (int *)malloc(sizeof(int) * pGraph->maxVertexCount);
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		dist[i] = INF;
		path[i] = -1;
	}
	stack[idx] = start;
	dist[start] = 0;

	/* 탐색 및 최단거리 갱신 */
	while (idx >= 0)
	{
		fromVertexID = stack[idx]; // pop
		stack[idx--] = 0;
		addVertexAG(visited, fromVertexID);
		list_node = pGraph->ppAdjEdge[fromVertexID]->headerNode.pLink;
		printf("from %d\n", fromVertexID);
		while (list_node)
		{
			toVertexID = list_node->data.vertexID;
			if (dist[toVertexID] > dist[fromVertexID] + list_node->data.weight) // 최단거리 갱신
			{
				printf("from %d to %d \n", fromVertexID, toVertexID);
				dist[toVertexID] = dist[fromVertexID] + list_node->data.weight;
				path[toVertexID] = fromVertexID; // toVertex의 선행 vertexID 저장
			}
			if (!checkVertexValid(visited, toVertexID)) // visitied 가 아닐때
				stack[++idx] = toVertexID; // push
			list_node = list_node->pLink;
		}
	}

	/* 출력 */
	for (int i; i < pGraph->maxVertexCount; i++)
		printf("%d에서 %d 최단거리 %d\n", start, i, dist[i]);
	for (int i; i < pGraph->maxVertexCount; i++)
		dijkstra_display_path(path, i);
	

	deleteLinkedGraph(&visited);
	free(stack);
	free(dist);
	free(path);
}

void dijkstra_display_path(int *path, int end)
{
	int	vertexID;

	if (path[end] == -1)
		return;
	vertexID = end;
	printf("------ dikstar path ------\n");
	printf("%d ", vertexID);
	vertexID = path[vertexID];
	while (vertexID != end && vertexID != -1)
	{
		printf("<- %d ", vertexID);
		vertexID = path[vertexID];
	}
	printf("\n");
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

	dijkstra(graph2, 1);

//	graph = prim(graph2);

//	displayLinkedGraph(graph);
	
//	system("leaks a.out");
	return (0);
}