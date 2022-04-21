#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

// displayLinkedList(), reverseLinkedList()의  currentElementcoutn == 0일때 예외처리 추가

/* 연결리스트 생성 */
LinkedList* createLinkedList()
{
	LinkedList *pList;

	pList = (LinkedList *)malloc(sizeof(LinkedList));
	if (pList == 0)
	{
		printf("malloc failed\n");
		return (NULL);
	}
	pList->currentElementCount = 0;
	pList->headerNode.data = 0;
	/*
		pLLink, pRLink 초기화
	*/
	pList->headerNode.pLink = NULL;
	return (pList);
}

/* 연결리스트 원소 추가 */
int addLLElement(LinkedList* pList, int position, ListNode element)
{
	ListNode *front;
	ListNode *new;

	if (pList == NULL)
	{
		printf("Invalid LinkedList\n");
		return (ERROR);
	}
	if (position < 0 || position > pList->currentElementCount)
	{
		printf("position out of bounds\n");
		return (ERROR);
	}
	new = (ListNode *)malloc(sizeof(ListNode));
	if (new == NULL)
	{
		printf("malloc failed\n");
		return (ERROR);
	}
	new->data = element.data;
	front = getLLElement(pList, position - 1);
	/*
	1. new 오른쪽 노드링크에 front 오른쪽 노드링크 연결
	2. new	왼쪽 노드링크에 front 노드 연결
	3. front 오른쪽 노드링크에 new 노드 연결
	4. new 오른쪽노드의 왼쪽링크에 new 노드 연결
	if (오른쪽 노드가 존재 할때만)
		4번 실행;
	*/
	new->pLink = front->pLink;
	front->pLink = new;
	pList->currentElementCount++;
	return (pList->currentElementCount);
}

/* 연결리스트 원소 삭제 */
int removeLLElement(LinkedList* pList, int position)
{
	ListNode *remove;
	ListNode *front;

	if (pList == NULL)
	{
		printf("Invalid LinkedList\n");
		return (ERROR);
	}
	if (position < 0 || position >= pList->currentElementCount)
	{
		printf("position out of bound\n");
		return (ERROR);
	}
	front = getLLElement(pList, position - 1);
	remove = front->pLink;
	/*
	front 노드와 remove다음 노드의 연결 (pLLink, pRLink)
	*/
	front->pLink = remove->pLink;
	free(remove);
	pList->currentElementCount--;
	return (pList->currentElementCount);
}

/* 연결리스트 원소 반환 */
ListNode* getLLElement(LinkedList* pList, int position)
{
	ListNode *get;
	int	cnt;

	if (pList == NULL)
	{
		printf("Invalid LinkedList\n");
		return (NULL);
	}
	if (pList->currentElementCount < 0 && position != -1)
	{
		printf("the LinkedList is empty\n");
		return (NULL);
	}
	if (position < -1 || position >= pList->currentElementCount)
	{
		printf("position out of bound\n");
		return (NULL);
	}
	if (position == -1)
		return (&(pList->headerNode));
	get = (pList->headerNode).pLink;
	for (cnt = 0; cnt < position; cnt++)
		get = get->pLink;
	return (get);
}

/* 연결리스트 초기화 */
void clearLinkedList(LinkedList* pList)
{
	ListNode *clear;

	if (pList == NULL)
		printf("Invalid LinkedList\n");
	else
	{
		clear = (pList->headerNode).pLink;
		while (pList->currentElementCount)
		{
			pList->headerNode.pLink = clear->pLink;
			clear->data = 0;
			free(clear);
			clear = (pList->headerNode).pLink;
			pList->currentElementCount--;
		}
		(pList->headerNode).pLink = NULL;
	}
}

/* 연결리스트 길이 반환 */
int getLinkedListLength(LinkedList* pList)
{
	if (pList == NULL)
	{
		printf("Invalid LinkedList\n");
		return(ERROR);
	}
	return (pList->currentElementCount);
}

/* 연결리스트 삭제 */
void deleteLinkedList(LinkedList** pList)
{
	if (pList == NULL)
		printf("Invalid LinkedList\n");
	else
	{
		clearLinkedList(*pList);
		free(*pList);
		*pList = NULL;
	}
}

/* 연결리스트 출력 */
void displayLinkedList(LinkedList* pList)
{
	int	i;

	if (pList == NULL)
		printf("Invalid LinkedList\n");
	else if (pList->currentElementCount) //추가
		printf("the LinkedList is empty\n");
	else
	{
		for (i = 0; i < pList->currentElementCount - 1; i++)
			printf("%d ", getLLElement(pList, i)->data);
 		printf("%d\n", getLLElement(pList, i)->data);
	}
}

/* 연결리스트 순서 반전 */
void reverseLinkedList(LinkedList* pList) /////
{
	int	position;
	ListNode *get;
	ListNode *attach;
	ListNode *last;

	if (pList == NULL)
		printf("Invalid LinkedList\n");
	else if (pList->currentElementCount) //추가
		printf("the LinkedList is empty\n");
	else
	{
		last = getLLElement(pList, pList->currentElementCount - 1);
		attach = last;
		for (position = pList->currentElementCount - 2; position >= 0; position--)
		{
			get = getLLElement(pList, position);
			attach->pLink = get;
			/*
			attach->pRLink = get;
			if (get != NULL)
				get->pLLink = attach;
			*/
			attach = get;
		}
		attach->pLink = NULL;
		pList->headerNode.pLink = last;
	}
}

/*
int main(void)
{
	ListNode	node;
	LinkedList* pList;
	node.data = 1;
	node.pLink = NULL;
	pList = createLinkedList();
	addLLElement(pList, 0, node);
	displayLinkedList(pList);
	printf("get %d\n", getLLElement(pList, 0)->data);
	deleteLinkedList(&pList);
	displayLinkedList(pList);
//	system("leaks a.out");
	return (0);
}
*/