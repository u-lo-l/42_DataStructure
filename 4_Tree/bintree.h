#ifndef _BIN_TREE_
# define _BIN_TREE_

typedef struct BinTreeNodeType
{
	char data;
	int visited;

	struct BinTreeNodeType* pLeftChild;
	struct BinTreeNodeType* pRightChild;
} BinTreeNode;

typedef struct BinTreeType
{
	struct BinTreeNodeType* pRootNode;
} BinTree;

BinTree		*makeBinTree(BinTreeNode rootNode);
BinTreeNode	*getRootNodeBT(BinTree* pBinTree);
BinTreeNode	*getLeftChildNodeBT(BinTreeNode* pNode);
BinTreeNode	*getRightChildNodeBT(BinTreeNode* pNode);
void		deleteBinTree(BinTree* pBinTree);
void		insert(BinTreeNode *pParentNode, int data);
void		preorderTraversalBinTree(BinTreeNode *node);
void		inorderTraversalBinTree(BinTreeNode *node);
void		postorderTraversalBinTree(BinTreeNode *node);
void		levelOrderTraversalBinTree(BinTreeNode *root);

#endif

#ifndef _COMMON_TREE_DEF_
# define _COMMON_TREE_DEF_

# define TRUE		1
# define FALSE		0
# define ERROR		-1

#endif