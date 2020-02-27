#pragma once


class savebox : public CDialogEx
{
	DECLARE_DYNAMIC(savebox)

public:
	savebox(CWnd* pParent = NULL);   // standard constructor
	virtual ~savebox();
// Dialog Data
	enum { IDD = IDD_DIALOG1 };
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	
	int _Sflag;
	CString m_savebrowseval;
};
