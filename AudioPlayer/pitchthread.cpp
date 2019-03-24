#include "pitchthread.h"

PitchThread::PitchThread(QObject *parent)
	: QThread(parent)
{
	stopped = false;

}
void PitchThread::gethandle(HMIDIOUT handle)
{
	this->outhandle = handle;
}
void PitchThread::gettext(QString text1)
{
	this->text = text1;
}
void PitchThread::do_run()
{
	this->run();
}
void PitchThread::getinformations(int flip1,int volume1,int baseflip1)
{
	this->flip = flip1;
	this->volume = volume1;
	this->baseflip = baseflip1;
}
void PitchThread::stop()
{
	stopped = true;

}
void PitchThread::run()
{
	stopped = false;
	int number = text.length();
	int playnumber = number/4;
	
	while(playnumber>0 && stopped == false)
	{
		QString text1 = text.mid(number-playnumber*4,4);
		playnumber--;
		do_play_note(text1);
		sleep(300);
	}
}
void PitchThread::sleep(unsigned int msec)
{
	QTime reachTime = QTime::currentTime().addMSecs(msec);
	while(QTime::currentTime() < reachTime)
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
void PitchThread::do_play_note(QString text)
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
PitchThread::~PitchThread()
{

}
