#include	"./linkedstack/linkedstack.h"
#include	<string.h>

int	checkBracketMatching(char *arr);
int	isBracketLeft(char c);
int	isBracketRight(char c);
int	checkBracketLR(char a, char b);

int	main(void)
{
	char	arr1[] = "{ ( a + b ) * [ g * h ] }";
	char	arr2[] = "(a * b)( 40 + 50 ) * [ g * h ]";
	char	arr3[] = "{}{ [()()()()] }{";
	char	arr4[] = "( ( A * B ) / C ) - { ( D + E ) && ( F - G ) }";
	char	arr5[] = "( ( A * B ) / C - { ( D + E ) && ( F - G ) ) }";



	printf("\ncheck 1\n");
	if (checkBracketMatching(arr1))
		printf("Match\n");
	else
		printf("not Match\n");

	printf("\ncheck 2\n");
	if (checkBracketMatching(arr2))
		printf("Match\n");
	else
		printf("not Match\n");

	printf("\ncheck 3\n");
	if (checkBracketMatching(arr3))
		printf("Match\n");
	else
		printf("not Match\n");

	printf("\ncheck 4\n");
	if (checkBracketMatching(arr4))
		printf("Match\n");
	else
		printf("not Match\n");

	printf("\ncheck 5\n");
	if (checkBracketMatching(arr5))
		printf("Match\n");
	else
		printf("not Match\n");

	return (0);
}

int	checkBracketMatching(char *arr)
{
	LinkedStack	*stack;
	StackNode	node;
	int	rtn;

	if (NULLCHECK(arr))
		return (ERROR);
	stack = createLinkedStack();
	if (NULLCHECK(stack))
		return (ERROR);
	rtn = FALSE;
	while (*arr)
	{
		if (isBracketLeft(*arr))
		{
			node.data = *arr;
			pushLS(stack, node);
		}
		else if (isBracketRight(*arr))
		{
			if (isLinkedStackEmpty(stack) == FALSE
					&& checkBracketLR((peekLS(stack))->data, *arr))
				popLS(stack);
			else 
				break;
		}
		arr++;
	}
	if (*arr == '\0' && isLinkedStackEmpty(stack) == TRUE)
		rtn = TRUE;
	deleteLinkedStack(stack);
	return (rtn);
}

int	isBracketLeft(char c)
{
	if (c == '(' || c == '{' || c == '[')
		return (TRUE);
	else
		return (FALSE);
}

int	isBracketRight(char c)
{
	if (c == ')' || c == '}' || c == ']')
		return (TRUE);
	else
		return (FALSE);
}

int	checkBracketLR(char a, char b)
{
	if ((a == '(' && b == ')') || (a == '{' && b == '}') 
		|| (a == '[' && b == ']'))
		return (TRUE);
	else
		return (FALSE);
}