// IndicateViewer.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CrazyLang.h"
#include "IndicateViewer.h"


// IndicateViewer

IMPLEMENT_DYNCREATE(IndicateViewer, CMDIChildWnd)

IndicateViewer::IndicateViewer()
{

}

IndicateViewer::~IndicateViewer()
{








}

BOOL IndicateViewer::OnCreateClient(LPCREATESTRUCT /*lpcs*/, CCreateContext* pContext)
{
	return m_wndSplitter.Create(this,
		2, 2,       // TODO: 행 및 열의 개수를 조정합니다.
		CSize(10, 10),  // TODO: 최소 창 크기를 조정합니다.
		pContext);
}

BEGIN_MESSAGE_MAP(IndicateViewer, CMDIChildWnd)
END_MESSAGE_MAP()


// IndicateViewer 메시지 처리기입니다.
