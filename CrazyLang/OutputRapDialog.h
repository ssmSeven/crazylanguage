#pragma once
#include "afxcmn.h"
#include "resource.h"


// OutputRapDialog ��ȭ �����Դϴ�.

class OutputRapDialog : public CDialog
{
	DECLARE_DYNAMIC(OutputRapDialog)




public:
	OutputRapDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~OutputRapDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_OUTPUTRAPDIALOG };







protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
