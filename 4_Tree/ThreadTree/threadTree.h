#ifndef _THREAD_TREE_
# define _THREAD_TREE_

typedef struct threadNodeType
{
	int data;
	int leftThread;
	int rightThread;
	struct threadNodeType *leftChild;
	struct threadNodeType *rightChild;	
} threadNode;

typedef struct threadBinTreeType
{
	threadNode *pRootNode;
} threadBinTree;

#endif