/************************************************************************/
/* Double Linked List for Crazy Language								*/
/*																		*/
/* author : LGR															*/
/************************************************************************/
#include "stdafx.h"
#include "leegwiro_list.h"

#define COL                   GetStdHandle(STD_OUTPUT_HANDLE)        // �ܼ�â�� �ڵ����� �ޱ�
#define BLACK                SetConsoleTextAttribute(COL, 0x0000);        // ������
#define DARK_BLUE         SetConsoleTextAttribute(COL, 0x0001);			  // �Ķ���
#define GREEN                SetConsoleTextAttribute(COL, 0x0002);        // ���
#define BLUE_GREEN        SetConsoleTextAttribute(COL, 0x0003);           // û���
#define BLOOD               SetConsoleTextAttribute(COL, 0x0004);         // �˺�����
#define PURPLE               SetConsoleTextAttribute(COL, 0x0005);        // �����
#define GOLD                 SetConsoleTextAttribute(COL, 0x0006);        // �ݻ�
#define ORIGINAL            SetConsoleTextAttribute(COL, 0x0007);         // ���� ȸ�� (ORIGINAL CONSOLE COLOR)
#define GRAY                 SetConsoleTextAttribute(COL, 0x0008);        // ȸ��
#define BLUE                  SetConsoleTextAttribute(COL, 0x0009);       // �Ķ���
#define HIGH_GREEN       SetConsoleTextAttribute(COL, 0x000a);            // ���λ�
#define SKY_BLUE           SetConsoleTextAttribute(COL, 0x000b);          // �ϴû�
#define RED                   SetConsoleTextAttribute(COL, 0x000c);       // ������
#define PLUM                SetConsoleTextAttribute(COL, 0x000d);         // ���ֻ�
#define YELLOW             SetConsoleTextAttribute(COL, 0x000e);          // �����
#define WHITE                SetConsoleTextAttribute(COL, 0x000f);        // ���

int dataStructureFlag;

/**
	@brief ����Ʈ�� �������� �����δ�.
	@param List ���õ� ����Ʈ �ڷᱸ��
*/
void move_left_list(struct List* list) {
	// ���� ��尡 ���� ��
	if (list->point->prev == NULL) {		// ��� ���� ���� ���� �޸� �Ҵ�
		Node *temp = (Node*)malloc(sizeof(Node));
		temp->data = 0;

		temp->next = list->head;
		list->head->prev = temp;
		temp->prev = NULL;
		list->head = temp;

		list->point = list->point->prev;
		(list->size)++;
	}
	
	else {	// ���� ��尡 ������ ��
		// �׳� ����Ʈ�� �ű�
		list->point = list->point->prev;
	}
}

/**
	@brief ����Ʈ�� ���������� �����δ�.
	@param List ���õ� ����Ʈ �ڷᱸ��
*/
void move_right_list(struct List* list) {
	// ���� ��尡 ���� ��
	if (list->point->next == NULL) {
		// ��� ���� ���� ���� �޸� �Ҵ�
		Node *temp = (Node*)malloc(sizeof(Node));
		temp->data = 0;

		temp->prev = list->tail;
		list->tail->next = temp;
		temp->next = NULL;
		list->tail = temp;

		list->point = list->point->next;
		(list->size)++;
	}
	// ���� ��尡 ������ ��
	else {
		// �׳� ����Ʈ�� �ű�
		list->point = list->point->next;
	}
}

/**
	@brief ����Ʈ�� ����Ű�� ��忡 �����͸� 1 ������Ų��.
	@param List ���õ� ����Ʈ �ڷᱸ��
*/
void add_data_list(struct List* list) {
	// ���� ����Ʈ�� �����͸� 1 ������Ŵ
	++(list->point->data);
}

/**
	@brief ����Ʈ�� ����Ű�� ��忡 �����͸� 1 ���ҽ�Ų��.
	@param List ���õ� ����Ʈ �ڷᱸ��
*/
void sub_data_list(struct List* list) {
	// ���� ����Ʈ�� �����͸� 1 ����
	--(list->point->data);
}

/**
	@brief ����Ʈ�� ����Ű�� ��忡�� �����͸� ��´�.
	@param List ���õ� ����Ʈ �ڷᱸ��
	@return ���� ������
*/
int get_data_list(struct List* list) {
	// ���� ����Ʈ���� �����͸� ����
	return list->point->data;
}

/**
	@brief ��ü ��带 ����Ѵ�.
	@param List ���õ� ����Ʈ �ڷᱸ��
*/
void display_list(struct List* list) {
	// ��ü ��� ���
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
	@brief ���ο� ����Ʈ�� �����Ѵ�.
	@return ������ ����Ʈ �ڷᱸ��
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
	@brief ȯ��ť�� Data�� Addr�� �����Ѵ�.
	@param List ���õ� ����Ʈ �ڷᱸ��
*/
void enQueue_list(List *list)
{
	init(list->queue);

	Node *p = list->head;
	while(1) {
		enQueue(list->queue, (int*)p, p->data);
		/*printf(" L�ּ� : %#x value : %d", p,  p->data);
		printf(" Q�ּ� : %#x value : %d", (int*)p,  p->data);
		printf("  realy.value = %d\n", ((Node*)((int*)p))->data);*/
		if(p != list->tail)
			p = p->next;
		else
			break;
	}
}

/**
	@brief ȯ��ť�� Data�� Addr�� ����Ѵ�.
	@param List ���õ� ����Ʈ �ڷᱸ��
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


// ���� �ҽ�
/*int main () {
	printf("����Ʈ ��ü ����\n");
    List list = create_list();

	printf("���� ����Ʈ ���\n");
	list.display_list(&list);

	printf("�������� ����Ʈ 2 �ű�\n");
	for(int i=0; i<2; i++) {
		list.move_right_list(&list);
	}
	printf("�������� ����Ʈ 4 �ű�\n");
	for(int i=0; i<4; i++) {
		list.move_left_list(&list);
	}
	printf("����Ʈ�� ���� 1 ������Ŵ\n");
	for(int i=0; i<4; i++) {
		list.move_right_list(&list);
		for(int j=0; j<i+1; j++)
			list.add_data_list(&list);
	}
	

	printf("��ü ����Ʈ ��� \n");
	list.display_list(&list);

	puts("---------------------------------------");
	
	list.display_list(&list);

	list.enQueue_list(&list);
	list.print_Queue(&list);
	list.init_list(&list);
	printf("�������� ����Ʈ 2 �ű�\n");
	for(int i=0; i<2; i++) {
		list.move_right_list(&list);
	}
	printf("�������� ����Ʈ 4 �ű�\n");
	for(int i=0; i<4; i++) {
		list.move_left_list(&list);
	}
	printf("����Ʈ�� ���� 1 ������Ŵ\n");
	for(int i=0; i<4; i++) {
		list.move_right_list(&list);
		for(int j=0; j<i+1; j++)
			list.add_data_list(&list);
	}
	

	printf("��ü ����Ʈ ��� \n");
	list.display_list(&list);

	return 0;
}*/



/*int flag = 0;

int main()
{

	while(1)
	{
		�ϲ� �Լ� ȣ��
		if ( ���ڰ� / �̸�)
		{
			//flag = 0 �ƴϸ� 1;
			if ( flag == 0) flag =1;
			else if (flag == 1) flag = 0;
		}
		
		if (flag == 0)
			���� �ڷᱸ���� ����

		else if (flag == 1)
			�Ǹ��� �ڷᱸ���� ����

	}
}*/