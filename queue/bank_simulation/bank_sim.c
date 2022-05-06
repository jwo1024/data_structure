#include	"simdef.h"


/*
	FCFS first come first service
	pArrivalDeque 에 미리 넣어두기 // insertCustomer 이용

	대기시간, 실행시간 구하기
	
	도착한 프로세스가 있나 확인 (proccessArivlal 통해서) 있다면 waitDeque 로 이동

	processServiceNodeEnd 로 실행완료된 노드 종료 // ServiceUserCount? 와 총 대기시간 반환

	processServiceNodeStart 로 waitDeque 의 front 노드 반환,, 
		->밖에서 pServieNode로 받음, 밖에서 pServiceUserCount와 pTotalWaitTime(평균대기시간?) 계산

	printSimCustomer 출력
	printWaitDequeStatus 대기큐 출력
	printReport 결과 출력

	// 잘 조합한다면 다른 운영체제 알고리즘 시뮬레이션도 할 수 있다. RR 정도, 혹은 SJF
	// 다시 대기큐로 넣는 함수필요.
	// SJF 하려면 대기큐의 노드들을 비교하여 정렬하는 함수 하나가 더 필요하다 ex) SJF SRT RR HRN 다단계피드백큐
	
*/

void insertCutomer(int arrivalTime, int processTime, LinkedDeque *pDeque)
{
	// 도착시간, 프로세스시간, 덱에 넣기
}


void processArrival(int currentTime, LinkedDeque *pArrivalDeque, LinkedDeque *pWaitDeque)
{
	// 현재시간과 비교하여 도착한 노드가 있는지 확인
	// 있다면 대기큐에 넣음
}

// 실행되고 있는 노드(프로세스)가 없다면 
// 새로운 노드 실행
DequeNode* processServiceNodeStart(int currentTime, LinkedDeque *pWaitDeque)
{
	// 대기큐에서 노드하나를 빼온다
	// currentTime으로 해당 노드 시작시간 설정해주기
}

// 현재시각 - 실행노드시작시간 == 실행노드서비스시각 일때 
// 노드 종료
DequeNode* processServiceNodeEnd(int currentTime, DequeNode *pServiceNode, \
	int *pServiceUserCount, int *pTotalWaitTime)
{
	// currentTime 으로 서비스노드의 종료시간 설정
	//  ServiceUserCount ++
	// pTotalWaitTiem += 서비스노드의 대기시간 더하기
}

// 커스토머 정보
void printSimCustomer(int currentTime, SimCustomer customer)
{
	// 커스토머 status 
	// 도착, 서비스, 시작, 종료 시간 출력
}

// 현재 대기큐 출력
void printWaitDequeStatus(int currentTime, LinkedDeque *pWaitDeque)
{
	// 현재 대기큐 출력
	// 대기큐 각 커스토머 정보 출력
}

void printReport(LinkedDeque *pWaitDeque, int serviceUserCount, int totalWaitTime)
{
	// 현재 대기큐 출력
	// 평균 대기시간 출력
	//// pServiceUserCount로 pTotalWaitTime 을 나누어 평균 대기시간을 구하라는 뜻 같아 보임
}