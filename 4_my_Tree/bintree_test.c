#include "AVLTree/avl_tree.h"
#include <stdio.h>
#include <stdlib.h>

int bintreeTest(void);
int binsearchtreeTest(void);
int avltreeTest(void);

int main()
{
	printf("===Tree and Nodes Initialize===\n");
	BinTreeNode	*rootNode = makeBinTreeNode(11);
	BinTreeNode	*Node1 = makeBinTreeNode(12);
	BinTreeNode	*Node2 = makeBinTreeNode(13);
	BinTreeNode	*Node3 = makeBinTreeNode(14);
	BinTreeNode	*Node4 = makeBinTreeNode(15);
	BinTreeNode	*Node5 = makeBinTreeNode(16);
	BinTreeNode	*Node6 = makeBinTreeNode(17);
	BinTreeNode	*Node7 = makeBinTreeNode(18);
	BinTreeNode	*Node8 = makeBinTreeNode(19);
	BinTreeNode	*Node9 = makeBinTreeNode(20);
	BinTreeNode	*Node10 = makeBinTreeNode(21);

	printf("==============DONE==============\n");
	BinTree *Tree = makeBinTree(*rootNode);
	addNodeAVL(Tree, *Node1);
	addNodeAVL(Tree, *Node2);
	addNodeAVL(Tree, *Node3);
	addNodeAVL(Tree, *Node4);
	addNodeAVL(Tree, *Node5);
	addNodeAVL(Tree, *Node6);
	addNodeAVL(Tree, *Node7);
	addNodeAVL(Tree, *Node8);
	addNodeAVL(Tree, *Node9);
	addNodeAVL(Tree, *Node10);
	printf("\033[1;33m");
	printf("ROOT : %d\n", getRootNodeBT(Tree)->data);
	printf("\033[0;34m");
	// balanceTree(Tree->pRootNode);
	
	printf("\033[0;32m");
	showBinTree(Tree);
	printf("\033[0m");

	printf("\033[0;36m");
	printf("====DELETE=====\n");
	deleteNodeAVL(Tree, 14);
	printf("ROOT : %d\n", getRootNodeBT(Tree)->data);
	showBinTree(Tree);
	deleteNodeAVL(Tree, 15);
	printf("ROOT : %d\n", getRootNodeBT(Tree)->data);
	showBinTree(Tree);
	deleteNodeAVL(Tree, 11);
	showBinTree(Tree);
	deleteNodeAVL(Tree, 12);
	showBinTree(Tree);
	deleteNodeAVL(Tree, 16);
	showBinTree(Tree);
	deleteNodeAVL(Tree, 20);
	showBinTree(Tree);
	deleteNodeAVL(Tree, 17);
	showBinTree(Tree);
	deleteNodeAVL(Tree, 9);
	showBinTree(Tree);

	deleteBinTree(Tree);
}

int simpleBT(void)
{
	
}