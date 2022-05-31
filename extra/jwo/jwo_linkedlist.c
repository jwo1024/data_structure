#include	"linkedlist.h"
#include	<stdio.h>
#include	<stdlib.h>

// live share typing
int	main(void)
{
	LinkedList *alist;
	ListNode element;
	ListNode *get;
	int	i;

	alist = createLinkedList();
	element.data = 33;
	element.pLink = NULL;

	for (int i = 0; i < 5; i++) // 33, 34, 35, 36, 37
	{
		addLLElement(alist, i, element);
		element.data++;
	}
	displayLinkedList(alist);
	printf("\n");


	removeLLElement(alist, 2);

	element.data = 100;
	addLLElement(alist, 2, element);

	removeLLElement(alist, 4);

	displayLinkedList(alist);
	printf("\ndisplay end\n");

	reverseLinkedList(alist);

	displayLinkedList(alist);
	printf("\ndisplay end\n");

	for (int i = 0; i < 5; i++)
	{
		addLLElement(alist, i, element);
		element.data++;
	}
	printf("\nadd end\n");

/*
	printf("get length %d\n", getLinkedListLength(alist));
​
​
​
	clearLinkedList(alist);
	for (int i = 0; i < getLinkedListLength(alist); i++)
 		printf("%d ", getLLElement(alist, i)->data);
	printf("\n");
​
​
​
	for (int i = 0; i < 5; i++)
	{
		addLLElement(alist, i, element);
		element.data++;
	}
	printf("\n");
​
​
​*/

	deleteLinkedList(&alist);
/*
	printf("after delete test!\n");

	addLLElement(alist, 0, element);
	removeLLElement(alist, 0);
	getLLElement(alist, 0);
	clearLinkedList(alist);
	printf("get length %d\n", getLinkedListLength(alist));
	deleteLinkedList(alist);
*/

	system("leaks a.out");
	return(0);
}


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
		printf("Linked List is NULL\n");
		return (-1);
	}
	if (position < 0 || position > pList->currentElementCount)
	{
		printf("position out of bounds\n");
		return (-1);
	}
	new = (ListNode *)malloc(sizeof(ListNode));
	if (new == NULL)
	{
		printf("malloc failed\n");
		return (-1);
	}
	new->data = element.data;
	front = getLLElement(pList, position - 1);
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
		printf("Linked List is NULL\n");
		return (-1);
	}
	if (position < 0 || position >= pList->currentElementCount)
	{
		printf("position out of bounds\n");
		return (-1);
	}
	front = getLLElement(pList, position - 1);
	remove = front->pLink;
	front->pLink = remove->pLink;
	free(remove);
	pList->currentElementCount--;
	return (pList->currentElementCount);
}

/* 연결리스트 원소 반환 */ /////
ListNode* getLLElement(LinkedList* pList, int position)
{
	ListNode *get;
	int	cnt;

	if (pList == NULL)
	{
		printf("Linked List is NULL\n");
		return (NULL);
	}
	if (pList->currentElementCount < 0 && position != -1)
	{
		printf("Linked List is empty\n");
		return (NULL);
	}
	if (position < -1 || position >= pList->currentElementCount)
	{
		printf("position out of bounds\n");
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
		printf("Linked List is NULL\n");
	else
	{
		clear = (pList->headerNode).pLink;
		while (pList->currentElementCount)
		{
			pList->headerNode.pLink = clear->pLink;
			clear->data = 0; //추가!
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
		printf("Linked List is NULL\n");
		return(-1);
	}
	return (pList->currentElementCount);
}




/* 연결리스트 삭제 */
void deleteLinkedList(LinkedList** pList)
{
	if (pList == NULL)
		printf("Linked List is NULL\n");
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
		printf("Linked List is NULL\n");
	else
	{
		for (i = 0; i + 1 < pList->currentElementCount; i++)
			printf("%d ", getLLElement(pList, i)->data);
 		printf("%d\n", getLLElement(pList, i)->data);
	}
}

/* 연결리스트 순서 반전 */
void reverseLinkedList(LinkedList* pList)
{
	int	position;
	ListNode *get;
	ListNode *attach;
	ListNode *last;

	if (pList == NULL)
		printf("Linked List is NULL\n");
	else
	{
		last = getLLElement(pList, pList->currentElementCount - 1);
		attach = last;
		for (position = pList->currentElementCount - 2; position >= 0; position--)
		{
			get = getLLElement(pList, position);
			attach->pLink = get;
			attach = get;
		}
		attach->pLink = NULL;
		pList->headerNode.pLink = last;
	}
}