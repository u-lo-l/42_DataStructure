#include "BinSearchTree/binsearchtree.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("===Tree and Nodes Initialize===\n");
	BinTreeNode	*rootNode = makeBinTreeNode(10);
	BinTreeNode	*Node1 = makeBinTreeNode(4);
	BinTreeNode	*Node2 = makeBinTreeNode(7);
	BinTreeNode	*Node3 = makeBinTreeNode(15);
	BinTreeNode	*Node4 = makeBinTreeNode(21);
	BinTreeNode	*Node5 = makeBinTreeNode(1);
	printf("==============DONE==============\n");

	BinTree *Tree = makeBinTree(*rootNode);
	showBinTree(Tree);
	addNodeBST(Tree, *Node5); // 1
	showBinTree(Tree);
	addNodeBST(Tree, *Node1); // 4
	showBinTree(Tree);
	addNodeBST(Tree, *Node4); // 21
	showBinTree(Tree);
	addNodeBST(Tree, *Node5); // 1
	showBinTree(Tree);
	printf("=================================\n");

}