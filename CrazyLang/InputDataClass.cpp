// InputDataClass.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CrazyLang.h"
#include "InputDataClass.h"
#include "MainFrm.h"
#include "afxdialogex.h"


// InputDataClass ��ȭ �����Դϴ�.

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


// InputDataClass �޽��� ó�����Դϴ�.


void InputDataClass::OnBnClickedInputbtn()
{
	CString string=_T("");
	InputDataEdit.GetWindowTextW(string);

	if(string=="")
	{
	

	}else
	{

		

	char temp=string.GetAt(0);

	if(atoi(&temp)==0)//����
	{
		
		int tempdata=temp;
		CString tempValue=_T("");
		tempValue.Format(_T("%d"),tempdata);

		int Value=_ttoi(tempValue);
	
		CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

		pFrame->inputDatavalue.setInputData(Value);
		
		//AfxMessageBox(_T("����"));
		

	}
	else//����
	{

		//CString intdata;
		//intdata=string.GetAt(0);
	
		int Value=_ttoi(string);
	
		CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

		pFrame->inputDatavalue.setInputData(Value);

	//	AfxMessageBox(_T("����"));
	}

	 OnDestroy(); 
	 OnOK();
	
	}


	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


BOOL InputDataClass::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

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

	//MoveWindow(0,0,327,90);//�� �Լ��� ����ϸ� ��ȭ���� ũ�⸦ ���� �Ҽ� �ֳ׿�.
	inputbackground.LoadBitmapW(IDB_BITMAP7);


	InputOkbutton.LoadBitmaps(IDB_BITMAP8);
	InputOkbutton.SizeToContent();
	//InputDataEdit.SetFocus();
		//SetFocus();
	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void InputDataClass::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
		
	if(nChar== VK_RETURN)
	{


	}




	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);



}


//void InputDataClass::OnOK()
//{
//	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
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

	if(atoi(&temp)==0)//����
	{
		
		int tempdata=temp;
		CString tempValue=_T("");
		tempValue.Format(_T("%d"),tempdata);

		int Value=_ttoi(tempValue);
	
		CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

		pFrame->inputDatavalue.setInputData(Value);
		
		//AfxMessageBox(_T("����"));
		

	}
	else//����
	{

		//CString intdata;
		//intdata=string.GetAt(0);
	
		int Value=_ttoi(string);
	
		CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

		pFrame->inputDatavalue.setInputData(Value);

	//	AfxMessageBox(_T("����"));
	}

	 OnDestroy(); 
	// OnOK();
	
	}

	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	CDialog::OnOK();
}
