// BuildOoutput.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CrazyLang.h"
#include "BuildOoutput.h"
#include "afxdialogex.h"


// BuildOoutput 대화 상자입니다.

IMPLEMENT_DYNAMIC(BuildOoutput, CDialog)

BuildOoutput::BuildOoutput(CWnd* pParent /*=NULL*/)
	: CDialog(BuildOoutput::IDD, pParent)
{

}

BuildOoutput::~BuildOoutput()
{
}

void BuildOoutput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RESULTTEXT, Resulttext);
	DDX_Control(pDX, IDC_SysmbolTextView, SymbolCountView);
}


BEGIN_MESSAGE_MAP(BuildOoutput, CDialog)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
//	ON_WM_KEYUP()
//ON_WM_WINDOWPOSCHANGING()
END_MESSAGE_MAP()


// BuildOoutput 메시지 처리기입니다.


BOOL BuildOoutput::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CRect rect;
	GetClientRect(&rect);

	CDC dc;
	dc.CreateCompatibleDC(pDC);
	CBitmap * pOldBitmap=dc.SelectObject(&backgroundbuild);

	BITMAP bmap;
	backgroundbuild.GetBitmap(&bmap);

	pDC->StretchBlt(0,0,rect.Width(),rect.Height(),&dc,0,0,bmap.bmWidth,bmap.bmHeight,SRCCOPY);

	dc.SelectObject(pOldBitmap);




		return true;

	//return CDialog::OnEraseBkgnd(pDC);
}


BOOL BuildOoutput::OnInitDialog()
{
	CDialog::OnInitDialog();


	MoveWindow(0,0,644,638);//이 함수를 사용하면 대화상자 크기를 조정 할수 있네요.
	
	backgroundbuild.LoadBitmapW(IDB_BITMAP6);


	CFont font;
	LOGFONT lf;
	::ZeroMemory(&lf,sizeof(lf));
	lf.lfHeight=32;
	lf.lfWeight=FW_BOLD;
	::lstrcpy(lf.lfFaceName,(LPCWSTR)"08서울남산체");
	font.CreateFontIndirect(&lf);
	GetDlgItem(IDC_RESULTTEXT)->SetFont(&font);
	font.Detach();

	Resulttext.SetWindowText(_T(""));	

	SymbolCountView.SetWindowText(_T(""));	
	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}



HBRUSH BuildOoutput::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	CRect rect;
	UINT nID=pWnd->GetDlgCtrlID();

	if(nCtlColor==CTLCOLOR_STATIC)
	{
		if(nID==IDC_RESULTTEXT  || nID==IDC_SysmbolTextView)
		{
			 pDC->SetBkColor(RGB(255,255,255));
			 pDC->SetBkMode(TRANSPARENT);
			 pDC->SetTextColor(RGB(255,255,255));
			return (HBRUSH)::GetStockObject(NULL_BRUSH);
		}

	
	}

	


	// TODO:  여기서 DC의 특성을 변경합니다.

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}


//void BuildOoutput::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
//{
//	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
//
//	if ( nChar== VK_LEFT)
//	{
//	
//
//
//
//	}
//	else if( nChar == VK_RIGHT )
//	{
//
//
//
//	
//	}
//
//
//
//	CDialog::OnKeyUp(nChar, nRepCnt, nFlags);
//}


//void BuildOoutput::OnWindowPosChanging(WINDOWPOS* lpwndpos)
//{
//	CDialog::OnWindowPosChanging(lpwndpos);
//
//	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
//}
