#include "linkeddeque.h"
#include <stdio.h>

int	main(void)
{
	LinkedDeque	*pDeque;
	DequeNode	elem;

	pDeque = createLinkedDeque();
	elem.data = 'A';
	insertFrontLD(pDeque, elem);
	elem.data = 'B';
	insertFrontLD(pDeque, elem);
	displayLinkedDeque(pDeque);

	printf("-----\n");

	elem.data = 'C';
	insertRearLD(pDeque, elem);
	elem.data = 'D';
	insertRearLD(pDeque, elem);
	displayLinkedDeque(pDeque);

	deleteRearLD(pDeque);
	printf("-----\n");
	displayLinkedDeque(pDeque);

	deleteFrontLD(pDeque);
	printf("-----\n");
	displayLinkedDeque(pDeque);

	printf("peekFrontLD: [%c]\n", peekFrontLD(pDeque)->data);
	printf("peekRearLD: [%c]\n", peekRearLD(pDeque)->data);

	printf("-----deleteFront all\n");
	while (isLinkedDequeEmpty(pDeque) == FALSE)
		deleteFrontLD(pDeque);
	displayLinkedDeque(pDeque);

	elem.data = 'C';
	insertRearLD(pDeque, elem);
	elem.data = 'D';
	insertRearLD(pDeque, elem);
	printf("----- insert C and D\n");
	displayLinkedDeque(pDeque);

	printf("-----deleteRear all\n");
	while (isLinkedDequeEmpty(pDeque) == FALSE)
		deleteRearLD(pDeque);
	displayLinkedDeque(pDeque);


	elem.data = 'C';
	insertRearLD(pDeque, elem);
	elem.data = 'D';
	insertRearLD(pDeque, elem);
	deleteLinkedDeque(pDeque);
	
	pDeque = NULL;

	displayLinkedDeque(pDeque);
	

	//printf("LinkedDeque[] %c\n", pDeque->pFrontNode->data);

	return (0);
}
