#include	"arraystack.h"

void	deleteArrayStack(ArrayStack* pStack)
{
	if (NULLCHECK(pStack))
		return ;
	free(pStack->pElement);
	free(pStack);
}

// 할당 해제시 꼭 데이터를 초기화 하지 않아도 되지 않을까
// 데이터를 초기화하고 할당 해제를 했을때 그 주소를 다시 참조하면 쓰레기값이 나옴
// 새로 할당 받을때만 초기화 후 사용한다면 문제 없을것 같다.