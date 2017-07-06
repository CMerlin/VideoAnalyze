#/***************************************************************************
#* Makefile
#****************************************************************************/

FFMPEG=/usr/local/ffmpeg
#FFMPEG=/usr/local/libFFmpeg
CC=gcc
CFLAGS=-g -I$(FFMPEG)/include
LDFLAGS = -L$(FFMPEG)/lib/ -lswscale -lswresample -lavformat -lavdevice -lavcodec -lavutil -lavfilter -lpostproc -lm
TARGETS=VideoAnalyze.bin
all: $(TARGETS)
VideoAnalyze.bin:./src/simplest_ffmpeg_remuxer.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
clean:
	rm -rf $(TARGETS)

