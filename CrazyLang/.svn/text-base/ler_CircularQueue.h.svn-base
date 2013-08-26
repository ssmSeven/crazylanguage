#ifndef _CIRCULARQUEUE_H
#define _CIRCULARQUEUE_H

#include <iostream>
using namespace std;

#define MAX_SIZE 50

typedef struct Data {
	int data;
	int *memoryData;
} Data;

typedef struct {

	int front, rear;

	int *memoryData[MAX_SIZE];
	int data[MAX_SIZE];

} cQueueType;

void init( cQueueType *q );

int isEmpty( cQueueType *q );
int isFull( cQueueType *q );

void enQueue( cQueueType *q, int *memory, int data );
Data deQueue( cQueueType *q );		//데이터 값을 뺌

// 원형 큐의 가장 앞에 있는 원소를 검색하여 반환하는 연산
int peekData ( cQueueType *q );
int peekMemory ( cQueueType *q );

// 원형 큐의 front에서 원소를 삭제하는 연산
int del ( cQueueType *q );




#endif