#ifndef PITCHTHREAD_H
#define PITCHTHREAD_H

#include "qthread.h"
#include "Windows.h"
#include "MMSystem.h"
#include "qdatetime.h"
#include "qcoreapplication.h"

#pragma comment(lib,"WinMM.lib") //��������ͷ�ļ��� 

class PitchThread : public QThread
{
	Q_OBJECT

public:
	PitchThread(QObject *parent);
	~PitchThread();
	void do_play_note(QString text);
	HMIDIOUT outhandle;					//���MIDI�豸���
	int flip;							//����
	int volume;							//����
	int baseflip;						//����
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
