
// CrazyLangView.cpp : CCrazyLangView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "CrazyLang.h"
#endif

#include "CrazyLangDoc.h"
#include "CrazyLangView.h"

#include "memory.h"


#include "OutputWnd.h"
#include "OutputRapDialog.h"


#include "leegwiro_list.h"
#include "leegwiro_operator_array.h"
#include "CodeConverter.h"
#include "KyoungMin_parser.h"

#include "MainFrm.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCrazyLangView

IMPLEMENT_DYNCREATE(CCrazyLangView, CEditView)

BEGIN_MESSAGE_MAP(CCrazyLangView, CEditView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCrazyLangView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CTLCOLOR_REFLECT()
	ON_COMMAND(ID_Start, &CCrazyLangView::OnStartMenu)
	ON_COMMAND(ID_Stop, &CCrazyLangView::OnStopMenu)
	ON_COMMAND(ID_Debug, &CCrazyLangView::OnDebugMenu)
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYUP()
END_MESSAGE_MAP()

// CCrazyLangView ����/�Ҹ�

CCrazyLangView::CCrazyLangView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

		DebugFlag=false;


		memset(OperationArray,0,sizeof(OperationArray));
	
		 iconPlus=AfxGetApp()->LoadIcon(IDI_ICON1);
		 iconMinus=AfxGetApp()->LoadIcon(IDI_ICON2);
		 iconForstart=AfxGetApp()->LoadIcon(IDI_ICON3);
		 iconForend=AfxGetApp()->LoadIcon(IDI_ICON4);
		 iconScanf=AfxGetApp()->LoadIcon(IDI_ICON5);
		 iconPrintf=AfxGetApp()->LoadIcon(IDI_ICON6);
		 iconChar=AfxGetApp()->LoadIcon(IDI_ICON7);
		 nullcon=AfxGetApp()->LoadIcon(IDI_ICON8);
		 direction=AfxGetApp()->LoadIcon(IDI_ICON2);
}

CCrazyLangView::~CCrazyLangView()
{



}

BOOL CCrazyLangView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// �ڵ� �ٹٲ��� ����մϴ�.

	return bPreCreated;
}


// CCrazyLangView �μ�


void CCrazyLangView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CCrazyLangView::OnPreparePrinting(CPrintInfo* pInfo)
{
	
	

	// �⺻���� CEditView �غ�
	return CEditView::OnPreparePrinting(pInfo);
}

void CCrazyLangView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{

	// �⺻ CEditView ���� �μ�
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CCrazyLangView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// �⺻ CEditView ���� �μ�
	CEditView::OnEndPrinting(pDC, pInfo);
}

void CCrazyLangView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCrazyLangView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CCrazyLangView ����

#ifdef _DEBUG
void CCrazyLangView::AssertValid() const
{
	CEditView::AssertValid();
}

void CCrazyLangView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CCrazyLangDoc* CCrazyLangView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCrazyLangDoc)));
	return (CCrazyLangDoc*)m_pDocument;
}
#endif //_DEBUG


// CCrazyLangView �޽��� ó����


HBRUSH CCrazyLangView::CtlColor(CDC* pDC, UINT /*nCtlColor*/)
{
	// TODO:  ���⼭ DC�� Ư���� �����մϴ�.




	pDC->SetTextColor(RGB(255, 255, 255)); // ��¥ ������
    pDC->SetBkColor(RGB(0, 0, 0)); // ��� ���
    static CBrush br(RGB(0, 0, 0)); // ��� ĥ�� �귯��.
    return br;





	// TODO:  �θ� ó���Ⱑ ȣ����� ���� ��� Null�� �ƴ� �귯�ø� ��ȯ�մϴ�.
	return NULL;
}


List list = create_list();
Array ary = create_array();









void CCrazyLangView::OnStartMenu()
{

	
	if(DebugFlag==true)
	{
		AfxMessageBox(_T("����� ���Դϴ�."));

	}
	else
	{
	
	

	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	
	

//	pFrame->m_wndOutput.


	
	 GetEditCtrl().GetWindowText(fData);				//��ü �����͸� �޾ƿ´�.
	
//	 CString fDataTrim=fData.Trim();


	char* ch = new char [4096];				// �ؽ�Ʈâ�� �� ���ڿ��� ch*�� ����
	//ch =  LPSTR(LPCTSTR(fData));
	WideCharToMultiByte(CP_ACP, NULL, fData, -1, ch,  4096, NULL, FALSE);

	
	CodeConverter cc;
	//char *ch = "/��������.>>>>>.";
	//while(true) {
	//TRACE(TEXT("ch1 = %s\n"), ch);


	ch = streamParser(ch);

	//TRACE(TEXT("ch2 = %s\n"), ch);

	cc.CodeConverte(ch, &list, &ary, &dataStructureFlag);

	//wsprintf( cc.gtgim, TEXT("%d"), cc.outputData );
	//cc.outputStr.Format(_T("%d"), cc.outputData);

	csTemp = cc.csDump;
	
	
	//pFrame->m_wndOutput.FillResult(csTemp);
	//MessageBox(cc.gtgim);
	
	
	 pFrame->m_wndOutput.m_wndOutputBuildCustom.Resulttext.SetWindowText(csTemp);	
	 pFrame->m_wndOutput.m_wndOutputBuildCustom.Resulttext.ShowWindow( SW_HIDE );
	 pFrame->m_wndOutput.m_wndOutputBuildCustom.Resulttext.ShowWindow( SW_SHOW );


	list.init_list(&list);
	ary.init_array(&ary);
	dataStructureFlag = 0;
	//

	 /*
	 CRect Rect; 
	 GetDlgItem(IDC_RESULTTEXT)->GetWindowRect(&Rect);
	 ScreenToClient(&Rect);
	 InvalidateRect(Rect);
	
	
	 CString T=_T("�׽�Ʈ");
	 pFrame->m_wndOutput.FillResult(T);


	  CString Address=_T("0x00");
	  CString Value=_T("1");
	 pFrame->m_wndOutput.m_wndOutputDialog.DebugTextResult(Address,Value);


	 */
	 //pFrame->m_wndOutput.FillBuildWindow();

	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.


	//pFrame->m_wndOutput.setf

	}


}


void CCrazyLangView::OnStopMenu()
{

	DebugFlag=false;
	AfxMessageBox(_T("����"));
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CCrazyLangView::OnDebugMenu()
{

	if(DebugFlag==true)
	{
	
	AfxMessageBox(_T("����� ���Դϴ�."));

	}else{

	DebugFlag=true;

	CString LeftData;
	GetEditCtrl().GetWindowText(fData);				//��ü �����͸� �޾ƿ´�.
	
	fData=fData.Trim();

	int nLineIndex = 0;
	int nCharIndex = 0;
	int nStrLength = 0;
		DebugLeftChar=0;
	
	nLineIndex = HIWORD(MouseCouser);							
	DebugLeftChar = LOWORD(MouseCouser);

	DebugLeftCharMove=DebugLeftChar;

	DebugLeftdata = fData.Left(DebugLeftChar);	

	DebugLeftdata=DebugLeftdata.Trim();

	GetEditCtrl().SetSel(0,DebugLeftChar);

	char* ch = new char [4096];	 			// �ؽ�Ʈâ�� �� ���ڿ��� ch*�� ����

	WideCharToMultiByte(CP_ACP, NULL, DebugLeftdata, -1, ch,  4096, NULL, FALSE);

	
	CodeConverter cc;


	ch = streamParser(ch);

	cc.CodeConverte(ch, &list, &ary, &dataStructureFlag);

	list.enQueue_list(&list);
	
	int QueueSize = list.Queue_Size(&list);
	

	Data data;
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

	CString value;
	CString address;


	 pFrame->m_wndOutput.m_wndOutputDialog.DebugTextClear();


	for(int i=0; i<QueueSize; i++) {

		data=print_Queue(&list);


		value.Format(_T("%d"),data.data);
		address.Format(_T("%.2X"),data.memoryData);

		 pFrame->m_wndOutput.m_wndOutputDialog.DebugTextResult(address,value);

	}


	operationString=cc.tmep2;
	

	init(list.queue);
	list.init_list(&list);
	ary.init_array(&ary);
	dataStructureFlag = 0;


	}

	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CCrazyLangView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	MouseCouser=GetEditCtrl().CharFromPos(point);
	//pointSave=point;

	CString LeftData, RightData, NewData;
	int nLineIndex = 0;
	int nCharIndex = 0;
	int nStrLength = 0;
	CString shadowStr;

	GetEditCtrl().GetWindowText(fData);				//��ü �����͸� �޾ƿ´�.
	fData=fData.Trim();
	int n = GetEditCtrl().CharFromPos(point);		//���� Ŀ���� ��ġ�� 4����Ʈ ���·� �����Ѵ�.
	nStrLength = fData.GetLength();					// ��ü ���ڿ��� ����

	leftIndex = 0;
	rightIndex = 0;

	nLineIndex = HIWORD(n);							//���� 2����Ʈ ���� ���° �������� ��Ÿ����.
	nCharIndex = LOWORD(n);							//���� 2����Ʈ ���� ��ü ���ڿ������� ��ġ�� ��Ÿ����.


	LeftData = fData.Left(nCharIndex);				//���� Ŀ�� ���� ���ڿ� ����
	RightData = fData.Right(fData.GetLength() - nCharIndex);		//���� Ŀ�� ������ ���ڿ� ����

	
	GetEditCtrl().SetWindowText(fData);								//�߰� ���� ����
	char LeftChar, RightChar;

	if( fData.GetLength() - LeftData.GetLength() > 0 && LeftData.GetLength() >= 1 ) {
		LeftChar = (char)LeftData.GetAt(LeftData.GetLength()-1);
	}
	else {
		LeftChar='\0';
	}
	RightChar = (char)RightData.GetAt(0);



	char temp;

	if ( nCharIndex >= 1 ) {

		if ( fData[nCharIndex-1] == fData[nCharIndex]) {			// ���� ������ ���ڿ� ��

			for ( int i = nCharIndex; i > 0; i-- ) {

				temp = fData[i];

				if ( i == 0 ) {

					leftIndex = 0;

				} else if ( LeftChar != fData[i-1] ) {

					leftIndex = i;
					break;
				}
			}

			for ( int i = nCharIndex; i < nStrLength; i++ ) {
				if ( i == nStrLength-1 ) {
					rightIndex = nStrLength;
				} else if ( RightChar != fData[i] ) {
					rightIndex = i;
					break;
				} 
			}
		} 
		else {

			leftIndex = nCharIndex-1;
			rightIndex = nCharIndex;
		}

	}

	shadowStr = "";

	if ( nCharIndex >= 1 ) {

		for ( int i = leftIndex; i < rightIndex; i++ ) {
			shadowStr += fData[i];
		}
	}

	TRACE(TEXT("leftIndex = %d, rightIndex = %d, shadowStr = %s\r\n"), 
		leftIndex, rightIndex, shadowStr);


	CString stringdata;

	if ( shadowStr.GetLength() != 1) {
		stringdata.Format(_T("%c    ->    %d"), shadowStr[0],shadowStr.GetLength());
	}

	setSymbolCountView(stringdata);

	pointSave=point;

	CEditView::OnLButtonDown(nFlags, point);
}


void CCrazyLangView::setSymbolCountView(CString Symbol)
{

	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	pFrame->m_wndOutput.m_wndOutputBuildCustom.SymbolCountView.SetWindowText(Symbol);	
	pFrame->m_wndOutput.m_wndOutputBuildCustom.SymbolCountView.ShowWindow( SW_HIDE );
	pFrame->m_wndOutput.m_wndOutputBuildCustom.SymbolCountView.ShowWindow( SW_SHOW );

}



void CCrazyLangView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.


	if(DebugFlag==true)
	{

		
	

		CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();



			if ( nChar== VK_LEFT)
			{	

				int nLineIndex=0;
				nLineIndex= HIWORD(MouseCouser);	


						 if(DebugLeftCharMove>0)
						 {
								
			 					pFrame->m_wndOutput.m_wndOutputDialog.ImgList.Replace(7,nullcon);
								pFrame->m_wndOutput.m_wndOutputDialog.ImgList.Replace(8,nullcon);
								pFrame->m_wndOutput.m_wndOutputDialog.ImgList.Replace(9,nullcon);
								pFrame->m_wndOutput.m_wndOutputDialog.ImgList.Replace(10,nullcon);
								pFrame->m_wndOutput.m_wndOutputDialog.ImgList.Replace(11,nullcon);
								pFrame->m_wndOutput.m_wndOutputDialog.ImgList.Replace(12,nullcon);
								pFrame->m_wndOutput.m_wndOutputDialog.ImgList.Replace(13,nullcon);


								DebugLeftCharMove--;

								GetEditCtrl().SetSel(0,DebugLeftCharMove);

		
									switch(operationString[DebugLeftCharMove])
									{


									case '+':
										pFrame->m_wndOutput.m_wndOutputDialog.ImgList.Replace(7,direction);
										break;

									case '-':
										pFrame->m_wndOutput.m_wndOutputDialog.ImgList.Replace(8,direction);
										break;

									case '[':
										pFrame->m_wndOutput.m_wndOutputDialog.ImgList.Replace(9,direction);
										break;

									case ']':
										pFrame->m_wndOutput.m_wndOutputDialog.ImgList.Replace(10,direction);
										break;

									case 's':
										pFrame->m_wndOutput.m_wndOutputDialog.ImgList.Replace(11,direction);
										break;

									case 'p':
										pFrame->m_wndOutput.m_wndOutputDialog.ImgList.Replace(12,direction);
										break;

									case 'c':
										pFrame->m_wndOutput.m_wndOutputDialog.ImgList.Replace(13,direction);
										break;

									case '/':
										break;

									case '&':
										break;
									}


										pFrame->m_wndOutput.m_wndOutputDialog.Invalidate();		
				
						 }



		    }
			else if( nChar == VK_RIGHT )
			{



				if(DebugLeftChar>DebugLeftCharMove)
				{


						pFrame->m_wndOutput.m_wndOutputDialog.ImgList.Replace(7,nullcon);
						pFrame->m_wndOutput.m_wndOutputDialog.ImgList.Replace(8,nullcon);
						pFrame->m_wndOutput.m_wndOutputDialog.ImgList.Replace(9,nullcon);
						pFrame->m_wndOutput.m_wndOutputDialog.ImgList.Replace(10,nullcon);
						pFrame->m_wndOutput.m_wndOutputDialog.ImgList.Replace(11,nullcon);
						pFrame->m_wndOutput.m_wndOutputDialog.ImgList.Replace(12,nullcon);
						pFrame->m_wndOutput.m_wndOutputDialog.ImgList.Replace(13,nullcon);

					
						DebugLeftCharMove++;

					GetEditCtrl().SetSel(0,DebugLeftCharMove);



					switch(operationString[DebugLeftCharMove-1])
					{
					case '+':
						pFrame->m_wndOutput.m_wndOutputDialog.ImgList.Replace(7,direction);
						break;

					case '-':
						pFrame->m_wndOutput.m_wndOutputDialog.ImgList.Replace(8,direction);
						break;

					case '[':
						pFrame->m_wndOutput.m_wndOutputDialog.ImgList.Replace(9,direction);
						break;

					case ']':
						pFrame->m_wndOutput.m_wndOutputDialog.ImgList.Replace(10,direction);
						break;

					case 's':
						pFrame->m_wndOutput.m_wndOutputDialog.ImgList.Replace(11,direction);
						break;

					case 'p':
						pFrame->m_wndOutput.m_wndOutputDialog.ImgList.Replace(12,direction);
						break;

					case 'c':
						pFrame->m_wndOutput.m_wndOutputDialog.ImgList.Replace(13,direction);
						break;

					case '/':
						break;

					case '&':
						break;

					}

					pFrame->m_wndOutput.m_wndOutputDialog.Invalidate();
				}
				else if(DebugLeftCharMove<0 || DebugLeftCharMove> DebugLeftChar)
				{
					DebugLeftCharMove=DebugLeftChar;
				}

			}
	}

	CEditView::OnKeyUp(nChar, nRepCnt, nFlags);
}