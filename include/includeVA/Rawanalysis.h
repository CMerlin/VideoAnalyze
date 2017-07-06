/* 
 *
 * 
 * VideoEye
 *
 */



#pragma once


#include "stdafx.h"
#include "resource.h"
//OpenCV
#include <opencv/cxcore.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>
// Rawanalysis �Ի���

//-----------
#define MR(Y,U,V) (Y + (1.403)*(V-128))  
#define MG(Y,U,V) (Y - (0.344) * (U-128) - (0.714) * (V-128) )   
#define MB(Y,U,V) (Y + ((1.773) * (U-128))) 

//���Ի���------
class CVideoEyeDlg;
//-----------
class Rawanalysis : public CDialogEx
{
	DECLARE_DYNAMIC(Rawanalysis)

public:
	Rawanalysis(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Rawanalysis();
	//�Լ���ӵģ���ʼ��
	virtual BOOL OnInitDialog();
// �Ի�������
	enum { IDD = IDD_RAWANALYSIS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRawanalysisOpen();
	//------------------
	CVideoEyeDlg *maindlg;
	//֡��
	int frame_index;
	//YUVתIplImage�����ַ���-----------
	//��ŷ�ѹ����
	char *y_data;
	char *u_data;
	char *v_data;
	int y_width;
	int y_height;
	//���ת�����ͼ��
	IplImage *result_image;
	IplImage *yuvimage;
	//-----------------
	//�����ٽ��
	CCriticalSection critical_section;
	int YUVtoIpl1();
	void YUV420_C_RGB( char* pY,char* pU,char* pV, unsigned char* pRGB, int height, int width);
	int YUVtoIpl2();
	//----------------
	int LoadFromMemory();
	int LoadFromURL();
	//�㷨����------------------------------------
	//��ɫ�ֲ�ֱ��ͼ
	int Color_Histogram();
	//��Ե���
	int Canny();
	//�������
	int Contour();
	//��ά����Ҷ�任
	void cvShiftDFT(CvArr * src_arr, CvArr * dst_arr );
	int DFT();
	//����ʶ��
	CvMemStorage* storage;
	CvHaarClassifierCascade* cascade;
	void detect_and_draw( IplImage* img );
	int face_detect();


	int m_rawanalysismethod;
	void SystemClear();
	afx_msg void OnBnClickedCancel();
	//-------------------------
	enum {SHOW_R_COMP,SHOW_G_COMP,SHOW_B_COMP,SHOW_Y_COMP,SHOW_U_COMP,SHOW_V_COMP};
	//��ʾ��ɫ����
	int show_color_component(int nameid);
	int m_rawanalysisautointerframenum;
	CButton m_rawanalysisauto;
	afx_msg void OnBnClickedRawanalysisAuto();
	afx_msg void OnKillfocusRawanalysisAutoInterframenum();
	CButton m_rawanalysisoutpicfolder;
	CMFCEditBrowseCtrl m_rawanalysisoutpicfolderurl;
	afx_msg void OnClickedRawanalysisOutpicfolder();
	int m_rawanalysiscolorhbin;
	int m_rawanalysiscolorsbin;
	int m_rawanalysiscontourthres;
	int m_rawanalysiscannythres1;
	int m_rawanalysiscannythres2;
	CString m_rawanalysisfacexmlurl;
};
