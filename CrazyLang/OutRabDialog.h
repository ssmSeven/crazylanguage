#pragma once


// OutRabDialog ��ȭ �����Դϴ�.

class OutRabDialog : public CDialog
{
	DECLARE_DYNAMIC(OutRabDialog)

public:
	OutRabDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~OutRabDialog();

// ��ȭ ���� �������Դϴ�.


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
