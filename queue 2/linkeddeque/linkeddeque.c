#include	"linkeddeque.h"
#include	<stdlib.h>
#include	<stdio.h>

LinkedDeque* createLinkedDeque()
{
	LinkedDeque	*new_deque;

	new_deque = calloc(1, sizeof(LinkedDeque));
	if (new_deque == NULL)
		return (NULL);
	new_deque->currentElementCount = 0;
	new_deque->pFrontNode = NULL;
	new_deque->pRearNode = NULL;
	return (new_deque);
}

int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode	*in_node;

	if (pDeque == NULL)
		return (-1);
	in_node = calloc(1, sizeof(DequeNode));
	if (in_node == NULL)
		return (-1);
	*in_node = element;
	in_node->pRLink = pDeque->pFrontNode;
	in_node->pLLink = NULL;
	pDeque->pFrontNode = in_node;
	if (in_node->pRLink == NULL)
		pDeque->pRearNode = in_node;
	else
		in_node->pRLink->pLLink = in_node;
	return (pDeque->currentElementCount++);
}

int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode	*in_node;

	if (pDeque == NULL)
		return (-1);
	in_node = calloc(1, sizeof(DequeNode));
	if (in_node == NULL)
		return (-1);
	*in_node = element;
	in_node->pRLink = NULL;
	in_node->pLLink = pDeque->pRearNode;
	pDeque->pRearNode = in_node;
	if (in_node->pLLink == NULL)
		pDeque->pFrontNode = in_node;
	else
		in_node->pLLink->pRLink = in_node;
	return (pDeque->currentElementCount++);
}

DequeNode* deleteFrontLD(LinkedDeque* pDeque) // 양쪽에서 마지막 노드라면
{
	DequeNode	*delete_node;

	if (pDeque == NULL || pDeque->currentElementCount <= 0) // empty
		return (NULL);
	delete_node = pDeque->pFrontNode;
	pDeque->pFrontNode = delete_node->pRLink;
	pDeque->currentElementCount--;
	if (isLinkedDequeEmpty(pDeque))
		pDeque->pRearNode = NULL;
	else
		pDeque->pFrontNode->pLLink = NULL;
	return (delete_node);
}

DequeNode* deleteRearLD(LinkedDeque* pDeque)
{
	DequeNode	*delete_node;

	if (pDeque == NULL || pDeque->currentElementCount <= 0)
		return (NULL);
	delete_node = pDeque->pRearNode;
	pDeque->pRearNode = delete_node->pLLink;
	pDeque->currentElementCount--;
	if (isLinkedDequeEmpty(pDeque))
		pDeque->pFrontNode = NULL;
	else
		pDeque->pRearNode->pRLink = NULL;
	return (delete_node);
}

DequeNode* peekFrontLD(LinkedDeque* pDeque) //노드 정보만 복사하여 반환
{
	DequeNode	*peek_node;

	if (pDeque == NULL || pDeque->currentElementCount <= 0)
		return (NULL);
	peek_node = calloc(1, sizeof(DequeNode));
	if (peek_node == NULL)
		return (NULL);
	*peek_node = *(pDeque->pFrontNode);
	peek_node->pRLink = NULL; // 링크를 잘라서 줄것인가? 
	return (peek_node);
}

DequeNode* peekRearLD(LinkedDeque* pDeque)
{
	DequeNode	*peek_node;

	if (pDeque == NULL || pDeque->currentElementCount <= 0)
		return (NULL);
	peek_node = calloc(1, sizeof(DequeNode));
	if (peek_node == NULL)
		return (NULL);
	*peek_node = *(pDeque->pRearNode);
	peek_node->pLLink = NULL;
	return (peek_node);
}

void deleteLinkedDeque(LinkedDeque* pDeque)
{
	DequeNode	*tmp;

	if (pDeque == NULL)
		return ;
	while (pDeque->currentElementCount--)
	{
		tmp = pDeque->pFrontNode;
		pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
		free(tmp);
	}
	free(pDeque);
}

int isLinkedDequeFull(LinkedDeque* pDeque) //링크드 에서 이러한 상황이 존재하는가?
{
	if (pDeque == NULL)
		return (-1);
	return (FALSE);
}

int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
	if (pDeque == NULL)
		return (-1);
	return (pDeque->currentElementCount == 0);
}

void	displayLinkedDeque(LinkedDeque *pDeque)
{
	DequeNode	*display;

	if (pDeque == NULL)
		return ;
	if (isLinkedDequeEmpty(pDeque))
	{
		printf("LinkedDeque is Empty\n");
		return ;
	}
	display = pDeque->pFrontNode;

	for (int i = 0; display; i++)
	{
		printf("LinkedDeque[%d]\t%c\n", i, display->data);
		display = display->pRLink;
	}
}
