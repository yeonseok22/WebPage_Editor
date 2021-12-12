// CBody.cpp: 구현 파일
//

#include "pch.h"
#include "mfcWeb.h"
#include "CBody.h"
#include "afxdialogex.h"


// CBody 대화 상자

IMPLEMENT_DYNAMIC(CBody, CDialogEx)

CBody::CBody(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCWEB_DIALOG, pParent)
{

}

CBody::~CBody()
{
}

void CBody::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CBody, CDialogEx)
END_MESSAGE_MAP()


// CBody 메시지 처리기
