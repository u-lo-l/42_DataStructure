#ifndef _BIN_SEARCH_TREE_
# define _BIN_SEARCH_TREE_
# include "../BinTree/bintree.h"

int	addNodeBST(BinTree *binSearchTree, BinTreeNode element);
BinTreeNode*	getNodeByDataBST(BinTree *binSearchTree, int data);
int				deleteNodeBST(BinTree *binSearchTree, int data);

#endif