#pragma once

#include "afxcmn.h"
#include "resource.h"
#include "afxwin.h"

// BuildOoutput 대화 상자입니다.

class BuildOoutput : public CDialog
{
	DECLARE_DYNAMIC(BuildOoutput)

public:
	BuildOoutput(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~BuildOoutput();

	CBitmap backgroundbuild;


// 대화 상자 데이터입니다.
	enum { IDD = IDD_BUILDOOUTPUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
