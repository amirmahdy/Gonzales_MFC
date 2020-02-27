
// MFC-SDIView.cpp : implementation of the CMFCSDIView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFC-SDI.h"
#endif
CPoint PNT;
#include "MFC-SDIDoc.h"
#include "MFC-SDIView.h"

#include "Report.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BOOL _DRAW = 0;
CRect LPC ;
	
// CMFCSDIView

IMPLEMENT_DYNCREATE(CMFCSDIView, CScrollView)

BEGIN_MESSAGE_MAP(CMFCSDIView, CScrollView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCSDIView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	
	ON_WM_RBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCSDIView construction/destruction

CMFCSDIView::CMFCSDIView()
{
	// TODO: add construction code here

}

CMFCSDIView::~CMFCSDIView()
{
}

BOOL CMFCSDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// CMFCSDIView drawing

void CMFCSDIView::OnDraw(CDC* pDC)
{
	CMFCSDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if(pDoc->img.IsNull())
		return;

	CRect rc;
	GetClientRect(&rc);
	pDoc->img.Draw(pDC->m_hDC, rc, Gdiplus::InterpolationMode::InterpolationModeBilinear);
}

void CMFCSDIView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CMFCSDIView printing


void CMFCSDIView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCSDIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCSDIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCSDIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


void CMFCSDIView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCSDIView diagnostics

#ifdef _DEBUG
void CMFCSDIView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CMFCSDIView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CMFCSDIDoc* CMFCSDIView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCSDIDoc)));
	return (CMFCSDIDoc*)m_pDocument;
}
#endif //_DEBUG

void CMFCSDIView::OnRButtonUp(UINT nFlags, CPoint point)
{
	
	CRect rc;
	GetClientRect(&rc);	
	CMFCSDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if(pDoc->img.IsNull())
		return;
		Report Dlgp;
		char str[10];
		PNT = PNT - point;
		CString print;
		int y = PNT.y*pDoc->img.GetHeight()/rc.bottom;
		int x = PNT.x*pDoc->img.GetWidth()/rc.right;
		
		itoa(x,str,10);
		print = L"x=";
		print += str;
		
		itoa(y,str,10);
		print += L"   y=";
		print += str;
		
		Dlgp.m_reportedit = print;
		Dlgp.DoModal();
		_DRAW = 0;
		GetDC()->GetWindow()->Invalidate(1);
		CScrollView::OnRButtonUp(nFlags, point);
}

void CMFCSDIView::OnRButtonDown(UINT nFlags, CPoint point)
{
	PNT = point ;
	_DRAW = 1;
	LPC.bottom = 0;
	LPC.top = 0;
	LPC.right= 0;
	LPC.left = 0;

	CScrollView::OnRButtonDown(nFlags, point);
}

void CMFCSDIView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	CRect rc;
	GetClientRect(&rc);	
	CMFCSDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if(pDoc->img.IsNull())
		return;
		
		int y = point.y*pDoc->img.GetHeight()/rc.bottom;
		int x = point.x*pDoc->img.GetWidth()/rc.right;
		
	point.x = x;
	point.y = y;
	pDoc->ZOOMDBCLICK(point);
	CScrollView::OnLButtonDblClk(nFlags, point);
}

void CMFCSDIView::OnMouseMove(UINT nFlags, CPoint point)
{
	if(_DRAW)
	{
	CRect rc;
	GetClientRect(&rc);	
	CMFCSDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if(pDoc->img.IsNull())
		return;

	CRect CUR ;
	CUR.bottom = point.y;
	CUR.left = point.x;
	CUR.right = PNT.x;
	CUR.top = PNT.y;

	SIZE szy;
	szy.cx = 5;
	szy.cy = 5;

	GetDC()->DrawDragRect(CUR,szy,LPC,szy);
	LPC = CUR;

	}
	CScrollView::OnMouseMove(nFlags, point);
}
