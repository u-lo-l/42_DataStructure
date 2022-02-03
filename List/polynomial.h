#ifndef POLYNOMIAL_H
# define POLYNOMIAL_H

typedef double t_coef;
typedef int t_exp;

typedef struct TermType
{
	t_coef	coef; // 계수
	t_exp	exp;  // 차수
} Term;

typedef struct DoublyListNodeType
{
	Term data;
	struct DoublyListNodeType* pLLink;
	struct DoublyListNodeType* pRLink;
} DoublyListNode;

typedef struct DoublyListType
{
	int	currentElementCount;		// 현재 저장된 노드의 갯수
	DoublyListNode	headerNode;		// 헤더 노드 (Header Node)
} DoublyList;

DoublyList* createDoublyList();
DoublyListNode *createNode(t_coef c, t_exp e);
int addDLElement(DoublyList* pList, int position, t_coef c, t_exp e);
int removeDLElement(DoublyList* pList, int position);
DoublyListNode* getDLElement(DoublyList* pList, int position);

int getDoublyListLength(DoublyList* pList);
void clearDoublyList(DoublyList* pList);
void deleteDoublyList(DoublyList* pList);
void displayDoublyList(DoublyList* pList);

DoublyList *addPolynomials(DoublyList *pList1, DoublyList *pList2); // 두 다항식의 합을 반환
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif
