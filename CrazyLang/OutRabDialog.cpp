// OutRabDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CrazyLang.h"
#include "OutRabDialog.h"
#include "afxdialogex.h"


// OutRabDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(OutRabDialog, CDialog)

OutRabDialog::OutRabDialog(CWnd* pParent /*=NULL*/)
	: CDialog(OutRabDialog::IDD, pParent)
{

}

OutRabDialog::~OutRabDialog()
{
}

void OutRabDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(OutRabDialog, CDialog)
END_MESSAGE_MAP()


// OutRabDialog 메시지 처리기입니다.
