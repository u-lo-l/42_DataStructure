#ifndef _BIN_TREE_
# define _BIN_TREE_

typedef struct BinTreeNodeType
{
	char data;
	int height;
	int balance;
	int index;
	int level;
	struct BinTreeNodeType* pLeftChild;
	struct BinTreeNodeType* pRightChild;
} BinTreeNode;

typedef struct BinTreeType
{
	int depth;
	struct BinTreeNodeType* pRootNode;
} BinTree;

BinTreeNode *makeBinTreeNode(char data);
int	deleteBinTreeNode(BinTreeNode *node);
BinTree* makeBinTree(BinTreeNode rootNode);
BinTreeNode* getRootNodeBT(BinTree* pBinTree);
BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element);
BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element);
BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode);
BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode);
void deleteBinTree(BinTree* pBinTree);
int isLeafNode(BinTreeNode *pNode);
int showBinTreeNode(BinTreeNode *pNode);
void showBinTree(BinTree *pBinTree);

void setTreeInfo(BinTree *pBinTree);
void showBinTreeStructure(BinTree *pBinTree);
#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

#endif