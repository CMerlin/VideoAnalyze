/* 
 *
 * 
 * VideoEye
 *
 */

#pragma once


// Assistantmediainfo �Ի���
#include "resource.h"
#include "stdafx.h"
#include "MediaInfoDLL.h"

class CVideoEyeDlg;

class Assistantmediainfo : public CDialogEx
{
	DECLARE_DYNAMIC(Assistantmediainfo)

public:
	Assistantmediainfo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Assistantmediainfo();

// �Ի�������
	enum { IDD = IDD_ASSISTANTMEDIAINFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	//�Լ���ӵ�
	virtual BOOL OnInitDialog();
	BOOL mediainfo();
	CString fileurl;
	//Ҫ��ʾ����Ϣ
	CString To_Display;
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_mediainfodisplay;
	CVideoEyeDlg *maindlg;
//	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnIdcancel();
};
