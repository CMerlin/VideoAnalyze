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

#pragma once

#include "Dfanalysis.h"
// Dfanalysispic �Ի���
class Dfanalysis;

class Dfanalysispic : public CDialogEx
{
	DECLARE_DYNAMIC(Dfanalysispic)

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	Dfanalysispic(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Dfanalysispic();

	// �Ի�������
	enum { IDD = IDD_DFANALYSIS_PIC };

	virtual BOOL OnInitDialog();

	//�������ƶ���ʱ����Ҫ�ػ棬���µ��ú���
	Dfanalysis *dfanalysisdlg;

	afx_msg void OnPaint();
	afx_msg void OnMove(int x, int y);

	
};
