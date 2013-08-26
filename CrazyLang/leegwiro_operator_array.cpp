/************************************************************************/
/* Operator Array for Crazy Language								    */
/*																		*/
/* author : LGR															*/
/************************************************************************/
#include "stdafx.h"
#include "leegwiro_operator_array.h"

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



/**
	@brief 포인트를 왼쪽으로 움직인다.
	@param List 선택된 원형배열 자료구조
*/
void move_left_array(struct Array* ary) {
	if (ary->point == ary->operatorArray) {
		ary->point = &ary->operatorArray[6];
	}
	else {
		ary->point = --(ary->point);
	}
}

/**
	@brief 포인트를 오른쪽으로 움직인다.
	@param List 선택된 원형배열 자료구조
*/
void move_right_array(struct Array* ary) {
	if (ary->point == &(ary->operatorArray[6])) {
		ary->point = ary->operatorArray;
	}
	else {
		ary->point = ++(ary->point);
	}
}

/**
	@brief 포인트가 가르키는 노드에서 데이터를 얻는다.
	@param List 선택된 리스트 자료구조
	@return 꺼낸 데이터
*/
char get_data_array(struct Array* ary) {
	// 현재 포인트에서 데이터를 꺼냄
	return *(ary->point);
}




/**
	@brief 전체 노드를 출력한다.
	@param List 선택된 리스트 자료구조
*/
void display_array (struct Array* ary) {
	// 전체 노드 출력
	for (int i = 0; i <= 6; i++) {
		if (ary->point == &ary->operatorArray[i]) {
			printf("  %c", ary->operatorArray[i]);
			if (dataStructureFlag == 1) HIGH_GREEN;
			printf("<-"); ORIGINAL;
		}
		else
			printf("  %c  ", ary->operatorArray[i]);
	}
	printf("\n");
}

/**
	@brief 자료구조 초기화
	@param List 선택된 리스트 자료구조
*/
void init_array(struct Array* ary) {
	ary->point = ary->operatorArray;
}



/**
	@brief 새로운 리스트를 생성한다.
	@return 생성된 리스트 자료구조
*/
Array create_array() {
	Array ary;

	ary.operatorArray = (char*)malloc(7);
	ary.operatorArray[0] = '+';
	ary.operatorArray[1] = '-';
	ary.operatorArray[2] = '[';
	ary.operatorArray[3] = ']';
	ary.operatorArray[4] = 's';
	ary.operatorArray[5] = 'p';
	ary.operatorArray[6] = 'c';

	ary.point = ary.operatorArray;

	ary.move_left_array = &move_left_array;
	ary.move_right_array = &move_right_array;
	ary.get_data_array = &get_data_array;

	ary.display_array = &display_array;
	ary.init_array = &init_array;

	return ary;
}


/*
// 예제 소스
int main () {

	Array ary = create_array();

	ary.display_array(&ary);

	ary.move_left_array(&ary);
	ary.display_array(&ary);

	ary.move_left_array(&ary);
	ary.display_array(&ary);

	ary.move_left_array(&ary);
	ary.display_array(&ary);

	ary.move_right_array(&ary);
	ary.display_array(&ary);

	ary.move_right_array(&ary);
	ary.display_array(&ary);

	ary.move_right_array(&ary);
	ary.display_array(&ary);

	ary.move_right_array(&ary);
	ary.display_array(&ary);

	ary.move_right_array(&ary);
	ary.display_array(&ary);

	ary.move_right_array(&ary);
	ary.display_array(&ary);

	ary.move_right_array(&ary);
	ary.display_array(&ary);

	return 0;
}

/<<<.

*/


