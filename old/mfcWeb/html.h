#pragma once
#include "atlstr.h"		// CString 사용하려면 atlstr.h 사용

class html
{
public:

#pragma region html 문서로 반출할 때 사용하는 함수


	/// <summary>
	/// body, head 태그 감싸는 함수
	/// </summary>
	/// <param name="text_box"></param>
	/// <param name="types (0 : body, else : head)"></param>
	/// <returns></returns>
	CString cover_tags(CString text_box, int types)
	{
		CString str = _T("");
		switch(types)
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
		str += primary_str + _T("\r\n") + head_str + _T("\r\n") + body_str;
		str += _T("</html>");
		return str;
	}
	/// <summary>
	/// html 문서 형태로 합치는 기능
	/// </summary>
	/// <param name="primary"></param>
	/// <param name="head"></param>
	/// <param name="body"></param>
	/// <returns></returns>
	CString ReturnHTML(CString primary, CString head, CString body)
	{
		CString str = _T("");



		return str;
	}
#pragma endregion


};