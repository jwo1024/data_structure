#include "arraylist.h"
#include <stdlib.h>
#include <stdio.h>

// 수정
// display 마지막data 출력후 공백 대신 줄바꿈이 되도록 수정
// deleteArrayList에서 element를 clearArrayList 작업후(0으로 초기화) free하도록 수정
// 매개변수 (ArrayList* pList) -> (ArrayList** pList) 변경

int	main(void)
{
	ArrayList* pList;
	ArrayListNode node;

	node.data = 10;
	pList = createArrayList(1);
	addALElement(pList, 0, node);
	displayArrayList(pList);
	printf("length %d\n", getArrayListLength(pList));
	printf("full %d\n", isArrayListFull(pList));

	deleteArrayList(&pList);

	displayArrayList(pList);

//	system("leaks a.out");
	return (0);
}

ArrayList* createArrayList(int maxElementCount)
{
	ArrayList *pList = (ArrayList *)malloc(sizeof(ArrayList));

	pList->maxElementCount = maxElementCount;
	pList->currentElementCount = 0;
	pList->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * maxElementCount);
	if (pList->pElement == 0)
	{
		printf("malloc failed\n");
		return (NULL);
	}
	for (int i = 0; i < maxElementCount; i++)
		pList->pElement[i].data = 0;
	return (pList);
}

void deleteArrayList(ArrayList** pList)
{
	if (*pList == NULL || (*pList)->pElement == NULL)
	{
		printf("invalid ArrayList\n");
		return ;
	}
	(*pList)->maxElementCount = 0;
	(*pList)->currentElementCount = 0;
	clearArrayList(*pList);
	free((*pList)->pElement);
	(*pList)->pElement = NULL;
	free(*pList);
	*pList = NULL;
}

int isArrayListFull(ArrayList* pList)
{
	if (pList == NULL || pList->pElement == NULL)
	{
		printf("invalid ArrayList\n");
		return (-1);
	}
	if (pList->currentElementCount == pList->maxElementCount)
		return (TRUE);
	else
		return (FALSE);
}

// position이 index 번호로 주어진다고 가정
// 여기서 자바에서 사용하는 ArrayList처럼 만들어야 할지, 아니면 C의 primitive 배열처럼 만들어야 할지 고민이 됐다
// 고민 좀 하다가 둘이 섞은 방식으로 하기로 함
int addALElement(ArrayList* pList, int position, ArrayListNode element) 
{
	int	value = element.data;

	if (pList == NULL || pList->pElement == NULL)
	{
		printf("invalid ArrayList\n");
		return (-1);
	}
	if (position < 0 || pList->currentElementCount < position || pList->maxElementCount == position)
	{
		printf("position out of bound\n");
		return (-1);
	}
	if (isArrayListFull(pList) == TRUE)
	{
		printf("the ArrayList is full\n");
		return (-1);
	}
	if (position <= pList->currentElementCount - 1)
	{
		for (int i = pList->currentElementCount - 1; i >= position; i--)
			pList->pElement[i + 1].data = pList->pElement[i].data;
	}
	pList->pElement[position].data = value;
	pList->currentElementCount++;
	return (position);
}

int removeALElement(ArrayList* pList, int position)
{
	if (pList == NULL || pList->pElement == 0)
		printf("invalid ArrayList\n");
	else if (pList->currentElementCount == 0)
		printf("the ArrayList is empty\n");
	else if (position < 0 || (pList->currentElementCount) <= position)
		printf("position out of bound\n");
	else if (0 <= position && position < (pList->currentElementCount))
	{
		for (int i = position; i < pList->currentElementCount - 1; i++)
			pList->pElement[i].data = pList->pElement[i + 1].data;
		pList->currentElementCount--;
		pList->pElement[pList->currentElementCount].data = 0;
		return (position);
	}
	return (-1);
}

ArrayListNode* getALElement(ArrayList* pList, int position)
{
	if (pList == NULL || pList->pElement == 0)
	{
		printf("invalid ArrayList\n");
		return (NULL);
	}
	if (position < 0 || pList->currentElementCount <= position)
	{
		printf("position out of bound\n");
		return (NULL);
	}
	return (&(pList->pElement[position]));
}

void displayArrayList(ArrayList* pList)
{
	int	i;

	if (pList == NULL || pList->pElement == 0)
	{
		printf("invalid ArrayList\n");
		return ;
	}
	if (pList->currentElementCount == 0)
	{
		printf("the ArrayList is empty\n");
		return ;
	}
	for (i = 0; i + 1< pList->currentElementCount; i++)
		printf("%d ", pList->pElement[i].data);
	printf("%d\n", pList->pElement[i].data);
}

void clearArrayList(ArrayList* pList)
{
	if (pList == NULL || pList->pElement == 0)
	{
		printf("invalid ArrayList\n");
		return ;
	}
	for (int i = 0; i < pList->currentElementCount; i++)
		pList->pElement[i].data = 0;
	pList->currentElementCount = 0;
}

int getArrayListLength(ArrayList* pList)
{
	if (pList == NULL || pList->pElement == NULL)
	{
		printf("invalid ArrayList\n");
		return (-1);
	}
	return (pList->currentElementCount);
}