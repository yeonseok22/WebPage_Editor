#pragma once


// CBody 대화 상자

class CBody : public CDialogEx
{
	DECLARE_DYNAMIC(CBody)

public:
	CBody(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CBody();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCWEB_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
