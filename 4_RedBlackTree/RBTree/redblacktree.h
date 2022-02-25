#ifndef _REDBLACKTREE_H_
# define _REDBLACKTREE_H_

enum color {red = 0 , black = 1};
typedef struct RBTreeNodeType
{
	int color;
	char data;
	int index;
	int level;
	struct RBTreeNodeType *pLeftChild;
	struct RBTreeNodeType *pRightChild;
	struct RBTreeNodeType *pParent;
} RBTreeNode;

typedef struct RBTreeType
{
	int treeheight;
	RBTreeNode *nilNode;
	RBTreeNode *pRootNode;
} RBTree;

RBTreeNode *makeRBTreeNode(char data);
int deleteRBTreeNode(RBTreeNode *pNode);
RBTree *makeRBTree(void);
void deleteRBTree(RBTree **ppTree); //by postorder
void rightRotation(RBTree *pTree, RBTreeNode *pNode);
void leftRotation(RBTree *pTree, RBTreeNode *pNode);
int addNodeRB(RBTree *pTree, RBTreeNode element);
int deleteNodeRB(RBTree *pTree, RBTreeNode element);

/*Red Black Tree Traversal*/
void preorderTraversal(RBTree *pTree, RBTreeNode *pNode, int (*func)(RBTreeNode *));
void inorderTraversal(RBTree *pTree, RBTreeNode *pNode, int (*func)(RBTreeNode *));
void postorderTraversal(RBTree *pTree, RBTreeNode *pNode, int (*func)(RBTreeNode *));
void levelorderTraversal(RBTree *pTree, int (*func)(RBTreeNode *));

/*Show Red Black Tree*/
int printNodeInfo(RBTreeNode *pNode);
void showTreePreorder(RBTree *pTree);
void showTreeInorder(RBTree *pTree);
void showTreePostorder(RBTree *pTree);
void showTreeLevelorder(RBTree *pTree);

void setTreeInfo(RBTree *pBinTree);
void showRBTreeStructure(RBTree *pTree);

#endif