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
	return (1);
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
	RBTreeNode *Nil;

	newTree = malloc(sizeof(RBTree));
	if (!newTree)
		return (NULL);
	Nil = makeRBTreeNode(' ');
	if (!Nil)
	{
		free(newTree);
		newTree = NULL;
		return (NULL);
	}
	newTree->nilNode = Nil;
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

static RBTreeNode *addRestructTree(RBTree *pTree, RBTreeNode *pNode);
static void addNodeRBrecursive(RBTree *pTree, RBTreeNode *pNode, int key);
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

/*
 * 레드블랙 트리에 노드를 추가할 때 발생하는 경우의 수는 4가지이다.
 * 그 중 parentnNode가 red일 때 restruct가 필요하다.
 * 여기서 전달 받은 
*/
static RBTreeNode *addRestructTree(RBTree *T, RBTreeNode *N)
{
	RBTreeNode *uncle;
	RBTreeNode *temp;
	if (!T || !N)
		return (NULL);
	if (N->pParent->color == black)
		return (NULL);
	while (N->pParent->color == red)
	{
		if (N->pParent == N->pParent->pParent->pLeftChild)
		{
			uncle = N->pParent->pParent->pRightChild;
			if (uncle->color == red)
			{
				N->pParent->color = uncle->color = black;
				N->pParent->pParent->color = red;
				N = N->pParent->pParent;
			}
			else
			{
				if(N == N->pParent->pRightChild)
					leftRotation(T, N->pParent);
				rightRotation(T, N->pParent);
				N->color = black;
				N->pRightChild->color = red;
			}
		}
		else
		{
			uncle = N->pParent->pParent->pLeftChild;
			if (uncle->color == red)
			{
				N->pParent->color = uncle->color = black;
				N->pParent->pParent->color = red;
				N = N->pParent->pParent;
			}
			else
			{
				if (N == N->pParent->pLeftChild)
					rightRotation(T, N->pParent);
				else
					N = N->pParent;
				N->color = black;
				N->pParent->color = red;
				leftRotation(T, N->pParent);
			}
		}
	}
	T->pRootNode->color = black;
	return (N);
}

static void addNodeRBrecursive(RBTree *T, RBTreeNode *N, int key)
{
	RBTreeNode *temp;
	RBTreeNode *newNode;
	newNode = makeRBTreeNode(key);
	newNode->pParent = N;
	newNode->pLeftChild = T->nilNode;
	newNode->pRightChild = T->nilNode;
	if (key == N->data)
	{
		printf("\033[0;31m");
		printf("Duplicated value is not allowed : %c\n", N->data);
		printf("\033[0m");
		deleteRBTreeNode(newNode);
		return ;
	}
	else if (key < N->data)
	{
		if (N->pLeftChild == T->nilNode)
		{
			N->pLeftChild = newNode;
			addRestructTree(T, N->pLeftChild);
		}
		else
		{
			addNodeRBrecursive(T, N->pLeftChild, key);
		}
	}
	else
	{
		if (N->pRightChild == T->nilNode)
		{
			N->pRightChild = newNode;
			addRestructTree(T, N->pRightChild);
		}
		else
			addNodeRBrecursive(T, N->pRightChild, key);
	}
}

static int delRestructTree(RBTree* pTree, RBTreeNode *pNode);
static RBTreeNode *delNodeRBRecursive(RBTree* pTree, RBTreeNode *pNode, char key);
int deleteNodeRB(RBTree *pTree, RBTreeNode element)
{
	RBTreeNode *result;
	if (!pTree)
		return (0);
	printf("DEL %c from tree\n", element.data);
	
	result = delNodeRBRecursive(pTree, pTree->pRootNode, element.data);
	if (result == NULL) return (0);
	pTree->pRootNode = result;
	pTree->pRootNode->color = black;
	return (1);
}
/*
 * 기본적으로 이진탐색트리에서 노드 삭제 방법을 이어받는다.
 *  한 가지 다른 점은 노드의 parent포인터가 추가되었다는 점이다.
 * parentnode를 알기때문에, 함수 내부에서 부모노드의 자식에 대해 수정해줄 수 있어서
 * 반환 타입이 Node *가 아니여도 된다. 대신 부모의 자식노드이동에 대한 절차가 추가된다.
*/
static RBTreeNode *delNodeRBRecursive(RBTree *T, RBTreeNode *N, char key)
{
	RBTreeNode *result;
	int N_color = black; // 삭제할 노드의 색을 저장할 자료이다.
	RBTreeNode *successor;
	if (!T || !N)	return (NULL);
	if (N == T->nilNode)
	{
		printf("Reach to nilnode. fail to find key:[%c]\n", key);
		return (NULL);
	}
	if (key < N->data)
	{
		result = delNodeRBRecursive(T, N->pLeftChild, key);
		if (result == NULL)	return (NULL);
		N->pLeftChild = result;
	}
	else if (key > N->data)
	{
		result = delNodeRBRecursive(T, N->pRightChild, key);
		if (result == NULL)	return (NULL);
		N->pRightChild = result;
	}
	else 
	{
		N_color = N->color;
		N->color = black;						//successor가 N의 자리에 오게 될텐데 successor의 색을 black으로 바꿔준다.
		if (N->pLeftChild == T->nilNode)		// 오른쪽 자식만 있거나 리프노드이거나
			successor = N->pRightChild;
		else if (N->pRightChild == T->nilNode)	// 왼쪽 자식만 있는 경우
			successor = N->pLeftChild;
		else									// 둘 다 있는 경우. 이 경우는 위의 두 케이스를 만날 때 까지 재귀한다.
		{
			successor = N->pRightChild;
			while(successor->pLeftChild != T->nilNode)
				successor = successor->pLeftChild;

			N->data = successor->data;			//N을 successor로 대체하고

			result = delNodeRBRecursive(T, N->pRightChild, successor->data); //N의 오른쪽 서브트리에서 재귀한다.
			if (result == NULL)	return(NULL);
			N->pRightChild = result;

			return (N);
		}
		// 자식의 수가 0이거나 1인 경우에 편하게 삭제할 수 있다.
		deleteRBTreeNode(N);
		return (successor);
	}
	if (N_color == red)
		delRestructTree(T, N);
	return (N);
}
/*
 * 삭제되는 노드가 red인 경우, 별다른 과정 없이 그냥 삭제하면 된다.
 * 삭제되는 노드가 검정인 경우 삭제되는 노드의 "successor를 검정으로 바꾼다".
 * 검정으로 색이 바뀌게 되는 노드의 기존 색에 따라 경우의 수가 나뉜다.
 * RED		: 이진 탐색 트리의 규칙에 맞게 삭제한다.
 * BLACK	: black이 black으로 바뀌게 되는 경우를 double black이라 하며
 *			  4가지 case로 분류할 수 있다.(좌우 대칭이므로 총 8개)
 *[삭제되는 노드를 C, 부모 형제를 각각 P, S라 하고 S의 왼쪽, 오른쪽자식을 가각 SL, SR이라 가정]
 *
 *- CASE 1 -: S가 red인 경우
 *----------> P를 red, S를 black으로 바꾼다. 이후 P를 기준으로 rotation한다.
 *
 *- CASE 2 -: S, SL, SR이 모두 black인 경우
 *----------> S를 red로 바꾸고, 색이 바뀌는 대상을 P로 바꾼다.
 *			  P가 red였다면, 그냥 black으로 바꿔주면 된다.
 *			  P가 black이라면 다시 double black상황이므로 CASE1~4에 따라 다시 조정한다.
 *
 *- CASE 3 -: S가 black, SL이 red, SR이 black인 경우
 *----------> S를 red, SL을 black으로 바꾼 뒤 S, SL를 기준으로 rotation한다. 이후 CASE 를 다시 확인한다.
 *
 *- CASE 4 -: S가 black SR이 red인 경우 (SL의 색은 관련 없음)
 *----------> S의 색을 P의 색으로 바꾼다. (P가 red라면 red, P가 black이라면 black으로 바꾼다.)
 *			  이후 P, S를 기준으로 rotation한다.
*/
static int delRestructTree(RBTree *T, RBTreeNode *N)
{
	RBTreeNode *P, *S, *SL, *SR;
	if (!T || !N)
		return (0);
	while (N->color == black) // 삭제되는 노드인 N이 red인 경우, 그냥 넘어가면 된다.
	{
		P = N->pParent;
		if (N == P->pLeftChild)
		{
			S = P->pRightChild;
			SL = S->pLeftChild;
			SR = S->pRightChild;
			if (S->color == red)
			{
				P->color = red;
				S->color = black;
				leftRotation(T, P);
				// N = P;
			}
			else if (S->color == black && SL->color == black && SR->color == black)
			{
				S->color = red;
				N = P;
			}
			else if (S->color == black && SL->color == red && SR->color == black)
			{
				S->color = red;
				SL->color = black;
				rightRotation(T, S);
			}
			else if (S->color == black && SR->color == red)
			{
				S->color = P->color;
				P->color = black;
				SR->color = black;
				leftRotation(T, P);
			}
		}
		else
		{
			S = P->pLeftChild;
			SL = S->pLeftChild;
			SR = S->pRightChild;
			if (S->color == red)
			{
				P->color = red;
				S->color = black;
				rightRotation(T, P);
				// N = P;
			}
			else if (S->color == black && SL->color == black && SR->color == black)
			{
				S->color = red;
				N = P;
			}
			else if (S->color == black && SR->color == red && SL->color == black)
			{
				S->color = red;
				SR->color = black;
				leftRotation(T, S);
			}
			else if (S->color == black && SL->color == red)
			{
				S->color = P->color;
				P->color = black;
				SL->color = black;
				rightRotation(T, P);
			}
		}
	}
	return (1);
}