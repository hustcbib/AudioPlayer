#ifndef PITCHTHREAD_H
#define PITCHTHREAD_H

#include "qthread.h"
#include "Windows.h"
#include "MMSystem.h"
#include "qdatetime.h"
#include "qcoreapplication.h"

#pragma comment(lib,"WinMM.lib") //导入声音头文件库 

class PitchThread : public QThread
{
	Q_OBJECT

public:
	PitchThread(QObject *parent);
	~PitchThread();
	void do_play_note(QString text);
	HMIDIOUT outhandle;					//输出MIDI设备句柄
	int flip;							//音调
	int volume;							//音量
	int baseflip;						//基调
	QString text;
	void sleep(unsigned int msec);
protected:
	void run();
private slots:
	void gettext(QString );
	void getinformations(int ,int , int);
	void stop();
	void do_run();
	void gethandle(HMIDIOUT);
private:
	bool stopped;
};

#endif // PITCHTHREAD_H
