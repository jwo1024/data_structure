#include "Maze.h"

char	**scan_graph(MapNode *startNode, MapNode *endNode, int *row, int *column)
{
	char **graph;

	scanf("%d %d", row, column);
	graph = calloc(*row, sizeof(char *));
	for (int i = 0; i < *row; i++)
	{
		graph[i] = calloc(*column + 1, sizeof(char));
		for (int j = 0; j < *column; j++)
		{
			scanf(" %c", &graph[i][j]);
			if (graph[i][j] == 's')
			{
				startNode->x = j;
				startNode->y = i;
			}
			else if (graph[i][j] == 'e')
			{
				endNode->x = j;
				endNode->y = i;
				graph[i][j] = '0';
			}
		}
		graph[i][*column] = '\0';
	}
	return (graph);
}

int	main(void)
{
	MapNode	*startNode;
	MapNode *endNode;
	Map		*map;
	Direction	*dir;

	int	row;
	int	column;

	startNode = createMapNode();
	endNode = createMapNode();
	startNode->x = 1;
	startNode->y = 0;
	startNode->dist = 0;
	endNode->x = 4;
	endNode->y = 4;
	char	**graph = scan_graph(startNode, endNode, &row, &column);
	map = createMap(row, column, graph, startNode, endNode);
	printf("result = %d\n", Go(map));

	for (int i = 0; i< row; i++)
		printf("%s\n", graph[i]);

//	system("leaks a.out > leaks_result; cat leaks_result | \
        grep leaked && rm -rf leaks_result");
}

// 5 5
// 1s111
// 10000
// 11110
// 11110
// 1111e

// pop 시 경로 회수 안됨 문제
// path에 경로 저장문제
// 메모리 누수 문제
// 경로가 없을 경우 문제
// 통로가 2차선이상일 때 탐색 이상한곳 하며, 길을 찾지못하는 문제
/*
5 5
1s111
10011
00111
01111
0000e

5 5
1s111
10011
00111
01111
0001e
*/
