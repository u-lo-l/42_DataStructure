#include "simutil.h"
#include <stdlib.h>
#include <time.h>
int main()
{
    LinkedDeque *arrivalQueue;
    LinkedDeque *waitQueue;
    arrivalQueue = createLinkedDeque();
    srand(time(NULL));
    
    int arrival_time = rand()%2 + 1;
    int process_time;
    // for (int i = 0 ; i < 3; i++)
    // {
    //     arrival_time += (rand()%4 + 1);
    //     process_time = (rand()%5 + 1);
    //     insertCustomer(arrival_time, process_time, arrivalQueue);
    // }

    insertCustomer(1,2,arrivalQueue);
    insertCustomer(2,5,arrivalQueue);
    insertCustomer(3,1,arrivalQueue);

    display(arrivalQueue);
    waitQueue = createLinkedDeque();

    // ArrivalQueue 에 노드 추후 추가.
    int time = 1;
    int terminateTime = 5;
    int ServiceUserCount = 0;
    int TotalWaitTime = 0;

    DequeNode *newCustomer;
    DequeNode *serviceNode;
    DequeNode *endNode;
    newCustomer = NULL;
    serviceNode = NULL;
    endNode = NULL;
    while(1)
    {
        printf("[[TIME %d]]\n", time);
        processArrival(time, arrivalQueue, waitQueue);
        if (serviceNode != NULL)
            endNode = processServiceNodeEnd(time, serviceNode, &ServiceUserCount, &TotalWaitTime);
        if (endNode == NULL) // 
        {
            printf("service node : Empty\n");
            serviceNode = processServiceNodeStart(time, waitQueue);
        }
        else
            printf("service node : Full\n");
        printWaitQueueStatus(time, waitQueue);
        if (time >= terminateTime)
        {
            // 서비스 처리중이던 고객이 기다리던 시간
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

    printReport(waitQueue, ServiceUserCount, TotalWaitTime);
    deleteLinkedDeque(waitQueue);
    deleteLinkedDeque(arrivalQueue);
}