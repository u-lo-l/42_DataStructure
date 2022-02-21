#ifndef _AVL_TREE_
# define _AVL_TREE_
# include "../BinSearchTree/binsearchtree.h"
# ifndef max
#  define max(a, b) (((a) > (b)) ? (a) : (b))
# endif

int		calcHeight(BinTreeNode *pNode);
int		calcBalance(BinTreeNode *pNode);
void	balanceTree(BinTreeNode *pNode);
BinTreeNode *rotate_LL(BinTreeNode *pNode);
BinTreeNode *rotate_RR(BinTreeNode *pNode);
BinTreeNode *rotate_LR(BinTreeNode *pNode);
BinTreeNode *rotate_RL(BinTreeNode *pNode);
int		addNodeAVL(BinTree *binSearchTree, BinTreeNode element);
int		deleteNodeAVL(BinTree *binSearchTree, int data);

#endif