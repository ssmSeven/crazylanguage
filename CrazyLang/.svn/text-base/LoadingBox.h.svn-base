#pragma once
#include "afxwin.h"


// LoadingBox 대화 상자입니다.

class LoadingBox : public CDialog
{
	DECLARE_DYNAMIC(LoadingBox)

public:
	LoadingBox(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~LoadingBox();


	

// 대화 상자 데이터입니다.
	enum { IDD = IDD_LOADINGBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	public:
	CBitmap background;
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	CStatic stState;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
