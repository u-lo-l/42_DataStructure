#ifndef _GRAPH_ADJMATRIX_
#define _GRAPH_ADJMATRIX_

typedef struct ArrayGraphType
{
	int maxVertexCount;
	int currentVertexCount;
	int graphType;	//directed / undirected
	int **ppAdjEdge;
	int *pVertex;
} ArrayGraph;

ArrayGraph* createArrayGraph(int maxVertexCount); //undirected
ArrayGraph* createArrayDirectedGraph(int maxVertexCount);

void deleteArrayGraph(ArrayGraph* pGraph);

int isEmptyAG(ArrayGraph* pGraph);

int addVertexAG(ArrayGraph* pGraph, int vertexID);

int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID);
int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight);

int checkVertexValid(ArrayGraph* pGraph, int vertexID);

int removeVertexAG(ArrayGraph* pGraph, int vertexID);

int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID);

void displayArrayGraph(ArrayGraph* pGraph);
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
