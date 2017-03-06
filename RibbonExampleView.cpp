// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// http://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// RibbonExampleView.cpp : implementation of the CRibbonExampleView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "RibbonExample.h"
#endif

#include "RibbonExampleDoc.h"
#include "RibbonExampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRibbonExampleView

IMPLEMENT_DYNCREATE(CRibbonExampleView, CView)

BEGIN_MESSAGE_MAP(CRibbonExampleView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRibbonExampleView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CRibbonExampleView construction/destruction

CRibbonExampleView::CRibbonExampleView()
{
	// TODO: add construction code here

}

CRibbonExampleView::~CRibbonExampleView()
{
}

BOOL CRibbonExampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CRibbonExampleView drawing

void CRibbonExampleView::OnDraw(CDC* /*pDC*/)
{
	CRibbonExampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CRibbonExampleView printing


void CRibbonExampleView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CRibbonExampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRibbonExampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRibbonExampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CRibbonExampleView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CRibbonExampleView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CRibbonExampleView diagnostics

#ifdef _DEBUG
void CRibbonExampleView::AssertValid() const
{
	CView::AssertValid();
}

void CRibbonExampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRibbonExampleDoc* CRibbonExampleView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRibbonExampleDoc)));
	return (CRibbonExampleDoc*)m_pDocument;
}
#endif //_DEBUG


// CRibbonExampleView message handlers
