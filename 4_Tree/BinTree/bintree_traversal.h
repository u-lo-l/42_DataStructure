#ifndef BINTREE_TRAVERSAL_H
# define BINTREE_TRAVERSAL_H
# include "bintree.h"
# include "../Queue/linkedqueue.h"

void preorderTraversal(BinTreeNode *pNode, int (*func)(BinTreeNode *));
void inorderTraversal(BinTreeNode *pNode, int (*func)(BinTreeNode *));
void postorderTraversal(BinTreeNode *pNode, int (*func)(BinTreeNode *));
void levelorderTraversal(BinTree *pBinTree, int (*func)(BinTreeNode *));

#endif