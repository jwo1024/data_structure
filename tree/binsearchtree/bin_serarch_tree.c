#include	"bin_search_tree.h"
// 트리 생성
// 검색
// 자료 추가
// 자료 제거

BinTree* makeBinSearchTree(BinTreeNode rootNode)
{
    BinTree *newTree;

	newTree = calloc(1, sizeof(BinTree));
	newTree->pRootNode = calloc(1, sizeof(BinTreeNode));
	newTree->pRootNode->data = rootNode.data;
	newTree->pRootNode->key = rootNode.key;
	return(newTree);
}

BinTreeNode* searchBinTreeNode(BinTree *tree, int key) // 같은 key 값이 있는지 체크해주어야 한다.
{
	BinTreeNode	*result;
	BinTreeNode	*next;
	
	result = tree->pRootNode;
	while(result != NULL)
	{
		if (key == result->key)
			break ;
		else if (key < result->key)
			result = result ->pLeftChild;
		else
			result = result ->pRightChild;
	}
	return result;
}

BinTreeNode* insertBinSearchTree(BinTree *tree, BinTreeNode element)
{
	BinTreeNode *pParentNode;
	BinTreeNode *currentNode;

	pParentNode = tree->pRootNode;
    if (searchBinTreeNode(tree, element.key))
		return (NULL);
	while (currentNode)
	{
		pParentNode = currentNode;
       	currentNode = (pParentNode->key > element.key ? pParentNode->pLeftChild : pParentNode->pRightChild);
    }
	currentNode = calloc(1, sizeof(BinTreeNode));
	if (pParentNode->key > element.key)
		pParentNode->pLeftChild = currentNode;
	else
		pParentNode->pRightChild = currentNode;
	currentNode->data = element.data;
	currentNode->key = element.key;
	
	return (currentNode);
}





static BinTreeNode* find_minimum_search(BinTreeNode* pNode)
{
    while (pNode->pLeftChild)
		pNode = pNode->pLeftChild;
    return (pNode);
}

void deleteBinSearchTreeNode(BinTreeNode* pNode, BinTree *tree)
{
	BinTreeNode *tmp;
 	BinTreeNode	*next;

	if (!pNode)
		;
	    //zero
	else if (!pNode->pLeftChild && !pNode->pRightChild)
    {
        if (pNode == tree->pRootNode)
            tree->pRootNode = NULL;
        else if (pNode->parent->pLeftChild == pNode)
            pNode->parent->pLeftChild = NULL;
        else if (pNode->parent->pRightChild == pNode)
            pNode->parent->pRightChild = NULL;
        free(pNode);
    }
        //two
    else if (pNode->pLeftChild && pNode->pRightChild)
    {
        tmp = find_minimum_search(pNode->pRightChild);
        pNode->data = tmp->data;
        if(tmp != pNode->pRightChild)
        {
            tmp->parent->pLeftChild = NULL;
            free(tmp);
        }
        else
        {
            free(tmp);
            pNode->pRightChild = NULL;
        }
    }
        //one
    else
    {
        next = pNode->pLeftChild ? pNode->pLeftChild : pNode->pRightChild;
        if (pNode->parent == 0)
            tree->pRootNode->data = next->data;
        else if(pNode->parent->pLeftChild == pNode)
            pNode->data = next->data;
        else
            pNode->data = next->data;
        pNode->pLeftChild = NULL;
        pNode->pRightChild = NULL;
        free(next);
    }
}



int main()
{
    BinTreeNode node;
	BinTreeNode	*tmp;

	node.data = 'a';
    node.key = 10;
    BinTree *tree = makeBinSearchTree(node);
    node.key = 15;
    insertBinSearchTree(tree, node);
    node.key = 20;
    insertBinSearchTree(tree, node);
    node.key = 5;
    insertBinSearchTree(tree, node);
    node.key = 0;
    insertBinSearchTree(tree, node);
    node.key = -5;
    insertBinSearchTree(tree, node);
	
	
	tmp = searchBinTreeNode(tree, 15);
	//if (tmp == NULL)	
		printf("key %d data %c\n", tmp->key, tmp->data);

//    preOrderTraversalBinTree(tree->pRootNode);
    return (0);
}