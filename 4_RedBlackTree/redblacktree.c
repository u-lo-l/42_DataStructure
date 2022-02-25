#include "redblacktree.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * data를 이용해서 노드를 하나 생성한다.
 * 색은 red, 포인터는 0으로 초기화한다.
*/
RBTreeNode *makeRBTreeNode(char data)
{
	RBTreeNode *newNode;
	if (data < 0)
		return (NULL);
	newNode = calloc(1, sizeof(RBTreeNode));
	if (!newNode)
		return (NULL);
	newNode->data = data;
	return (newNode);
}

int deleteRBTreeNode(RBTreeNode *pNode)
{
	free(pNode);
}

/*
 * 빈 트리를 생서한다.
 * red black트리의 특징인 nil노드를 포함한다.
 * nil노드는 black노드이다.
 * 
*/
RBTree *makeRBTree(void)
{
	RBTree *newTree;
	RBTreeNode *nil;

	newTree = malloc(sizeof(RBTree));
	if (!newTree)
		return (NULL);
	nil = makeRBTreeNode(' ');
	if (!nil)
	{
		free(newTree);
		newTree = NULL;
		return (NULL);
	}
	newTree->nilNode = nil;
	newTree->nilNode->color = black;
	newTree->pRootNode = NULL;
	return (newTree);
}

/*후위순회를 이용해서 노드를 제거하고 트리를 제거한다.*/
void deleteRBTree(RBTree **ppTree)
{
	if (!ppTree || !*ppTree)
		return ;
	postorderTraversal((*ppTree), (*ppTree)->pRootNode, deleteRBTreeNode);
	free((*ppTree)->nilNode);
	free(*ppTree);
	*ppTree = NULL;
}

/*
 * AVL트리의 LL-Rotation과 비슷하다.(parent 포인터가 추가되었다.) 
 * temp는 서브트리의 새 root가 되는 노드이고, pNode는 기존 루트노드이다.
 * step 1 :	 root의 left가 temp의 right_subtree를 가리키도록 한다.
 * 			subtree가 아니라 nil이라면 nilnode는 parent노드가 없으므로
 * 			그냥 넘어가고
 * 			nil가 아니라면, subtree의 parent가 root를 가리키도록 한다.
 * 			그 후 temp의 parent가 root의 parent를 가리키도록 한다.
 * step 2 :	 root와  root의 Parent사이의 관계에 따라 3가지로 나뉜다.
 * 	2-1	->	root->parent == Nil (root가 트리의 루트)
 * 			트리의 루트노드가 temp를 가리키도록 한다.
 * 	2-2 ->	root가 어떤 노드의 leftChild인 경우
 * 			그 노드의 leftchild가 temp를 가리키도록 한다.
 * 	2-3	->	root가 어떤 노드의 rightChild인 경우
 * 			그 노드의 rightChild가 temp를 가리키도록 한다.
 * step 3 :	 원래 루트였던 root를 새 루트인 temp의 rightchild가 되도록 한다.
 * 			root의 parent가 temp를 가리키도록 한다.
 * 이후 새 루트노드인 temp를 반환한다.
 */
void rightRotation(RBTree *pTree, RBTreeNode *pNode)
{
	printf("R rot\n");
	RBTreeNode *temp;

	if (!pTree || !pNode)
		return ;
	temp = pNode->pLeftChild;
	//step1
	pNode->pLeftChild = temp->pRightChild;
	if (temp->pRightChild != pTree->nilNode)
		temp->pRightChild->pParent = pNode;
	temp->pParent = pNode->pParent;
	//step2
	if (temp->pParent == pTree->nilNode)
		pTree->pRootNode = temp;
	else if (pNode == pNode->pParent->pLeftChild)
		pNode->pParent->pLeftChild = temp;
	else if (pNode == pNode->pParent->pRightChild)
		pNode->pParent->pRightChild = temp;
	//step3
	temp->pRightChild = pNode;
	pNode->pParent = temp;
}

/*rightRotation과 대칭적으로 작동한다.*/
void leftRotation(RBTree *pTree, RBTreeNode *pNode)
{
	printf("L rot\n");
	RBTreeNode *temp;
	if (!pTree || !pNode)
		return ;
	temp = pNode->pRightChild;
	pNode->pRightChild = temp->pLeftChild;
	if (temp->pLeftChild != pTree->nilNode)
		temp->pLeftChild->pParent = pNode;
	temp->pParent = pNode->pParent;
	if (temp->pParent == pTree->nilNode)
		pTree->pRootNode = temp;
	else if (pNode == pNode->pParent->pLeftChild)
		pNode->pParent->pLeftChild = temp;
	else if (pNode == pNode->pParent->pRightChild)
		pNode->pParent->pRightChild = temp;
	temp->pLeftChild = pNode;
	pNode->pParent = temp;
}

/*
 * 레드블랙 트리에 노드를 추가할 때 발생하는 경우의 수는 4가지이다.
 * 그 중 parentnNode가 red일 때 restruct가 필요하다.
 * 여기서 전달 받은 
*/
RBTreeNode *addRestructTree(RBTree *pTree, RBTreeNode *pNode)
{
	RBTreeNode *uncle;
	RBTreeNode *temp;
	if (!pTree || !pNode)
		return (NULL);
	if (pNode->pParent->color == black)
		return (NULL);
	while (pNode->pParent->color == red)
	{
		if (pNode->pParent == pNode->pParent->pParent->pLeftChild)
		{
			uncle = pNode->pParent->pParent->pRightChild;
			if (uncle->color == red)
			{
				pNode->pParent->color = uncle->color = black;
				pNode->pParent->pParent->color = red;
				pNode = pNode->pParent->pParent;
			}
			else
			{
				if(pNode == pNode->pParent->pRightChild)
					leftRotation(pTree, pNode->pParent);
				rightRotation(pTree, pNode->pParent);
				pNode->color = black;
				pNode->pRightChild = red;
			}
		}
		else
		{
			uncle = pNode->pParent->pParent->pLeftChild;
			if (uncle->color == red)
			{
				pNode->pParent->color = uncle->color = black;
				pNode->pParent->pParent->color = red;
				pNode = pNode->pParent->pParent;
			}
			else
			{
				if (pNode == pNode->pParent->pLeftChild)
					rightRotation(pTree, pNode->pParent);
				else
					pNode = pNode->pParent;
				pNode->color = black;
				pNode->pParent->color = red;
				leftRotation(pTree, pNode->pParent);
			}
		}
	}
	pTree->pRootNode->color = black;
	return (pNode);
}

static void addNodeRBrecursive(RBTree *pTree,
								RBTreeNode *pNode,
								int key)
{
	RBTreeNode *temp;
	RBTreeNode *newNode;
	newNode = makeRBTreeNode(key);
	newNode->pParent = pNode;
	newNode->pLeftChild = pTree->nilNode;
	newNode->pRightChild = pTree->nilNode;
	if (key == pNode->data)
	{
		printf("\033[0;31m");
		printf("Duplicated value is not allowed : %c\n", pNode->data);
		printf("\033[0m");
		deleteRBTreeNode(newNode);
		return ;
	}
	else if (key < pNode->data)
	{
		if (pNode->pLeftChild == pTree->nilNode)
		{
			pNode->pLeftChild = newNode;
			addRestructTree(pTree, pNode->pLeftChild);
		}
		else
		{
			addNodeRBrecursive(pTree, pNode->pLeftChild, key);
		}
	}
	else
	{
		if (pNode->pRightChild == pTree->nilNode)
		{
			pNode->pRightChild = newNode;
			addRestructTree(pTree, pNode->pRightChild);
		}
		else
			addNodeRBrecursive(pTree, pNode->pRightChild, key);
	}
}

int addNodeRB(RBTree *pTree, RBTreeNode element)
{
	RBTreeNode *newNode;
	if (!pTree)
		return (0);
	printf("ADD START : %c\n", element.data);
	if (pTree->pRootNode == NULL || pTree->pRootNode == pTree->nilNode)
	{	
		printf("ADD TO ROOT\n");
		newNode = makeRBTreeNode(element.data);
		newNode->color = black;
		newNode->pLeftChild = pTree->nilNode;
		newNode->pRightChild = pTree->nilNode;
		pTree->pRootNode = newNode; 
	}
	else
		addNodeRBrecursive(pTree, pTree->pRootNode, element.data);
	pTree->pRootNode->pParent = pTree->nilNode;
	return (1);
}
