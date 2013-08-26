
// CrazyLangView.h : CCrazyLangView 클래스의 인터페이스
//

#pragma once


class CCrazyLangView : public CEditView
{
protected: // serialization에서만 만들어집니다.
	CCrazyLangView();
	DECLARE_DYNCREATE(CCrazyLangView)

// 특성입니다.
public:
	CCrazyLangDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CCrazyLangView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
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



#ifndef _DEBUG  // CrazyLangView.cpp의 디버그 버전
inline CCrazyLangDoc* CCrazyLangView::GetDocument() const
   { return reinterpret_cast<CCrazyLangDoc*>(m_pDocument); }
#endif

