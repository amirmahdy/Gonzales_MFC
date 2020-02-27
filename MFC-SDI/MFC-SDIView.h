
// MFC-SDIView.h : interface of the CMFCSDIView class
//

#pragma once
#include "MainFrm.h"

class CMFCSDIView : public CScrollView
{
protected: // create from serialization only
	CMFCSDIView();
	DECLARE_DYNCREATE(CMFCSDIView)

// Attributes
public:
	CMFCSDIDoc* GetDocument() const;

// Operations
public:
// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMFCSDIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in MFC-SDIView.cpp
inline CMFCSDIDoc* CMFCSDIView::GetDocument() const
   { return reinterpret_cast<CMFCSDIDoc*>(m_pDocument); }
#endif

