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
#include "stdafx.h"
#include "resource.h"
#include "afxcmn.h"
#include "VideoEyeDlg.h"

#include <vector>
using std::vector;

// InputList �Ի���
//ע�⣺VideoEyeDlg.h���Ѿ�include��inputlist.h
//������Ҫ��inputlist.h��include VideoEyeDlg.h
//��˻�����������ѭ����
//���������ò�����ڸ��ļ�����ǰ����һ��
//��֪���ǲ��Ǻ��ʵķ�������֮����ͨ����
class CVideoEyeDlg;

//-------
class InputList : public CDialogEx
{
	DECLARE_DYNAMIC(InputList)

public:
	InputList(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~InputList();

// �Ի�������
	enum { IDD = IDD_INPUTLIST};
	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	//�Լ���ӵģ���ʼ��InputList
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl m_urllist;
	afx_msg void OnBnClickedOpen();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnDblclkUrllist(NMHDR *pNMHDR, LRESULT *pResult);
	CToolBar m_wndToolBar;
	afx_msg void OnInputlistExport();
	afx_msg void OnInputlistImport();
	void XSPFImport(CString filepath);
	void XSPFExport(CString filepath);
	afx_msg void OnM3uImport();
	void M3UImport(CString filepath);
	void M3UExport(CString filepath);


	CString GetURLByIndex(int data_index);

	//����ֵ��ʱ���õ�
	CVideoEyeDlg *maindlg;
//	afx_msg void OnInputlistHelp();

	//һ����¼
	typedef struct Track{
		CString location;
		CString title;
		CString album;
		CString creator;
		CString trackNum;
		CString annotation;
		CString duration;
	}Track;
	//�����б�
	vector<Track> tracklist;
	void RefreshList();
	void SystemClear();
	//UTF-8תGB2312
	char* U2G(const char* utf8);
	afx_msg void OnM3uExport();
};
