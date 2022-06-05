#ifndef _GRAPH_LINKEDLIST_
#define _LINKEDLIST_

typedef struct GraphVertexType
{
	int vertexID;		// 노드 ID
	int weight;			// 가중치.
} GraphVertex;

typedef struct ListNodeType
{
	GraphVertex data;
	struct ListNodeType* pLink;
} ListNode;

typedef struct LinkedListType
{
	int currentElementCount;	// 현재 저장된 원소의 개수
	ListNode headerNode;		// 헤더 노드(Header Node)
} LinkedList;

LinkedList* createLinkedList();
int addLLElement(LinkedList* pList, int position, ListNode element);
int removeLLElement(LinkedList* pList, int position);
ListNode* getLLElement(LinkedList* pList, int position);

void clearLinkedList(LinkedList* pList);
int getLinkedListLength(LinkedList* pList);
void deleteLinkedList(LinkedList** pList);

void displayLinkedList(LinkedList* pList);
void reverseLinkedList(LinkedList* pList);

// graph
int removeLLElementGID(LinkedList* pList, int vertexID);

#endif
#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1

#endif