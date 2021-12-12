// CAboutBox.cpp: 구현 파일
//

#include "pch.h"
#include "mfcWeb.h"
#include "CAboutBox.h"
#include "afxdialogex.h"


// CAboutBox 대화 상자

IMPLEMENT_DYNAMIC(CAboutBox, CDialogEx)

CAboutBox::CAboutBox(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ABOUTBOX, pParent)
{

}

CAboutBox::~CAboutBox()
{
}

void CAboutBox::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAboutBox, CDialogEx)
END_MESSAGE_MAP()


// CAboutBox 메시지 처리기
