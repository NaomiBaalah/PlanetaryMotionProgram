
// MFCApp1View.cpp : implementation of the CMFCApp1View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApp1.h"
#endif

#include "MFCApp1Doc.h"
#include "MFCApp1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApp1View

IMPLEMENT_DYNCREATE(CMFCApp1View, CView)

BEGIN_MESSAGE_MAP(CMFCApp1View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApp1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_MOTIONSETTINGS_START32779, &CMFCApp1View::OnMotionsettingsStart32779)
	ON_COMMAND(ID_MOTIONSETTINGS_SUSPEND, &CMFCApp1View::OnMotionsettingsSuspend)
	ON_COMMAND(ID_MOTIONSETTINGS_RESUME32781, &CMFCApp1View::OnMotionsettingsResume32781)
END_MESSAGE_MAP()

// CMFCApp1View construction/destruction

CMFCApp1View::CMFCApp1View() noexcept
{
	// TODO: add construction code here
	m_pCurrentThread=NULL();

}

CMFCApp1View::~CMFCApp1View()
{
}

BOOL CMFCApp1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCApp1View drawing

void CMFCApp1View::OnDraw(CDC* pDC)
{
	CMFCApp1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CPen npen;
		npen.CreatePen(PS_SOLID,5, RGB(0,0,255));
		CPen* olpen = pDC->SelectObject(&npen);
		

	pDC->Ellipse(450,350,150,50);//Outer circle
	pDC->Ellipse(400,300,200,100);//Inner circle
	pDC->Ellipse(330,230,270,170);//innermost circle
	
	pDC->Ellipse(x+10,y+10,x-10,y-10);//outer small circle
	pDC->Ellipse(x1+10,y1+10,x1-10,y1-10);//inner small circle
	pDC->SelectObject(olpen);

	// TODO: add draw code for native data here
	

}


// CMFCApp1View printing


void CMFCApp1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApp1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCApp1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCApp1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMFCApp1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApp1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApp1View diagnostics

#ifdef _DEBUG
void CMFCApp1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApp1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApp1Doc* CMFCApp1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApp1Doc)));
	return (CMFCApp1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApp1View message handlers


void CMFCApp1View::OnMotionsettingsStart32779()
{
	// TODO: Add your command handler code here
	
	m_pCurrentThread = AfxBeginThread(CMFCApp1View::StartThread,this);
	
}


void CMFCApp1View::OnMotionsettingsSuspend()
{
	// TODO: Add your command handler code here
	m_pCurrentThread->SuspendThread();
}


void CMFCApp1View::OnMotionsettingsResume32781()
{
	// TODO: Add your command handler code here
	m_pCurrentThread->ResumeThread();

}


UINT CMFCApp1View::StartThread(LPVOID Param)
{
	// TODO: Add your implementation code here.
	CMFCApp1View* pView = (CMFCApp1View*)Param;
	CPoint MyPoint(0, 0);
	int j = 0;
	while (1)
	{
		j = j + 6;
		pView->x = 300+100 * cos(j);
		pView->y = 200+100* sin(j);

		
		pView->x1 = 300 + 150 * cos(j + 3);
		pView->y1 = 200 + 150 * sin(j + 3);

		pView->Invalidate();
		Sleep(300);

	}
	return 0;
}
