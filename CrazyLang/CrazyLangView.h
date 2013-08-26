
// CrazyLangView.h : CCrazyLangView Ŭ������ �������̽�
//

#pragma once


class CCrazyLangView : public CEditView
{
protected: // serialization������ ��������ϴ�.
	CCrazyLangView();
	DECLARE_DYNCREATE(CCrazyLangView)

// Ư���Դϴ�.
public:
	CCrazyLangDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CCrazyLangView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH CtlColor(CDC* /*pDC*/, UINT /*nCtlColor*/);
	afx_msg void OnStartMenu();
	afx_msg void OnStopMenu();
	afx_msg void OnDebugMenu();

	int MouseCouser;
	CPoint pointSave;
	CString fData;
	CString csTemp;

	int DebugLeftChar;
	int DebugLeftCharMove;
	CString DebugLeftdata;
	

	bool DebugFlag;

	void setSymbolCountView(CString value);


	CString operationString;

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	int leftIndex;
	int rightIndex;


	CString SaveTextView;

	int OperationArray[100000];

	int OperationCountLeftData;

		HICON iconPlus;
		HICON iconMinus;
		HICON iconForstart;
		HICON iconForend;
		HICON iconScanf;
		HICON iconPrintf;
		HICON iconChar;
		HICON nullcon;
		HICON direction;

	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
};



#ifndef _DEBUG  // CrazyLangView.cpp�� ����� ����
inline CCrazyLangDoc* CCrazyLangView::GetDocument() const
   { return reinterpret_cast<CCrazyLangDoc*>(m_pDocument); }
#endif

