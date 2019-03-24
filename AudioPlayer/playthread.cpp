#include "PlayThread.h"

PlayThread::PlayThread(QObject *parent)
	: QThread(parent)
{
	stopped = false;
	playspeed = 1.0;
}
void PlayThread::gethandle(HMIDIOUT handle)
{
	this->outhandle = handle;
}
void PlayThread::gettext(QString text1)
{
	this->text = text1;
}
void PlayThread::gettimelist(QList<int> *sTime)
{
	this->sTime = sTime;
}
void PlayThread::do_run()
{
	run();
}
void PlayThread::get_speed(double spd)
{
	playspeed = spd;
}
void PlayThread::run()
{
	stopped = false;
	int control = 0;
	int doplaynumber = text.length()/4;
	int num = text.length();
	sleep(20*sTime->at(control++)/playspeed);
	QString text1 = text.mid(num-4*doplaynumber,4);
	QString text2 = text.mid(0,num-4*doplaynumber);
	QString text3 = text.right(4*doplaynumber-4);
	emit settextedit(text2+"<span style='color:#0000CC;'>"+text1+"</span>"+text3);
	do_play_note(text1);
	doplaynumber--;
	while(doplaynumber > 0 && stopped == false)
	{	
		text1 = text.mid(num-4*doplaynumber,4);
		text2 = text.mid(0,num-4*doplaynumber);
		text3 = text.right(4*doplaynumber-4);
		sleep(20*sTime->at(control++)/playspeed);
		do_play_note(text1);
		emit settextedit(text2+"<span style='color:#0000CC;'>"+text1+"</span>"+text3);
		doplaynumber--;
	}
	emit playover(doplaynumber);
}
void PlayThread::circulationplay()
{
	stopped = false;
	int control = 0;
	int doplaynumber = text.length()/4;
	int num = text.length();
	QString text1 = text.mid(num-4*doplaynumber,4);
	QString text2 = text.mid(0,num-4*doplaynumber);
	QString text3 = text.right(4*doplaynumber-4);
	emit settextedit(text2+"<span style='color:#0000CC;'>"+text1+"</span>"+text3);
	do_play_note(text1);
	sleep(20*sTime->at(control++)/playspeed);
	doplaynumber--;
	while(stopped == false)
	{	
		text1 = text.mid(num-4*doplaynumber,4);
		text2 = text.mid(0,num-4*doplaynumber);
		text3 = text.right(4*doplaynumber-4);
		sleep(20*sTime->at(control++)/playspeed);
		do_play_note(text1);
		emit settextedit(text2+"<span style='color:#0000CC;'>"+text1+"</span>"+text3);
		doplaynumber--;
		if(doplaynumber == 0)
		{
			doplaynumber = text.length()/4;
			control = 0;
		}

	}
	emit playover(doplaynumber);
}
void PlayThread::beatplay(int start,int end)
{
	stopped = false;
	int control = start;
	int num = text.length();
	QString text1 = text.mid(4*control,4);
	QString text2 = text.left(4*control);
	QString text3 = text.right(num-4*control-4);
	if(!text1.isEmpty())
	{
		emit settextedit(text2+"<span style='color:#0000CC;'>"+text1+"</span>"+text3);
		do_play_note(text1);
		sleep(20*3/playspeed);
		control++;
	}
	while(stopped == false && control < end && control < num/4)
	{	
		text1 = text.mid(4*control,4);
		text2 = text.mid(0,4*control);
		text3 = text.right(num-4*control-4);
		if(!text1.isEmpty())
		{
			emit settextedit(text2+"<span style='color:#0000CC;'>"+text1+"</span>"+text3);
			do_play_note(text1);
			sleep(20*sTime->at(control++)/playspeed);
		}
	}
	emit sendbeatstartnumber(control);
	if(control == num/4)
		emit playover(0);
}
void PlayThread::rhythmplay(int start,int end)
{
	stopped = false;
	int control = start;
	int num = text.length();
	QString text1 = text.mid(4*control,4);
	QString text2 = text.left(4*control);
	QString text3 = text.right(num-4*control-4);
	if(!text1.isEmpty())
	{
		emit settextedit(text2+"<span style='color:#0000CC;'>"+text1+"</span>"+text3);
		do_play_note(text1);
		sleep(20*3/playspeed);
		control++;
	}
	while(stopped == false && control < end && control < num/4)
	{	
		text1 = text.mid(4*control,4);
		text2 = text.mid(0,4*control);
		text3 = text.right(num-4*control-4);
		if(!text1.isEmpty())
		{
			emit settextedit(text2+"<span style='color:#0000CC;'>"+text1+"</span>"+text3);
			do_play_note(text1);
			sleep(20*sTime->at(control++)/playspeed);
		}
	}
	emit sendrhythmstartnumber(control);
	if(control == num/4)
		emit playover(0);
}
void PlayThread::getinformations(int flip,int volume,int baseflip)
{
	this->baseflip = baseflip;
	this->flip = flip;
	this->volume = volume;
}
void PlayThread::stop()
{
	stopped = true;
}
void PlayThread::sleep(unsigned int msec)
{
	QTime reachTime = QTime::currentTime().addMSecs(msec);
	while(QTime::currentTime() < reachTime)
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
void PlayThread::do_play_note(QString text)
{
	if(text==QString("C_1 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("C#1 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 1;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("D_1 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 2;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("D#1 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 3;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("E_1 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip =baseflip + 4;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("F_1 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 5;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("F#1 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 6;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("G_1 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 7;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("G#1 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 8;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("A_1 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 9;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("A#1 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 10;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("B_1 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 11;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("C_2 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 12;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("C#2"))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 13;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("D_2 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 14;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}

	else if(text==QString("D#2 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 15;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("E_2 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 16;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("F_2 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 17;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("F#2 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 18;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("G_2 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 19;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("G#2 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 20;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("A_2 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 21;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("A#2 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 22;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("B_2 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 23;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("C_3 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 24;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("C#3 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 25;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("D_3 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 26;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("D#3 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 27;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("E_3 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 28;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("F_3 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 29;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("F#3 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 30;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("G_3 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 31;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("G#3 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 32;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("A_3 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 33;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("A#3 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 34;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("B_3 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 35;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("C_4 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 36;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("C#4 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 37;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("D_4 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 38;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("D#4 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 39;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("E_4 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 40;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("F_4 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 41;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("F#4 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 42;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("G_4 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 43;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("G#4 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 44;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("A_4 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 45;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("A#4 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 46;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("B_4 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 47;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("C_5 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 48;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("C#5 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 49;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("D_5 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 50;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("D#5 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 51;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("E_5 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 52;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("F_5 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 53;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("F#5 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 54;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("G_5 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 55;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("G#5 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 56;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("A_5 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 57;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("A#5 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 58;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("B_5 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 59;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
	else if(text==QString("C_6 "))
	{
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
		flip = baseflip + 60;
		midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	}
}
PlayThread::~PlayThread()
{

}
