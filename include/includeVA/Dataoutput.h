/* 
 *
 * 
 * VideoEye
 *
 *
 */

#pragma once


// Dataoutput �Ի���

class Dataoutput : public CDialogEx
{
	DECLARE_DYNAMIC(Dataoutput)

public:
	Dataoutput(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Dataoutput();

// �Ի�������
	enum { IDD = IDD_DATAOUTPUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	//�Լ���ӵģ���ʼ��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_outdirma;
	CEdit m_outdirmo;
	CEdit m_outdirmv;
	CEdit m_outdirru;
	CEdit m_outdirrv;
	CEdit m_outdirry;
	CEdit m_outdirryuv;
	CButton m_outcheckma;
	CButton m_outcheckmo;
	CButton m_outcheckmv;
	CButton m_outcheckru;
	CButton m_outcheckrv;
	CButton m_outcheckry;
	CButton m_outcheckryuv;
	afx_msg void OnBnClickedOutDirMVD();
	afx_msg void OnBnClickedOutDirMAD();
	afx_msg void OnBnClickedOutDirMOD();
	afx_msg void OnBnClickedOutDirRYuvD();
	afx_msg void OnBnClickedOutDirRYD();
	afx_msg void OnBnClickedOutDirRUD();
	afx_msg void OnBnClickedOutDirRVD();
	afx_msg void OnBnClickedOutCheckMV();
	CButton m_outcheckrpcm;
	CEdit m_outdirrpcm;
	afx_msg void OnBnClickedOutDirRPcmD();
	CButton m_outcheckmaaac;
	CButton m_outcheckmvh264;
	CEdit m_outdirmaaac;
	CEdit m_outdirmvh264;
	afx_msg void OnBnClickedOutDirMVH264D();
	afx_msg void OnBnClickedOutDirMAAacD();
};
