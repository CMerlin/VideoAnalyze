/* 
 * FFplay for MFC
 * 
 * �����̽�ffmpeg��Ŀ�е�ffplay��������ffplay.c����ֲ����VC�Ļ����¡�
 * ����ʹ��MFC����һ�׼򵥵Ľ��档
 * This software transplant ffplay to Microsoft VC++ environment. 
 * And use MFC to build a simple Graphical User Interface. 
 */

#include "stdafx.h"
#include "Sysinfo.h"
#include "afxdialogex.h"


// Sysinfosubac �Ի���

IMPLEMENT_DYNAMIC(Sysinfosubac, CDialogEx)

	Sysinfosubac::Sysinfosubac(CWnd* pParent /*=NULL*/)
	: CDialogEx(Sysinfosubac::IDD, pParent)
{

}

Sysinfosubac::~Sysinfosubac()
{
}

void Sysinfosubac::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SYSINFO_AC, m_sysinfoac);
}


BEGIN_MESSAGE_MAP(Sysinfosubac, CDialogEx)
END_MESSAGE_MAP()



// Sysinfosubif �Ի���

IMPLEMENT_DYNAMIC(Sysinfosubif, CDialogEx)

	Sysinfosubif::Sysinfosubif(CWnd* pParent /*=NULL*/)
	: CDialogEx(Sysinfosubif::IDD, pParent)
{

}

Sysinfosubif::~Sysinfosubif()
{
}

void Sysinfosubif::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SYSINFO_IF, m_sysinfoif);
}


BEGIN_MESSAGE_MAP(Sysinfosubif, CDialogEx)
END_MESSAGE_MAP()


// Sysinfosubif ��Ϣ�������

// Sysinfosuboc �Ի���

IMPLEMENT_DYNAMIC(Sysinfosuboc, CDialogEx)

	Sysinfosuboc::Sysinfosuboc(CWnd* pParent /*=NULL*/)
	: CDialogEx(Sysinfosuboc::IDD, pParent)
{

}

Sysinfosuboc::~Sysinfosuboc()
{
}

void Sysinfosuboc::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SYSINFO_OC, m_sysinfooc);
}


BEGIN_MESSAGE_MAP(Sysinfosuboc, CDialogEx)
END_MESSAGE_MAP()


// Sysinfosuboc ��Ϣ�������

// Sysinfosubup �Ի���

IMPLEMENT_DYNAMIC(Sysinfosubup, CDialogEx)

	Sysinfosubup::Sysinfosubup(CWnd* pParent /*=NULL*/)
	: CDialogEx(Sysinfosubup::IDD, pParent)
{

}

Sysinfosubup::~Sysinfosubup()
{
}

void Sysinfosubup::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SYSINFO_UP, m_sysinfoup);
}


BEGIN_MESSAGE_MAP(Sysinfosubup, CDialogEx)
END_MESSAGE_MAP()


// Sysinfosubup ��Ϣ�������


// Sysinfosubvc �Ի���

IMPLEMENT_DYNAMIC(Sysinfosubvc, CDialogEx)

	Sysinfosubvc::Sysinfosubvc(CWnd* pParent /*=NULL*/)
	: CDialogEx(Sysinfosubvc::IDD, pParent)
{

}

Sysinfosubvc::~Sysinfosubvc()
{
}

void Sysinfosubvc::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SYSINFO_VC, m_sysinfovc);
}


BEGIN_MESSAGE_MAP(Sysinfosubvc, CDialogEx)
END_MESSAGE_MAP()


// Sysinfosubvc ��Ϣ�������




// Sysinfo �Ի���

IMPLEMENT_DYNAMIC(Sysinfo, CDialogEx)

Sysinfo::Sysinfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(Sysinfo::IDD, pParent)
{

}

Sysinfo::~Sysinfo()
{
}

void Sysinfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SYSINFO_TAB, m_sysinfotab);
}


BEGIN_MESSAGE_MAP(Sysinfo, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_SYSINFO_TAB, &Sysinfo::OnSelchangeSysinfoTab)
END_MESSAGE_MAP()


// Sysinfo ��Ϣ�������
BOOL Sysinfo::OnInitDialog(){
	CDialogEx::OnInitDialog();

	//�������֧��
	CString resloader;
	resloader.LoadString(IDS_SYSINFO);
	SetWindowText(resloader);
	
	sysinfosubup.Create(IDD_SYSINFOSUB_UP,&m_sysinfotab);
	sysinfosubif.Create(IDD_SYSINFOSUB_IF,&m_sysinfotab);
	sysinfosubvc.Create(IDD_SYSINFOSUB_VC,&m_sysinfotab);
	sysinfosubac.Create(IDD_SYSINFOSUB_AC,&m_sysinfotab);
	sysinfosuboc.Create(IDD_SYSINFOSUB_OC,&m_sysinfotab);

	pDialog[0]=&sysinfosubup;
	pDialog[1]=&sysinfosubif;
	pDialog[2]=&sysinfosubvc;
	pDialog[3]=&sysinfosubac;
	pDialog[4]=&sysinfosuboc;

	resloader.LoadString(IDS_SYSINFO_UP);
	m_sysinfotab.InsertItem(0,resloader);
	resloader.LoadString(IDS_SYSINFO_IF);
	m_sysinfotab.InsertItem(1,resloader);
	resloader.LoadString(IDS_SYSINFO_VC);
	m_sysinfotab.InsertItem(2,resloader);
	resloader.LoadString(IDS_SYSINFO_AC);
	m_sysinfotab.InsertItem(3,resloader);
	resloader.LoadString(IDS_SYSINFO_OC);
	m_sysinfotab.InsertItem(4,resloader);

	//����ѡ���б���ߣ���ͷ����������
	DWORD dwExStyle=LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE;
	//�����񣻵���ѡ�񣻸�����ʾѡ����
	//��Ƶ
	sysinfosubif.m_sysinfoif.ModifyStyle(0,LVS_SINGLESEL|LVS_REPORT|LVS_SHOWSELALWAYS);
	sysinfosubif.m_sysinfoif.SetExtendedStyle(dwExStyle);

	resloader.LoadString(IDS_SYSINFO_COMMON_NUM);
	sysinfosubif.m_sysinfoif.InsertColumn(0,resloader,LVCFMT_CENTER,40,0);
	resloader.LoadString(IDS_SYSINFO_COMMON_NAME);
	sysinfosubif.m_sysinfoif.InsertColumn(1,resloader,LVCFMT_CENTER,60,0);
	resloader.LoadString(IDS_SYSINFO_COMMON_FULLNAME);
	sysinfosubif.m_sysinfoif.InsertColumn(2,resloader,LVCFMT_CENTER,200,0);
	resloader.LoadString(IDS_SYSINFO_IF_EXT);
	sysinfosubif.m_sysinfoif.InsertColumn(3,resloader,LVCFMT_CENTER,60,0);
	resloader.LoadString(IDS_SYSINFO_COMMON_PRIVSIZE);
	sysinfosubif.m_sysinfoif.InsertColumn(4,resloader,LVCFMT_CENTER,90,0);
	//-------------------------------------
	sysinfosubac.m_sysinfoac.ModifyStyle(0,LVS_SINGLESEL|LVS_REPORT|LVS_SHOWSELALWAYS);
	sysinfosubac.m_sysinfoac.SetExtendedStyle(dwExStyle);

	resloader.LoadString(IDS_SYSINFO_COMMON_NUM);
	sysinfosubac.m_sysinfoac.InsertColumn(0,resloader,LVCFMT_CENTER,40,0);
	resloader.LoadString(IDS_SYSINFO_COMMON_NAME);
	sysinfosubac.m_sysinfoac.InsertColumn(1,resloader,LVCFMT_CENTER,60,0);
	resloader.LoadString(IDS_SYSINFO_COMMON_FULLNAME);
	sysinfosubac.m_sysinfoac.InsertColumn(2,resloader,LVCFMT_CENTER,200,0);
	resloader.LoadString(IDS_SYSINFO_AC_SAMPLERATE);
	sysinfosubac.m_sysinfoac.InsertColumn(3,resloader,LVCFMT_CENTER,80,0);
	resloader.LoadString(IDS_SYSINFO_AC_SAMPLEFMT);
	sysinfosubac.m_sysinfoac.InsertColumn(4,resloader,LVCFMT_CENTER,80,0);
	resloader.LoadString(IDS_SYSINFO_COMMON_PRIVSIZE);
	sysinfosubac.m_sysinfoac.InsertColumn(5,resloader,LVCFMT_CENTER,90,0);
	//--------------------------------------
	sysinfosubvc.m_sysinfovc.ModifyStyle(0,LVS_SINGLESEL|LVS_REPORT|LVS_SHOWSELALWAYS);
	sysinfosubvc.m_sysinfovc.SetExtendedStyle(dwExStyle);

	resloader.LoadString(IDS_SYSINFO_COMMON_NUM);
	sysinfosubvc.m_sysinfovc.InsertColumn(0,resloader,LVCFMT_CENTER,40,0);
	resloader.LoadString(IDS_SYSINFO_COMMON_NAME);
	sysinfosubvc.m_sysinfovc.InsertColumn(1,resloader,LVCFMT_CENTER,60,0);
	resloader.LoadString(IDS_SYSINFO_COMMON_FULLNAME);
	sysinfosubvc.m_sysinfovc.InsertColumn(2,resloader,LVCFMT_CENTER,200,0);
	resloader.LoadString(IDS_SYSINFO_VC_FRAMERATE);
	sysinfosubvc.m_sysinfovc.InsertColumn(3,resloader,LVCFMT_CENTER,80,0);
	resloader.LoadString(IDS_SYSINFO_VC_PIXFMT);
	sysinfosubvc.m_sysinfovc.InsertColumn(4,resloader,LVCFMT_CENTER,80,0);
	resloader.LoadString(IDS_SYSINFO_COMMON_PRIVSIZE);
	sysinfosubvc.m_sysinfovc.InsertColumn(5,resloader,LVCFMT_CENTER,90,0);
	//--------------------------------------
	sysinfosubup.m_sysinfoup.ModifyStyle(0,LVS_SINGLESEL|LVS_REPORT|LVS_SHOWSELALWAYS);
	sysinfosubup.m_sysinfoup.SetExtendedStyle(dwExStyle);

	resloader.LoadString(IDS_SYSINFO_COMMON_NUM);
	sysinfosubup.m_sysinfoup.InsertColumn(0,resloader,LVCFMT_CENTER,40,0);
	resloader.LoadString(IDS_SYSINFO_COMMON_NAME);
	sysinfosubup.m_sysinfoup.InsertColumn(1,resloader,LVCFMT_CENTER,200,0);
	//--------------------------------------
	sysinfosuboc.m_sysinfooc.ModifyStyle(0,LVS_SINGLESEL|LVS_REPORT|LVS_SHOWSELALWAYS);
	sysinfosuboc.m_sysinfooc.SetExtendedStyle(dwExStyle);

	resloader.LoadString(IDS_SYSINFO_COMMON_NUM);
	sysinfosuboc.m_sysinfooc.InsertColumn(0,resloader,LVCFMT_CENTER,40,0);
	resloader.LoadString(IDS_SYSINFO_COMMON_NAME);
	sysinfosuboc.m_sysinfooc.InsertColumn(1,resloader,LVCFMT_CENTER,60,0);
	resloader.LoadString(IDS_SYSINFO_COMMON_FULLNAME);
	sysinfosuboc.m_sysinfooc.InsertColumn(2,resloader,LVCFMT_CENTER,200,0);
	resloader.LoadString(IDS_SYSINFO_COMMON_PRIVSIZE);
	sysinfosuboc.m_sysinfooc.InsertColumn(3,resloader,LVCFMT_CENTER,90,0);
	//--------------------------------------
	//�趨��Tab����ʾ�ķ�Χ
	CRect rc;
	m_sysinfotab.GetClientRect(rc);
	rc.top += 20;
	rc.bottom -= 0;
	rc.left += 0;
	rc.right -= 0;

	sysinfosubup.MoveWindow(&rc);
	sysinfosubif.MoveWindow(&rc);
	sysinfosubvc.MoveWindow(&rc);
	sysinfosubac.MoveWindow(&rc);
	sysinfosuboc.MoveWindow(&rc);

	pDialog[0]->ShowWindow(TRUE);
	//-------------
	m_CurSelTab=0;

	GetSysinfo();

	return TRUE;
}

void Sysinfo::GetSysinfo(){


	//ȡ��ϵͳ֧�ֵĸ�ʽ��Ϣ��Э�飬��װ��ʽ����������
	av_register_all();
	//��ʼ��
	si.first_c=NULL;
	si.first_if=NULL;
	si.first_up=NULL;

	URLProtocol **pup=&(si.first_up);
	avio_enum_protocols((void **)pup,0);
	int up_index=0;
	while((*pup)!=NULL){
		CString f_index,name,isread,iswrite,priv_data_size;
		int nIndex=0;

#ifdef _UNICODE
		name.Format(_T("%S"),(*pup)->name);
#else
		//��%S��unicode�����£�����Ĳ�����Ϊansi����
		name.Format(_T("%s"),(*pup)->name);
#endif
		priv_data_size.Format(_T("%d"),(*pup)->priv_data_size);
		f_index.Format(_T("%d"),up_index);
		//��ȡ��ǰ��¼����
		nIndex=sysinfosubup.m_sysinfoup.GetItemCount();
		//���С����ݽṹ
		LV_ITEM lvitem;
		lvitem.mask=LVIF_TEXT;
		lvitem.iItem=nIndex;
		lvitem.iSubItem=0;
		//ע��vframe_index������ֱ�Ӹ�ֵ��
		//���ʹ��f_indexִ��Format!�ٸ�ֵ��
		lvitem.pszText=f_index.GetBuffer();
		//lvitem.pszText=(LPWSTR)(LPCTSTR)f_index;
		//------------------------
		sysinfosubup.m_sysinfoup.InsertItem(&lvitem);
		sysinfosubup.m_sysinfoup.SetItemText(nIndex,1,name);
		//��һ��
		avio_enum_protocols((void **)pup,0);
		up_index++;
	}




	si.first_if= av_iformat_next(NULL);
	si.first_c=av_codec_next(NULL);

	AVInputFormat *if_temp=si.first_if;
	AVCodec *c_temp=si.first_c;
	//InputFormat
	int if_index=0;
	while(if_temp!=NULL){
		CString f_index,name,long_name,extensions,priv_data_size;
		int nIndex=0;
#ifdef _UNICODE
		name.Format(_T("%S"),if_temp->name);
		long_name.Format(_T("%S"),if_temp->long_name);
		extensions.Format(_T("%S"),if_temp->extensions);
#else
		name.Format(_T("%s"),if_temp->name);
		long_name.Format(_T("%s"),if_temp->long_name);
		extensions.Format(_T("%s"),if_temp->extensions);
#endif
		priv_data_size.Format(_T("%d"),if_temp->priv_data_size);
		f_index.Format(_T("%d"),if_index);
		//��ȡ��ǰ��¼����
		nIndex=sysinfosubif.m_sysinfoif.GetItemCount();
		//���С����ݽṹ
		LV_ITEM lvitem;
		lvitem.mask=LVIF_TEXT;
		lvitem.iItem=nIndex;
		lvitem.iSubItem=0;
		//ע��vframe_index������ֱ�Ӹ�ֵ��
		//���ʹ��f_indexִ��Format!�ٸ�ֵ��
		lvitem.pszText=f_index.GetBuffer();
		//------------------------
		sysinfosubif.m_sysinfoif.InsertItem(&lvitem);
		sysinfosubif.m_sysinfoif.SetItemText(nIndex,1,name);
		sysinfosubif.m_sysinfoif.SetItemText(nIndex,2,long_name);
		sysinfosubif.m_sysinfoif.SetItemText(nIndex,3,extensions);
		sysinfosubif.m_sysinfoif.SetItemText(nIndex,4,priv_data_size);
		if_temp=if_temp->next;
		if_index++;
	}
	//Codec
	int c_index=0;
	while(c_temp!=NULL){
		CString f_index,name,long_name,priv_data_size,capabilities,
			supported_framerates,pix_fmts,supported_samplerates,sample_fmts,channel_layouts;
		int nIndex=0;

#ifdef _UNICODE
		name.Format(_T("%S"),c_temp->name);
		long_name.Format(_T("%S"),c_temp->long_name);
#else
		name.Format(_T("%s"),c_temp->name);
		long_name.Format(_T("%s"),c_temp->long_name);
#endif
		priv_data_size.Format(_T("%d"),c_temp->priv_data_size);
		f_index.Format(_T("%d"),c_index);
		//���С����ݽṹ
		LV_ITEM lvitem;
		lvitem.mask=LVIF_TEXT;
		lvitem.iSubItem=0;

		switch(c_temp->type){
		case AVMEDIA_TYPE_VIDEO:

			if(c_temp->supported_framerates==NULL){
				supported_framerates.Format(_T("Any"));
			}else{
				float sf_cal=0.0;
				sf_cal=(c_temp->supported_framerates->num)/(c_temp->supported_framerates->den);
				supported_framerates.Format(_T("%f"),sf_cal);
			}

			if(c_temp->pix_fmts==NULL){
				pix_fmts.Format(_T("Unknown"));
			}else{
				const enum AVPixelFormat *pf_temp=c_temp->pix_fmts;
				while(*pf_temp!=-1){
					pix_fmts.AppendFormat(_T("%d;"),*pf_temp);
					pf_temp++;
				}
			}

			//��ȡ��ǰ��¼����
			nIndex=sysinfosubvc.m_sysinfovc.GetItemCount();
			lvitem.iItem=nIndex;

			lvitem.pszText=f_index.GetBuffer();
			//------------------------
			sysinfosubvc.m_sysinfovc.InsertItem(&lvitem);
			sysinfosubvc.m_sysinfovc.SetItemText(nIndex,1,name);
			sysinfosubvc.m_sysinfovc.SetItemText(nIndex,2,long_name);
			sysinfosubvc.m_sysinfovc.SetItemText(nIndex,3,supported_framerates);
			sysinfosubvc.m_sysinfovc.SetItemText(nIndex,4,pix_fmts);
			sysinfosubvc.m_sysinfovc.SetItemText(nIndex,5,priv_data_size);

			break;
		case AVMEDIA_TYPE_AUDIO:

			if(c_temp->supported_samplerates==NULL){
				supported_samplerates.Format(_T("Unknown"));
			}else{
				const int *sr_temp=c_temp->supported_samplerates;
				while(*sr_temp!=0){
					supported_samplerates.AppendFormat(_T("%d;"),*sr_temp);
					sr_temp++;
				}
			}
			if(c_temp->sample_fmts==NULL){
				pix_fmts.Format(_T("Any"));
			}else{
				const enum AVSampleFormat *sf_temp=c_temp->sample_fmts;
				while(*sf_temp!=-1){
					sample_fmts.AppendFormat(_T("%d;"),*sf_temp);
					sf_temp++;
				}
			}

			//��ȡ��ǰ��¼����
			nIndex=sysinfosubac.m_sysinfoac.GetItemCount();
			lvitem.iItem=nIndex;

			lvitem.pszText=f_index.GetBuffer();
			//------------------------
			sysinfosubac.m_sysinfoac.InsertItem(&lvitem);
			sysinfosubac.m_sysinfoac.SetItemText(nIndex,1,name);
			sysinfosubac.m_sysinfoac.SetItemText(nIndex,2,long_name);
			sysinfosubac.m_sysinfoac.SetItemText(nIndex,3,supported_samplerates);
			sysinfosubac.m_sysinfoac.SetItemText(nIndex,4,sample_fmts);
			sysinfosubac.m_sysinfoac.SetItemText(nIndex,5,priv_data_size);
			break;
		default:
			//��ȡ��ǰ��¼����
			nIndex=sysinfosuboc.m_sysinfooc.GetItemCount();
			lvitem.iItem=nIndex;

			lvitem.pszText=f_index.GetBuffer();
			//------------------------
			sysinfosuboc.m_sysinfooc.InsertItem(&lvitem);
			sysinfosuboc.m_sysinfooc.SetItemText(nIndex,1,name);
			sysinfosuboc.m_sysinfooc.SetItemText(nIndex,2,long_name);
			sysinfosuboc.m_sysinfooc.SetItemText(nIndex,3,priv_data_size);
			break;
		}
		c_temp=c_temp->next;
		c_index++;
	}

	



}

void Sysinfo::OnSelchangeSysinfoTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	//�ѵ�ǰ��ҳ����������
	pDialog[m_CurSelTab]->ShowWindow(SW_HIDE);
	//�õ��µ�ҳ������
	m_CurSelTab = m_sysinfotab.GetCurSel();
	//���µ�ҳ����ʾ����
	pDialog[m_CurSelTab]->ShowWindow(SW_SHOW);
	*pResult = 0;
}
