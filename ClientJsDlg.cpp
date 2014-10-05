// ClientJsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ClientJs.h"
#include "ClientJsDlg.h"
#include <string>

//#include <windows.h>
//#include "string.h" 
//#include "regex.h" 



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClientJsDlg dialog

CClientJsDlg::CClientJsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClientJsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClientJsDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClientJsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClientJsDlg)
	DDX_Control(pDX, IDC_EXPLORER1, m_ctrlWeb);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CClientJsDlg, CDialog)
	//{{AFX_MSG_MAP(CClientJsDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


CRect m_rect;

/////////////////////////////////////////////////////////////////////////////
// CClientJsDlg message handlers


BOOL CClientJsDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	GetClientRect(&m_rect); 

	TCHAR _szPath[MAX_PATH + 1]={0};
	GetModuleFileName(NULL, _szPath, MAX_PATH);
	(_tcsrchr(_szPath, _T('\\')))[1] = 0;//删除文件名，只获得路径 字串
	CString strPath;
	for (int n=0;_szPath[n];n++)
	{
		if (_szPath[n]!=_T('\\'))
		{
		   strPath +=_szPath[n] ;
		}
		else
		{
		   strPath += _T("\\\\");
		}
	}

	char buf[1000];
	CString Path;
	CString webpath;


	GetCurrentDirectory(1000,buf);   //得到当前工作路径
	Path=buf;

    //m_ctrlWeb.Navigate("c:/test/index.htm",NULL,NULL,NULL,NULL);
	//MessageBox(strPath);
    m_ctrlWeb.Navigate("res://"+strPath+"\\res.dll/source/index.html",NULL,NULL,NULL,NULL);

	return TRUE;  // return TRUE  unless you set the focus to a control
}


// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CClientJsDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}


	CWnd *pWnd;
	pWnd = GetDlgItem(0); 

    if(pWnd)
    {
        CRect rect;
        GetWindowRect(&rect);  
        ScreenToClient(&rect); 
		rect.left=0;
		rect.top=0;
        pWnd->MoveWindow(rect); 
    }

}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CClientJsDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CClientJsDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
    CWnd *pWnd;
    pWnd = GetDlgItem(nType);
    if(pWnd)
    {
        CRect rect;
        pWnd->GetWindowRect(&rect);  
        ScreenToClient(&rect); 
        rect.left  =0; 
        rect.right =cx; 
        rect.top  = 0;
        rect.bottom =cy; 
        pWnd->MoveWindow(rect); 
    }
	
}

BEGIN_EVENTSINK_MAP(CClientJsDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CClientJsDlg)
	ON_EVENT(CClientJsDlg, IDC_EXPLORER1, 259 /* DocumentComplete */, OnDocumentCompleteExplorer1, VTS_DISPATCH VTS_PVARIANT)
	ON_EVENT(CClientJsDlg, IDC_EXPLORER1, 102 /* StatusTextChange */, OnStatusTextChangeExplorer1, VTS_BSTR)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CClientJsDlg::OnStatusTextChangeExplorer1(LPCTSTR Text) 
{
	   // TODO: Add your control notification handler code here

}

void CClientJsDlg::OnDocumentCompleteExplorer1(LPDISPATCH lpDisp, VARIANT FAR* URL) 
{

	// TODO: Add your control notification handler code here
	   HWND hParent = ::FindWindow("#32770", "ClientJs");
	   //m_ctrlWeb.MoveWindow(0,0,0,0,FALSE);

	   IUnknown*  pUnk;
	   LPDISPATCH lpWBDisp;
	   HRESULT    hr;

	   pUnk = m_ctrlWeb.GetControlUnknown();
	   ASSERT(pUnk);

	   hr = pUnk->QueryInterface(IID_IDispatch, (void**)&lpWBDisp);
	   ASSERT(SUCCEEDED(hr));

 

	   if (lpDisp == lpWBDisp)
	   {

				TCHAR _szPath[MAX_PATH + 1]={0};
				GetModuleFileName(NULL, _szPath, MAX_PATH);
				//(_tcsrchr(_szPath, _T('\\')))[1] = 0;//删除文件名，只获得路径 字串
				CString strPath;
				for (int n=0;_szPath[n];n++)
				{
					if (_szPath[n]!=_T('\\'))
					{
					   strPath +=_szPath[n] ;
					}
					else
					{
					   strPath += _T("\\\\");
					}
				}

			    CString str = _T("res://") + strPath;
			    str +=_T("/143");
          

				VARIANT vTemplatePath;
				V_VT(&vTemplatePath) = VT_BSTR;


				WCHAR buffer[1024] = {0};
				MultiByteToWideChar(CP_ACP,0,(char*)LPCSTR(str),(int)strlen((char*)LPCSTR(str)),buffer,sizeof(buffer)/sizeof(buffer[0]));
				BSTR bstrValue = ::SysAllocString(buffer);  //目的就是想使用strPath这个值

				//V_BSTR(&vTemplatePath) = SysAllocString(L"F:/test/exejs/res/dialog.htm");
				V_BSTR(&vTemplatePath) = SysAllocString(buffer);


				LPDISPATCH lpDispApp = m_ctrlWeb.GetApplication();
					  
				if(lpDispApp)
				{
						// Get the HTMLDocument interface.
						LPDISPATCH lpDispDoc = m_ctrlWeb.GetDocument();
						if (lpDispDoc != NULL)
						{
							// Get the IOleCommandTarget interface so that 
							// we can dispatch the command.
							LPOLECOMMANDTARGET lpTarget = NULL;
							if (SUCCEEDED(lpDispDoc->QueryInterface(IID_IOleCommandTarget, (LPVOID*) &lpTarget)))
							{
								lpTarget->Exec(NULL,OLECMDID_PRINTPREVIEW, 0, &vTemplatePath, NULL);
					
								lpTarget->Release();
							}
							lpDispDoc->Release();
						}
						lpDispApp->Release();
				}

				HWND hdialog1 = ::FindWindow("Internet Explorer_TridentDlgFrame", "ClientJs");
				::ShowWindow(hdialog1,SW_HIDE);  //隐藏弹出的模式窗体

				HWND hParent = ::FindWindow("#32770", "ClientJs");
				::EnableWindow(hParent, TRUE);  //设置主窗体可用

	   }
	  lpWBDisp->Release();
}
