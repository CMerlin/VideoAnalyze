/* 
 *
 * 
 * VideoEye
 *
 *
 */


#pragma once
#include "resource.h"
#include "stdafx.h"
#include "afxcmn.h"
// Videodecode �Ի���

class Videodecode : public CDialogEx
{
	DECLARE_DYNAMIC(Videodecode)

public:
	Videodecode(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Videodecode();

// �Ի�������
	enum { IDD = IDD_VIDEODECODE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	//�Լ���ӵģ���ʼ��Teechart
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_decodeframe_v;
	afx_msg void OnBnClickedCancel();
	void SystemClear();
	void OnCustomdrawMyList ( NMHDR* pNMHDR, LRESULT* pResult );
};
