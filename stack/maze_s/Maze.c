#include "Maze.h"

// 들어온 map을 받아줄 함수
Map	*createMap(int row, int column, char **graph, MapNode *startNode, MapNode *endNode)
{
	Map		*newMap;
	newMap = calloc(1, sizeof(Map));
	newMap->row = row;
	newMap->column = column;
	newMap->graph = graph;
	newMap->startNode = startNode;
	newMap->endNode = endNode;
	return (newMap);
}


MapNode	*createMapNode()
{
	MapNode	*newNode;

	newNode = calloc(1, sizeof(MapNode));
	if (NULLCHECK(newNode))
		return (NULL);
	return (newNode);
}

int	Go(Map *map)
{
	MapNode		*topNode;
	Stack		*stack;
	Direction	*dir;

	MapNode		*path;
	int			min;
	min = setMinDistance(map);
	path = NULL;

	stack = createStack();
	dir = setDirection(map);
	topNode = map->startNode;
	topNode->func = &FIRST;
	map->endNode->dist = 2147483647;
	// stack이 비게되면 topNode는 NULL이 된다.
	while (topNode)
	{
		displayGraph(map);
		printf("y%d x %d dist %d\n", topNode->y, topNode->x, topNode->dist);
		getchar();
		// endNode 도착하면 거리를 갱신해주어야 한다.
		if (topNode->x == map->endNode->x && topNode->y == map->endNode->y)
		{
			printf("min %d top %d\n", min, topNode->dist);
			if (min != topNode->dist && (printf("min")|| path == NULL || topNode->dist <= path->dist))
			{
				printf("path");
				pushLS(stack, *topNode);
				path = popLS(stack); //path 만이 아닌 stack을 복사해야함
				topNode = popLS(stack);
			//	map->graph[topNode->y][topNode->x] = '0';

				printf("\npath dist %d\n", path->dist);
				displayPATH(path);
				map->graph[map->endNode->y][map->endNode->x] = '0';
				getchar();

				continue;
			}
			// 첫번째 탐색 혹은 현재탐색 dist가 더 작다면 pathnode에 저장
			// (pathnode를 다른 topnode로 덮어 쓸때 할당 해제는 어떻게 할것인지)
			// 가능한 최소거리라면 break 및 출력
			// 최소거리가 아니라면 pop하여 뒤로 가서 다시 탐색
			pushLS(stack, *topNode);
			free(topNode);
			printf("\nbreak top dist %d\n", path->dist);
			displayPATH(path);
			path = popLS(stack);
			break ;
		}
		// 함수 pointer가 NULL이다 == 이미 지나간 노드이고, 4방향 전부 진행했다.
		// 따라서 pop해준다.
		//// 탐색중 dist가 path->dist 보다 커지면 탐색 중지 및 뒤로 pop
		if (topNode->func == NULL || (path && topNode->dist >= path->dist))
		{
			map->graph[topNode->y][topNode->x] = '0';
	//		free(topNode); //메모리를 잃고 결과를 얻음(메모리 누수)
			topNode = popLS(stack);
			continue ;
		}
		// printf("a\n");
		// node의 함수 포인터 실행 -> (FSTF) -> (FSTF는 DIR의 fstf를 각각 실행)
		// true이면 이동에 성공 및 거리 증가
		// false이면 이동에 실패 --> 다음 함수 혹은 pop으로 가야한다.
	
		if ((*(t_order)topNode->func)(map, &topNode, stack, dir))
			topNode->func = &FIRST;
	}
	printf("\npath\n");
	if (path == NULL) // 경로 탐색 실패
		return (FALSE);
	setPATH(path, map); //경로 출력 및 graph 에 패스 표시

	free(dir);
	deleteLS(stack);
	deleteMap(map);
	return (TRUE); // false 가 나는 경우가 없음
}
