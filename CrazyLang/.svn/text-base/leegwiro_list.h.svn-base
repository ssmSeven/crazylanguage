/************************************************************************/
/* Double Linked List for Crazy Language								*/
/*																		*/
/* author : LGR															*/
/************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "ler_CircularQueue.h"

#ifndef _LIST_H
#define _LIST_H

#if _MSC_VER >= 1000	// VS 4.x 이상
#pragma once			// include guard
#endif

#ifdef __cplusplus
extern "C" {
#endif
	extern int dataStructureFlag;

	typedef struct Node {
		int data;
		struct Node *prev;
		struct Node *next;
	}Node;

	typedef struct List {
		Node* head;
		Node* tail;
		Node* point;	// 현재 가르키고 있는 노드
		cQueueType *queue;	//원형큐 가르키는 포인터

		void (*move_left_list) (struct List*);
		void (*move_right_list) (struct List*);
		void (*add_data_list) (struct List*);
		void (*sub_data_list) (struct List*);
		int (*get_data_list) (struct List*);
		void (*display_list) (struct List*);
		void (*init_list) (struct List*);
		void (*enQueue_list) (struct List*);
		Data (*print_Queue) (struct List*);
		int (*Queue_Size) (struct List*);

		int size;
	}List;

	void move_left_list(struct List*);
	void move_right_list(struct List*);
	void add_data_list(struct List*);
	void sub_data_list(struct List*);
	int get_data_list(struct List*);
	void display_list(struct List*);
	void init_list (struct List*);

	void enQueue_list(struct List*);
	Data print_Queue(struct List*);
	int Queue_Size(struct List*);

	List create_list();


#ifdef __cplusplus
}
#endif

#endif	// _LIST_H