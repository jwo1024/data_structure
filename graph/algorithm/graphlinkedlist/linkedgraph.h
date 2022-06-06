#ifndef _GRAPH_ADJMATRIX_
#define _GRAPH_ADJMATRIX_

#include	"./linked_list/graphlinkedlist.h"

typedef struct LinkedGraphType
{
	int maxVertexCount;		// �ִ� ��� ����
	int currentVertexCount;	// ���� ���Ǵ� ����� ����
	int graphType;			// �׷��� ����: 1-Undirected, 2-Directed ������, ����
	LinkedList **ppAdjEdge;		// ���� ������ ���� 2���� Linked
	int *pVertex;			// ��� ������ ���� 1���� Linked // node�� �������־���ϳ�
} LinkedGraph;

// �׷��� ����
LinkedGraph* createLinkedGraph(int maxVertexCount);
LinkedGraph* createLinkedDirectedGraph(int maxVertexCount);

// �׷��� ����
void deleteLinkedGraph(LinkedGraph** pGraph);

// ���� �׷��� ���� �Ǵ�
int isEmptyAG(LinkedGraph* pGraph);

// ��� �߰�
int addVertexAG(LinkedGraph* pGraph, int vertexID);

// ���� �߰�
int addEdgeAG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
int addEdgewithWeightAG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight);

// ����� ��ȿ�� ����.
int checkVertexValid(LinkedGraph* pGraph, int vertexID);

// ��� ����
int removeVertexAG(LinkedGraph* pGraph, int vertexID);

// ���� ����
int removeEdgeAG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);

// �׷��� ���� ���
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
