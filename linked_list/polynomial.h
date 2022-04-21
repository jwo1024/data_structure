#ifndef _POLYLINKEDLIST_
#define _POLYLINKEDLIST_

typedef struct NodeType  // 단항식
{
	int coef; //계수 cofficient
	int expo; //지수 exponent = degree
	// 음수 양수
	struct NodeType* pLink;
} Node;

typedef struct PolyListType // 다항식 polynomial
{
	int currentElementCount;	// 현재 저장된 원소의 개수
	Node headerNode;		// 헤더 노드(Header Node)
} PolyList;

PolyList* createPolyList();
int addPLElement(PolyList* pList, int position, Node element); //지수의 순서에 맞게 넣어줘야 한다.
int removePLElement(PolyList* pList, int position);
Node* getPLElement(PolyList* pList, int position); //지수 순서에 맞게 출력

void clearPolyList(PolyList* pList);
int getPolyListLength(PolyList* pList);
void deletePolyList(PolyList** pList);

void displayPolyList(PolyList* pList); //수정필요
void reversePolyList(PolyList* pList);

// 다항식의 덧셈을 계산하여 list를 반환하는 함수 구현
// (합병정렬을 생각하면 쉽다. , 전제조건은 다항식 a, b가 이미 정렬이 되어있어야한다.)
// 결과를 저장할 리스트를 생성
// 다항식 a 와 다항식 b의 지수를 비교
//		비교하여 큰 지수의 노드를 결과리스트에 저장
//		지수가 같을경우 지수의 node를 합하여 결과리스트에 저장
// 다항식의 곱을 계산할여 list를 반환하는 함수 //시간 없으면 x

// int addPolyNodeLast(LinkedList* pList, float coef, int degree)

#endif
#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1

#endif