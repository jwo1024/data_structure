#ifndef _ARRAYLIST_
#define _ARRAYLIST_

typedef struct ArrayListNodeType
{
	int data;
} ArrayListNode;

typedef struct ArrayListType
{
	int maxElementCount;		// 최대 원소 개수
	int currentElementCount;	// 현재 원소의 개수
	ArrayListNode *pElement;	// 원소 저장을 위한 1차원 배열
} ArrayList;

ArrayList* createArrayList(int maxElementCount);
void deleteArrayList(ArrayList** pList); // delete
int isArrayListFull(ArrayList* pList);
int addALElement(ArrayList* pList, int position, ArrayListNode element);
int removeALElement(ArrayList* pList, int position);
ArrayListNode* getALElement(ArrayList* pList, int position);
void displayArrayList(ArrayList* pList);
void clearArrayList(ArrayList* pList);
int getArrayListLength(ArrayList* pList);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif

//과제 배열을 구현을 하시는 건데배열과 링크드 리스트르ㅡㄹ 구현해오시는건데, 리니어 타입, 선형자료구조, 일대 일의 관계
// 아닌 경우, 트리나 그래프는 일대일이 아니다. 
// 우리가 당분간 구혀낳 것은 선형 자료구조
// 스택, 큐, 한줄로되어있는 선형 자료구조,
// arry list 배열, linked list는 연결리스트
// 단일기능만 구현, 42 함수의 기능을 너무 길게 구현하지 말ㄹ라하는, 