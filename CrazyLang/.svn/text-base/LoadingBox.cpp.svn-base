// LoadingBox.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CrazyLang.h"
#include "LoadingBox.h"
#include "afxdialogex.h"


// LoadingBox 대화 상자입니다.

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


// LoadingBox 메시지 처리기입니다.


BOOL LoadingBox::OnInitDialog()
{
	CDialog::OnInitDialog();
	LONG cur_style = GetWindowLong(m_hWnd, GWL_STYLE);
	SetWindowLong(m_hWnd, GWL_STYLE, cur_style & ~WS_SYSMENU);
	cur_style = GetWindowLong(m_hWnd, GWL_STYLE);
	cur_style&=~WS_CAPTION;
	::SetWindowLong(this->m_hWnd,GWL_STYLE,cur_style);

	MoveWindow(0,0,600,375);//이 함수를 사용하면 대화상자 크기를 조정 할수 있네요.
	
	background.LoadBitmapW(IDB_BITMAP3);

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


BOOL LoadingBox::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.


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
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.


    
	// cs.style = WS_POPUP; //이 옵션으로 바꾼다.
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
			//pDC->SetBkMode(TRANSPARENT);  // 이것을
			//GetDlgItem(IDC_STATIC_STATUS)->GetClientRect(&rect);
		//	InvalidateRect(rect);

			//pDC->SetBkMode(TRANSPARENT);  // 이것을
			//pDC->SetBkMode(OPAQUE);  // 바꿔준다
		
		
		}


	}
	else
	{
		hbr=CDialog::OnCtlColor(pDC,pWnd,nCtlColor);
	
	}


	// TODO:  여기서 DC의 특성을 변경합니다.

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}
