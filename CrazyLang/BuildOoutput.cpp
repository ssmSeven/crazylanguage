// BuildOoutput.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CrazyLang.h"
#include "BuildOoutput.h"
#include "afxdialogex.h"


// BuildOoutput ��ȭ �����Դϴ�.

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


// BuildOoutput �޽��� ó�����Դϴ�.


BOOL BuildOoutput::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

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


	MoveWindow(0,0,644,638);//�� �Լ��� ����ϸ� ��ȭ���� ũ�⸦ ���� �Ҽ� �ֳ׿�.
	
	backgroundbuild.LoadBitmapW(IDB_BITMAP6);


	CFont font;
	LOGFONT lf;
	::ZeroMemory(&lf,sizeof(lf));
	lf.lfHeight=32;
	lf.lfWeight=FW_BOLD;
	::lstrcpy(lf.lfFaceName,(LPCWSTR)"08���ﳲ��ü");
	font.CreateFontIndirect(&lf);
	GetDlgItem(IDC_RESULTTEXT)->SetFont(&font);
	font.Detach();

	Resulttext.SetWindowText(_T(""));	

	SymbolCountView.SetWindowText(_T(""));	
	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
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

	


	// TODO:  ���⼭ DC�� Ư���� �����մϴ�.

	// TODO:  �⺻���� �������� ������ �ٸ� �귯�ø� ��ȯ�մϴ�.
	return hbr;
}


//void BuildOoutput::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
//{
//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
//}
