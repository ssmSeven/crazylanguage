
#include "stdafx.h"
#include <iostream>
#include <cstring>




#include "leegwiro_list.h"
#include "leegwiro_operator_array.h"
#include "CodeConverter.h"
#include "KyoungMin_parser.h"
#include "InputDataClass.h"

#include "OutputWnd.h"
#include "MainFrm.h"
using namespace std;



#include <windows.h>

int cnt=0;

void CodeConverter::CodeConverte(char *codeStr, List *pList, Array *pAry, int *pDataStructureFlag ) {
	

	
	char data = 0;
	int codeLen = strlen(codeStr);
	int repeatPoint = 0;
	CString temp;

	int loofend=0;

	char operation[10000];
	loofstart=false;
	bool error=false;
		CString t;



	for (int i = 0; i < codeLen; i++) {
		
		
			
		if (*pDataStructureFlag == 0) {
			switch (codeStr[i])	{
			case '<' :
				move_left_list(pList);
				operation[i]='<';
				tmep2+=operation[i];
				break;
			case '>' :
				move_right_list(pList);
				operation[i]='>';
				tmep2+=operation[i];
				break;
			case '/' :
				*pDataStructureFlag = 1;
		
				tmep2+='/';
				break;
			}
		}
		else if (*pDataStructureFlag == 1) {
			switch (codeStr[i])	{
			case '<' :
				move_left_array(pAry);
				operation[i]=get_data_array(pAry);
				tmep2+=operation[i];

				break;
			case '>' :
				move_right_array(pAry);
				operation[i]=get_data_array(pAry);
				tmep2+=operation[i];

				break;
			case '.' :
				data = get_data_array(pAry);


				operation[i]=get_data_array(pAry);
				tmep2+=operation[i];



			

				if (data == '+') {
					add_data_list(pList);
				}
				else if (data == '-') {
					sub_data_list(pList);
				}
				else if (data == '[') {
					cnt++;
					loofstart=true;
					repeatPoint = i;
					


				}
				else if (data == ']') {
					cnt++;
					loofstart=false;

					if (get_data_list(pList) != 0) {
						move_left_array(pAry);
						i = repeatPoint;

					
					}
						
				
				}
				else if (data == 's') {
				
					InputDataClass input;
					
					input.DoModal();

					CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

					pList->point->data=pFrame->inputDatavalue.getInputData();

					//=10;
					TRACE(TEXT("입력을 받아야함\n"));
				}
				else if (data == 'p') {

					outputData = pList->point->data;

					if(error==true)
					{
					


					}else
					{
					
					outputStr.Format(_T("%d"), outputData);
					csDump += outputStr;

					
					
					}
			


					

				}
				else if (data == 'c') {

					outputData = pList->point->data;

					if(outputData>127 || outputData<10)
					{
						error=true;
						csDump="출력 범위를 초과하였습니다!.";

					}
					else
					{
					
						
						outputStr.Format(_T("%c"), (char)outputData);
						csDump += outputStr;

					

					}

				}

				

				break;
			case '/' :
				*pDataStructureFlag = 0;
				operation[i]=get_data_array(pAry);
				tmep2+='/';
				
				break;
			}

			

		}

		pList->display_list(pList);
		pAry->display_array(pAry);

	}


				if(loofstart==true)
				{
					csDump = "괄호의 짝이 맞지 않습니다!!";
				}


}

