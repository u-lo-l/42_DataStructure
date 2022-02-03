#ifndef _DOUBLYLIST_
#define _DOUBLYLIST_

typedef struct DoublyListNodeType
{
	int data;
	struct DoublyListNodeType* pLLink;
	struct DoublyListNodeType* pRLink;
} DoublyListNode;

typedef struct DoublyListType
{
	int	currentElementCount;		// 현재 노드의 갯수
	DoublyListNode	headerNode;		// 헤더 노드 (Header Node)
} DoublyList;

DoublyList*		createDoublyList();
int				addDLElement(DoublyList* pList, int position, DoublyListNode element);
int				removeDLElement(DoublyList* pList, int position);
DoublyListNode*	getDLElement(DoublyList* pList, int position);
int				getDoublyListLength(DoublyList* pList);
void			clearDoublyList(DoublyList* pList);
void			deleteDoublyList(DoublyList* pList);
void			displayDoublyList(DoublyList* pList);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif
