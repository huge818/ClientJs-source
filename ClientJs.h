// ClientJs.h : main header file for the CLIENTJS application
//

#if !defined(AFX_CLIENTJS_H__B4DA8D9B_8941_44D4_AC96_E18CD8EC19AA__INCLUDED_)
#define AFX_CLIENTJS_H__B4DA8D9B_8941_44D4_AC96_E18CD8EC19AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CClientJsApp:
// See ClientJs.cpp for the implementation of this class
//

class CClientJsApp : public CWinApp
{
public:
	CClientJsApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientJsApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CClientJsApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTJS_H__B4DA8D9B_8941_44D4_AC96_E18CD8EC19AA__INCLUDED_)
