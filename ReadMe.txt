VideoEye

 
VideoEye是一个开源的视频分析的软件。本软件可以播放和分析视频数据。它支持多种视频流输入方式：HTTP，RTMP，RTSP以及文件等等。该软件可以实时分析视频流并能以图形化的方式呈现其分析结果。目前该软件还处于完善阶段。

VideoEye is an open-source stream analysis software. It can play and make analysis of video bit stream. It supports multiple kind of sources, include: HTTP, RTMP, RTSP and files, etc. The software can make real time stream analysis and show the result graphically. Currently the software is under development yet.


/************************************************************************************
 * Question:
 ************************************************************************************/
视频/音频实时分析是不是太占内存了？能否改成可开关的？添加颜色的时候，第一列常常由于插入太快而现实背景为白色
视频/音频实时分析得条数可配置，而不是Define成固定的。
软件快速操作的时候，会出现死机的情况，看看是什么原因？
码流分析的帧和视频播放的帧不一致，如何解决？

原始码流分析中，参数的配置方式是否要使用RadioButton？还是给换成PropertyGrid更好？
单帧解码分析中，是否要一个面板上像是各种统计信息？还是给换成多个面板？

考虑新功能增加：
IO的统计（原程序中的）
图表？

遥远的添加：视频质量评价功能
