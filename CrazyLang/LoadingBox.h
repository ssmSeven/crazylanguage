#pragma once
#include "afxwin.h"


// LoadingBox ��ȭ �����Դϴ�.

class LoadingBox : public CDialog
{
	DECLARE_DYNAMIC(LoadingBox)

public:
	LoadingBox(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~LoadingBox();


	

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_LOADINGBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
