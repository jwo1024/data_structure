#ifndef	_SIM_DEF_
#define	_SIM_DEF_

#include "simlinkeddeque.h"

typedef enum SimStatusType { arrival, start, end } SimStatus;
typedef struct SimCustomerType
{
	SimStatus status;
	int arrivalTime;	// 도착 시각.
	int serviceTime;	// 서비스 시간.	
	int startTime;		// 시작 시각.
	int endTime;		// 종료 시각: 시작 시각 + 서비스 시간.
} SimCustomer;

typedef struct DequeNodeType
{
	SimCustomer data;
	struct DequeNodeType* pRLink;
	struct DequeNodeType* pLLink;
} DequeNode;



void insertCutomer(int arrivalTime, int processTime, LinkedDeque *pDeque);
void processArrival(int currentTime, LinkedDeque *pArrivalDeque, LinkedDeque *pWaitDeque);
DequeNode* processServiceNodeStart(int currentTime, LinkedDeque *pWaitDeque);
DequeNode* processServiceNodeEnd(int currentTime, DequeNode *pServiceNode, \
	int *pServiceUserCount, int *pTotalWaitTime);
void printSimCustomer(int currentTime, SimCustomer customer);
void printWaitDequeStatus(int currentTime, LinkedDeque *pWaitDeque);
void printReport(LinkedDeque *pWaitDeque, int serviceUserCount, int totalWaitTime);

#endif