/* 
 *
 * 
 * VideoEye
 *
 */



#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CVideoEyeApp:
// �йش����ʵ�֣������ VideoEye.cpp
//

class CVideoEyeApp : public CWinApp
{
public:
	CVideoEyeApp();

// ��д
public:
	virtual BOOL InitInstance();
	//������������
	void LoadLaguage();
// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CVideoEyeApp theApp;
