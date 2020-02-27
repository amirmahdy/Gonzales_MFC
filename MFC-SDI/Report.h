#pragma once


class Report : public CDialogEx
{
	DECLARE_DYNAMIC(Report)

public:
	Report(CWnd* pParent = NULL);   // standard constructor
	virtual ~Report();

// Dialog Data
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_reportedit;
	afx_msg void OnBnClickedOk();
};
