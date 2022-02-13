#ifndef SIMUTIL_H
# define SIMUTIL_H
# include "simlinkeddeque.h"

void insertCustomer(int arrivalTime,
					int processTime,
					LinkedDeque *pQueue);

void processArrival(int currentTime,
					LinkedDeque *pArrivalQueue,
					LinkedDeque *pWaitQueue);

DequeNode* processServiceNodeStart(int currentTime, LinkedDeque *pWaitQueue);

DequeNode* processServiceNodeEnd(int currentTime, DequeNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime);

void printSimCustomer(int currentTime, SimCustomer customer);

void printWaitQueueStatus(int currentTime, LinkedDeque *pWaitQueue);

void printReport(LinkedDeque *pWaitQueue, int ServiceUserCount, int TotalWaitTime);

void playSimulation(int customerCount, int terminateTime);

#endif