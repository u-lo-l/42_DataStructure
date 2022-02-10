#ifndef _CIRCULARLIST_
# define _CIRCULARLIST_

typedef struct CircularListNodeType
{
	int data;
	struct CircularListNodeType* pLink;
} CircularListNode;

typedef struct CircularListType
{
	int currentElementCount;	// 현재 저장된 노드의 갯수
	CircularListNode *pLink;	// Head Pointer
} CircularList;

CircularList*		createCircularList();
int					addCLElement(CircularList* pList, int position, CircularListNode element);
int					removeCLElement(CircularList* pList, int position);
CircularListNode*	getCLElement(CircularList* pList, int position);
int					getCircularListLength(CircularList* pList);
void				clearCircularList(CircularList* pList);
void				deleteCircularList(CircularList* pList);
void				displayCircularList(CircularList* pList);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif
