#ifndef _GRAPH_ADJMATRIX_
#define _GRAPH_ADJMATRIX_

#include "arraygraph_data.h"

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

int traversal_DFS_iter_AG(ArrayGraph *AG, int startID);

int traversal_BFS_iter_AG(ArrayGraph *AG, int startID);
#endif

