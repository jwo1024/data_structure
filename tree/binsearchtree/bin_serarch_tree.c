#include	"bin_search_tree.h"

// 트리 생성
// 검색
// 자료 추가
// 자료 제거

BinTreeNode	*searchBinTreeNode()
{

}

/*
search( tree, key ) {
	result ← tree->pRootNode
	while(result != NULL)
	{
		if (key == result ->key)
			break
		else if (key < result ->key)
			result = result ->pLeftChild
		else
			result = result ->pRightChild
	}
	return result
}
*/

BinTreeNode *insertBinSearchTree(BinTreeNode *element, int key)
{
	// if (element == NULL)
	// 같은 노드가 있는지 search
	// 있다면 printf("fail to insert : same key\n");
	// key < element->key
	// 	search(element->left, key);
	// else
	// 	search(element->right, key);
	// return;
}

BinTreeNode *deleteBinSearchTree(BinTree *BinTree, BinTreeNode element)
{
	// 삭제하려는 노드 검색
	// 없는 경우 null return
	// 자식 노드가 1개인 경우
		// 삭제노드의 부모노드와 삭제노드의 자식노드 연결
	// 자식 노드가 2개인 경우
		// 삭제할 노드와 가장 근사랎을 가지 노드(직후, 혹은 직전 노드)를 삭제할 위치로 가져옴
		// 왼쪽 서브트리의 가장 큰 값 ?
		// 오른족 서브트리의 가장 작은 값 ?
}


