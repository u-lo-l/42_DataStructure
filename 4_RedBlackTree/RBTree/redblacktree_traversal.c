#include "redblacktree.h"
#include "../Queue/linkedqueue.h"

void preorderTraversal(RBTree *pTree, RBTreeNode *pNode, int (*func)(RBTreeNode *))
{
	if (!pNode || pNode == pTree->nilNode)
		return ;
	if (func) func(pNode);
	preorderTraversal(pTree, pNode->pLeftChild, func);
	preorderTraversal(pTree, pNode->pRightChild, func);
}

void inorderTraversal(RBTree *pTree, RBTreeNode *pNode, int (*func)(RBTreeNode *))
{
	if (!pNode || pNode == pTree->nilNode)
		return ;
	inorderTraversal(pTree, pNode->pLeftChild, func);
	if (func) func(pNode);
	inorderTraversal(pTree, pNode->pRightChild, func);
}

void postorderTraversal(RBTree *pTree, RBTreeNode *pNode, int (*func)(RBTreeNode *))
{
	if (!pNode || pNode == pTree->nilNode)
		return ;
	postorderTraversal(pTree, pNode->pLeftChild, func);
	postorderTraversal(pTree, pNode->pRightChild, func);
	if (func) func(pNode);
}

void levelorderTraversal(RBTree *pTree, int (*func)(RBTreeNode *))
{
	LinkedQueue *queue = createLinkedQueque();
	QueueNode	*firstNode = NULL;
	QueueNode	tempNode;
	if (!pTree)
		return ;
	if (!func)
		return ;
	tempNode.node = *(pTree->pRootNode);
	enqueueLQ(queue, tempNode);
	while (!isLinkedQueueEmpty(queue))
	{
		firstNode = dequeueLQ(queue);
		if (firstNode->node.pLeftChild != pTree->nilNode)
		{
			tempNode.node = *(firstNode->node.pLeftChild);
			enqueueLQ(queue, tempNode);
		}
		if (firstNode->node.pRightChild != pTree->nilNode)
		{
			tempNode.node = *(firstNode->node.pRightChild);
			enqueueLQ(queue, tempNode);
		}
		func(&(firstNode->node));
		free(firstNode);
	}
	deleteLinkedQueue(queue);
}