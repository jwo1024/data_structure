#ifndef _GRAPH_ADJMATRIX_
#define _GRAPH_ADJMATRIX_

#include	"./linked_list/graphlinkedlist.h"

typedef struct LinkedGraphType
{
	int maxVertexCount;		// 최대 노드 개수
	int currentVertexCount;	// 현재 사용되는 노드의 개수
	int graphType;			// 그래프 종류: 1-Undirected, 2-Directed 무방향, 방향
	LinkedList **ppAdjEdge;		// 간선 저장을 위한 2차원 Linked
	int *pVertex;			// 노드 저장을 위한 1차원 Linked // node로 변경해주어야하나
} LinkedGraph;

// 그래프 생성
LinkedGraph* createLinkedGraph(int maxVertexCount);
LinkedGraph* createLinkedDirectedGraph(int maxVertexCount);

// 그래프 삭제
void deleteLinkedGraph(LinkedGraph** pGraph);

// 공백 그래프 여부 판단
int isEmptyAG(LinkedGraph* pGraph);

// 노드 추가
int addVertexAG(LinkedGraph* pGraph, int vertexID);

// 간선 추가
int addEdgeAG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
int addEdgewithWeightAG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight);

// 노드의 유효성 점검.
int checkVertexValid(LinkedGraph* pGraph, int vertexID);

// 노드 제거
int removeVertexAG(LinkedGraph* pGraph, int vertexID);

// 간선 제거
int removeEdgeAG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);

// 그래프 정보 출력
void displayLinkedGraph(LinkedGraph* pGraph);

#endif

#ifndef _COMMON_GRAPH_DEF_
#define _COMMON_GRAPH_DEF_

#define USED				1
#define NOT_USED			0

#define SUCCESS				1
#define FAIL				0

#define TRUE				1
#define FALSE				0

#define ERROR				-1 //

#define GRAPH_UNDIRECTED	1
#define GRAPH_DIRECTED		2
#endif
