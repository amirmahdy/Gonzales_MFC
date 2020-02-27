// savebox.cpp : implementation file
//

#include "stdafx.h"
#include "MFC-SDI.h"
#include "savebox.h"
#include "afxdialogex.h"




IMPLEMENT_DYNAMIC(savebox, CDialogEx)
savebox::savebox(CWnd* pParent /*=NULL*/)
	: CDialogEx(savebox::IDD, pParent)
	, m_savebrowseval(_T(""))
{
	
}

savebox::~savebox()
{
}

void savebox::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MFCEDITBROWSE1, m_savebrowseval);
}


BEGIN_MESSAGE_MAP(savebox, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &savebox::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &savebox::OnBnClickedOk)
END_MESSAGE_MAP()



void savebox::OnBnClickedCancel()
{
	_Sflag = 0;
	CDialogEx::OnCancel();
}


void savebox::OnBnClickedOk()
{
	_Sflag  = 1;
	CDialogEx::OnOK();
}
