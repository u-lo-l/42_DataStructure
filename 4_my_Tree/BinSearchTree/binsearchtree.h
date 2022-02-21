#ifndef _BIN_SEARCH_TREE_
# define _BIN_SEARCH_TREE_
# include "../BinTree/bintree.h"

BinTreeNode *addNodeBSTrecursive(BinTreeNode *root,
									BinTreeNode element,
									BinTreeNode *(*func)(BinTreeNode *));
int			addNodeBST(BinTree *binSearchTree, BinTreeNode element);
BinTreeNode	*getNodeByDataBST(BinTree *binSearchTree, int data);
BinTreeNode *deleteNodeBSTrecursive(BinTree *tree,
									BinTreeNode *root,
									int data);
int			deleteNodeBST(BinTree *binSearchTree, int data);

#endif