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
	for (int i = 0; i < 10; i++)
	{
		data += rand()%3 + 1;
		Nodes[i] = makeRBTreeNode(data);
	}
	for (int i = 0; i < 10; i++)
	{
		addNodeRB(Tree, *Nodes[i]);
		showRBTreeStructure(Tree);
	}
	for (int i = 0; i < 10; i++)
		deleteRBTreeNode(Nodes[i]);
	deleteRBTree(&Tree);
}