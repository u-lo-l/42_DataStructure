#include "BinTree/bintree.h"
#include "BinSearchTree/binsearchtree.h"
#include "AVLTree/avl_tree.h"
#include "ThreadTree/threadTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void test_BinTree(BinTreeNode *rootNode, BinTreeNode *Nodes[8]);
void test_BinSearchTree(BinTreeNode *rootNode, BinTreeNode *Nodes[8]);
void test_AVLTree(BinTreeNode *rootNode, BinTreeNode *Nodes[8]);
void test_ThreadedBinTree();


int main()
{
	srand(time(NULL));
	
	char data = rand()%3 + 'J';
	BinTreeNode *rootNode = makeBinTreeNode(data);
	BinTreeNode *Nodes[9];
	data -= 10;
	for (int i = 0 ; i < 9; i++)
	{
		data += rand()%4 + 1;
		Nodes[i] = makeBinTreeNode(data);
	}
	printf("================CREATED DATA=================\n");
	printf("[%c]", rootNode->data);
	for (int i = 0 ; i < 9 ; i++)
		printf("->[%c]", Nodes[i]->data);
	// printf("\n=====================BT=====================\n");
	// test_BinTree(rootNode, Nodes);
	printf("\n=====================BST====================\n");
	test_BinSearchTree(rootNode, Nodes);
	printf("\n=====================AVL====================\n");
	test_AVLTree(rootNode, Nodes);


	free(rootNode);
	for (int i = 0 ; i < 9 ; i++)
		free(Nodes[i]);
	return (0);
}

void test_BinTree(BinTreeNode *rootNode, BinTreeNode *Nodes[9])
{
	BinTree *Tree;
	Tree = makeBinTree(*rootNode);

	insertLeftChildNodeBT(Tree->pRootNode, *Nodes[4]);
	insertRightChildNodeBT(Tree->pRootNode, *Nodes[0]);
	insertRightChildNodeBT(Tree->pRootNode->pLeftChild, *Nodes[5]);
	insertRightChildNodeBT(Tree->pRootNode->pRightChild, *Nodes[3]);
	insertLeftChildNodeBT(Tree->pRootNode->pRightChild, *Nodes[1]);
	insertLeftChildNodeBT(Tree->pRootNode->pRightChild->pLeftChild, *Nodes[7]);
	insertRightChildNodeBT(Tree->pRootNode->pRightChild->pLeftChild, *Nodes[6]);
	insertLeftChildNodeBT(Tree->pRootNode->pRightChild->pLeftChild->pLeftChild, *Nodes[2]);
	insertRightChildNodeBT(Tree->pRootNode->pRightChild->pLeftChild->pLeftChild, *Nodes[8]);
	setTreeInfo(Tree);
	showBinTreeStructure(Tree);
	deleteBinTree(Tree);

	return ;
}

void test_BinSearchTree(BinTreeNode *rootNode, BinTreeNode *Nodes[9])
{
	BinTree *Tree;
	Tree = makeBinTree(*rootNode);

	addNodeBST(Tree, *Nodes[4]);
	addNodeBST(Tree, *Nodes[0]);
	addNodeBST(Tree, *Nodes[5]);
	addNodeBST(Tree, *Nodes[3]);
	addNodeBST(Tree, *Nodes[1]);
	addNodeBST(Tree, *Nodes[7]);
	addNodeBST(Tree, *Nodes[6]);
	addNodeBST(Tree, *Nodes[2]);
	addNodeBST(Tree, *Nodes[8]);
	setTreeInfo(Tree);
	showBinTreeStructure(Tree);
	for (int i = 0 ; i < 8 ; i++)
	{
		deleteNodeBST(Tree, Nodes[i]->data);
		setTreeInfo(Tree);
		showBinTreeStructure(Tree);
	}	
	deleteBinTree(Tree);
	
	return ;
}

void test_AVLTree(BinTreeNode *rootNode, BinTreeNode *Nodes[9])
{
	BinTree *Tree;
	Tree = makeBinTree(*rootNode);

	addNodeAVL(Tree, *Nodes[4]);
	addNodeAVL(Tree, *Nodes[0]);
	addNodeAVL(Tree, *Nodes[5]);
	addNodeAVL(Tree, *Nodes[3]);
	addNodeAVL(Tree, *Nodes[1]);
	addNodeBST(Tree, *Nodes[7]);
	addNodeAVL(Tree, *Nodes[6]);
	addNodeAVL(Tree, *Nodes[2]);
	addNodeAVL(Tree, *Nodes[8]);
	setTreeInfo(Tree);
	showBinTreeStructure(Tree);
	for (int i = 0 ; i < 8 ; i++)
	{
		deleteNodeAVL(Tree, Nodes[i]->data);
		setTreeInfo(Tree);
		showBinTreeStructure(Tree);
	}	
	deleteBinTree(Tree);

	
	return ;
}
