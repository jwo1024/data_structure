#include "linkedstack.h"

int	main(void)
{
	LinkedStack	*stack = createLinkedStack(10);
	StackNode	*node1 = calloc(1, sizeof(StackNode));
	StackNode	*node2 = calloc(1, sizeof(StackNode));
	StackNode	*node3 = calloc(1, sizeof(StackNode));
	StackNode	*node4 = calloc(1, sizeof(StackNode));
	StackNode	*node5 = calloc(1, sizeof(StackNode));
	StackNode	*node6 = calloc(1, sizeof(StackNode));
	StackNode	*node7 = calloc(1, sizeof(StackNode));

	node1->data = 'm';
	node2->data = 'i';
	node3->data = 'n';
	node4->data = 'g';
	node5->data = 'k';
	node6->data = 'i';
	node7->data = 'm';
	pushLS(stack, *node1);
	displayLinkedStack(stack);
	printf("====================================================\n");

	pushLS(stack, *node2);
	displayLinkedStack(stack);
	printf("====================================================\n");

	pushLS(stack, *node3);
	displayLinkedStack(stack);
	printf("====================================================\n");

	pushLS(stack, *node4);
	displayLinkedStack(stack);
	printf("====================================================\n");

	pushLS(stack, *node5);
	displayLinkedStack(stack);
	printf("====================================================\n");

	pushLS(stack, *node6);
	displayLinkedStack(stack);
	printf("====================================================\n");

	pushLS(stack, *node7);
	displayLinkedStack(stack);
	printf("====================================================\n");

	printf("***********now peek & pop*****************\n");
	printf("***********now peek & pop*****************\n");
	printf("***********now peek & pop*****************\n");

	StackNode	*temp;
	temp = peekLS(stack);
	printf("peek : %c\n", temp->data);
	temp = popLS(stack);
	free(temp);
	displayLinkedStack(stack);
	printf("====================================================\n");
	
	temp = peekLS(stack);
	printf("peek : %c\n", temp->data);
	temp = popLS(stack);
	free(temp);
	displayLinkedStack(stack);
	printf("====================================================\n");

	temp = peekLS(stack);
	printf("peek : %c\n", temp->data);
	temp = popLS(stack);
	free(temp);
	displayLinkedStack(stack);
	printf("====================================================\n");
	temp = peekLS(stack);
	printf("peek : %c\n", temp->data);
	temp = popLS(stack);
	free(temp);
	displayLinkedStack(stack);
	printf("====================================================\n");
	temp = peekLS(stack);
	printf("peek : %c\n", temp->data);
	temp = popLS(stack);
	free(temp);
	displayLinkedStack(stack);
	printf("====================================================\n");
	temp = peekLS(stack);
	printf("peek : %c\n", temp->data);
	temp = popLS(stack);
	free(temp);
	displayLinkedStack(stack);
	printf("====================================================\n");
	temp = peekLS(stack);
	printf("peek : %c\n", temp->data);
	temp = popLS(stack);
	free(temp);
	displayLinkedStack(stack);
	printf("====================================================\n");
	// temp = peekLS(stack);
	// printf("peek : %c\n", temp->data);
	// temp = popLS(stack);
	// displayLinkedStack(stack);
	printf("====================================================\n");
	deleteLinkedStack(stack);
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);
	free(node6);
	free(node7);
	node1 = NULL;
	node2 = NULL;
	node3 = NULL;
	node4 = NULL;
	node5 = NULL;
	node6 = NULL;
	node7 = NULL;
	// printf("Is stack empty ? : %d\n", isLinkedStackEmpty(stack));
	system("leaks a.out > leaks_result; cat leaks_result | \
        grep leaked && rm -rf leaks_result");
	return (0);
}