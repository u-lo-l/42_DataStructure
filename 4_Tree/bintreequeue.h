#ifndef _BINARY_TREE_QUEUE_
# define _BINARY_TREE_QUEUE_
# include "bintree.h"

typedef struct s_LOQNodeType
{
	BinTreeNode 			treeNode;
	struct s_LOQNodeType	*pElement;
}	t_LOQNode;

typedef struct s_LOQ
{
	int	currentElementCount;
	t_LOQNode	*pFrontNode;
	t_LOQNode	*pRearNode;
} t_LOQ;

t_LOQ		*createLOQ();
int			enqueueLOQ(t_LOQ* pQueue, t_LOQNode element);
t_LOQNode	*dequeueLOQ(t_LOQ* pQueue);
t_LOQNode	*peekLOQ(t_LOQ* pQueue);
void		deleteLOQ(t_LOQ** pQueue);
int			isLOQEmpty(t_LOQ* pQueue);
void		displayLOQ(t_LOQ* pQueue);

#endif

#ifndef _COMMON_QUEUE_DEF_
# define _COMMON_QUEUE_DEF_

# define TRUE		1
# define FALSE		0

#endif