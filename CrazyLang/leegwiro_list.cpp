/************************************************************************/
/* Double Linked List for Crazy Language								*/
/*																		*/
/* author : LGR															*/
/************************************************************************/
#include "stdafx.h"
#include "leegwiro_list.h"

#define COL                   GetStdHandle(STD_OUTPUT_HANDLE)        // 콘솔창의 핸들정보 받기
#define BLACK                SetConsoleTextAttribute(COL, 0x0000);        // 검정색
#define DARK_BLUE         SetConsoleTextAttribute(COL, 0x0001);			  // 파란색
#define GREEN                SetConsoleTextAttribute(COL, 0x0002);        // 녹색
#define BLUE_GREEN        SetConsoleTextAttribute(COL, 0x0003);           // 청녹색
#define BLOOD               SetConsoleTextAttribute(COL, 0x0004);         // 검붉은색
#define PURPLE               SetConsoleTextAttribute(COL, 0x0005);        // 보라색
#define GOLD                 SetConsoleTextAttribute(COL, 0x0006);        // 금색
#define ORIGINAL            SetConsoleTextAttribute(COL, 0x0007);         // 밝은 회색 (ORIGINAL CONSOLE COLOR)
#define GRAY                 SetConsoleTextAttribute(COL, 0x0008);        // 회색
#define BLUE                  SetConsoleTextAttribute(COL, 0x0009);       // 파란색
#define HIGH_GREEN       SetConsoleTextAttribute(COL, 0x000a);            // 연두색
#define SKY_BLUE           SetConsoleTextAttribute(COL, 0x000b);          // 하늘색
#define RED                   SetConsoleTextAttribute(COL, 0x000c);       // 빨간색
#define PLUM                SetConsoleTextAttribute(COL, 0x000d);         // 자주색
#define YELLOW             SetConsoleTextAttribute(COL, 0x000e);          // 노란색
#define WHITE                SetConsoleTextAttribute(COL, 0x000f);        // 흰색

int dataStructureFlag;

/**
	@brief 포인트를 왼쪽으로 움직인다.
	@param List 선택된 리스트 자료구조
*/
void move_left_list(struct List* list) {
	// 다음 노드가 없을 때
	if (list->point->prev == NULL) {		// 노드 생성 위해 동적 메모리 할당
		Node *temp = (Node*)malloc(sizeof(Node));
		temp->data = 0;

		temp->next = list->head;
		list->head->prev = temp;
		temp->prev = NULL;
		list->head = temp;

		list->point = list->point->prev;
		(list->size)++;
	}
	
	else {	// 다음 노드가 존재할 때
		// 그냥 포인트만 옮김
		list->point = list->point->prev;
	}
}

/**
	@brief 포인트를 오른쪽으로 움직인다.
	@param List 선택된 리스트 자료구조
*/
void move_right_list(struct List* list) {
	// 다음 노드가 없을 때
	if (list->point->next == NULL) {
		// 노드 생성 위해 동적 메모리 할당
		Node *temp = (Node*)malloc(sizeof(Node));
		temp->data = 0;

		temp->prev = list->tail;
		list->tail->next = temp;
		temp->next = NULL;
		list->tail = temp;

		list->point = list->point->next;
		(list->size)++;
	}
	// 다음 노드가 존재할 때
	else {
		// 그냥 포인트만 옮김
		list->point = list->point->next;
	}
}

/**
	@brief 포인트가 가르키는 노드에 데이터를 1 증가시킨다.
	@param List 선택된 리스트 자료구조
*/
void add_data_list(struct List* list) {
	// 현재 포인트의 데이터를 1 증가시킴
	++(list->point->data);
}

/**
	@brief 포인트가 가르키는 노드에 데이터를 1 감소시킨다.
	@param List 선택된 리스트 자료구조
*/
void sub_data_list(struct List* list) {
	// 현재 포인트의 데이터를 1 감소
	--(list->point->data);
}

/**
	@brief 포인트가 가르키는 노드에서 데이터를 얻는다.
	@param List 선택된 리스트 자료구조
	@return 꺼낸 데이터
*/
int get_data_list(struct List* list) {
	// 현재 포인트에서 데이터를 꺼냄
	return list->point->data;
}

/**
	@brief 전체 노드를 출력한다.
	@param List 선택된 리스트 자료구조
*/
void display_list(struct List* list) {
	// 전체 노드 출력
	Node *p = list->head;
	while(1) {
		if(&list->point->data == &p->data) {
			printf("  %d", p->data);
			if (dataStructureFlag == 0) HIGH_GREEN;
			printf("<-"); ORIGINAL;
		}
		else 
			printf("  %d  ", p->data);
		if(p != list->tail) {
			p = p->next;
			printf(" <=> ");
		} else {
			break;
		}
	}
	printf("\n");
}

void init_list(List *list)
{
	Node *p = list->head;
	Node *temp;
	while(p != list->tail) {
		temp = p;
		p = p->next;
		p->prev = NULL;
		free(temp);
	}
	list->head = p;
	list->head->data = 0;
	list->head->prev = 0;
	list->size = 1;
	list->point = list->head;
}

/**
	@brief 새로운 리스트를 생성한다.
	@return 생성된 리스트 자료구조
*/
List create_list() {
	List list;

	Node* node = (Node*)malloc(sizeof(Node));
	node->data = 0;
	node->prev = NULL;
	node->next = NULL;

	list.size = 1;

	list.head = node;
	list.tail = node;
	list.point = node;

	list.move_left_list = &move_left_list;
	list.move_right_list = &move_right_list;
	list.add_data_list= &add_data_list;
	list.sub_data_list= &sub_data_list;
	list.get_data_list = &get_data_list;

	list.display_list = &display_list;
	list.init_list = &init_list;

	list.enQueue_list = &enQueue_list;
	list.print_Queue = &print_Queue;
	list.Queue_Size = &Queue_Size;
	list.queue = (cQueueType*)malloc(sizeof(cQueueType)); 
	
	return list;
}

/**
	@brief 환형큐에 Data와 Addr를 삽입한다.
	@param List 선택된 리스트 자료구조
*/
void enQueue_list(List *list)
{
	init(list->queue);

	Node *p = list->head;
	while(1) {
		enQueue(list->queue, (int*)p, p->data);
		/*printf(" L주소 : %#x value : %d", p,  p->data);
		printf(" Q주소 : %#x value : %d", (int*)p,  p->data);
		printf("  realy.value = %d\n", ((Node*)((int*)p))->data);*/
		if(p != list->tail)
			p = p->next;
		else
			break;
	}
}

/**
	@brief 환형큐에 Data와 Addr를 출력한다.
	@param List 선택된 리스트 자료구조
*/
Data print_Queue(List *list)
{
	Data data = deQueue(list->queue);;
	//int size = (list->queue->rear)-(list->queue->front);

	/*for(int i=0; i<size; i++) {
		data = deQueue(list->queue);
		printf("addr = %#x, value = %d, addr->value = %d\n", data.memoryData, data.data, ((Node*)(data.memoryData))->data);
	}

	init(list->queue);*/

	return data;
}

int Queue_Size(List *list)
{
	return (list->queue->rear)-(list->queue->front);
}


// 예제 소스
/*int main () {
	printf("리스트 객체 생성\n");
    List list = create_list();

	printf("현재 리스트 출력\n");
	list.display_list(&list);

	printf("오른쪽을 포인트 2 옮김\n");
	for(int i=0; i<2; i++) {
		list.move_right_list(&list);
	}
	printf("왼쪽으로 포인트 4 옮김\n");
	for(int i=0; i<4; i++) {
		list.move_left_list(&list);
	}
	printf("포인트의 값을 1 증가시킴\n");
	for(int i=0; i<4; i++) {
		list.move_right_list(&list);
		for(int j=0; j<i+1; j++)
			list.add_data_list(&list);
	}
	

	printf("전체 리스트 출력 \n");
	list.display_list(&list);

	puts("---------------------------------------");
	
	list.display_list(&list);

	list.enQueue_list(&list);
	list.print_Queue(&list);
	list.init_list(&list);
	printf("오른쪽을 포인트 2 옮김\n");
	for(int i=0; i<2; i++) {
		list.move_right_list(&list);
	}
	printf("왼쪽으로 포인트 4 옮김\n");
	for(int i=0; i<4; i++) {
		list.move_left_list(&list);
	}
	printf("포인트의 값을 1 증가시킴\n");
	for(int i=0; i<4; i++) {
		list.move_right_list(&list);
		for(int j=0; j<i+1; j++)
			list.add_data_list(&list);
	}
	

	printf("전체 리스트 출력 \n");
	list.display_list(&list);

	return 0;
}*/



/*int flag = 0;

int main()
{

	while(1)
	{
		니꺼 함수 호출
		if ( 문자가 / 이면)
		{
			//flag = 0 아니면 1;
			if ( flag == 0) flag =1;
			else if (flag == 1) flag = 0;
		}
		
		if (flag == 0)
			내꺼 자료구조에 접근

		else if (flag == 1)
			의리꺼 자료구조에 접근

	}
}*/