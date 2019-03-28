#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include "qmainwindow.h"
#include "ui_audioplayer.h"
#include "Windows.h"
#include "MMSystem.h"
#include "qslider.h"
#include "qfiledialog.h"
#include "qfile.h"
#include "qcoreapplication.h"
#include "qbytearray.h"
#include "qmessagebox.h"
#include "qstring.h"
#include "qtextstream.h"
#include "qevent.h"
#include "qwidget.h"
#include "qtextcursor.h"
#include "qtextformat.h"
#include "qpalette.h"
#include "qtimer.h"
#include "qlist.h"
#include "qdatetime.h"
#include "pitchthread.h"
#include "playthread.h"
//#include <Phonon/AudioDataOutput>
//#include <Phonon/SeekSlider>

#pragma comment(lib,"WinMM.lib") //��������ͷ�ļ��� 

void CALLBACK MidiInProc(					//�����豸��Ϣ�ص�����
	HMIDIIN   hMidiIn,						//�����豸���
	UINT      wMsg,							//������Ϣ����
	DWORD_PTR dwInstance,					//����ʵ��
	DWORD_PTR dwParam1,						//����1
	DWORD_PTR dwParam2						//����2
	);
class AudioPlayer : public QMainWindow
{
	Q_OBJECT

public:
	AudioPlayer(QWidget *parent = 0, Qt::WindowFlags flags = 0);
	~AudioPlayer();
	void doConnect();	//��������
	void sleep(unsigned int msec);
	QTimer timer;
	QList <int> sTime;
	QList <int> Paragraph;
	QList <int> Beats;
	PitchThread *pitchthread;
	PlayThread *playthread;
	void do_play_note(QString text);
	friend void CALLBACK MidiInProc(			//�����豸��Ϣ�ص�����
		HMIDIIN   hMidiIn,						//�����豸���
		UINT      wMsg,							//������Ϣ����
		DWORD_PTR dwInstance,					//����ʵ��
		DWORD_PTR dwParam1,						//����1
		DWORD_PTR dwParam2						//����2
		);
protected:
	 bool eventFilter(QObject *obj, QEvent *event);
signals:
	 //ɾ�������߳�
	 void sendtopitchthread(int, int, int );
	 void do_run_pitchup();
	 void sendtext(QString);
	 void sendhandle(HMIDIOUT);
	 void stoppitchthread();

	 //���������߳�
	 void sendtoplaythread(int, int, int );
	 void do_run_play();
	 void sendplaytext(QString);
	 void sendplayhandle(HMIDIOUT);
	 void stopplaythread();
	 void sendtimelist(QList <int> *);

	 void sendflip(int);
	 void sendspace();
	 void composeover();
	 void circulation_play();
	 void beats_play(int,int);
	 void rhythm_play(int,int);

	 void find_paragraph();
	 void find_beats();
	 void send_speed(double);			
private slots:
	void do_combox_change();			//���ѡ���ı�ʱ����
	void do_volume_change(int);			//�����ı����
	void do_speed_change(int);			//�����ٶȸı�
	void do_clear_textedit();			//��հ�ť����
	void update_time();					//����ʱ��
	void do_play_text();				//��д����
	void do_play();						//��������
	void do_circulation_play();			//ѭ������
	void do_beats_play();				//���ڲ���
	void do_rhythm_play();				//���Ĳ���
	void do_modi_rhythm();				//��������
	void get_beats_startnumber(int);	//��ȡ�ڿ�ʼ����
	void get_rhythm_startnumber(int);	//��ȡ�Ŀ�ʼ����
	void do_save_text();				//��������
	void modi_beats();					//��������
	void do_find_paragraph();			//Ѱ�Ҷ�
	void do_find_beats();				//Ѱ����
	void do_speed_change(double);		//�ٶȱ仯
	void do_load_swing();				//���ؽ���
	void do_save_swing();				//�������

	void do_set_textedit(QString);		//���Ź���������textedit�ؼ�
	void do_play_over(int);				//���������Ӧ
	void do_load_text();				//��������

	void do_rising();					//��Ӧ������ť
	void do_falling();					//��Ӧ������ť
	void do_move_left();				//��Ӧ���ư�ť
	void do_move_right();				//��Ӧ���ư�ť

	void do_space();					//��Ӧ�ո�ť
	void do_ctrl();						//��ӦCtrl��ť
	void do_backspace();				//��Ӧ�˸�ť

	void do_connect_MIDIIN();			//����MIDI�����豸
	void getflipText(int);				
	void getspace();
	void getcomposeover();

	void button1_pressed();				//��ť1����
	void button2_pressed();				//.....
	void button3_pressed();
	void button4_pressed();
	void button5_pressed();
	void button6_pressed();
	void button7_pressed();
	void button8_pressed();
	void button9_pressed();
	void button10_pressed();
	void button11_pressed();
	void button12_pressed();

	void button13_pressed();
	void button14_pressed();
	void button15_pressed();
	void button16_pressed();
	void button17_pressed();
	void button18_pressed();
	void button19_pressed();
	void button20_pressed();
	void button21_pressed();
	void button22_pressed();
	void button23_pressed();
	void button24_pressed();

	void button25_pressed();
	void button26_pressed();
	void button27_pressed();
	void button28_pressed();
	void button29_pressed();
	void button30_pressed();
	void button31_pressed();
	void button32_pressed();
	void button33_pressed();
	void button34_pressed();
	void button35_pressed();
	void button36_pressed();

	void button37_pressed();
	void button38_pressed();
	void button39_pressed();
	void button40_pressed();
	void button41_pressed();
	void button42_pressed();
	void button43_pressed();
	void button44_pressed();
	void button45_pressed();
	void button46_pressed();
	void button47_pressed();
	void button48_pressed();
	void button49_pressed();
private:
	Ui::AudioPlayerClass ui;
};

#endif // AUDIOPLAYER_H
