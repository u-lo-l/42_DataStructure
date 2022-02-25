#include "./RBTree/redblacktree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	srand(time(NULL));
	RBTree *Tree = makeRBTree();
	RBTreeNode *Nodes[10];
	char data = 'A' - 1;
	printf("============CREATED DATA==========\n");
	for (int i = 0; i < 10; i++)
	{
		data += rand()%3 + 1;
		printf("[%c]  ",data);
		Nodes[i] = makeRBTreeNode(data);
	}
	printf("\n-----------------------------------\n");
	for (int i = 0; i < 10; i++)
	{
		addNodeRB(Tree, *Nodes[i]);
		showRBTreeStructure(Tree);
	}
	printf("===========INSERT COMPLETE========\n");
	for (int i = 0; i < 10; i++)
	{
		deleteNodeRB(Tree, *Nodes[i]);
		showRBTreeStructure(Tree);
	}
	deleteRBTree(&Tree);
}