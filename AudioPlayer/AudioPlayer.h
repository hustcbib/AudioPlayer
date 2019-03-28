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

#pragma comment(lib,"WinMM.lib") //导入声音头文件库 

void CALLBACK MidiInProc(					//输入设备消息回调函数
	HMIDIIN   hMidiIn,						//输入设备句柄
	UINT      wMsg,							//输入消息类型
	DWORD_PTR dwInstance,					//输入实例
	DWORD_PTR dwParam1,						//参数1
	DWORD_PTR dwParam2						//参数2
	);
class AudioPlayer : public QMainWindow
{
	Q_OBJECT

public:
	AudioPlayer(QWidget *parent = 0, Qt::WindowFlags flags = 0);
	~AudioPlayer();
	void doConnect();	//创建连接
	void sleep(unsigned int msec);
	QTimer timer;
	QList <int> sTime;
	QList <int> Paragraph;
	QList <int> Beats;
	PitchThread *pitchthread;
	PlayThread *playthread;
	void do_play_note(QString text);
	friend void CALLBACK MidiInProc(			//输入设备消息回调函数
		HMIDIIN   hMidiIn,						//输入设备句柄
		UINT      wMsg,							//输入消息类型
		DWORD_PTR dwInstance,					//输入实例
		DWORD_PTR dwParam1,						//参数1
		DWORD_PTR dwParam2						//参数2
		);
protected:
	 bool eventFilter(QObject *obj, QEvent *event);
signals:
	 //删除控制线程
	 void sendtopitchthread(int, int, int );
	 void do_run_pitchup();
	 void sendtext(QString);
	 void sendhandle(HMIDIOUT);
	 void stoppitchthread();

	 //播放音乐线程
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
	void do_combox_change();			//组合选择框改变时操作
	void do_volume_change(int);			//音量改变操作
	void do_speed_change(int);			//播放速度改变
	void do_clear_textedit();			//清空按钮操作
	void update_time();					//更新时间
	void do_play_text();				//谱写乐谱
	void do_play();						//播放音乐
	void do_circulation_play();			//循环播放
	void do_beats_play();				//按节播放
	void do_rhythm_play();				//按拍播放
	void do_modi_rhythm();				//节拍修正
	void get_beats_startnumber(int);	//获取节开始数字
	void get_rhythm_startnumber(int);	//获取拍开始数字
	void do_save_text();				//保存乐谱
	void modi_beats();					//节拍修正
	void do_find_paragraph();			//寻找段
	void do_find_beats();				//寻找拍
	void do_speed_change(double);		//速度变化
	void do_load_swing();				//加载节奏
	void do_save_swing();				//保存节奏

	void do_set_textedit(QString);		//播放过程中设置textedit控件
	void do_play_over(int);				//播放完毕响应
	void do_load_text();				//加载乐谱

	void do_rising();					//响应升调按钮
	void do_falling();					//响应降调按钮
	void do_move_left();				//响应左移按钮
	void do_move_right();				//响应右移按钮

	void do_space();					//响应空格按钮
	void do_ctrl();						//响应Ctrl按钮
	void do_backspace();				//响应退格按钮

	void do_connect_MIDIIN();			//连接MIDI输入设备
	void getflipText(int);				
	void getspace();
	void getcomposeover();

	void button1_pressed();				//按钮1按下
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
