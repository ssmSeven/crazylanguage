// LoadingBox.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CrazyLang.h"
#include "LoadingBox.h"
#include "afxdialogex.h"


// LoadingBox ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(LoadingBox, CDialog)

LoadingBox::LoadingBox(CWnd* pParent /*=NULL*/)
	: CDialog(LoadingBox::IDD, pParent)
{



}

LoadingBox::~LoadingBox()
{
}

void LoadingBox::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_STATUS, stState);
}


BEGIN_MESSAGE_MAP(LoadingBox, CDialog)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// LoadingBox �޽��� ó�����Դϴ�.


BOOL LoadingBox::OnInitDialog()
{
	CDialog::OnInitDialog();
	LONG cur_style = GetWindowLong(m_hWnd, GWL_STYLE);
	SetWindowLong(m_hWnd, GWL_STYLE, cur_style & ~WS_SYSMENU);
	cur_style = GetWindowLong(m_hWnd, GWL_STYLE);
	cur_style&=~WS_CAPTION;
	::SetWindowLong(this->m_hWnd,GWL_STYLE,cur_style);

	MoveWindow(0,0,600,375);//�� �Լ��� ����ϸ� ��ȭ���� ũ�⸦ ���� �Ҽ� �ֳ׿�.
	
	background.LoadBitmapW(IDB_BITMAP3);

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


BOOL LoadingBox::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.


	if(!background.m_hObject)
		true;



	CRect rect;
	GetClientRect(&rect);

	CDC dc;
	dc.CreateCompatibleDC(pDC);
	CBitmap * pOldBitmap=dc.SelectObject(&background);

	BITMAP bmap;
	background.GetBitmap(&bmap);

	pDC->StretchBlt(0,0,rect.Width(),rect.Height(),&dc,0,0,bmap.bmWidth,bmap.bmHeight,SRCCOPY);

	dc.SelectObject(pOldBitmap);


	return true;
}


BOOL LoadingBox::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.


    
	// cs.style = WS_POPUP; //�� �ɼ����� �ٲ۴�.
	  // Call the base-class version
   if( !LoadingBox::PreCreateWindow(cs) )
      return FALSE;

    // Create a window without min/max buttons or sizable border 
    cs.style = WS_OVERLAPPED | WS_SYSMENU | WS_BORDER;

    // Size the window to 1/3 screen size and center it 
    cs.cy = ::GetSystemMetrics(SM_CYSCREEN) / 3; 
    cs.cx = ::GetSystemMetrics(SM_CXSCREEN) / 3; 
    cs.y = ((cs.cy * 3) - cs.cy) / 2; 
    cs.x = ((cs.cx * 3) - cs.cx) / 2;


	 return true;
	//return LoadingBox::PreCreateWindow(cs);
}


HBRUSH LoadingBox::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr;// = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	

	const UINT nID=pWnd->GetDlgCtrlID();
	CRect rect;

	if(nCtlColor==CTLCOLOR_STATIC)
	{
		pDC->SetBkMode(TRANSPARENT);
		hbr=(HBRUSH)::GetStockObject(NULL_BRUSH);
	

		if(nID==IDC_STATIC_STATUS)
		{
			//InvalidateRect(rect);
			pDC->SetTextColor(RGB(255,255,255));
			//pDC->SetBkMode(TRANSPARENT);  // �̰���
			//GetDlgItem(IDC_STATIC_STATUS)->GetClientRect(&rect);
		//	InvalidateRect(rect);

			//pDC->SetBkMode(TRANSPARENT);  // �̰���
			//pDC->SetBkMode(OPAQUE);  // �ٲ��ش�
		
		
		}


	}
	else
	{
		hbr=CDialog::OnCtlColor(pDC,pWnd,nCtlColor);
	
	}


	// TODO:  ���⼭ DC�� Ư���� �����մϴ�.

	// TODO:  �⺻���� �������� ������ �ٸ� �귯�ø� ��ȯ�մϴ�.
	return hbr;
}
