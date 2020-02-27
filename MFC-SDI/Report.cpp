// Report.cpp : implementation file
//

#include "stdafx.h"
#include "MFC-SDI.h"
#include "Report.h"
#include "afxdialogex.h"


// Report dialog

IMPLEMENT_DYNAMIC(Report, CDialogEx)

Report::Report(CWnd* pParent /*=NULL*/)
	: CDialogEx(Report::IDD, pParent)
	, m_reportedit(_T(""))
{

}

Report::~Report()
{
}

void Report::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_reportedit);
}


BEGIN_MESSAGE_MAP(Report, CDialogEx)
	ON_BN_CLICKED(IDOK, &Report::OnBnClickedOk)
END_MESSAGE_MAP()




void Report::OnBnClickedOk()
{
	CDialogEx::OnOK();
}