/* 
 *
 * 
 * VideoEye
 *
 */

#pragma once
#include "resource.h"
#include "stdafx.h"
#include "afxcmn.h"

// Audiodecode �Ի���

class Audiodecode : public CDialogEx
{
	DECLARE_DYNAMIC(Audiodecode)

public:
	Audiodecode(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Audiodecode();

// �Ի�������
	enum { IDD = IDD_AUDIODECODE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	//�Լ���ӵģ���ʼ��Teechart
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	void SystemClear();
	CListCtrl m_decodeframe_a;
	afx_msg void OnBnClickedCancel();
};
