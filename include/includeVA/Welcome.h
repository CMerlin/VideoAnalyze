/* 
 *
 * 
 * VideoEye
 *
 */


#pragma once


// Welcome

class Welcome : public CWnd
{
	DECLARE_DYNAMIC(Welcome)

public:
	Welcome();
	virtual ~Welcome();

protected:
	DECLARE_MESSAGE_MAP()
public:   
	CBitmap m_bitmap;   
	//  void Create(void);   
	void Create(UINT nBitmapID);   
	afx_msg void OnPaint();   
	afx_msg void OnTimer(UINT_PTR nIDEvent);   

};


