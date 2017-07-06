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

//ʹ��STL
#include <vector>
using std::vector;
// Optplayer �Ի���

class Optplayer : public CDialogEx
{
	DECLARE_DYNAMIC(Optplayer)

public:
	Optplayer(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Optplayer();

// �Ի�������
	enum { IDD = IDD_OPTPLAYER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	//�Լ���ӵ�
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CMFCPropertyGridCtrl m_optplayergrid;
	CMFCPropertyGridProperty *enable_size;
	CMFCPropertyGridProperty *x;
	CMFCPropertyGridProperty *y;
	CMFCPropertyGridProperty *fs;
	CMFCPropertyGridProperty *an;
	CMFCPropertyGridProperty *vn;
	CMFCPropertyGridProperty *enable_ss;
	CMFCPropertyGridProperty *ss;
	CMFCPropertyGridProperty *enable_t;
	CMFCPropertyGridProperty *t;
	CMFCPropertyGridProperty *bytes;
	CMFCPropertyGridProperty *nodisp;
	CMFCPropertyGridProperty *enable_f;
	CMFCPropertyGridProperty *f;
	CMFCPropertyGridProperty *enable_pix_fmt;
	CMFCPropertyGridProperty *pix_fmt;
	CMFCPropertyGridProperty *enable_idct;
	CMFCPropertyGridProperty *idct;
	CMFCPropertyGridProperty *enable_ec;
	CMFCPropertyGridProperty *ec;
	CMFCPropertyGridProperty *enable_sync;
	CMFCPropertyGridProperty *sync;
	CMFCPropertyGridProperty *autoexit;
	CMFCPropertyGridProperty *enable_loop;
	CMFCPropertyGridProperty *loop;
	CMFCPropertyGridProperty *framedrop;
	CMFCPropertyGridProperty *infbuf;
	CMFCPropertyGridProperty *enable_window_title;
	CMFCPropertyGridProperty *window_title;
	CMFCPropertyGridProperty *enable_rdftspeed;
	CMFCPropertyGridProperty *rdftspeed;
	CMFCPropertyGridProperty *enable_showmode;
	CMFCPropertyGridProperty *showmode;
	CMFCPropertyGridProperty *enable_codec;
	CMFCPropertyGridProperty *codec;
	afx_msg void OnClickedOptPlayerGrid();
	void CheckPropertyEnable();
	char** generate_opt_argv();
	int generate_opt_argc();
	void free_opt_argv(char** charlist,int charlist_size);

	vector<CString> opt_argv;

	int counter;
	afx_msg void OnDestroy();
};
