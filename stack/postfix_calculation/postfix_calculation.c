#include	"./linkedstack/linkedstack.h"

int	checkBracketMatching(char *arr);
int	is_operator(char c);
int	operate_stack(LinkedStack *stack, char c);

int	main(void)
{
	char	arr1[] = "2 2 3 + 4 * - 2 /"; // (2 - (2 + 3) * 4 )/ 2 = -9
	char	arr2[] = "2 3 + 4"; // 문자가 많을때 
	char	arr3[] = "2 3 + -"; // 연산자가 많을때
	char	arr4[] = "2 3 +a -"; // 잘못된 문자가 들어 있을때
	char	arr5[] = "1"; // 숫자 하나일때

	printf("result %d\n", checkBracketMatching(arr1));
	printf("result %d\n", checkBracketMatching(arr2));
	printf("result %d\n", checkBracketMatching(arr3));
	printf("result %d\n", checkBracketMatching(arr4));
	printf("result %d\n", checkBracketMatching(arr5));

	return (0);
}

int	checkBracketMatching(char *arr)
{
	LinkedStack	*stack;
	StackNode	node;
	int	rtn;
	int	num;

	if (NULLCHECK(arr))
		return (ERROR);
	stack = createLinkedStack();
	if (NULLCHECK(stack))
		return (ERROR);
	rtn = ERROR;
	while (*arr)
	{
		if ('0' <= *arr && *arr <= '9') //숫자일 경우
		{
			node.data = *arr - '0';
			for (; '0' <= *(arr + 1) && *(arr + 1) <= '9';)
			{
				arr++;
				node.data *= 10;
				node.data += *arr - '0';
			}
			pushLS(stack, node);
		}
		else if (is_operater(*arr)) //연산자일 경우
		{
			if (stack->currentElementCount < 2) //최소 2개가 있어야 연산가능
				break;
			node.data = operate_stack(stack, *arr);
			pushLS(stack, node);
		}
		else if (*arr != ' ')
			break;
		arr++;
	}
	if (*arr == '\0' && stack->currentElementCount == 1) //마지막 저장된 결과값 1개 일때
		rtn = (popLS(stack))->data;
	deleteLinkedStack(stack);
	return (rtn);
}

int	is_operator(char c)
{
	if (c == '*' || c == '/' || c == '+' || c == '-')
		return (TRUE);
	return (FALSE);
}

int	operate_stack(LinkedStack *stack, char c)
{
	int	rtn;
	int	a;
	int	b;

	b = (popLS(stack))->data;
	a = (popLS(stack))->data; // 순서 주의 나눗셈할때
	if (c == '+')
		rtn = a + b;
	else if (c == '-')
		rtn = a - b;
	else if (c == '*')
		rtn = a * b;
	else if (c == '/')
		rtn = a / b;
	return (rtn);
}