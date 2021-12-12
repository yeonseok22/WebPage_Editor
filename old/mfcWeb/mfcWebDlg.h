
// mfcWebDlg.h: 헤더 파일
//

#pragma once


// CmfcWebDlg 대화 상자
class CmfcWebDlg : public CDialogEx
{
// 생성입니다.
public:
	CmfcWebDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCWEB_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedExit();
	afx_msg void OnFileExit();
	afx_msg void OnBnClickedRbEuckr();
	afx_msg void OnEnChangeTbPrimary();
	afx_msg void OnH1();
	afx_msg void OnH2();
	afx_msg void OnH3();
	afx_msg void OnH4();
	afx_msg void OnH5();
	afx_msg void OnH6();
	CEdit CBody2;
	afx_msg void OnEditControl();
	afx_msg void OnHyperlink();
	CEdit CHyperContent;
	CEdit CHyperAddress;
	CEdit CContents;
	afx_msg void OnWebimage();
	afx_msg void OnInformation();
	afx_msg void OnFileOpen();
	CEdit CBody1;
	afx_msg void OnFileSave();
	CEdit CBodyPrimary;
	afx_msg void OnBnClickedMake();
};
