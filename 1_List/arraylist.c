/*
 * Array List
 * Author: minjkim2, dkim2
 * Language:  C
 */
#include "arraylist.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/*
 * createArrayList() - create and initialize ArrayList
 * 
 * return			: Array List의 포인터
 * maxElementCount	: Array List의 최대 원소 갯수
 */
ArrayList *createArrayList(int maxElementCount)
{
	ArrayList *ary;

	if (maxElementCount <= 0)
		return (NULL);
	ary = (ArrayList *)malloc(sizeof(ArrayList));
    if (!ary)
        return (NULL);
	ary->maxElementCount = maxElementCount;
	ary->currentElementCount = 0;
	ary->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * maxElementCount);
    if (!ary->pElement)
        return (NULL);
	for (int i = 0; i < ary->maxElementCount ; i++)
		ary->pElement[i].data = 0;
	return (ary);
}

/*
 * isArrayListFull() - Array List가 가득 찼는지 검사
 *
 * return : 0 / 1
 * pList : Array List의 포인터
 */
int isArrayListFull(ArrayList* pList)
{
	if (!pList)
		return (-1);
	return (pList->maxElementCount == pList->currentElementCount);
}

/*
 * addALElement() - Array List의 position 위치에 element 추가
 * 
 * return : SUCCESS 0 FAILURE 1
 * pList : Array List의 포인터
 * position : element가 저장될 위치
 * element : 저장될 원소
 */
int addALElement(ArrayList* pList, int position, ArrayListNode element)
{
	if (!pList || position < 0 || position >= pList->maxElementCount || isArrayListFull(pList))
		return (EXIT_FAILURE);
	if (pList->currentElementCount != 0)
		for (int i = pList->currentElementCount; position < i; i--)
			pList->pElement[i] = pList->pElement[i - 1];
	pList->pElement[position] = element;
	pList->currentElementCount++;
	return (EXIT_SUCCESS);
}

/*
 * removeALElement() - Array List의 position 위치의 element 삭제 
 *
 * return : SUCCESS 0 FAILURE 1
 * pList : Array List의 포인터
 * position : 삭제할 원소의 위치
 */
int removeALElement(ArrayList* pList, int position)
{
	int i;

	if (!pList || position < 0 || position >= pList->currentElementCount)
		return (EXIT_FAILURE);
	for (i = position; i < pList->currentElementCount - 1; i++)
		pList->pElement[i] = pList->pElement[i + 1];
	pList->pElement[i].data = 0;
	pList->currentElementCount--;
	return (EXIT_SUCCESS);
}

/*
 * getALElement() - position 위치에 있는 node를 반환
 *
 * return : node의 포인터
 * pList : Array List의 포인터
 * position : 반환할 위치
 */
ArrayListNode *getALElement(ArrayList* pList, int position)
{
	ArrayListNode *node;

	if (!pList || position < 0 || position >= pList->currentElementCount)
		return (NULL);
	node = &pList->pElement[position];
	return (node);
}

/*
 * clearArrayList() - Array List의 원소 초기화
 * 
 * return : None
 * pList : Array List의 포인터
 */
void clearArrayList(ArrayList *pList)
{
    if (!pList)
        return ;
	/* 현재까지 저장된 원소를 모두 초기화한다. */
	for (int i = 0; i < pList->currentElementCount ; i++)
	{
		pList->pElement[i].data = 0;
		pList->currentElementCount--;
	}
	assert(pList->currentElementCount == 0);
}

/*
 * deleteArrayList() - Destroy Array List
 * 
 * return : None
 * pList : Pointer of Array List
 */
void deleteArrayList(ArrayList* pList)
{
    if (!pList)
        return ;
    free(pList->pElement);
    free(pList);
}

/*
 * getArrayListLength() - Array List의 현재 원소의 갯수 반환
 *
 * return : 현재 원소의 갯수
 * pList : Array List의 포인터
 */
int getArrayListLength(ArrayList* pList)
{
	if (!pList)
		return (-1);
	return (pList->currentElementCount);
}

/*
 * displayArraylist() - Print Array List
 *
 * return : None
 * pList : Array List의 포인터
*/
void displayArrayList(ArrayList *pList)
{
	printf("maxElementCount : %d\n", pList->maxElementCount);
	printf("currentElementCount : %d\n", pList->currentElementCount);
	for (int i = 0 ; i < pList->maxElementCount ; i++)
		printf("%d ", pList->pElement[i].data);
	printf("\n");
}

int main(void)
{
	ArrayList *arrayList;
	ArrayListNode node;
	ArrayListNode *get_node;

	arrayList = createArrayList(10);
	
	node.data = 10;
	addALElement(arrayList, 0, node);
	node.data = 20;
	addALElement(arrayList, 1, node);
	node.data = 30;
	addALElement(arrayList, 2, node);
	node.data = 40;
	addALElement(arrayList, 1, node);

	displayArrayList(arrayList);
	// 10 40 20 30
	
	get_node = getALElement(arrayList, 2);
	printf("node : %d\n", get_node->data); // 20
	printf("length : %d\n", getArrayListLength(arrayList));
	printf("is_full : %d\n",isArrayListFull(arrayList));

	removeALElement(arrayList, 3);
	// 10 40 20
	displayArrayList(arrayList);
	removeALElement(arrayList, 1);
	// 10 20
	displayArrayList(arrayList);
	
	removeALElement(arrayList, 0);
	// 20
	displayArrayList(arrayList);
	clearArrayList(arrayList);
	// deleteArrayList(arrayList);
}
