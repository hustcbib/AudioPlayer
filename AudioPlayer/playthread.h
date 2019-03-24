#ifndef PLAYTHREAD_H
#define PLAYTHREAD_H

#include "qthread.h"
#include "Windows.h"
#include "MMSystem.h"
#include "qdatetime.h"
#include "qcoreapplication.h"
#include "qlist.h"
#include "qmessagebox.h"
#include "qdatetime.h"

#pragma comment(lib,"WinMM.lib") //导入声音头文件库 

class PlayThread : public QThread
{
	Q_OBJECT

public:
	PlayThread(QObject *parent);
	~PlayThread();
	void do_play_note(QString);
	int flip;
	int volume;
	int baseflip;
	double playspeed;
	HMIDIOUT outhandle;
	QString text;
	QList <int> *sTime;
	void sleep(unsigned int msec);
protected:
	void run();
signals:
	void settextedit(QString);
	void playover(int);
	void sendbeatstartnumber(int);
	void sendrhythmstartnumber(int);
private slots:
	void do_run();
	void gettext(QString);
	void getinformations(int,int,int);
	void stop();
	void gethandle(HMIDIOUT);
	void gettimelist(QList <int> *);
	void circulationplay();
	void beatplay(int,int);
	void rhythmplay(int,int);
	void get_speed(double);
private:
	bool stopped;
};

#endif // PLAYTHREAD_H
