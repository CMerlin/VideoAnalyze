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


#include "VideoEye.h"
#include "VideoEyeDlg.h"
#include "afxdialogex.h"
//--------------
#include "config.h"
#include <inttypes.h>
#include <math.h>
#include <limits.h>
#include <signal.h>
#include "libavutil/avstring.h"
#include "libavutil/colorspace.h"
#include "libavutil/mathematics.h"
#include "libavutil/pixdesc.h"
#include "libavutil/imgutils.h"
#include "libavutil/dict.h"
#include "libavutil/parseutils.h"
#include "libavutil/samplefmt.h"
#include "libavutil/avassert.h"
#include "libavutil/time.h"
#include "libavformat/avformat.h"
#include "libavdevice/avdevice.h"
#include "libswscale/swscale.h"
#include "libavutil/opt.h"
#include "libavcodec/avfft.h"
#include "libswresample/swresample.h"

#if CONFIG_AVFILTER
# include "libavfilter/avcodec.h"
# include "libavfilter/avfilter.h"
# include "libavfilter/avfiltergraph.h"
# include "libavfilter/buffersink.h"
# include "libavfilter/buffersrc.h"
#endif


#include "SDL/SDL.h"
#include "SDL/SDL_thread.h"

#include "cmdutils.h"

#include <assert.h>

void ve_play_pause();
void ve_seek_step();
void ve_play_fullcreen();
void ve_seek(int time);
void ve_aspectratio(int num,int den);
void ve_size(int percentage);
void ve_audio_display(int mode);
//ͨ��SDL��Push Eventʵ�ֵ��˳���������ֱ�ӵ��õ��˳�������
//�������˳����źţ�����EventLoop��ִ��
void ve_quit();
//��Ҫ���õĽ��뺯��
int ve_play(LPVOID lpParam);
//--------
int ve_reset_index();
//���Ž���
void ve_seek_bar(int pos);

void ve_stretch(int stretch);