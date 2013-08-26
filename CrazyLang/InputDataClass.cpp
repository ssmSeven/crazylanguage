// InputDataClass.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CrazyLang.h"
#include "InputDataClass.h"
#include "MainFrm.h"
#include "afxdialogex.h"


// InputDataClass 대화 상자입니다.

IMPLEMENT_DYNAMIC(InputDataClass, CDialog)

InputDataClass::InputDataClass(CWnd* pParent /*=NULL*/)
	: CDialog(InputDataClass::IDD, pParent)
{

}

InputDataClass::~InputDataClass()
{
}

void InputDataClass::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_InputEditText, InputDataEdit);
	DDX_Control(pDX, IDR_InputBtn, InputOkbutton);
}


BEGIN_MESSAGE_MAP(InputDataClass, CDialog)
	ON_BN_CLICKED(IDR_InputBtn, &InputDataClass::OnBnClickedInputbtn)
	ON_WM_ERASEBKGND()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()


// InputDataClass 메시지 처리기입니다.


void InputDataClass::OnBnClickedInputbtn()
{
	CString string=_T("");
	InputDataEdit.GetWindowTextW(string);

	if(string=="")
	{
	

	}else
	{

		

	char temp=string.GetAt(0);

	if(atoi(&temp)==0)//문자
	{
		
		int tempdata=temp;
		CString tempValue=_T("");
		tempValue.Format(_T("%d"),tempdata);

		int Value=_ttoi(tempValue);
	
		CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

		pFrame->inputDatavalue.setInputData(Value);
		
		//AfxMessageBox(_T("문자"));
		

	}
	else//숫자
	{

		//CString intdata;
		//intdata=string.GetAt(0);
	
		int Value=_ttoi(string);
	
		CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

		pFrame->inputDatavalue.setInputData(Value);

	//	AfxMessageBox(_T("숫자"));
	}

	 OnDestroy(); 
	 OnOK();
	
	}


	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


BOOL InputDataClass::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	if(!inputbackground.m_hObject)
		true;


	CRect rect;
	GetClientRect(&rect);

	CDC dc;
	dc.CreateCompatibleDC(pDC);
	CBitmap * pOldBitmap=dc.SelectObject(&inputbackground);

	BITMAP bmap;
	inputbackground.GetBitmap(&bmap);

	pDC->StretchBlt(0,0,rect.Width(),rect.Height(),&dc,0,0,bmap.bmWidth,bmap.bmHeight,SRCCOPY);

	dc.SelectObject(pOldBitmap);


	return true;

//	return CDialog::OnEraseBkgnd(pDC);
}


BOOL InputDataClass::OnInitDialog()
{
	CDialog::OnInitDialog();

	//MoveWindow(0,0,327,90);//이 함수를 사용하면 대화상자 크기를 조정 할수 있네요.
	inputbackground.LoadBitmapW(IDB_BITMAP7);


	InputOkbutton.LoadBitmaps(IDB_BITMAP8);
	InputOkbutton.SizeToContent();
	//InputDataEdit.SetFocus();
		//SetFocus();
	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void InputDataClass::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
		
	if(nChar== VK_RETURN)
	{


	}




	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);



}


//void InputDataClass::OnOK()
//{
//	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
//
//	CDialog::OnOK();
//}


void InputDataClass::OnOK()
{

	CString string=_T("");
	InputDataEdit.GetWindowTextW(string);

	if(string=="")
	{
	

	}else
	{

		

	char temp=string.GetAt(0);

	if(atoi(&temp)==0)//문자
	{
		
		int tempdata=temp;
		CString tempValue=_T("");
		tempValue.Format(_T("%d"),tempdata);

		int Value=_ttoi(tempValue);
	
		CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

		pFrame->inputDatavalue.setInputData(Value);
		
		//AfxMessageBox(_T("문자"));
		

	}
	else//숫자
	{

		//CString intdata;
		//intdata=string.GetAt(0);
	
		int Value=_ttoi(string);
	
		CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

		pFrame->inputDatavalue.setInputData(Value);

	//	AfxMessageBox(_T("숫자"));
	}

	 OnDestroy(); 
	// OnOK();
	
	}

	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	CDialog::OnOK();
}
