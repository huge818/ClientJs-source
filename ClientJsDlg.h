// ClientJsDlg.h : header file
//
//{{AFX_INCLUDES()
#include "webbrowser2.h"
//}}AFX_INCLUDES

#if !defined(AFX_CLIENTJSDLG_H__7BED8113_86B5_4473_A10A_8A858C42B27E__INCLUDED_)
#define AFX_CLIENTJSDLG_H__7BED8113_86B5_4473_A10A_8A858C42B27E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CClientJsDlg dialog

class CClientJsDlg : public CDialog
{
// Construction
public:
	CClientJsDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CClientJsDlg)
	enum { IDD = IDD_CLIENTJS_DIALOG };
	CWebBrowser2	m_ctrlWeb;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientJsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CClientJsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDocumentCompleteExplorer1(LPDISPATCH pDisp, VARIANT FAR* URL);
	afx_msg void OnStatusTextChangeExplorer1(LPCTSTR Text);
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTJSDLG_H__7BED8113_86B5_4473_A10A_8A858C42B27E__INCLUDED_)
