
// MFCApp1View.h : interface of the CMFCApp1View class
//

#pragma once


class CMFCApp1View : public CView
{
	CWinThread* m_pCurrentThread;
	CArray<CPoint, CPoint> m_PointArray;

protected: // create from serialization only
	CMFCApp1View() noexcept;
	DECLARE_DYNCREATE(CMFCApp1View)

// Attributes
public:
	CMFCApp1Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMFCApp1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMotionsettingsStart32779();
	afx_msg void OnMotionsettingsSuspend();
	afx_msg void OnMotionsettingsResume32781();
	static UINT StartThread(LPVOID Param);
	
	int x = 400;
	int y = 200;
	double x1 = 300 + 150 * cos(3);
	double y1 = 200 + 150 * sin(3);

};

#ifndef _DEBUG  // debug version in MFCApp1View.cpp
inline CMFCApp1Doc* CMFCApp1View::GetDocument() const
   { return reinterpret_cast<CMFCApp1Doc*>(m_pDocument); }
#endif

