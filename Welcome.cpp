/* 
 *
 * 
 * VideoEye
 *
 * ������ Lei Xiaohua
 * leixiaohua1020@126.com
 * �й���ý��ѧ/���ֵ��Ӽ���
 * Communication University of China / Digital TV Technology
 * http://blog.csdn.net/leixiaohua1020
 *
 */

#include "stdafx.h"
#include "Welcome.h"


// Welcome

IMPLEMENT_DYNAMIC(Welcome, CWnd)

Welcome::Welcome()
{

}

Welcome::~Welcome()
{
}


BEGIN_MESSAGE_MAP(Welcome, CWnd)
	ON_WM_PAINT()
	ON_WM_TIMER()
END_MESSAGE_MAP()



// Welcome ��Ϣ�������

// Welcome ��Ϣ�������   
void Welcome::Create(UINT nBitmapID)   
{   
	m_bitmap.LoadBitmap(nBitmapID);   
	BITMAP bitmap;   
	m_bitmap.GetBitmap(&bitmap);   
	//CreateEx(0,AfxRegisterWndClass(0),"",WS_POPUP|WS_VISIBLE|WS_BORDER,0,0,bitmap.bmWidth,bitmap.bmHeight,NULL,0);   
	CreateEx(0,   
		AfxRegisterWndClass(0, AfxGetApp()->LoadStandardCursor(IDC_ARROW)),   
		NULL, WS_POPUP | WS_VISIBLE, 0, 0, bitmap.bmWidth, bitmap.bmHeight, NULL , NULL);   
}   
void Welcome::OnPaint()   
{   
	// TODO: �ڴ˴������Ϣ����������   
	// ��Ϊ��ͼ��Ϣ���� CWnd::OnPaint()   
	CPaintDC dc(this); // device context forpainting   
	BITMAP bitmap;   
	m_bitmap.GetBitmap(&bitmap);   
	CDC dcComp;   
	dcComp.CreateCompatibleDC(&dc);   
	dcComp.SelectObject(&m_bitmap);   
	// draw bitmap   
	dc.BitBlt(0,0,bitmap.bmWidth,bitmap.bmHeight,&dcComp,0,0,SRCCOPY);   
}   
void Welcome::OnTimer(UINT_PTR nIDEvent)   
{   
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ   
	//CWnd::OnTimer(nIDEvent);   
	DestroyWindow(); //���ٳ�ʼ���洰��   
}   

