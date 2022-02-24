#include "bintree_traversal.h"

void preorderTraversal(BinTreeNode *pNode, int (*func)(BinTreeNode *))
{
	if (!pNode || !func)
		return ;

	func(pNode);
	preorderTraversal(pNode->pLeftChild, func);
	preorderTraversal(pNode->pRightChild, func);
}

void inorderTraversal(BinTreeNode *pNode, int (*func)(BinTreeNode *))
{
	if (!pNode || !func)
		return ;

	inorderTraversal(pNode->pLeftChild, func);
	func(pNode);
	inorderTraversal(pNode->pRightChild, func);
}

void postorderTraversal(BinTreeNode *pNode, int (*func)(BinTreeNode *))
{
	if (!pNode || !func)
		return ;

	postorderTraversal(pNode->pLeftChild, func);
	postorderTraversal(pNode->pRightChild, func);
	func(pNode);
}

void levelorderTraversal(BinTree *pBinTree, int (*func)(BinTreeNode *))
{
	LinkedQueue *queue = createLinkedQueque();
	QueueNode	*firstNode = NULL;
	QueueNode	tempNode;
	if (!pBinTree)
		return ;
	if (!func)
		return ;
	tempNode.node = *(pBinTree->pRootNode);
	enqueueLQ(queue, tempNode);
	while (!isLinkedQueueEmpty(queue))
	{
		firstNode = dequeueLQ(queue);
		if (firstNode->node.pLeftChild)
		{
			tempNode.node = *(firstNode->node.pLeftChild);
			enqueueLQ(queue, tempNode);
		}
		if (firstNode->node.pRightChild)
		{
			tempNode.node = *(firstNode->node.pRightChild);
			enqueueLQ(queue, tempNode);
		}
		func(&(firstNode->node));
		free(firstNode);
	}
	deleteLinkedQueue(queue);
}
