#pragma once

#include "afxcmn.h"
#include "resource.h"
#include "afxwin.h"

// BuildOoutput ��ȭ �����Դϴ�.

class BuildOoutput : public CDialog
{
	DECLARE_DYNAMIC(BuildOoutput)

public:
	BuildOoutput(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~BuildOoutput();

	CBitmap backgroundbuild;


// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_BUILDOOUTPUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual BOOL OnInitDialog();

	CStatic Resulttext;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CStatic SymbolCountView;
//	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
//	afx_msg void OnWindowPosChanging(WINDOWPOS* lpwndpos);
};