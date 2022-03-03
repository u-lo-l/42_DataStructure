#include "graph_traversal.h"

int traversal_DFS_iter_AG(ArrayGraph *AG, int startID)
{
	if (!AG || startID + 1 > AG->maxVertexCount)
		return (ERROR);
	if (AG->pVertex[startID] == NOT_USED)
		return (FALSE);
	LinkedStack *stack;
}
int traversal_DFS_iter_LG(LinkedGraph *LG, int startID);

int traversal_BFS_iter_AG(ArrayGraph *AG, int startID));
int traversal_BFS_iter_LG(LinkedGraph *LG, int startID);