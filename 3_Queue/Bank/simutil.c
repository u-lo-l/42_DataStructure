#include "simutil.h"
/*
 * 함수 외부에서 도착 및 처리시간 지정
 * 고객을 함수 내부에서 생성
 * 고객을 Q에 insertFrontLD
 * 고객의 arrivalTime 초기화
 * 고객의 serviceTime 초기화
 * ArrivalQueue를 초기화 하는 데 사용될 것이다.
 * 고객의 은행 도착시간(arrival타임)을 미리 설정 해 둔다.
*/
void insertCustomer(int arrivalTime, int processTime, LinkedDeque *pQueue)
{
    DequeNode newCustomerNode;
    newCustomerNode.customer_data.status = 0;
    newCustomerNode.customer_data.arrivalTime = arrivalTime;
    newCustomerNode.customer_data.serviceTime = processTime;
    newCustomerNode.customer_data.startTime = 0;
    newCustomerNode.customer_data.endTime = 0;
    insertRearLD(pQueue, newCustomerNode);
}
/*
 * 호출 될 때 ArrivalQueue에 있는 노드를 WaitQueue에 넣어준다.
 * while loop내애서 호출되며, currentTime과 ArrivalQueue의 
 * front고객의 arrivaltime이 같으면 waitQueue에 넣는다.
*/
void processArrival(int currentTime, int terminateTime, int *currWaitTime, LinkedDeque *pArrivalQueue, LinkedDeque *pWaitQueue)
{
    DequeNode *newCustomerNode;
    newCustomerNode = peekFrontLD(pArrivalQueue);
    if (!newCustomerNode)	return ;
    if (currentTime == newCustomerNode->customer_data.arrivalTime)
    {
		if ((*currWaitTime) + currentTime >= terminateTime)
			printf("\033[0;31mOVER TERMINATE TIME\nVISIT TOMORROW\033[0m\n");
		else
		{
			printf("\033[1mNEW CUSTOMER VISITED\033[0m\n");
			newCustomerNode = deleteFrontLD(pArrivalQueue);
			if (newCustomerNode == NULL)	return ;
			insertRearLD(pWaitQueue, *newCustomerNode);
			*currWaitTime += newCustomerNode->customer_data.serviceTime;
			free(newCustomerNode);
		}
    }
}

/* main함수에서 서비스 노드가 null인지 확인
 * 1) null이 아니라면
 *      processStart함수 실행 X
 * 2) null이면
 *      함수 실행
 *      대기 큐의 노드 수 가 1이상인지 확인
 *      2-1) 1이상
 *          startTime <- currTime
 *          endTime <- startTime + serviceTime
 *          다음 고객 노드의 status -> 1
 *          다음 고객 노드 반환
 *      2-2) 0이하
 *          NULL 반환
 */
DequeNode* processServiceNodeStart(int currentTime, LinkedDeque *pWaitQueue)
{
	DequeNode *nextCustomerNode;

	nextCustomerNode = deleteFrontLD(pWaitQueue);
	if (nextCustomerNode == NULL)
		return (NULL);
	int service = nextCustomerNode->customer_data.serviceTime;
	nextCustomerNode->customer_data.startTime = currentTime;
	nextCustomerNode->customer_data.endTime = currentTime + service;
	nextCustomerNode->customer_data.status = start;
	printf("\033[0;32m");
	printf("\n    <<Service Start>>\n");
	printSimCustomer(currentTime, nextCustomerNode->customer_data);
	printf("\033[0m");
	return (nextCustomerNode);
}

/*
*	pServiceUserCount   : 서비스를 받은 고객의 수
*	pTotalWaitTime      : 은행 업무가 진행되는 동안, 모든 고객의 대기 시간의 합
						: 0부터 시작해서 방금 들어온 고객의 대기시간(startTime - arrivalTime)을 더해간다.
*	서비스 노드가 null인지 확인
* 	1) null이면
*		Null 반환
*	2) null이 아니라면
*      endTime과 currTime이 같은가?
*      2-1) NO  -> 서비스 중
*          return(pServiceNode)
*      2-2) YES -> 서비스 완료  
*          *pTotalWaitTime에 고객의 대기사간(startTime - arrivalTime)을 더해준다.
*          
*          pServiceUserCount++;
*          free(노드)
*          NULL 반환
*/
DequeNode* processServiceNodeEnd(int currentTime, DequeNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime)
{
	if (pServiceNode == NULL)
		return (NULL);
	if (pServiceNode->customer_data.endTime != currentTime)
		return (pServiceNode);
	int start = pServiceNode->customer_data.startTime;
	int arrival = pServiceNode->customer_data.arrivalTime;
	*pTotalWaitTime += (start - arrival);
	(*pServiceUserCount)++;
	printf("\033[0;35m");
	printf("\n    <<Service End>>\n");
	printSimCustomer(currentTime, pServiceNode->customer_data);
	printf("\033[0m");
	free(pServiceNode);
	return (NULL);
}

void printSimCustomer(int currentTime, SimCustomer customer)
{
	printf("------Customer Info------\n");
	printf("ARRIVED : %.2d | ", customer.arrivalTime);
	printf("  WAIT  : %.2d\n", customer.startTime - customer.arrivalTime);
	printf("     SERVICE TIME: %.2d\n", customer.serviceTime);
	printf("-------------------------\n\n");
}

void printWaitQueueStatus(int currentTime, LinkedDeque *pWaitQueue)
{
	display(pWaitQueue);
}

void printReport(LinkedDeque *pArrivalQueue, int ServiceUserCount, int TotalWaitTime)
{
	printf("     <<BANK ClOSED>>   \n");
	printf("\033[0;31m");
	printf("==NOT SERVED CUSTOMERS==\n");
	display(pArrivalQueue);
	printf("========================\n");
	printf("\033[0;33m");
	printf("TOTAL SERVICED USER          : %d\n", ServiceUserCount);
	printf("TOTAL SERVICED USER WAITTIME : %d\n", TotalWaitTime);
	printf("\033[0m");
}

void playSimulation(int customerCount, int terminateTime)
{
	printf("\033[1;33m\nSIMULATION START\n");
	printf("Bank Close Time : %02d\n", terminateTime);
	printf("Total Customers : %02d\n", customerCount);
	printf("\033[0m\n");
	LinkedDeque *arrivalQueue;
	LinkedDeque *waitQueue;
	DequeNode *newCustomer = NULL;
	DequeNode *serviceNode = NULL;
	DequeNode *endNode = NULL;
	int time = 1;
	int ServiceUserCount = 0;
	int TotalWaitTime = 0;
	int currWaitTime = 0;

	arrivalQueue = createLinkedDeque();
	int arrival_time = rand()%2 + 1;
	int process_time = 0;
	for (int i = 0 ; i < customerCount; i++)
	{
		arrival_time += (rand()%3 + 1);
		process_time = (rand()%5 + 1);
		insertCustomer(arrival_time, process_time, arrivalQueue);
	}
	printf("\033[1;34m (ARRIVAL QUEUE CREATED)\n");
	display(arrivalQueue);
	printf("\033[0m");
	waitQueue = createLinkedDeque();


	while(1)
	{
		printf("\033[0;36m[[TIME %d]]\033[0m\n", time);
		if (currWaitTime > 0)	currWaitTime--;
		printf("<CURRENT WAIT TIME : %d>\n", currWaitTime);
		processArrival(time, terminateTime, &currWaitTime, arrivalQueue, waitQueue);
		if (serviceNode != NULL)
			endNode = processServiceNodeEnd(time, serviceNode, &ServiceUserCount, &TotalWaitTime);
		if (endNode == NULL)
		{
			printf("service node : Empty\n");
			serviceNode = processServiceNodeStart(time, waitQueue);
		}
		else
			printf("service node : Occupied\n");
		printWaitQueueStatus(time, waitQueue);
		if (time >= terminateTime)
		{
			if (serviceNode != NULL)
			{
				int arrival = serviceNode->customer_data.arrivalTime;
				int start = serviceNode->customer_data.startTime;
				TotalWaitTime += (start - arrival);
			}
			free(serviceNode);
			break;
		}
		time++;
	}
	printReport(arrivalQueue, ServiceUserCount, TotalWaitTime);
	deleteLinkedDeque(waitQueue);
	deleteLinkedDeque(arrivalQueue);
}