#ifndef _LINKED_STACK_
#define _LINKED_STACK_
#include "maze_data.h"

typedef struct StackNodeType
{
	point					data;
	struct StackNodeType*	pLink;
} StackNode;

typedef struct LinkedStackType
{
	int currentElementCount;
	StackNode* pTopElement;
} LinkedStack;

StackNode *createLSNode(int row, int col);
LinkedStack* createLinkedStack();
int pushLS(LinkedStack* pStack, StackNode element);
StackNode* popLS(LinkedStack* pStack);
StackNode* peekLS(LinkedStack* pStack);
void deleteLinkedStack(LinkedStack* pStack);
int isLinkedStackFull(LinkedStack* pStack);
int isLinkedStackEmpty(LinkedStack* pStack);
void printLinkedStack(LinkedStack *pStack);
LinkedStack *reverseStack(LinkedStack *pStack);

#endif
#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_
#define TRUE        1
#define FALSE       0
#endif