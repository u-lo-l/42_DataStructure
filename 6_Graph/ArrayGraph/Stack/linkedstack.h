#ifndef _LINKED_STACK_
#define _LINKED_STACK_

#include "../arraygraph_data.h"

StackNode *createLSNode(int data);
LinkedStack* createLinkedStack();
int pushLS(LinkedStack* pStack, StackNode element);
StackNode* popLS(LinkedStack* pStack);
StackNode* peekLS(LinkedStack* pStack);
void deleteLinkedStack(LinkedStack* pStack);
int isLinkedStackFull(LinkedStack* pStack);
int isLinkedStackEmpty(LinkedStack* pStack);
void printLinkedStack(LinkedStack *pStack);
#endif
