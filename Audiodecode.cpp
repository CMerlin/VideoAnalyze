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
#include "Audiodecode.h"
#include "afxdialogex.h"


// Audiodecode �Ի���

IMPLEMENT_DYNAMIC(Audiodecode, CDialogEx)

Audiodecode::Audiodecode(CWnd* pParent /*=NULL*/)
	: CDialogEx(Audiodecode::IDD, pParent)
{

}

Audiodecode::~Audiodecode()
{
}

void Audiodecode::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DECODEFRAME_A, m_decodeframe_a);
}


BEGIN_MESSAGE_MAP(Audiodecode, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &Audiodecode::OnBnClickedCancel)
END_MESSAGE_MAP()


// Audiodecode ��Ϣ�������
BOOL Audiodecode::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CString resloader;
	resloader.LoadString(IDS_AUDIODECODE);
	SetWindowText(resloader);
	//����ѡ���б���ߣ���ͷ����������
	DWORD dwExStyle=LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE;
	m_decodeframe_a.ModifyStyle(0,LVS_SINGLESEL|LVS_REPORT|LVS_SHOWSELALWAYS);
	m_decodeframe_a.SetExtendedStyle(dwExStyle);

	resloader.LoadString(IDS_AUDIODECODE_NUM);
	m_decodeframe_a.InsertColumn(0,resloader,LVCFMT_CENTER,60,0);
	resloader.LoadString(IDS_AUDIODECODE_SIZE);
	m_decodeframe_a.InsertColumn(1,resloader,LVCFMT_CENTER,60,0);
	resloader.LoadString(IDS_AUDIODECODE_PTS);
	m_decodeframe_a.InsertColumn(2,resloader,LVCFMT_CENTER,60,0);
	resloader.LoadString(IDS_AUDIODECODE_DTS);
	m_decodeframe_a.InsertColumn(3,resloader,LVCFMT_CENTER,60,0);
	

	return TRUE;
}

void Audiodecode::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShowWindow(SW_HIDE);
}

void Audiodecode::SystemClear(){
	m_decodeframe_a.DeleteAllItems();
}

