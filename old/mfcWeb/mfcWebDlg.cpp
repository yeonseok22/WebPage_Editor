
// mfcWebDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "mfcWeb.h"
#include "mfcWebDlg.h"
#include "afxdialogex.h"
#include "CAboutBox.h"
#include "locale.h"

//#include "html.h"


#pragma region Encoding
// 출처 : https://oksujay1127.tistory.com/113
// 출처 : https://m.blog.naver.com/kaistd/90182385446
#include <OleAuto.h>

/// <summary>
/// UTF8 -> ANSI (parameter : CString)
/// </summary>
/// <param name="pszCode"></param>
/// <returns></returns>
char* UTF8ToANSI(const char* pszCode)
{
	BSTR    bstrWide;
	char*	pszAnsi;
	int     nLength;

	// Get nLength of the Wide Char buffer
	nLength = MultiByteToWideChar(CP_UTF8, 0, pszCode, strlen(pszCode) + 1,
		NULL, NULL);
	bstrWide = SysAllocStringLen(NULL, nLength);

	// Change UTF-8 to Unicode (UTF-16)
	MultiByteToWideChar(CP_UTF8, 0, pszCode, strlen(pszCode) + 1, bstrWide, nLength);

	// Get nLength of the multi byte buffer
	nLength = WideCharToMultiByte(CP_ACP, 0, bstrWide, -1, NULL, 0, NULL, NULL);
	pszAnsi = new char[nLength];

	// Change from unicode to mult byte
	WideCharToMultiByte(CP_ACP, 0, bstrWide, -1, pszAnsi, nLength, NULL, NULL);
	SysFreeString(bstrWide);

	return pszAnsi;
}
/// <summary>
/// ANSI -> UTF8 (parameter : CString)
/// </summary>
/// <param name="pszCode"></param>
/// <returns></returns>
char* ANSIToUTF8(const char* pszCode)
{
	BSTR bstrCode;
	char* pszUTFCode = NULL;
	int  nLength, nLength2;

	nLength = MultiByteToWideChar(CP_ACP, 0, pszCode, lstrlen(pszCode), NULL, NULL);
	bstrCode = SysAllocStringLen(NULL, nLength);
	MultiByteToWideChar(CP_ACP, 0, pszCode, lstrlen(pszCode), bstrCode, nLength);

	nLength2 = WideCharToMultiByte(CP_UTF8, 0, bstrCode, -1, pszUTFCode, 0, NULL, NULL);
	pszUTFCode = (char*)malloc(nLength2 + 1);
	WideCharToMultiByte(CP_UTF8, 0, bstrCode, -1, pszUTFCode, nLength2, NULL, NULL);

	return pszUTFCode;
}
#pragma endregion


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CmfcWebDlg 대화 상자



CmfcWebDlg::CmfcWebDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCWEB_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmfcWebDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TB_Body, CBody2);
	DDX_Control(pDX, IDC_TB_HyperContent, CHyperContent);
	DDX_Control(pDX, IDC_TB_HyperAddress, CHyperAddress);
	DDX_Control(pDX, IDC_TB_CONTENTS, CContents);
	DDX_Control(pDX, IDC_TB_Head, CBody1);
	DDX_Control(pDX, IDC_TB_Primary, CBodyPrimary);
}

BEGIN_MESSAGE_MAP(CmfcWebDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_Exit, &CmfcWebDlg::OnBnClickedExit)
	ON_COMMAND(ID_FILE_EXIT, &CmfcWebDlg::OnFileExit)
	ON_BN_CLICKED(IDC_RB_EUCKR, &CmfcWebDlg::OnBnClickedRbEuckr)
	ON_EN_CHANGE(IDC_TB_Primary, &CmfcWebDlg::OnEnChangeTbPrimary)
	ON_COMMAND(ID_H1, &CmfcWebDlg::OnH1)
	ON_COMMAND(ID_H2, &CmfcWebDlg::OnH2)
	ON_COMMAND(ID_H3, &CmfcWebDlg::OnH3)
	ON_COMMAND(ID_H4, &CmfcWebDlg::OnH4)
	ON_COMMAND(ID_H5, &CmfcWebDlg::OnH5)
	ON_COMMAND(ID_H6, &CmfcWebDlg::OnH6)
	ON_COMMAND(ID_EDIT_Control, &CmfcWebDlg::OnEditControl)
	ON_COMMAND(ID_HyperLink, &CmfcWebDlg::OnHyperlink)
	ON_COMMAND(ID_WebImage, &CmfcWebDlg::OnWebimage)
	ON_COMMAND(ID_INFORMATION, &CmfcWebDlg::OnInformation)
	ON_COMMAND(ID_FILE_OPEN, &CmfcWebDlg::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, &CmfcWebDlg::OnFileSave)
	ON_BN_CLICKED(ID_Make, &CmfcWebDlg::OnBnClickedMake)
END_MESSAGE_MAP()


// CmfcWebDlg 메시지 처리기

BOOL CmfcWebDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CmfcWebDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CmfcWebDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CmfcWebDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

/// <summary>
/// 텍스트 파일 오픈 |
/// 텍스트 파일을 content 상자에 옮기기
/// | 인코딩 과정 진행하기
/// </summary>
void CmfcWebDlg::OnFileOpen()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CString m_strPath, str, text;
	CStdioFile OpenFile;
	char* pLocale = setlocale(LC_ALL, "Korean");
	CFileException ex;
	CFileDialog dlg(TRUE, _T("*.txt"), NULL, OFN_FILEMUSTEXIST | OFN_OVERWRITEPROMPT, _T("TXT files(*.txt)|*.txt|"), NULL);
	
	if(dlg.DoModal() == IDOK)
	{
		m_strPath = dlg.GetPathName();
		OpenFile.Open(m_strPath, CFile::modeReadWrite | CFile::typeText, &ex);

		while (OpenFile.ReadString(str))
		{
			text += (UTF8ToANSI(LPSTR(LPCTSTR(str + _T("\r\n")))));		// 인코딩(UTF-8 -> ANSI)
		}
		OpenFile.Close();

		CContents.SetWindowTextA(text);
	}

}

#pragma region html 문서로 반출할 때 사용하는 함수


/// <summary>
/// body, head 태그 감싸는 함수
/// </summary>
/// <param name="text_box"></param>
/// <param name="types (0 : head, else : body)"></param>
/// <returns></returns>
CString cover_tags(CString text_box, int types)
{
	CString str = _T("");
	switch (types)
	{
	case 0:
		str += _T("<head>\r\n") + text_box + _T("\r\n</head>");
		str += _T("\r\n");
		break;

	default:
		str += _T("<body>\r\n") + text_box + _T("\r\n</body>");
		str += _T("\r\n");
		break;
	}
	return str;
}
/// <summary> html 태그 감싸는 기능 </summary>
/// <param name="primary 태그 문자열"></param>
/// <param name="head 태그 문자열"></param>
/// <param name="body 태그 문자열"></param>
/// <returns></returns>
CString html_tag(CString primary_str, CString head_str, CString body_str)
{
	CString str = _T("");
	str += primary_str + _T("\r\n") + head_str + body_str;
	str += _T("</html>");
	return str;
}
#pragma endregion

/// <summary>
/// html 파일 저장
/// </summary>
void CmfcWebDlg::OnFileSave()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	// primary text + head text + body text 합치기
	CString PrimaryText = _T("");
	CString HeadText = _T("");
	CString BodyText = _T("");

	CBodyPrimary.GetWindowTextA(PrimaryText);	// 처음 부분
	CBody1.GetWindowTextA(HeadText);			// head 부분
	CBody2.GetWindowTextA(BodyText);			// body 부분

	CString str = html_tag(PrimaryText, cover_tags(HeadText, 0), cover_tags(BodyText, 1));
	
	CString m_strPath;
	CStdioFile SaveFile;
	char* pLocale = setlocale(LC_ALL, "Korean");
	CFileException ex;
	CFileDialog dlg(FALSE, _T("*.html"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("HTML files(*.html)|*.html"), NULL);
	
	if (dlg.DoModal() == IDOK) 
	{
		m_strPath = dlg.GetPathName();
		
		if (m_strPath.Right(5) != ".html")
		{
			m_strPath += ".html";
		}
		SaveFile.Open(m_strPath, CFile::modeCreate | CFile::modeReadWrite, &ex);
		
		// 에디트 박스에 있는 것을 저장한다.
		UpdateData(TRUE);

		SaveFile.WriteString(str);

		// html 저장함을 알리는 알림창 띄움
		MessageBox(_T("html 파일을 저장하였습니다.", _T("정보")));
	}
}

/// <summary>
/// 메인 다이얼로그 - html 파일 만들기
/// </summary>
void CmfcWebDlg::OnBnClickedMake()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	// primary text + head text + body text 합치기
	CString PrimaryText = _T("");
	CString HeadText = _T("");
	CString BodyText = _T("");

	CBodyPrimary.GetWindowTextA(PrimaryText);	// 처음 부분
	CBody1.GetWindowTextA(HeadText);			// head 부분
	CBody2.GetWindowTextA(BodyText);			// body 부분

	CString str = html_tag(PrimaryText, cover_tags(HeadText, 0), cover_tags(BodyText, 1));

	CString m_strPath;
	CStdioFile SaveFile;
	char* pLocale = setlocale(LC_ALL, "Korean");
	CFileException ex;
	CFileDialog dlg(FALSE, _T("*.html"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("HTML files(*.html)|*.html"), NULL);

	if (dlg.DoModal() == IDOK)
	{
		m_strPath = dlg.GetPathName();

		if (m_strPath.Right(5) != ".html")
		{
			m_strPath += ".html";
		}
		SaveFile.Open(m_strPath, CFile::modeCreate | CFile::modeReadWrite, &ex);

		// 에디트 박스에 있는 것을 저장한다.
		UpdateData(TRUE);

		SaveFile.WriteString(str);

		// html 저장함을 알리는 알림창 띄움
		MessageBox(_T("html 파일을 저장하였습니다.", _T("정보")));
	}
}


/// <summary>
/// 메인 다이얼로그 - 파일 종료
/// </summary>
void CmfcWebDlg::OnBnClickedExit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	PostQuitMessage(0);
}

/// <summary>
/// 메뉴 - 파일 종료 2
/// </summary>
void CmfcWebDlg::OnFileExit()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	PostQuitMessage(0);
}

/// <summary>
/// EUC-KR 클릭
/// 1. primary 입력(!doctype, html lang...)
/// 2. head 부분 입력(meta charset, 페이지 제목)
/// </summary>
void CmfcWebDlg::OnBnClickedRbEuckr()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// 1. primary 입력
	CString str1 = _T("<!DOCTYPE html>");
	str1 += "\r\n";
	str1 += _T("<html lang = ko>");

	// primary 텍스트에 값 입력하기
	SetDlgItemText(IDC_TB_Primary, str1);

	// 2. head 부분 입력
	// 1) 제목
	CString title;
	GetDlgItemText(IDC_TB_Title, title);

	CString str2 = _T("<meta charset = \"euc-kr\">");
	str2 += "\r\n";
	str2 += _T("<title>");
	str2 += title;
	str2 += _T("</title>");

	// head 텍스트에 값 입력하기
	// 방법 1 : 멤버변수 추가
	// 방법 2 : 멤버변수.ReplaceSel(str);
	CBody1.ReplaceSel(str2);
}

/// <summary>
/// 머리말 h1
/// </summary>
void CmfcWebDlg::OnH1()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CString h1s = _T("<h1>");
	CString h1e = _T("</h1>");
	CString ConT1;
	GetDlgItemText(IDC_TB_CONTENTS, ConT1);		// IDC_EDIT4 = IDC_TB_CONTENTS

	// body 텍스트에 값 입력하기
	CString header1 = h1s + ConT1 + h1e;
	header1 += "\r\n";
	
	CBody2.ReplaceSel(header1);

}
/// <summary>
/// 머리말 h2
/// </summary>
void CmfcWebDlg::OnH2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CString h2s = _T("<h2>");
	CString h2e = _T("</h2>");
	CString ConT2;
	GetDlgItemText(IDC_TB_CONTENTS, ConT2);

	// body 텍스트에 값 입력하기
	CString header2 = h2s + ConT2 + h2e;
	header2 += "\r\n";
	
	CBody2.ReplaceSel(header2);
}
/// <summary>
/// 머리말 h3
/// </summary>
void CmfcWebDlg::OnH3()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CString h3s = _T("<h3>");
	CString h3e = _T("</h3>");
	CString ConT3;
	GetDlgItemText(IDC_TB_CONTENTS, ConT3);

	// body 텍스트에 값 입력하기
	CString header3 = h3s + ConT3 + h3e;
	header3 += "\r\n";
	CBody2.ReplaceSel(header3);
}
/// <summary>
/// 머리말 h4
/// </summary>
void CmfcWebDlg::OnH4()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CString h4s = _T("<h4>");
	CString h4e = _T("</h4>");
	CString ConT4;
	GetDlgItemText(IDC_TB_CONTENTS, ConT4);

	// body 텍스트에 값 입력하기
	CString header4 = h4s + ConT4 + h4e;
	header4 += "\r\n";
	CBody2.ReplaceSel(header4);
}
/// <summary>
/// 머리말 h5
/// </summary>
void CmfcWebDlg::OnH5()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CString h5s = _T("<h5>");
	CString h5e = _T("</h5>");
	CString ConT5;
	GetDlgItemText(IDC_TB_CONTENTS, ConT5);

	// body 텍스트에 값 입력하기
	CString header5 = h5s + ConT5 + h5e;
	header5 += "\r\n";
	CBody2.ReplaceSel(header5);
}
/// <summary>
/// 머리말 h6
/// </summary>
void CmfcWebDlg::OnH6()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CString h6s = _T("<h6>");
	CString h6e = _T("</h6>");
	CString ConT6;
	GetDlgItemText(IDC_TB_CONTENTS, ConT6);

	// body 텍스트에 값 입력하기
	CString header6 = h6s + ConT6 + h6e;
	header6 += "\r\n";
	CBody2.ReplaceSel(header6);
}
/// <summary>
/// 내용 입력 : <p>
/// </summary>
void CmfcWebDlg::OnEditControl()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CString ps = _T("<p>");
	CString pe = _T("</p>");
	CString texts;

	// texts에서 enter 역할인 \r\n을 <br> 태그로 변경
	CContents.GetWindowText(texts);
	texts.Replace(_T("\r\n"), _T("\r\n<br>"));

	// body 텍스트에 값 입력하기
	CString contents = ps + texts + pe;
	contents += "\r\n";
	CBody2.ReplaceSel(contents);
}
/// <summary>
/// 하이퍼링크 추가
/// <a href = "주소" > 내용 </a>
/// </summary>
void CmfcWebDlg::OnHyperlink()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CString contents, address;
	CHyperContent.GetWindowText(contents);
	CHyperAddress.GetWindowText(address);;

	CString as = _T("<a href = \"");
	CString am = _T("\" > ");
	CString ae = _T("</a>");

	CString hyperlink = as + address + am + contents + ae;
	CBody2.ReplaceSel(hyperlink);
}
/// <summary>
/// 웹 이미지 추가하기
/// </summary>
void CmfcWebDlg::OnWebimage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CString webAdds;
	CContents.GetWindowText(webAdds);;

	CString images = _T("<img src = \"");
	CString imagee = _T(" >");

	CString WebImages = images + webAdds + imagee;
	CBody2.ReplaceSel(WebImages);
}

void CmfcWebDlg::OnEnChangeTbPrimary()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
/// <summary>
/// 애플리케이션 정보
/// </summary>
void CmfcWebDlg::OnInformation()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CAboutBox dlg;
	dlg.DoModal();
}





