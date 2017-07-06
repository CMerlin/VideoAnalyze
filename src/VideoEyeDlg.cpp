/* 
 *
 * 
 * VideoEye
 *
 */

#include "stdafx.h"
#include "VideoEye.h"
#include "VideoEyeDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	CString m_intro;
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
	CString resloader;
	resloader.LoadString(IDS_ABOUTBOX_INTRO);
	m_intro.Format(_T("%s"),resloader);
	//Version Info
#if 0
	DWORD dwLen = 0;
	char* lpData=NULL;
	BOOL bSuccess = FALSE;

	//�����ļ�·��
	LPSTR exe_path=(LPSTR)malloc(MAX_URL_LENGTH);
	//���exe����·��
	GetModuleFileNameA(NULL,(LPSTR)exe_path,MAX_URL_LENGTH);//

	dwLen = GetFileVersionInfoSize((LPCTSTR)exe_path, 0);
	if ( dwLen==0 ){
	  return ;
	}
	lpData =new char [dwLen+1];
	bSuccess = GetFileVersionInfo((LPCTSTR)exe_path, 0, dwLen, lpData);
	if (!bSuccess){
	  delete lpData;
	  return ;
	}
	free(exe_path);


	LPVOID lpBuffer = NULL;
	UINT uLen = 0;

	bSuccess = VerQueryValue(lpData, 
				  TEXT("\\StringFileInfo\\080404b0\\CompanyName"), 
				  &lpBuffer, 
				  &uLen); 
					  //0804����
					  //04b0��1252,ANSI
					  //���Դ�ResourceView�е�Version��BlockHeader�п���
					  //���Բ��Ե�����
				 
					//CompanyName 
					//FileDescription 
					//FileVersion 
					//InternalName 
					//LegalCopyright
					//OriginalFilename
					//ProductName 
					//ProductVersion 
					//Comments
					//LegalTrademarks 
					//PrivateBuild 
					//SpecialBuild 
		 
	 if (!bSuccess)
	 {
	  delete lpData;
	  return ;
	 }
	 for (int i= 0; i<=uLen; i++)
	 {
			char a = ((char *)lpBuffer)[i];
	 }
		TRACE("%s",lpBuffer);

 
	 delete [] lpData;//�˴�����Ҫ�ͷ�lpBufferָ��Ŀռ�,��ΪlpBuffer��lpDataָ��ͬһ���ڴ�ռ�
#endif
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_INTRO, m_intro);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CVideoEyeDlg �Ի���




CVideoEyeDlg::CVideoEyeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CVideoEyeDlg::IDD, pParent)
	
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_edit_delay = 0;
}

void CVideoEyeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DECODER_NAME, m_decoder_name);
	//  DDX_Control(pDX, IDC_DECODER_TYPE, m_decoder_type);
	DDX_Control(pDX, IDC_PIX_FMT, m_pix_fmt);
	DDX_Control(pDX, IDC_WxH, m_wxh);
	DDX_Control(pDX, IDC_BITRATE, m_bitrate);
	DDX_Control(pDX, IDC_EXTENTION, m_extention);
	DDX_Control(pDX, IDC_METADATA, m_metadata);
	DDX_Control(pDX, IDC_FRAMERATE, m_framerate);
	DDX_Control(pDX, IDC_TIMELONG, m_timelong);

	DDX_Control(pDX, IDC_INPUT_FORMAT, m_input_format);
	DDX_Control(pDX, IDC_INPUT_PROTOCOL, m_input_protocol);
	DDX_Control(pDX, IDC_DECODER_AUDIO_NAME, m_decoder_name_au);
	DDX_Control(pDX, IDC_SAMPLE_RATE, m_sample_rate_au);
	DDX_Control(pDX, IDC_INPUTURL, m_inputurl);
	DDX_Control(pDX, IDC_CHANNELS, m_channels_au);
	DDX_Control(pDX, IDC_PLAY_PROGRESS, m_playprogress);
	DDX_Control(pDX, IDC_AQ_SIZE, m_aqsize);
	DDX_Control(pDX, IDC_VQ_SIZE, m_vqsize);
	DDX_Control(pDX, IDC_DURATION, m_duration);
	DDX_Control(pDX, IDC_CURRENT_CLOCK, m_currentclock);
	DDX_Control(pDX, IDC_AV_DIFF, m_avdiff);
}

BEGIN_MESSAGE_MAP(CVideoEyeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CVideoEyeDlg::OnBnClickedOk)
ON_BN_CLICKED(IDC_STOP, &CVideoEyeDlg::OnClickedStop)
ON_BN_CLICKED(IDC_ABOUT, &CVideoEyeDlg::OnBnClickedAbout)
ON_BN_CLICKED(IDC_PAUSE, &CVideoEyeDlg::OnBnClickedPause)
//ON_BN_CLICKED(IDCANCEL, &CVideoEyeDlg::OnBnClickedCancel)
ON_BN_CLICKED(IDC_INPUTURLBUTTON, &CVideoEyeDlg::OnBnClickedInputurlbutton)
ON_WM_DROPFILES()
ON_BN_CLICKED(IDC_OPEN_INPUTLIST, &CVideoEyeDlg::OnBnClickedOpenInputlist)
ON_BN_CLICKED(IDC_VIDEODECODE, &CVideoEyeDlg::OnBnClickedVideodecode)
ON_BN_CLICKED(IDC_AUDIODECODE, &CVideoEyeDlg::OnBnClickedAudiodecode)
ON_COMMAND(ID_HELP_DOC, &CVideoEyeDlg::OnHelpDoc)
ON_COMMAND(ID_HELP_HOMEPAGE, &CVideoEyeDlg::OnHelpHomepage)
ON_BN_CLICKED(IDC_FULLSCREEN, &CVideoEyeDlg::OnBnClickedFullscreen)
ON_BN_CLICKED(IDC_SEEK_F, &CVideoEyeDlg::OnBnClickedSeekF)
ON_BN_CLICKED(IDC_SEEK_B, &CVideoEyeDlg::OnBnClickedSeekB)
ON_BN_CLICKED(IDC_SEEK_STEP, &CVideoEyeDlg::OnBnClickedSeekStep)
ON_COMMAND(IDC_SEEK_F_10, &CVideoEyeDlg::OnSeekF10)
ON_COMMAND(IDC_SEEK_B_10, &CVideoEyeDlg::OnSeekB10)
ON_COMMAND(IDC_SEEK_F_600, &CVideoEyeDlg::OnSeekF600)
ON_COMMAND(IDC_SEEK_B_600, &CVideoEyeDlg::OnSeekB600)
ON_COMMAND(ID_RESIZE_50, &CVideoEyeDlg::OnResize50)
ON_COMMAND(ID_RESIZE_75, &CVideoEyeDlg::OnResize75)
ON_COMMAND(ID_RESIZE_100, &CVideoEyeDlg::OnResize100)
ON_COMMAND(ID_RESIZE_125, &CVideoEyeDlg::OnResize125)
ON_COMMAND(ID_RESIZE_150, &CVideoEyeDlg::OnResize150)
ON_COMMAND(ID_RESIZE_175, &CVideoEyeDlg::OnResize175)
ON_COMMAND(ID_RESIZE_200, &CVideoEyeDlg::OnResize200)
ON_COMMAND(ID_RESIZE_300, &CVideoEyeDlg::OnResize300)
ON_COMMAND(ID_RESIZE_400, &CVideoEyeDlg::OnResize400)
ON_COMMAND(ID_REASPECT_1_1, &CVideoEyeDlg::OnReaspect11)
ON_COMMAND(ID_REASPECT_3_2, &CVideoEyeDlg::OnReaspect32)
ON_COMMAND(ID_REASPECT_4_3, &CVideoEyeDlg::OnReaspect43)
ON_COMMAND(ID_REASPECT_5_4, &CVideoEyeDlg::OnReaspect54)
ON_COMMAND(ID_REASPECT_14_9, &CVideoEyeDlg::OnReaspect149)
ON_COMMAND(ID_REASPECT_14_10, &CVideoEyeDlg::OnReaspect1410)
ON_COMMAND(ID_REASPECT_16_9, &CVideoEyeDlg::OnReaspect169)
ON_COMMAND(ID_REASPECT_16_10, &CVideoEyeDlg::OnReaspect1610)
ON_COMMAND(ID_REASPECT_235_100, &CVideoEyeDlg::OnReaspect235100)
ON_COMMAND(ID_WINDOW_YUV, &CVideoEyeDlg::OnWindowYuv)

ON_COMMAND(ID_WINDOW_A_WAVE, &CVideoEyeDlg::OnWindowAWave)
ON_COMMAND(ID_WINDOW_A_RDFT, &CVideoEyeDlg::OnWindowARdft)
ON_COMMAND(ID_DATA_OUTPUT_M_A, &CVideoEyeDlg::OnDataOutputMA)
ON_COMMAND(ID_DATA_OUTPUT_M_V, &CVideoEyeDlg::OnDataOutputMV)
ON_COMMAND(ID_DATA_OUTPUT_M_O, &CVideoEyeDlg::OnDataOutputMO)
ON_COMMAND(ID_DATA_OUTPUT_R_YUV, &CVideoEyeDlg::OnDataOutputRYuv)
ON_COMMAND(ID_DATA_OUTPUT_R_Y, &CVideoEyeDlg::OnDataOutputRY)
ON_COMMAND(ID_DATA_OUTPUT_R_U, &CVideoEyeDlg::OnDataOutputRU)
ON_COMMAND(ID_DATA_OUTPUT_R_V, &CVideoEyeDlg::OnDataOutputRV)
ON_COMMAND(ID_DATA_OUTPUT, &CVideoEyeDlg::OnDataOutput)
ON_COMMAND(IDC_SPECIAL_P_RTMP, &CVideoEyeDlg::OnSpecialPRtmp)
ON_COMMAND(ID_ASSISTANT_MEDIAINFO, &CVideoEyeDlg::OnAssistantMediainfo)
ON_COMMAND(IDC_SPECIAL_V_I_JPG, &CVideoEyeDlg::OnSpecialVIJpg)
ON_COMMAND(IDC_RAWANALYSIS_HISTOGRAM, &CVideoEyeDlg::OnRawanalysisHistogram)
ON_COMMAND(IDC_RAWANALYSIS_CANNY, &CVideoEyeDlg::OnRawanalysisCanny)
ON_COMMAND(IDC_RAWANALYSIS_CONTOUR, &CVideoEyeDlg::OnRawanalysisContour)
ON_COMMAND(IDC_RAWANALYSIS_2DDFT, &CVideoEyeDlg::OnRawanalysis2ddft)
ON_COMMAND(IDC_RAWANALYSIS, &CVideoEyeDlg::OnRawanalysis)
ON_COMMAND(IDC_RAWANALYSIS_FACE_DETECT, &CVideoEyeDlg::OnRawanalysisFaceDetect)
ON_COMMAND(IDC_SPECIAL_F_FLV, &CVideoEyeDlg::OnSpecialFFlv)
ON_COMMAND(IDC_SPECIAL_A_AAC, &CVideoEyeDlg::OnSpecialAAac)
ON_COMMAND(IDC_SPECIAL_F_TS, &CVideoEyeDlg::OnSpecialFTs)
ON_COMMAND(IDC_SPECIAL_V_H264, &CVideoEyeDlg::OnSpecialVH264)

ON_COMMAND(ID_OPT_PLAYER, &CVideoEyeDlg::OnOptPlayer)
ON_WM_HSCROLL()
ON_COMMAND(ID_DFANALYSIS, &CVideoEyeDlg::OnDfanalysis)
ON_COMMAND(IDC_RAWANALYSIS_Y, &CVideoEyeDlg::OnRawanalysisY)
ON_COMMAND(IDC_RAWANALYSIS_U, &CVideoEyeDlg::OnRawanalysisU)
ON_COMMAND(IDC_RAWANALYSIS_V, &CVideoEyeDlg::OnRawanalysisV)
ON_COMMAND(IDC_RAWANALYSIS_R, &CVideoEyeDlg::OnRawanalysisR)
ON_COMMAND(IDC_RAWANALYSIS_G, &CVideoEyeDlg::OnRawanalysisG)
ON_COMMAND(IDC_RAWANALYSIS_B, &CVideoEyeDlg::OnRawanalysisB)
ON_COMMAND(ID_TOPMOST_ALWAYS, &CVideoEyeDlg::OnTopmostAlways)
ON_COMMAND(ID_TOPMOST_NEVER, &CVideoEyeDlg::OnTopmostNever)
//ON_COMMAND(IDC_SPECIAL_ABOUT, &CVideoEyeDlg::OnSpecialAbout)
ON_COMMAND(ID_LANG_CN, &CVideoEyeDlg::OnLangCn)
ON_COMMAND(ID_LANG_EN, &CVideoEyeDlg::OnLangEn)
ON_COMMAND(IDCANCEL, &CVideoEyeDlg::OnCancel)
ON_COMMAND(ID_SYSINFO, &CVideoEyeDlg::OnSysinfo)
ON_WM_CTLCOLOR()
ON_COMMAND(ID_WINDOWSTRETCH_KEEPRATIO, &CVideoEyeDlg::OnWindowstretchKeepratio)
ON_COMMAND(ID_WINDOWSTRETCH_RESIZE, &CVideoEyeDlg::OnWindowstretchResize)
END_MESSAGE_MAP()



UINT Thread_Play(LPVOID lpParam){
	CVideoEyeDlg *dlg=(CVideoEyeDlg *)lpParam;
	ve_play(lpParam);
	//LPDWORD nExitCode=0;
	return 0;
}





// CVideoEyeDlg ��Ϣ�������

BOOL CVideoEyeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	///////////////��ʾSplash ����ӭ���棩///////////////////////////////////   
	Welcome welcome;                 //���������������ʵ��   
	welcome.Create(IDB_WELCOME);   
	welcome.CenterWindow();   
	welcome.UpdateWindow();          //send WM_PAINT  
	//��ʾʱ��
	Sleep(2000);
	welcome.DestroyWindow();//���ٳ�ʼ���洰��   
	/////////////////////////////////////////////////////////////////////////
	//���ñ���ɫ
	//SetBackgroundColor(RGB(255,255,255));
	//����ڴ�й¶
	//�ڳ���ʼ�����ĵط�(�㹻ǰ�ĵط�,ֻҪ��й©���ڴ�����ǰ��)ʹ�ô���
	//����Ϊ�ڴ���ַ��{}���е�����
	//_CrtSetBreakAlloc(5253);

	//��ʼ��ͼƬ��ť
	InitBitmapButton();
	//��ʼ���Ӵ���
	InitSubWindow();
	//Tooltip---------------
	InitTooltip();
	//SliderControl
	m_playprogress.SetRange(0,1000);
	m_playprogress.SetTicFreq(10);
	
	//page=(CPage)lineSeries.
	//���ð�ť
	ResetBtn();
	is_playing=0;
	//֧����ϵͳ���Ҽ���----------------------
	//�����������ʱ��
	
	TCHAR* argvPath = __targv[1];

	if(argvPath != NULL){ 
		//����·��
		m_inputurl.SetWindowText(argvPath);
		OnBnClickedOk();
	}

	//----------------------------------------------------
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CVideoEyeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
// �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
// �⽫�ɿ���Զ���ɡ�

void CVideoEyeDlg::OnPaint()
{
	//IsIconic����˼�ǣ��Ƿ�����С���ģ�
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//һ��ͼ�궼������С����
		//���ᴥ������
		CDialogEx::OnPaint();

		//CDC *pDC = this->GetDC(); 
		//CRect rect;
		//CBrush pBrush;

		//
		////�ͻ���
		//GetClientRect(&rect); 
		//pBrush.CreateSolidBrush(RGB(255,255,255));
		//pDC->FillRect(rect,&pBrush);
		//pBrush.DeleteObject();
	}
	
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CVideoEyeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CVideoEyeDlg::OnBnClickedOk()
{

	SystemClear();
	if(GetURL()==-1){
		return ;
	}
	pThreadPlay = AfxBeginThread(Thread_Play,this);//�����߳�
	ActiveBtn();
	is_playing=1;

	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
}

int CVideoEyeDlg::GetURL()
{
	LPTSTR urlstr=(LPTSTR)malloc(MAX_URL_LENGTH);
	m_inputurl.GetWindowText((LPTSTR)urlstr,MAX_URL_LENGTH);
#ifdef _UNICODE
	USES_CONVERSION;
	strcpy(url,W2A(urlstr));
#else
	strcpy(url,urlstr);
#endif
	if(strcmp(url,"")==0){
		CString resloader;
		resloader.LoadString(IDS_MSGBOX_NOURL);
		AfxMessageBox(resloader);
		return -1;
	}
	return 0;
}

void CVideoEyeDlg::OnClickedStop()
{
	ve_quit();
	ResetBtn();
	is_playing=0;
	
}

void CVideoEyeDlg::OnBnClickedAbout()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CAboutDlg dlg;
	dlg.DoModal();
}


void CVideoEyeDlg::OnBnClickedPause()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ve_play_pause();

}

void CVideoEyeDlg::SystemClear()
{
	videodecode->SystemClear();
	audiodecode->SystemClear();
	ve_reset_index();
}



void CVideoEyeDlg::OnTimer(UINT nIDEvent)
{
	
}

void CVideoEyeDlg::OnBnClickedInputurlbutton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString FilePathName;
	//�ļ������ַ���������
	CString strfilter;
	strfilter.Append(_T("Common media formats|*.avi;*.wmv;*.wmp;*.wm;*.asf;*.rm;*.ram;*.rmvb;*.ra;*.mpg;*.mpeg;*.mpe;*.m1v;*.m2v;*.mpv2;"));
	strfilter.Append(_T("*.mp2v;*.dat;*.mp4;*.m4v;*.m4p;*.vob;*.ac3;*.dts;*.mov;*.qt;*.mr;*.3gp;*.3gpp;*.3g2;*.3gp2;*.swf;*.ogg;*.wma;*.wav;"));
	strfilter.Append(_T("*.mid;*.midi;*.mpa;*.mp2;*.mp3;*.m1a;*.m2a;*.m4a;*.aac;*.mkv;*.ogm;*.m4b;*.tp;*.ts;*.tpr;*.pva;*.pss;*.wv;*.m2ts;*.evo;"));
	strfilter.Append(_T("*.rpm;*.realpix;*.rt;*.smi;*.smil;*.scm;*.aif;*.aiff;*.aifc;*.amr;*.amv;*.au;*.acc;*.dsa;*.dsm;*.dsv;*.dss;*.pmp;*.smk;*.flic|"));
	strfilter.Append(_T("Windows Media Video(*.avi;*wmv;*wmp;*wm;*asf)|*.avi;*.wmv;*.wmp;*.wm;*.asf|"));
	strfilter.Append(_T("Windows Media Audio(*.wma;*wav;*aif;*aifc;*aiff;*mid;*midi;*rmi)|*.wma;*.wav;*.aif;*.aifc;*.aiff;*.mid;*.midi;*.rmi|"));
	strfilter.Append(_T("Real(*.rm;*ram;*rmvb;*rpm;*ra;*rt;*rp;*smi;*smil;*.scm)|*.rm;*.ram;*.rmvb;*.rpm;*.ra;*.rt;*.rp;*.smi;*.smil;*.scm|"));
	strfilter.Append(_T("MPEG Video(*.mpg;*mpeg;*mpe;*m1v;*m2v;*mpv2;*mp2v;*dat;*mp4;*m4v;*m4p;*m4b;*ts;*tp;*tpr;*pva;*pss;*.wv;)|"));
	strfilter.Append(_T("*.mpg;*.mpeg;*.mpe;*.m1v;*.m2v;*.mpv2;*.mp2v;*.dat;*.mp4;*.m4v;*.m4p;*.m4b;*.ts;*.tp;*.tpr;*.pva;*.pss;*.wv;|"));
	strfilter.Append(_T("MPEG Audio(*.mpa;*mp2;*m1a;*m2a;*m4a;*aac;*.m2ts;*.evo)|*.mpa;*.mp2;*.m1a;*.m2a;*.m4a;*.aac;*.m2ts;*.evo|"));
	strfilter.Append(_T("DVD(*.vob;*ifo;*ac3;*dts)|*.vob;*.ifo;*.ac3;*.dts|MP3(*.mp3)|*.mp3|CD Tracks(*.cda)|*.cda|"));
	strfilter.Append(_T("Quicktime(*.mov;*qt;*mr;*3gp;*3gpp;*3g2;*3gp2)|*.mov;*.qt;*.mr;*.3gp;*.3gpp;*.3g2;*.3gp2|"));
	strfilter.Append(_T("Flash Files(*.flv;*swf;*.f4v)|*.flv;*.swf;*.f4v|Playlist(*.smpl;*.asx;*m3u;*pls;*wvx;*wax;*wmx;*mpcpl)|*.smpl;*.asx;*.m3u;*.pls;*.wvx;*.wax;*.wmx;*.mpcpl|"));
	strfilter.Append(_T("Others(*.ivf;*au;*snd;*ogm;*ogg;*fli;*flc;*flic;*d2v;*mkv;*pmp;*mka;*smk;*bik;*ratdvd;*roq;*drc;*dsm;*dsv;*dsa;*dss;*mpc;*divx;*vp6;*.ape;*.flac;*.tta;*.csf)"));
	strfilter.Append(_T("|*.ivf;*.au;*.snd;*.ogm;*.ogg;*.fli;*.flc;*.flic;*.d2v;*.mkv;*.pmp;*.mka;*.smk;*.bik;*.ratdvd;*.roq;*.drc;*.dsm;*.dsv;*.dsa;*.dss;*.mpc;*.divx;*.vp6;*.ape;*.amr;*.flac;*.tta;*.csf|"));
	strfilter.Append(_T("All Files(*.*)|*.*||"));
	
	
	LPCTSTR lpszfilter=strfilter;
	CFileDialog dlg(TRUE,NULL,NULL,NULL,lpszfilter);///TRUEΪOPEN�Ի���FALSEΪSAVE AS�Ի��� 
	if(dlg.DoModal()==IDOK) {
		FilePathName=dlg.GetPathName();
		m_inputurl.SetWindowText(FilePathName);
	}

}




void CVideoEyeDlg::OnDropFiles(HDROP hDropInfo)
{
	CDialogEx::OnDropFiles(hDropInfo);

	LPTSTR pFilePathName =(LPTSTR)malloc(MAX_URL_LENGTH);
	::DragQueryFile(hDropInfo, 0, pFilePathName,MAX_URL_LENGTH);  // ��ȡ�Ϸ��ļ��������ļ�������ؼ���
	m_inputurl.SetWindowText(pFilePathName);
	::DragFinish(hDropInfo);   // ע����������٣��������ͷ�Windows Ϊ�����ļ��ϷŶ�������ڴ�
	free(pFilePathName);
}

void CVideoEyeDlg::OnBnClickedOpenInputlist()
{
	inputlist->ShowWindow(SW_SHOW);
}


void CVideoEyeDlg::OnBnClickedVideodecode()
{
	videodecode->ShowWindow(SW_SHOW);
}


void CVideoEyeDlg::OnBnClickedAudiodecode()
{
	audiodecode->ShowWindow(SW_SHOW);
}



void CAboutDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	// ��ӱ���ͼƬ
	CRect   rect;   
	GetClientRect(&rect);   
	CDC   dcMem;   
	dcMem.CreateCompatibleDC(&dc);   
	CBitmap   bmpBackground;   
	bmpBackground.LoadBitmap(IDB_ABOUT);   
	//IDB_BITMAP�����Լ���ͼ��Ӧ��ID   
	BITMAP   bitmap;   
	bmpBackground.GetBitmap(&bitmap);   
	CBitmap   *pbmpOld=dcMem.SelectObject(&bmpBackground);   
	dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,   
		bitmap.bmWidth,bitmap.bmHeight,SRCCOPY);   
}



void CVideoEyeDlg::OnHelpDoc()
{
	char realpath[400]={0};
	//���exe����·��
	GetModuleFileNameA(NULL,(LPSTR)realpath,400);//
	//���exe�ļҼ�·��
	strrchr(realpath, '\\')[0]= '\0';//���Ų��Ҷ�Ӧ���ַ�'\\'���滻��'\0'
	strcat(realpath,"\\helpdoc.pdf");
	ShellExecuteA( NULL,"open",realpath,NULL,NULL,SW_SHOWNORMAL);
}


void CVideoEyeDlg::OnHelpHomepage()
{
	ShellExecuteA(NULL, "open","http://blog.csdn.net/leixiaohua1020",NULL,NULL,SW_SHOWNORMAL);
}




void CVideoEyeDlg::OnBnClickedFullscreen()
{
	ve_play_fullcreen();
}


void CVideoEyeDlg::OnBnClickedSeekF()
{
	ve_seek(60);
}


void CVideoEyeDlg::OnBnClickedSeekB()
{
	ve_seek(-60);
}


void CVideoEyeDlg::OnBnClickedSeekStep()
{
	ve_seek_step();
}


void CVideoEyeDlg::OnSeekF10()
{
	ve_seek(10);
}


void CVideoEyeDlg::OnSeekB10()
{
	ve_seek(-10);
}


void CVideoEyeDlg::OnSeekF600()
{
	ve_seek(600);
}


void CVideoEyeDlg::OnSeekB600()
{
	ve_seek(-600);
}


void CVideoEyeDlg::OnResize50()
{
	ve_size(50);
}


void CVideoEyeDlg::OnResize75()
{
	ve_size(75);
}


void CVideoEyeDlg::OnResize100()
{
	ve_size(100);
}


void CVideoEyeDlg::OnResize125()
{
	ve_size(125);
}


void CVideoEyeDlg::OnResize150()
{
	ve_size(150);
}


void CVideoEyeDlg::OnResize175()
{
	ve_size(175);
}


void CVideoEyeDlg::OnResize200()
{
	ve_size(200);
}


void CVideoEyeDlg::OnResize300()
{
	ve_size(300);
}


void CVideoEyeDlg::OnResize400()
{
	ve_size(400);
}


void CVideoEyeDlg::OnReaspect11()
{
	ve_aspectratio(1,1);
}


void CVideoEyeDlg::OnReaspect32()
{
	ve_aspectratio(3,2);
}


void CVideoEyeDlg::OnReaspect43()
{
	ve_aspectratio(4,3);
}


void CVideoEyeDlg::OnReaspect54()
{
	ve_aspectratio(5,4);
}


void CVideoEyeDlg::OnReaspect149()
{
	ve_aspectratio(14,9);
}


void CVideoEyeDlg::OnReaspect1410()
{
	ve_aspectratio(14,10);
}


void CVideoEyeDlg::OnReaspect169()
{
	ve_aspectratio(16,9);
}


void CVideoEyeDlg::OnReaspect1610()
{
	ve_aspectratio(16,10);
}


void CVideoEyeDlg::OnReaspect235100()
{
	ve_aspectratio(235,100);
}


void CVideoEyeDlg::OnWindowYuv()
{
	ve_audio_display(0);
}





void CVideoEyeDlg::OnWindowAWave()
{
	ve_audio_display(1);
}


void CVideoEyeDlg::OnWindowARdft()
{
	ve_audio_display(2);
}


void CVideoEyeDlg::OnDataOutputMA()
{
	dataoutput->ShowWindow(SW_SHOW);
	dataoutput->m_outcheckma.SetCheck(1);
}


void CVideoEyeDlg::OnDataOutputMV()
{
	dataoutput->ShowWindow(SW_SHOW);
	dataoutput->m_outcheckmv.SetCheck(1);
}


void CVideoEyeDlg::OnDataOutputMO()
{
	dataoutput->ShowWindow(SW_SHOW);
	dataoutput->m_outcheckmo.SetCheck(1);
}


void CVideoEyeDlg::OnDataOutputRYuv()
{
	dataoutput->ShowWindow(SW_SHOW);
	dataoutput->m_outcheckryuv.SetCheck(1);
}


void CVideoEyeDlg::OnDataOutputRY()
{
	dataoutput->ShowWindow(SW_SHOW);
	dataoutput->m_outcheckry.SetCheck(1);
}


void CVideoEyeDlg::OnDataOutputRU()
{
	dataoutput->ShowWindow(SW_SHOW);
	dataoutput->m_outcheckru.SetCheck(1);
}


void CVideoEyeDlg::OnDataOutputRV()
{
	dataoutput->ShowWindow(SW_SHOW);
	dataoutput->m_outcheckrv.SetCheck(1);
}


void CVideoEyeDlg::OnDataOutput()
{
	dataoutput->ShowWindow(SW_SHOW);
}


void CVideoEyeDlg::OnSpecialPRtmp()
{
	char realpath[400]={0};
	//���exe����·��
	GetModuleFileNameA(NULL,(LPSTR)realpath,400);//
	//���exe�ļҼ�·��
	strrchr(realpath, '\\')[0]= '\0';//���Ų��Ҷ�Ӧ���ַ�'\\'���滻��'\0'
	strcat(realpath,"\\SpecialPRTMP.exe");
	//���ļ�
	ShellExecuteA( NULL,"open",realpath,NULL,NULL,SW_SHOWNORMAL);
}


void CVideoEyeDlg::OnAssistantMediainfo()
{
	assistantmi=new Assistantmediainfo;
	//������thisָ��
	assistantmi->maindlg=this;
	assistantmi->Create(IDD_ASSISTANTMEDIAINFO);
	assistantmi->ShowWindow(TRUE);
}


void CVideoEyeDlg::OnSpecialVIJpg()
{
	char realpath[400]={0};
	//���exe����·��
	GetModuleFileNameA(NULL,(LPSTR)realpath,400);//
	//���exe�ļҼ�·��
	strrchr(realpath, '\\')[0]= '\0';//���Ų��Ҷ�Ӧ���ַ�'\\'���滻��'\0'
	strcat(realpath,"\\SpecialVIJPG.exe");
	//���ļ�
	ShellExecuteA( NULL,"open",realpath,NULL,NULL,SW_SHOWNORMAL);
}





void CVideoEyeDlg::OnRawanalysisHistogram()
{
	rawanalysis->ShowWindow(SW_SHOW);
	rawanalysis->m_rawanalysismethod=0;
	rawanalysis->UpdateData(FALSE);
	rawanalysis->maindlg=this;
}


void CVideoEyeDlg::OnRawanalysisCanny()
{
	rawanalysis->ShowWindow(SW_SHOW);
	rawanalysis->m_rawanalysismethod=1;
	rawanalysis->UpdateData(FALSE);
	rawanalysis->maindlg=this;
}


void CVideoEyeDlg::OnRawanalysisContour()
{
	rawanalysis->ShowWindow(SW_SHOW);
	rawanalysis->m_rawanalysismethod=2;
	rawanalysis->UpdateData(FALSE);
	rawanalysis->maindlg=this;
}


void CVideoEyeDlg::OnRawanalysis2ddft()
{
	rawanalysis->ShowWindow(SW_SHOW);
	rawanalysis->m_rawanalysismethod=3;
	rawanalysis->UpdateData(FALSE);
	rawanalysis->maindlg=this;
}

void CVideoEyeDlg::OnRawanalysisFaceDetect()
{
	rawanalysis->ShowWindow(SW_SHOW);
	rawanalysis->m_rawanalysismethod=4;
	rawanalysis->UpdateData(FALSE);
	rawanalysis->maindlg=this;
}

void CVideoEyeDlg::OnRawanalysis()
{
	rawanalysis->ShowWindow(SW_SHOW);
	rawanalysis->maindlg=this;
}





void CVideoEyeDlg::OnSpecialFFlv()
{
	char realpath[400]={0};
	//���exe����·��
	GetModuleFileNameA(NULL,(LPSTR)realpath,400);//
	//���exe�ļҼ�·��
	strrchr(realpath, '\\')[0]= '\0';//���Ų��Ҷ�Ӧ���ַ�'\\'���滻��'\0'
	strcat(realpath,"\\SpecialFFLV.exe");
	//���ļ�
	ShellExecuteA( NULL,"open",realpath,NULL,NULL,SW_SHOWNORMAL);
}




void CVideoEyeDlg::OnSpecialAAac()
{
	char realpath[400]={0};
	//���exe����·��
	GetModuleFileNameA(NULL,(LPSTR)realpath,400);//
	//���exe�ļҼ�·��
	strrchr(realpath, '\\')[0]= '\0';//���Ų��Ҷ�Ӧ���ַ�'\\'���滻��'\0'
	strcat(realpath,"\\SpecialAAAC.exe");
	//���ļ�
	ShellExecuteA( NULL,"open",realpath,NULL,NULL,SW_SHOWNORMAL);
}


void CVideoEyeDlg::OnSpecialFTs()
{
	char realpath[400]={0};
	//���exe����·��
	GetModuleFileNameA(NULL,(LPSTR)realpath,400);//
	//���exe�ļҼ�·��
	strrchr(realpath, '\\')[0]= '\0';//���Ų��Ҷ�Ӧ���ַ�'\\'���滻��'\0'
	strcat(realpath,"\\SpecialFTS.exe");
	//���ļ�
	ShellExecuteA( NULL,"open",realpath,NULL,NULL,SW_SHOWNORMAL);
}


void CVideoEyeDlg::OnSpecialVH264()
{
	char realpath[400]={0};
	//���exe����·��
	GetModuleFileNameA(NULL,(LPSTR)realpath,400);//
	//���exe�ļҼ�·��
	strrchr(realpath, '\\')[0]= '\0';//���Ų��Ҷ�Ӧ���ַ�'\\'���滻��'\0'
	strcat(realpath,"\\SpecialVH264.exe");
	//���ļ�
	ShellExecuteA( NULL,"open",realpath,NULL,NULL,SW_SHOWNORMAL);
}


void CVideoEyeDlg::OnOptPlayer()
{
	optplayer->ShowWindow(SW_SHOW);
}

void CVideoEyeDlg::ResetBtn(){
	GetDlgItem(IDOK)->EnableWindow(TRUE);
	GetDlgItem(IDC_SEEK_B)->EnableWindow(FALSE);
	GetDlgItem(IDC_SEEK_F)->EnableWindow(FALSE);
	GetDlgItem(IDC_PAUSE)->EnableWindow(FALSE);
	GetDlgItem(IDC_STOP)->EnableWindow(FALSE);
	GetDlgItem(IDC_SEEK_STEP)->EnableWindow(FALSE);
	GetDlgItem(IDC_FULLSCREEN)->EnableWindow(FALSE);
	GetDlgItem(IDC_PLAY_PROGRESS)->EnableWindow(FALSE);

	//FIX
	GetDlgItem(IDC_RAWANALYSIS)->EnableWindow(FALSE);
	GetDlgItem(ID_DFANALYSIS)->EnableWindow(FALSE);
	GetDlgItem(IDC_VIDEODECODE)->EnableWindow(FALSE);
	GetDlgItem(IDC_AUDIODECODE)->EnableWindow(FALSE);
}

void CVideoEyeDlg::ActiveBtn(){
	GetDlgItem(IDOK)->EnableWindow(FALSE);
	GetDlgItem(IDC_SEEK_B)->EnableWindow(TRUE);
	GetDlgItem(IDC_SEEK_F)->EnableWindow(TRUE);
	GetDlgItem(IDC_PAUSE)->EnableWindow(TRUE);
	GetDlgItem(IDC_STOP)->EnableWindow(TRUE);
	GetDlgItem(IDC_SEEK_STEP)->EnableWindow(TRUE);
	GetDlgItem(IDC_FULLSCREEN)->EnableWindow(TRUE);
	GetDlgItem(IDC_PLAY_PROGRESS)->EnableWindow(TRUE);

	//FIX
	GetDlgItem(IDC_RAWANALYSIS)->EnableWindow(TRUE);
	GetDlgItem(ID_DFANALYSIS)->EnableWindow(TRUE);
	GetDlgItem(IDC_VIDEODECODE)->EnableWindow(TRUE);
	GetDlgItem(IDC_AUDIODECODE)->EnableWindow(TRUE);
}

void CVideoEyeDlg::InitBitmapButton(){

	//���ذ�ť------------
	//bitmapbutton.AutoLoad(IDOK,this);//
	okbutton.LoadBitmaps(IDB_MAIN_PLAY,IDB_MAIN_PLAY_H,IDB_MAIN_PLAY_H,IDB_MAIN_PLAY_D);
	okbutton.SubclassDlgItem(IDOK,this);
	okbutton.SizeToContent();
	seek_bbutton.LoadBitmaps(IDB_MAIN_SEEK_B,IDB_MAIN_SEEK_B_H,IDB_MAIN_SEEK_B_H,IDB_MAIN_SEEK_B_D);
	seek_bbutton.SubclassDlgItem(IDC_SEEK_B,this);
	seek_bbutton.SizeToContent();
	seek_fbutton.LoadBitmaps(IDB_MAIN_SEEK_F,IDB_MAIN_SEEK_F_H,IDB_MAIN_SEEK_F_H,IDB_MAIN_SEEK_F_D);
	seek_fbutton.SubclassDlgItem(IDC_SEEK_F,this);
	seek_fbutton.SizeToContent();
	pausebutton.LoadBitmaps(IDB_MAIN_PAUSE,IDB_MAIN_PAUSE_H,IDB_MAIN_PAUSE_H,IDB_MAIN_PAUSE_D);
	pausebutton.SubclassDlgItem(IDC_PAUSE,this);
	pausebutton.SizeToContent();
	stopbutton.LoadBitmaps(IDB_MAIN_STOP,IDB_MAIN_STOP_H,IDB_MAIN_STOP_H,IDB_MAIN_STOP_D);
	stopbutton.SubclassDlgItem(IDC_STOP,this);
	stopbutton.SizeToContent();
	seekstepbutton.LoadBitmaps(IDB_MAIN_SEEK_STEP,IDB_MAIN_SEEK_STEP_H,IDB_MAIN_SEEK_STEP_H,IDB_MAIN_SEEK_STEP_D);
	seekstepbutton.SubclassDlgItem(IDC_SEEK_STEP,this);
	seekstepbutton.SizeToContent();
	fullscreenbutton.LoadBitmaps(IDB_MAIN_FULLSCREEN,IDB_MAIN_FULLSCREEN_H,IDB_MAIN_FULLSCREEN_H,IDB_MAIN_FULLSCREEN_D);
	fullscreenbutton.SubclassDlgItem(IDC_FULLSCREEN,this);
	fullscreenbutton.SizeToContent();

	aboutbutton.LoadBitmaps(IDB_MAIN_ABOUT,IDB_MAIN_ABOUT_H,IDB_MAIN_ABOUT_H,IDB_MAIN_ABOUT_D);
	aboutbutton.SubclassDlgItem(IDC_ABOUT,this);
	aboutbutton.SizeToContent();

}
//��ʼ���Ӵ���
void CVideoEyeDlg::InitSubWindow(){
	//�Ӵ���-------------------------


	inputlist=new InputList;
	videodecode=new Videodecode;
	audiodecode=new Audiodecode;
	dataoutput=new Dataoutput;
	optplayer=new Optplayer;
	dfanalysis=new Dfanalysis;
	sysinfo=new Sysinfo;

	inputlist->Create(IDD_INPUTLIST,NULL);
	videodecode->Create(IDD_VIDEODECODE);
	audiodecode->Create(IDD_AUDIODECODE);
	dataoutput->Create(IDD_DATAOUTPUT);
	optplayer->Create(IDD_OPTPLAYER);
	dfanalysis->Create(IDD_DFANALYSIS);
	sysinfo->Create(IDD_SYSINFO);
	//inputlist����һ��ָ�������ڵ�ָ��------------------
	inputlist->maindlg=this;
	dfanalysis->maindlg=this;
	//RawAnalysis
	rawanalysis=new Rawanalysis;
	rawanalysis->Create(IDD_RAWANALYSIS);

}

//�ͷ��Ӵ���
void CVideoEyeDlg::FreeSubWindow(){
	
	inputlist->DestroyWindow();
	videodecode->DestroyWindow();
	audiodecode->DestroyWindow();
	dataoutput->DestroyWindow();
	optplayer->DestroyWindow();
	dfanalysis->DestroyWindow();
	rawanalysis->DestroyWindow();
	sysinfo->DestroyWindow();

	delete inputlist;
	delete videodecode;
	delete audiodecode;
	delete dataoutput;
	delete optplayer;
	delete dfanalysis;
	delete rawanalysis;
	delete sysinfo;
}


void CVideoEyeDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	//�������Ž�����
	if(nSBCode==SB_THUMBPOSITION){
		ve_seek_bar(nPos);
		//FIX:�϶�����������仯
	}
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}
//ToolTip
BOOL CVideoEyeDlg::PreTranslateMessage(MSG* pMsg){
	m_tooltip.RelayEvent(pMsg);
	return CDialogEx::PreTranslateMessage(pMsg);
}

void CVideoEyeDlg::InitTooltip(){
	EnableToolTips(TRUE);  
	m_tooltip.Create(this);  
	m_tooltip.Activate(TRUE);  

	CString resloader;

	CWnd* pW=GetDlgItem(IDOK);//�õ�����ָ��  
	resloader.LoadString(IDS_MAIN_TOOLTIP_OPEN);
	m_tooltip.AddTool(pW,resloader);//���

	pW=GetDlgItem(IDC_SEEK_B);
	resloader.LoadString(IDS_MAIN_TOOLTIP_SEEK_B);
	m_tooltip.AddTool(pW,resloader);
	pW=GetDlgItem(IDC_PAUSE);
	resloader.LoadString(IDS_MAIN_TOOLTIP_OPEN);
	m_tooltip.AddTool(pW,resloader);
	pW=GetDlgItem(IDC_SEEK_F);
	resloader.LoadString(IDS_MAIN_TOOLTIP_PAUSE);
	m_tooltip.AddTool(pW,resloader);
	pW=GetDlgItem(IDC_STOP);
	resloader.LoadString(IDS_MAIN_TOOLTIP_STOP);
	m_tooltip.AddTool(pW,resloader);
	pW=GetDlgItem(IDC_SEEK_STEP);
	resloader.LoadString(IDS_MAIN_TOOLTIP_STEP);
	m_tooltip.AddTool(pW,resloader);
	pW=GetDlgItem(IDC_FULLSCREEN);
	resloader.LoadString(IDS_MAIN_TOOLTIP_FULLSCREEN);
	m_tooltip.AddTool(pW,resloader);
	pW=GetDlgItem(IDC_ABOUT);
	resloader.LoadString(IDS_MAIN_TOOLTIP_ABOUT);
	m_tooltip.AddTool(pW,resloader);
}


void CVideoEyeDlg::OnDfanalysis()
{
	dfanalysis->ShowWindow(SW_SHOW);
	//��ͼ��
	dfanalysis->DrawSample();
}


void CVideoEyeDlg::OnRawanalysisY()
{

	rawanalysis->ShowWindow(SW_SHOW);
	rawanalysis->m_rawanalysismethod=8;
	rawanalysis->UpdateData(FALSE);
	rawanalysis->maindlg=this;
}


void CVideoEyeDlg::OnRawanalysisU()
{
	rawanalysis->ShowWindow(SW_SHOW);
	rawanalysis->m_rawanalysismethod=9;
	rawanalysis->UpdateData(FALSE);
	rawanalysis->maindlg=this;
}


void CVideoEyeDlg::OnRawanalysisV()
{
	rawanalysis->ShowWindow(SW_SHOW);
	rawanalysis->m_rawanalysismethod=10;
	rawanalysis->UpdateData(FALSE);
	rawanalysis->maindlg=this;
}


void CVideoEyeDlg::OnRawanalysisR()
{
	rawanalysis->ShowWindow(SW_SHOW);
	rawanalysis->m_rawanalysismethod=5;
	rawanalysis->UpdateData(FALSE);
	rawanalysis->maindlg=this;
}


void CVideoEyeDlg::OnRawanalysisG()
{
	rawanalysis->ShowWindow(SW_SHOW);
	rawanalysis->m_rawanalysismethod=6;
	rawanalysis->UpdateData(FALSE);
	rawanalysis->maindlg=this;
}


void CVideoEyeDlg::OnRawanalysisB()
{
	rawanalysis->ShowWindow(SW_SHOW);
	rawanalysis->m_rawanalysismethod=7;
	rawanalysis->UpdateData(FALSE);
	rawanalysis->maindlg=this;
}


void CVideoEyeDlg::OnTopmostAlways()
{
	//������ǰ��
	//::SetWindowPos(this->m_hWnd,HWND_TOPMOST,10,10,10,10,SWP_NOMOVE|SWP_NOSIZE);
	SetWindowPos(&wndTopMost, 0, 0, 0, 0,SWP_NOSIZE | SWP_NOMOVE);
}


void CVideoEyeDlg::OnTopmostNever()
{
	//ȡ��������ǰ��
	::SetWindowPos(this->m_hWnd,HWND_NOTOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
}




void CVideoEyeDlg::OnLangCn()
{
	//�����ļ�·��
	char conf_path[300]={0};
	//���exe����·��
	GetModuleFileNameA(NULL,(LPSTR)conf_path,300);//
	//���exe�ļҼ�·��
	strrchr( conf_path, '\\')[0]= '\0';//
	//_getcwd(realpath,MYSQL_S_LENGTH);
	printf("%s",conf_path);
	strcat(conf_path,"\\configure.ini");
	//д�������ļ�
	WritePrivateProfileStringA("Settings","language","Chinese",conf_path);

	//�������
	char exe_path[300]={0};
	//���exe����·��
	GetModuleFileNameA(NULL,(LPSTR)exe_path,300);
	ShellExecuteA( NULL,"open",exe_path,NULL,NULL,SW_SHOWNORMAL);

	//�ȵ�һ����ͣ
	OnClickedStop();
	//�ͷ��Ӵ���
	FreeSubWindow();
	CDialogEx::OnCancel();
}


void CVideoEyeDlg::OnLangEn()
{
	//�����ļ�·��
	char conf_path[300]={0};
	//���exe����·��
	GetModuleFileNameA(NULL,(LPSTR)conf_path,300);//
	//���exe�ļҼ�·��
	strrchr( conf_path, '\\')[0]= '\0';//
	//_getcwd(realpath,MYSQL_S_LENGTH);
	printf("%s",conf_path);
	strcat(conf_path,"\\configure.ini");
	//д�������ļ�
	WritePrivateProfileStringA("Settings","language","English",conf_path);

	//�������
	char exe_path[300]={0};
	//���exe����·��
	GetModuleFileNameA(NULL,(LPSTR)exe_path,300);
	ShellExecuteA( NULL,"open",exe_path,NULL,NULL,SW_SHOWNORMAL);

	//�ȵ�һ����ͣ
	OnClickedStop();
	//�ͷ��Ӵ���
	FreeSubWindow();
	CDialogEx::OnCancel();
}



void CVideoEyeDlg::OnCancel()
{
	CString resloader;
	resloader.LoadString(IDS_MSGBOX_EXIT);
	if(IDOK==AfxMessageBox(resloader,MB_OKCANCEL|MB_ICONINFORMATION)){
		//�ȵ�һ����ͣ
		OnClickedStop();
		//�ͷ��Ӵ���
		FreeSubWindow();
		CDialogEx::OnCancel();
	}
}


void CVideoEyeDlg::OnSysinfo()
{
	sysinfo->ShowWindow(TRUE);
}


HBRUSH CVideoEyeDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	//�ͻ���
	//CRect rect;
	//CBrush pBrush;
	//pWnd->GetClientRect(&rect); 
	//pBrush.CreateSolidBrush(RGB(255,255,255));
	//pDC->FillRect(rect,&pBrush);
	//pBrush.DeleteObject();
	//pDC->SetBkMode(TRANSPARENT);
	//pDC->SetBkColor(RGB(200, 200, 200));
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}


void CVideoEyeDlg::OnWindowstretchKeepratio()
{
	ve_stretch(0);
}


void CVideoEyeDlg::OnWindowstretchResize()
{
	ve_stretch(1);
}
