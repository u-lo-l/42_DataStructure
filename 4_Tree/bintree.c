#include "bintree.h"
#include <stdlib.h>

BinTree		*makeBinTree(BinTreeNode rootNode)
{
	BinTree	*bintree;
	BinTreeNode *newNode;

	bintree = (BinTree *)calloc(1, sizeof(BinTree));
	if (!bintree)
		return NULL;
	newNode = (BinTreeNode *)calloc(1, sizeof(BinTreeNode));
	newNode->data = rootNode.data;
	bintree->pRootNode = newNode;
	// *(bintree->pRootNode) = rootNode;
	return (bintree);
}

BinTreeNode	*getRootNodeBT(BinTree* pBinTree)
{
	if (!pBinTree)
		return NULL;
	return (pBinTree->pRootNode);
}

/*
	1) data가 parentnode->data보다 크면 : 
		1-1) rightchildnode != NULL
			rightchildnode를 새 parentnode로 재귀
		1-2) rightchildnode == NULL
			insertRightChildNodeBT();
	2) data가 parentnode->Data보다 작으면
		2-1) leftchildnode != NULL
			leftchildnode를 새 parentnode로 재귀
		2-2) leftchildnode == NULL
			insertLeftChildNode();
	3) 같으면 에러 출력
*/

static void	insertLeftChildNodeBT(BinTreeNode* pParentNode, int data)
{
	BinTreeNode	*newnode;

	newnode = (BinTreeNode *)calloc(1, sizeof(BinTreeNode));
	if (!newnode)
		return ;
	newnode->data = data;
	pParentNode->pLeftChild = newnode;
}

static void	insertRightChildNodeBT(BinTreeNode* pParentNode, int data)
{
	BinTreeNode	*newnode;

	newnode = (BinTreeNode *)calloc(1, sizeof(BinTreeNode));
	if (!newnode)
		return ;
	newnode->data = data;
	pParentNode->pRightChild = newnode;
}

void	insert(BinTreeNode *pParentNode, int data)
{
	if (!pParentNode)
		return ;
	if (data > pParentNode->data)
	{
		if (getRightChildNodeBT(pParentNode))
			insert(pParentNode->pRightChild, data);
		else
			insertRightChildNodeBT(pParentNode, data);
	}
	else if (data < pParentNode->data)
	{
		if (getLeftChildNodeBT(pParentNode))
			insert(pParentNode->pLeftChild, data);
		else
			insertLeftChildNodeBT(pParentNode, data);
	}
	else
		printf("ERROR : Node overlapped");
}

BinTreeNode	*getLeftChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode)
		return NULL;
	return (pNode->pLeftChild);
}

BinTreeNode	*getRightChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode)
		return NULL;
	return (pNode->pRightChild);
}

/*
후위 순회를 통해 모든 노드 free, 전체 트리도 free
*/
static void	deleteBinTreeNodeByPostorder(BinTreeNode *node)
{
	if (!node)
		return ;
	deleteBinTreeNodeByPostorder(node->pLeftChild);
	deleteBinTreeNodeByPostorder(node->pRightChild);
	free(node);
}

void		deleteBinTree(BinTree* pBinTree)
{
	if (!pBinTree || !pBinTree->pRootNode)
		return ;
	deleteBinTreeNodeByPostorder(pBinTree->pRootNode);
	free(pBinTree);
}