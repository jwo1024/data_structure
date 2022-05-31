#ifndef _LINKEDLIST_
#define _LINKEDLIST_

typedef struct ListNodeType
{
	int data;
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

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif

/*

\

*/



// 자료구조 책은 사라 마라 하지 않지만, 자료구조는 하나쯤 있으면 좋아요.
// 책은 정독하는게 좋아요.
// 물리적인 순서와 논리적인 순서가 같고 fixed length 는 없다. 
// computation time 수행시간에 대해 찾아보세요
// 시간복잡도
// 배열 같은 경우는 데이터를 중간에 녛는게 O(n)
// 링크드를 중간에 넣을때 선형이에요 O(1) -> 시간복잡도의 영향을 받지 않는다. 
//  다음주 화요일 까지 헤더파일대로 구현 및 공부

// sequential 한 어떨때 쓰이는 것이 좋을지, 장단점을 비교

// fundamental 응ㄹㅇ

// 사전 모임때 각 반의 모임때 반장이 있어야 반장을 뽑으셔서 나중에 짝 바꾸는 것 하나 하시고, 회의실스터디 할 회의실 모이는거
// 반장 되신분은 dm 주세요 
// 사전면담때 말씀 드렸지만, 얌전히 계시면 공부를 안한거다 
// 저랑 만들때 질문을 하시면 됩니다. 
// 자료구조는 다 도와드릴 수 있으니까 , 뭐가 잘 안될때는 킵해놨다가 얘기하시면 되어요!

// 명세 참고하라고 준거에요. 

// 금요일에 회고를 보내주시면 될꺼 같아요
// 짝이랑 공부할때 좋았다 어쨋다... 어떤 면을 반 분위기도 파악할 수 있고

// 맨토님 자바 책이 제일 좋아요.. 자료구조는 워낙에 많아요 서점에 가서 맞는 책을 사는 것을 추천해요. C책으로 편하니까. 
// 한빛미디어. 
// 이상진 교수님 숭실대 교수님 자료구조 책 조금 두꺼워여 그 책 기반으로 자료를 드린거에요 . 

// 오프라인으로 만나서 컴퓨터 두명에서 한명은 코드를 치고(핸들) 한명은 코치 !
// 코드 쉐어 한 페어가 나오는 것이 좋다. 각자 하지 말고 하나의 코드를 만들고 디스커션도 하고 그러셨으면 좋겟어요!
// 