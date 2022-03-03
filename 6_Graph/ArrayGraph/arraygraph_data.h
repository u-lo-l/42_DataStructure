#ifndef ARRAYGRAPH_DATA_H
# define ARRAYGRAPH_DATA_H

typedef struct ArrayGraphType
{
	int maxVertexCount;
	int currentVertexCount;
	int graphType;	//directed / undirected
	int **ppAdjEdge;
	int *pVertex;
} ArrayGraph;

typedef struct StackNodeType
{
	int data;
	struct StackNodeType* pLink;
} StackNode;

typedef struct LinkedStackType
{
	int currentElementCount;
	StackNode* pTopElement;
} LinkedStack;

#endif

#ifndef _COMMON_GRAPH_DEF_
#define _COMMON_GRAPH_DEF_

#define USED				1
#define NOT_USED			0

#define SUCCESS				1
#define FAIL				0

#define TRUE				1
#define FALSE				0
#define ERROR				-1

#define GRAPH_UNDIRECTED	1
#define GRAPH_DIRECTED		2
#endif
