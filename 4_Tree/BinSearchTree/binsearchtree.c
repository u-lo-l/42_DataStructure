#include "binsearchtree.h"
#include <stdio.h>

BinTreeNode *addNodeBSTrecursive(BinTreeNode *root,
								BinTreeNode element,
								BinTreeNode *(*func)(BinTreeNode *))
{
	BinTreeNode *temp;
	if (element.data == root->data)
	{	
		printf("\033[0;31m");
		printf("Duplicated value is not allowed : %c\n", root->data);
		printf("\033[0m");
		return (root);
	}
	else if (element.data < root->data)
	{
		if (root->pLeftChild)
		{
			temp = addNodeBSTrecursive(root->pLeftChild, element, func);
			if (temp)
				root->pLeftChild = temp;
		}
		else
			insertLeftChildNodeBT(root, element);
	}
	else
	{
		if (root->pRightChild)
		{
			temp = addNodeBSTrecursive(root->pRightChild, element, func);
			if (temp)
				root->pRightChild = temp;
		}
		else
			insertRightChildNodeBT(root, element);
	}
	if (func) 
		root = func(root);
	return (root);
}
int addNodeBST(BinTree *bst, BinTreeNode element)
{
	BinTreeNode *temp;
	if (!bst)
	{
		printf("\033[0;31m<ERR> Invalid tree\n\033[0m");
		return (-1);
	}
	temp = addNodeBSTrecursive(bst->pRootNode, element, NULL);
	if (temp)
		bst->pRootNode = temp;
	return (1);
}

static BinTreeNode* getNodeByDataBSTreculsive(BinTreeNode *root, int data)
{
	if (root == NULL)
		return (NULL);
	if (data == root->data)
		return (root);
	else if (data < root->data)
		return (getNodeByDataBSTreculsive(root->pLeftChild, data));
	else
		return (getNodeByDataBSTreculsive(root->pRightChild, data));
}
BinTreeNode* getNodeByDataBST(BinTree* bst, int data)
{
	BinTreeNode *currNode;
	return (getNodeByDataBSTreculsive(bst->pRootNode, data));
}


/*
 * 이진 탐색 트리의 규칙을 유지하면서, 트리의 특정 노도를 삭제하는 함수이다.
 * 	1) 트리가 부적절한 경우 segfault가 뜬다. root노드가 NULL이라면, NULL을 반환한다.
 * 	2) 찾고자 하는 데이터(key)와 루트노드의 데이터를 비교한다.
 * 		2-1) key가 더 작은 경우, 왼쪽 서브트리에서 함수를 다시 실행한다.
 * 			 왼쪽 서브트리에서 반환 받는 노드를 루트의 왼쪽자식으로 한다.
 * 			 (서브트리의 루트노드가 삭제 할 노드가 아니라면, 서브트리의 루트노드가 반환되어서 결과적으로 루트의 왼쪽자식은 바뀌지 않는다.)
 * 			 (서브트리의 루트노드가 삭제 할 노드라면, 서브트리에서의 successor가 반환되어서 결과적으로 루트의 왼쪽자식이 바뀐다.)
 * 
 * 		2-2) key가 더 큰 경우, 오른쪽 서브트리에서 함수를 다시 실행한다.
 * 			 오른쪽 서브트리에서 반환 받는 노드를 루트의 오른쪽자식으로 한다.
 * 			 (서브트리의 루트노드가 삭제 할 노드가 아니라면, 서브트리의 루트노드가 반환되어서 결과적으로 루트의 왼쪽자식은 바뀌지 않는다.)
 * 			 (서브트리의 루트노드가 삭제 할 노드라면, 서브트리에서의 successor가 반환되어서 결과적으로 루트의 왼쪽자식이 바뀐다.)
 * 
 * 		2-3) key와 로트노드의 데이터가 일치하는 경우, 4가지 케이스로 분류할 수 있다.
 * 			 (리프노드인 경우, 왼쪽자식만 있는 경우, 오른쪽 자식만 있는 경우, 둘 다 있는 경우)
 * 			 둘 다 있는 경우, 오른쪽 서브트리에서 가장 작은 노드를 successor node로 채택 할 것이다.
 * 
 * 			2-3-1) <리프노드인 경우, 오른쪽 자식만 있는 경우>
 * 					루트노드의 오른쪽 자식을 successor로 채택한다.(루트가 리프인경우, successor = NULL)
 * 
 * 					[현재 루트노드가 전체 트리의 루트노드와 일치 할 경우]
 * 					-> 전체 트리의 루트노드가 successor를 가리키도록 하고, 기존 root를 지운다.
 * 					-> succesor를 반환한다.
 * 					-> 결과적으로 재귀함수가 종료된다.
 * 					[현재 루트노드가 전체 트리의 루트노드가 아닌 경우]
 * 					-> 루트노드를 지우고, successor를 반환한다.
 * 					-> 반환된 successor는 2-1) 이나 2-2) 에서 불러진 함수에서 반환된다.
 * 
 * 			2-3-2) <왼쪽 자식만 있는 경우>
 * 					루트노드의 왼쪽 자식을 successor로 채택한다.
 * 
 * 					[현재 루트노드가 전체 트리의 루트노드와 일치 할 경우]
 * 					-> 전체 트리의 루트노드가 successor를 가리키도록 하고, 기존 root를 지운다.
 * 					-> 결과적으로 재귀함수가 종료된다.
 * 					[현재 루트노드가 전체 트리의 루트노드가 아닌 경우]
 * 					-> 루트노드를 지우고, successor를 반환한다.
 * 					-> 반환된 successor는 2-1) 이나 2-2) 에서 불러진 함수에서 반환된다.
 * 
 * 			2-3-3) <둘 다 있는 경우>
 * 					루트노드의 오른쪽 서브트리에서 가장 작은 노드를 successor로 채택한다.
 * 					루트노드의 데이터를 successor의 데이터로 바꾸고, successor를 지우기 위해
 * 					root->rightchild와 successor의 data를 이용해, root의 오른쪽 서브트리에서 함수를 반복한다.
*/
BinTreeNode *deleteNodeBSTrecursive(BinTree *tree,
									BinTreeNode *root,
									int data,
									BinTreeNode *(*func)(BinTreeNode *))
{
	BinTreeNode *successor;

	if (!root)
	{
		printf("\033[0;31mThere is no matching Node\n\033[0m");
		return (NULL);
	}
	if (data < root->data)
		root->pLeftChild = deleteNodeBSTrecursive(tree, root->pLeftChild, data, func);
	else if (data > root->data)
		root->pRightChild = deleteNodeBSTrecursive(tree, root->pRightChild, data, func);
	else // key == data!! else 부분은 결과적으로 successor를 return해서 if와 elseif 케이스에 반환해준다.
	{
		if (root->pLeftChild == NULL)				//삭제할 노드가 리프노드이거나 오른쪽 자식만 있거나
			successor = root->pRightChild;			
		else if (root->pRightChild == NULL)			//삭제할 노드가 왼쪽자식만 있는 경우
			successor = root->pLeftChild;
		else										//둘 다 있을 때
		{
			successor = root->pRightChild;
			while (successor->pLeftChild)
				successor = successor->pLeftChild;
			root->data = successor->data;
			root->pRightChild = deleteNodeBSTrecursive(tree, root->pRightChild, successor->data, func);
			return (root);
		}
		deleteBinTreeNode(root);
		return (successor);
	}
	if (func) root = func(root);
	return (root);
}
int deleteNodeBST(BinTree *bst, int data)
{
	if (bst == NULL)
		return (-1);
	bst->pRootNode = deleteNodeBSTrecursive(bst, bst->pRootNode, data, NULL);
	return (1);
}
