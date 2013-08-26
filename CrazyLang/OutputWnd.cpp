
#include "stdafx.h"

#include "OutputWnd.h"
#include "Resource.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COutputBar

COutputWnd::COutputWnd()
{





}

COutputWnd::~COutputWnd()
{
}

BEGIN_MESSAGE_MAP(COutputWnd, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_WINDOWPOSCHANGING()
END_MESSAGE_MAP()

int COutputWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	CRect rectDummy;
	rectDummy.SetRectEmpty();

	// 탭 창을 만듭니다.s
	if (!m_wndTabs.Create(CMFCTabCtrl::STYLE_FLAT, rectDummy, this, 1))
	{
		TRACE0("출력 탭 창을 만들지 못했습니다.\n");
		return -1;      // 만들지 못했습니다.
	}

	// 출력 창을 만듭니다.
	const DWORD dwStyle = LBS_NOINTEGRALHEIGHT | WS_CHILD | WS_VISIBLE | WS_HSCROLL | WS_VSCROLL;

	if (/*!m_wndOutputBuild.Create(dwStyle, rectDummy, &m_wndTabs, 2) ||*/
		/*!m_wndOutputDebug.Create(dwStyle, rectDummy, &m_wndTabs, 3) ||
		!m_wndOutputFind.Create(dwStyle, rectDummy, &m_wndTabs, 4) ||
		!m_wndOutputDebugBox.Create(dwStyle, rectDummy, &m_wndTabs,5) ||*/
		!m_wndOutputBuildCustom.Create(IDD_BUILDOOUTPUT,&m_wndTabs)||
		!m_wndOutputDialog.Create(IDD_OUTPUTRAPDIALOG,&m_wndTabs))

		//!m_wndOutputBuildCustom.Create(IDD_BUILDOOUTPUT,&m_wndTabs)

		//추가
	{
		TRACE0("출력 창을 만들지 못했습니다.\n");
		return -1;      // 만들지 못했습니다.
	}

	UpdateFonts();


	
	CRect rect;


	m_wndTabs.GetClientRect(&rect);
	m_wndOutputDialog.SetWindowPos(NULL,5,25,rect.Width()-10,rect.Height()-30,SWP_NOZORDER);
	//m_wndOutputBuildCustom.SetWindowPos(NULL,5,25,rect.Width()-10,rect.Height()-30,SWP_NOZORDER);

	//m_wndOutputDialog.ShowWindow(SW_HIDE);


	CString strTabName;
	BOOL bNameValid;

	// 탭에 목록 창을 연결합니다.
	//bNameValid = strTabName.LoadString(IDS_BUILD_TAB);
	//ASSERT(bNameValid);
	//m_wndTabs.AddTab(&m_wndOutputBuild, strTabName, (UINT)0);

	bNameValid = strTabName.LoadString(IDS_BUILD_TAB);
	ASSERT(bNameValid);
	m_wndTabs.AddTab(&m_wndOutputBuildCustom, _T("출력"), (UINT)0);


	//bNameValid = strTabName.LoadString(IDS_DEBUG_TAB);
	//ASSERT(bNameValid);
	//m_wndTabs.AddTab(&m_wndOutputDebug, strTabName, (UINT)1);

	//bNameValid = strTabName.LoadString(IDS_FIND_TAB);
	//ASSERT(bNameValid);
	//m_wndTabs.AddTab(&m_wndOutputFind, strTabName, (UINT)2);

	//bNameValid = strTabName.LoadString(IDS_FIND_TAB);
	//m_wndTabs.AddTab(&m_wndOutputDebugBox, strTabName, (UINT)3);

	bNameValid = strTabName.LoadString(IDS_FIND_TAB);
	ASSERT(bNameValid);
	m_wndTabs.AddTab(&m_wndOutputDialog, _T("디버그"), (UINT)1);


	
	
	



	// 출력 탭을 더미 텍스트로 채웁니다.
	//FillBuildWindow();
	FillDebugWindow();
	FillFindWindow();

	return 0;
}


void COutputWnd::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// Tab 컨트롤은 전체 클라이언트 영역을 처리해야 합니다.
	m_wndTabs.SetWindowPos (NULL, -1, -1, cx, cy, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);
}

void COutputWnd::AdjustHorzScroll(CListBox& wndListBox)
{
	CClientDC dc(this);
	CFont* pOldFont = dc.SelectObject(&afxGlobalData.fontRegular);

	int cxExtentMax = 0;

	for (int i = 0; i < wndListBox.GetCount(); i ++)
	{
		CString strItem;
		wndListBox.GetText(i, strItem);

		cxExtentMax = max(cxExtentMax, dc.GetTextExtent(strItem).cx);
	}

	wndListBox.SetHorizontalExtent(cxExtentMax);
	dc.SelectObject(pOldFont);
}

void COutputWnd::FillResult(CString Text)
{
	//m_wndOutputBuild.ResetContent();
	//m_wndOutputBuild.AddString(Text);


}


void COutputWnd::FillBuildWindow()
{

	//m_wndOutputBuild.AddString(_T("CL."));
	//m_wndOutputBuild.AddString(_T("CL."));
	//m_wndOutputBuild.AddString(_T("CL."));

	//int a=m_wndOutputDebugBox.InsertItem(0,_T("1."));
	//int b=m_wndOutputDebugBox.InsertItem(1,_T("2."));

	//m_wndOutputDebugBox.SetItemText(a,1,(LPCTSTR)"테스트");
	//m_wndOutputDebugBox.SetItemText(b,2,(LPCTSTR)"테스트");

	/*

	LVITEM item;
	::ZeroMemory(&item,sizeof(item));

	item.mask=LVIF_TEXT | LVIF_IMAGE | LVIF_GROUPID;

	CString strItem=_T("");


	for(int i=0; i<5; i++)
	{
		strItem.Format(_T("%dth Item"),i);

		item.pszText=strItem.GetBuffer();

		item.iItem=i;
		item.iImage=i;
		item.iGroupId=10;
		m_wndOutputDebugBox.InsertItem(&item);

		item.iGroup=20;
		m_wndOutputDebugBox.InsertItem(&item);
	
	}
	*/
	/*
	static CImageList ImgList;
	ImgList.Create(16,16,ILC_COLOR32,1,1);
	m_wndOutputDebugBox.SetImageList(&ImgList,LVSIL_NORMAL);

		CString strItem=_T("");
		DWORD dwSeed=::GetTickCount();
		LVITEM item;
		::ZeroMemory(&item,sizeof(item));
		item.mask=LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM;


	for(int i=0; i<5; i++)
	{

		ImgList.Add(AfxGetApp()->LoadIcon(IDR_MAINFRAME));

		strItem.Format(_T("%dth Item"),i);

		item.pszText=strItem.GetBuffer();

		item.iItem=i;
		item.iImage=i;
		item.lParam=dwSeed+i;
		m_wndOutputDebugBox.InsertItem(&item);

		strItem.Format(_T("%dth Data"),i);
		m_wndOutputDebugBox.SetItemText(i,1,strItem);


		strItem.Format(_T("%dth Desc"),i);
		m_wndOutputDebugBox.SetItemText(i,2,strItem);
	
	}

	*/

	/*
	//아이콘 이미지 리스트 생성.
	static CImageList ImgList, ImgListSmall;
	ImgList.Create(92, 92, ILC_COLOR32, 5, 0);
	ImgListSmall.Create(50, 50, ILC_COLOR32, 5, 0);

	//이미지 리스트를 리스트 컨트롤에 설정함.
	m_wndOutputDebugBox.SetImageList(&ImgList, LVSIL_NORMAL);
	m_wndOutputDebugBox.SetImageList(&ImgListSmall, LVSIL_SMALL);

	//컬럼을 추가하고 리포트 스타일로 변경
	m_wndOutputDebugBox.InsertColumn(0, _T("Name"), LVCFMT_LEFT, 150);
	m_wndOutputDebugBox.InsertColumn(1, _T("Data"), LVCFMT_LEFT, 150);
	m_wndOutputDebugBox.InsertColumn(2, _T("Description"), LVCFMT_LEFT, 150);
	m_wndOutputDebugBox.ModifyStyle(LVS_TYPEMASK, LVS_REPORT);

	//아이템 추가
	CString strItem = _T("");
	DWORD dwSeed = ::GetTickCount();
	LVITEM item;
	::ZeroMemory(&item, sizeof(item));
	item.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM;


	HICON icon=AfxGetApp()->LoadIcon(IDR_MAINFRAME);


	for(int i = 0; i < 6; ++i)
	{
		

		strItem.Format(_T("%dth Item"), i);

		item.pszText = strItem.GetBuffer();
		item.iItem = i;

		m_wndOutputDebugBox.InsertItem(&item);


		strItem.Format(_T("%dth Data"), i);
		
		m_wndOutputDebugBox.SetItemText(i, 1, strItem);

		strItem.Format(_T("%dth Desc"), i);
		m_wndOutputDebugBox.SetItemText(i, 2, strItem);
	}

	ImgListSmall.Replace(0,icon);

	//헤더 컨트롤 드래그-앤-드롭 가능
	DWORD dwExStyle = m_wndOutputDebugBox.GetExtendedStyle();
	m_wndOutputDebugBox.SetExtendedStyle(dwExStyle | LVS_EX_HEADERDRAGDROP );


	
	*/




	/*
	
	ImgList.Create(16,16,ILC_COLOR32,1,1);
	ImgList.Add(AfxGetApp()->LoadIcon(IDR_MAINFRAME));

	m_wndOutputDebugBox.SetImageList(&ImgList,LVSIL_NORMAL);
	m_wndOutputDebugBox.InsertItem(0,_T("1111"));
	*/
}

void COutputWnd::FillDebugWindow()
{

	/*




	m_wndOutputDebug.AddString(_T("CL."));
	m_wndOutputDebug.AddString(_T("CL"));
	m_wndOutputDebug.AddString(_T("CL."));
	*/
}

void COutputWnd::FillFindWindow()
{/*
	m_wndOutputFind.AddString(_T("CL."));
	m_wndOutputFind.AddString(_T("CL"));
	m_wndOutputFind.AddString(_T("CL."));
	*/
}

void COutputWnd::UpdateFonts()
{
	//m_wndOutputBuild.SetFont(&afxGlobalData.fontRegular);
	//m_wndOutputDebug.SetFont(&afxGlobalData.fontRegular);
	//m_wndOutputFind.SetFont(&afxGlobalData.fontRegular);
}

/////////////////////////////////////////////////////////////////////////////
// COutputList1

COutputList::COutputList()
{
}

COutputList::~COutputList()
{
}

BEGIN_MESSAGE_MAP(COutputList, CListBox)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_EDIT_CLEAR, OnEditClear)
	ON_COMMAND(ID_VIEW_OUTPUTWND, OnViewOutput)
	ON_WM_WINDOWPOSCHANGING()
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
// COutputList 메시지 처리기

void COutputList::OnContextMenu(CWnd* /*pWnd*/, CPoint point)
{
	CMenu menu;
	menu.LoadMenu(IDR_OUTPUT_POPUP);

	CMenu* pSumMenu = menu.GetSubMenu(0);

	if (AfxGetMainWnd()->IsKindOf(RUNTIME_CLASS(CMDIFrameWndEx)))
	{
		CMFCPopupMenu* pPopupMenu = new CMFCPopupMenu;

		if (!pPopupMenu->Create(this, point.x, point.y, (HMENU)pSumMenu->m_hMenu, FALSE, TRUE))
			return;

		((CMDIFrameWndEx*)AfxGetMainWnd())->OnShowPopupMenu(pPopupMenu);
		UpdateDialogControls(this, FALSE);
	}

	SetFocus();
}

void COutputList::OnEditCopy()
{
	MessageBox(_T("출력 복사"));
}

void COutputList::OnEditClear()
{
	MessageBox(_T("출력 지우기"));
}

void COutputList::OnViewOutput()
{
	
	CDockablePane* pParentBar = DYNAMIC_DOWNCAST(CDockablePane, GetOwner());
	CMDIFrameWndEx* pMainFrame = DYNAMIC_DOWNCAST(CMDIFrameWndEx, GetTopLevelFrame());

	if (pMainFrame != NULL && pParentBar != NULL)
	{
		pMainFrame->SetFocus();
		pMainFrame->ShowPane(pParentBar, FALSE, FALSE, FALSE);
		pMainFrame->RecalcLayout();

	}
	
}


COutputDebugBox::COutputDebugBox()
{


}


COutputDebugBox::~COutputDebugBox()
{


}


BEGIN_MESSAGE_MAP(COutputDebugBox, CListBox)

	
	
END_MESSAGE_MAP()





COutputRapDialogbox::COutputRapDialogbox()
{

}

COutputRapDialogbox::~COutputRapDialogbox()
{

}


BEGIN_MESSAGE_MAP(COutputRapDialogbox, CDialog)

	
	
END_MESSAGE_MAP()




void COutputWnd::OnWindowPosChanging(WINDOWPOS* lpwndpos)
{


	//lpwndpos->x=180;
	//lpwndpos->y=0;
	//CDockablePane::OnWindowPosChanging(lpwndpos);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}
