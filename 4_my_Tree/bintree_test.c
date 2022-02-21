#include "BinSearchTree/binsearchtree.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("===Tree and Nodes Initialize===\n");
	BinTreeNode	*rootNode = makeBinTreeNode(11);
	// BinTreeNode	*Node1 = makeBinTreeNode(6);
	// BinTreeNode	*Node2 = makeBinTreeNode(8);
	// BinTreeNode	*Node3 = makeBinTreeNode(19);
	// BinTreeNode	*Node4 = makeBinTreeNode(4);
	// BinTreeNode	*Node5 = makeBinTreeNode(10);
	// BinTreeNode	*Node6 = makeBinTreeNode(5);
	// BinTreeNode	*Node7 = makeBinTreeNode(17);
	// BinTreeNode	*Node8 = makeBinTreeNode(43);
	// BinTreeNode	*Node9 = makeBinTreeNode(49);
	// BinTreeNode	*Node10 = makeBinTreeNode(31);

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
	addNodeBST(Tree, *Node1);
	addNodeBST(Tree, *Node2);
	addNodeBST(Tree, *Node3);
	addNodeBST(Tree, *Node4);
	addNodeBST(Tree, *Node5);
	addNodeBST(Tree, *Node6);
	addNodeBST(Tree, *Node7);
	addNodeBST(Tree, *Node8);
	addNodeBST(Tree, *Node9);
	addNodeBST(Tree, *Node10);

	showBinTree(Tree);
	// printf("=================================\n");

	printf("====DELETE=====\n");
	// printf("ROOT : %d\n", getRootNodeBT(Tree)->data);
	// deleteNodeBST(Tree, 10);
	// showBinTree(Tree);
	// printf("ROOT : %d\n", getRootNodeBT(Tree)->data);
	deleteNodeBST(Tree, 11);
	showBinTree(Tree);
	deleteNodeBST(Tree, 12);
	showBinTree(Tree);
	deleteNodeBST(Tree, 13);
	showBinTree(Tree);
	deleteNodeBST(Tree, 14);
	showBinTree(Tree);
	deleteNodeBST(Tree, 15);
	showBinTree(Tree);
	// deleteNodeBST(Tree, 4);
	// showBinTree(Tree);
	deleteNodeBST(Tree, 49);
	showBinTree(Tree);
	printf("ROOT : %d\n", getRootNodeBT(Tree)->data);
	printf("ROOT : %d\n", getRootNodeBT(Tree)->data);

	// deleteNodeBST(Tree, 17);
	// showBinTree(Tree);
	// deleteNodeBST(Tree, 17);
	// showBinTree(Tree);

	// deleteBinTree(Tree);
}