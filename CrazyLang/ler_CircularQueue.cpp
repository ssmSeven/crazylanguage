#include "stdafx.h"
#include "ler_CircularQueue.h"




void init( cQueueType *q ){
	// 큐의 앞을 초기화
	q->front = q->rear = 0;
}

int isEmpty( cQueueType *q ){
	// 같으면 1, 다르면 0을 출력
	return (q->front == q->rear); 
}


int isFull( cQueueType *q ) {

	return ((q->rear+1) % MAX_SIZE == q->front);  
	// rear의 다음칸이 front라면 포화상태 값이 같으면 1 다르면 0반환
}

void enQueue( cQueueType *q, int *memory, int data ){

	if(isFull(q)) 
	{ 
		cout << "큐가 포화상태 입니다" << endl; 
		return ; 
	} 

	q->rear = (q->rear+1) % MAX_SIZE; 

	q->data[q->rear] = data;
	q->memoryData[q->rear] = memory;


}

Data deQueue( cQueueType *q ){
	Data data;
	memset(&data, -1,sizeof(data));
	//printf("%d %d\n", data.data, data.memoryData);

	if( isEmpty(q) ) { 
		cout << "큐가 공백상태 입니다." << endl;
		return data;
	} 
	q->front = ( q->front+1 ) % MAX_SIZE;

	data.data = q->data[q->front]; // 삭제 데이터 반환
	data.memoryData = q->memoryData[q->front]; // 삭제 데이터 반환 	

	return data;
}

// 원형 큐의 가장 앞에 있는 원소를 검색하여 반환하는 연산
int peekData ( cQueueType *q ) {

	if( isEmpty(q) ) 
	{ 
		std::cout << "큐가 공백상태 입니다.\n"; 
		return -1; 
	} 

	return q->data[q->rear]; 
}

int peekMemory ( cQueueType *q ) {

	if( isEmpty(q) ) 
	{ 
		std::cout << "큐가 공백상태 입니다.\n"; 
		return -1; 
	} 
	
	return (int)q->memoryData[q->rear]; 
}

// 원형 큐의 front에서 원소를 삭제하는 연산
int del ( cQueueType *q ) {

	if( isEmpty(q) ) 
	{ 
		std::cout << "큐가 공백상태 입니다.\n"; 
		return -1; 
	}
	return q->front = ( q->front + 1 ) % MAX_SIZE; 
}

/*int main() {

	cQueueType q; 
	int i; 

	init(&q); 

	for(i = 0 ; i < 10 ; i++ ) { 
		enQueue( &q, &i, i ); 

			cout << "Enqueue() : data = " << peekData( &q ) << ", front = " << q.front << ", rear = " << q.rear << endl;
	} 
			
	puts("-------------------------------------------");

	for( i = 0 ; i < 10 ; i++ ) {

			cout << "Dequeue() : data = " << deQueue(&q) << ", front = " << q.front << ", rear = " << q.rear << endl;
	}


	puts("-------------------------------------------"); 

	cout << "현재 상태 : front = " << q.front << ", rear = " << q.rear << endl;

	return 0; 

}*/