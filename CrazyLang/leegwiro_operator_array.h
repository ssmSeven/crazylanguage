#ifndef _OPERATOR_ARRAY_H
#define _OPERATOR_ARRAY_H

/************************************************************************/
/* Operator Array for Crazy Language								    */
/*																		*/
/* author : LGR															*/
/************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


#if _MSC_VER >= 1000	// VS 4.x 이상
#pragma once			// include guard
#endif

#ifdef __cplusplus
extern "C" {
#endif

	extern int dataStructureFlag;

	typedef struct Array {

		char* point;	// 현재 가르키고 있는 노드
		char* operatorArray;

		void (*move_left_array) (struct Array*);
		void (*move_right_array) (struct Array*);
		char (*get_data_array) (struct Array*);
		void (*display_array) (struct Array*);
		void (*init_array) (struct Array*);
	

	}Array;

	void move_left_array(struct Array*);
	void move_right_array(struct Array*);
	char get_data_array(struct Array*);
	void display_array(struct Array*);
	void init_array(struct Array*);


	Array create_array();

#ifdef __cplusplus
}
#endif	// _LIST_H

#endif
