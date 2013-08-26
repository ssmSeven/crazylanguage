// OutputRapDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CrazyLang.h"
#include "OutputRapDialog.h"
#include "afxdialogex.h"


// OutputRapDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(OutputRapDialog, CDialog)

OutputRapDialog::OutputRapDialog(CWnd* pParent /*=NULL*/)
	: CDialog(OutputRapDialog::IDD, pParent)
{

	count=6;

}

OutputRapDialog::~OutputRapDialog()
{
}

void OutputRapDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST3, Indication_Sysmbol);
	DDX_Control(pDX, IDC_LIST1, Indication_Memory);
}


BEGIN_MESSAGE_MAP(OutputRapDialog, CDialog)
	
ON_BN_CLICKED(IDC_BUTTON1, &OutputRapDialog::OnBnClickedButton1)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// OutputRapDialog 메시지 처리기입니다.






BOOL OutputRapDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	
	MoveWindow(0,0,644,638);//이 함수를 사용하면 대화상자 크기를 조정 할수 있네요.
	
	backgroundindicate.LoadBitmapW(IDB_BITMAP5);


	DWORD dwSeed = ::GetTickCount();
	LVITEM item;
	::ZeroMemory(&item, sizeof(item));
	item.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM;


	Indication_Sysmbol.SetBkColor(RGB(0,0,0));

	ImgList.Create(48,48,ILC_COLOR32,14,0);

	CString strItem=_T("");
	icon=AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	

	
	ImgList.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
	ImgList.Add(AfxGetApp()->LoadIcon(IDI_ICON3));
	ImgList.Add(AfxGetApp()->LoadIcon(IDI_ICON4));
	ImgList.Add(AfxGetApp()->LoadIcon(IDI_ICON5));
	ImgList.Add(AfxGetApp()->LoadIcon(IDI_ICON6));
	ImgList.Add(AfxGetApp()->LoadIcon(IDI_ICON7));
	ImgList.Add(AfxGetApp()->LoadIcon(IDI_ICON9));

	ImgList.Add(AfxGetApp()->LoadIcon(IDI_ICON8));// 빈이미지
	ImgList.Add(AfxGetApp()->LoadIcon(IDI_ICON8));
	ImgList.Add(AfxGetApp()->LoadIcon(IDI_ICON8));
	ImgList.Add(AfxGetApp()->LoadIcon(IDI_ICON8));
	ImgList.Add(AfxGetApp()->LoadIcon(IDI_ICON8));
	ImgList.Add(AfxGetApp()->LoadIcon(IDI_ICON8));
	ImgList.Add(AfxGetApp()->LoadIcon(IDI_ICON8));// 빈이미지


	
	for(int i=0; i<14; i++)
	{
		
	item.pszText = strItem.GetBuffer();
	item.iItem = i;
	item.iSubItem=0;
	item.iImage = i;
	Indication_Sysmbol.InsertItem(&item);


	
	}

	Indication_Sysmbol.SetImageList(&ImgList,LVSIL_NORMAL);


	CString strItemMemory=_T("");
	LVITEM Memoryitem;
	Indication_Memory.InsertColumn(0, _T("MemoryAddress"), LVCFMT_LEFT, 273);
	Indication_Memory.InsertColumn(1, _T("Data"), LVCFMT_LEFT, 273);

	Indication_Memory.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_GRIDLINES);
	Indication_Memory.ModifyStyle(LVS_TYPEMASK, LVS_REPORT);




	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}



void OutputRapDialog::DebugTextResult(CString Address, CString Value)
{


		 Indication_Memory.InsertItem(0,Address);
		 Indication_Memory.SetItemText(0,1,Value);

}


void OutputRapDialog::DebugTextClear()
{
		Indication_Memory.DeleteAllItems();
}



void OutputRapDialog::OnBnClickedButton1()
{

	

	HICON icon=AfxGetApp()->LoadIcon(IDI_ICON2);
	HICON nullicon=AfxGetApp()->LoadIcon(IDI_ICON8);


	if(count!=6){
	ImgList.Replace(count,nullicon);
	}
	count++;
	ImgList.Replace(count,nullicon);
	
	
		


		Indication_Memory.SetItemState( -1, 0, LVIS_SELECTED|LVIS_FOCUSED );
		Indication_Memory.SetItemState(count-7, LVIS_FOCUSED | LVIS_SELECTED, LVIS_FOCUSED | LVIS_SELECTED);
		Indication_Memory.EnsureVisible(count-7, false);
		Indication_Memory.SetFocus();
		ImgList.Replace(count,icon);
	

	if(count==14)
	{

		count=6;
	
	}
	

	Invalidate();




	
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


BOOL OutputRapDialog::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.


	
if(!backgroundindicate.m_hObject)
		true;
	
	CRect rect;
	GetClientRect(&rect);

	CDC dc;
	dc.CreateCompatibleDC(pDC);
	CBitmap * pOldBitmap=dc.SelectObject(&backgroundindicate);

	BITMAP bmap;
	backgroundindicate.GetBitmap(&bmap);

	pDC->StretchBlt(0,0,rect.Width(),rect.Height(),&dc,0,0,bmap.bmWidth,bmap.bmHeight,SRCCOPY);

	dc.SelectObject(pOldBitmap);




		return true;
	//return CDialog::OnEraseBkgnd(pDC);
}
