#pragma once
#include "afxcmn.h"
#include "resource.h"


// OutputRapDialog 대화 상자입니다.

class OutputRapDialog : public CDialog
{
	DECLARE_DYNAMIC(OutputRapDialog)




public:
	OutputRapDialog(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~OutputRapDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_OUTPUTRAPDIALOG };







protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CBitmap backgroundindicate;
	CImageList ImgList;



	CListCtrl Indication_Sysmbol;
	CListCtrl Indication_Memory;




	virtual BOOL OnInitDialog();
	HICON icon;
	int count;


	void DebugTextResult(CString Address, CString value);
	void DebugTextClear();

	afx_msg void OnBnClickedButton1();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	
};
