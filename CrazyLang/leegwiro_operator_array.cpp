/************************************************************************/
/* Operator Array for Crazy Language								    */
/*																		*/
/* author : LGR															*/
/************************************************************************/
#include "stdafx.h"
#include "leegwiro_operator_array.h"

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



/**
	@brief ����Ʈ�� �������� �����δ�.
	@param List ���õ� �����迭 �ڷᱸ��
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
	@brief ����Ʈ�� ���������� �����δ�.
	@param List ���õ� �����迭 �ڷᱸ��
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
	@brief ����Ʈ�� ����Ű�� ��忡�� �����͸� ��´�.
	@param List ���õ� ����Ʈ �ڷᱸ��
	@return ���� ������
*/
char get_data_array(struct Array* ary) {
	// ���� ����Ʈ���� �����͸� ����
	return *(ary->point);
}




/**
	@brief ��ü ��带 ����Ѵ�.
	@param List ���õ� ����Ʈ �ڷᱸ��
*/
void display_array (struct Array* ary) {
	// ��ü ��� ���
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
	@brief �ڷᱸ�� �ʱ�ȭ
	@param List ���õ� ����Ʈ �ڷᱸ��
*/
void init_array(struct Array* ary) {
	ary->point = ary->operatorArray;
}



/**
	@brief ���ο� ����Ʈ�� �����Ѵ�.
	@return ������ ����Ʈ �ڷᱸ��
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
// ���� �ҽ�
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


