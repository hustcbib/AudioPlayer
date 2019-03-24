#include "AudioPlayer.h"
#include "Imm.h"
#pragma comment(lib, "Imm32.lib")   //vc, in *.cpp

HIMC hIMC;
HWND hWnd;  

bool playsign = false;						//谱曲标志
int playnumber = 0;							//谱曲的音符数
bool doplaysign = false;					//播放标志
int doplaynumber = 0;						//播放的音符数
int nowtime = 0;							//时间
int lasttime = 0;							//上次的时间
int beats = 0;								//节拍
int speed = 0;								//播放速度
int beattime = 0;							//节拍长度
int maxtime = 0;							//最大时间间隔
double playspeed;							//播放速度
bool beatplaysign = false;					//按节播放标志
bool beatplayin = false;					//按节播放中	
int beatstartnumber = 0;					//按节播放的开始
int beatendnumber = 0;						//按节播放的结束
bool rhythmplaysign = false;				//按拍播放
bool rhythmplayin = false;					//按拍播放中
int rhythmstartnumber = 0;					//按拍播放的开始
int rhythmendnumber = 0;					//按拍播放的结束
int maxparagraph = 0;						//最大的段
int paragraphcount = 0;						//段落计数
int rhythmcount = 0;						//拍计数
bool modirhythm = false;
QString playText;							//谱曲内容
QString doplayText;							//播放内容
bool pitchup = false;						//选中标志
bool deleteit = false;						//删除标志
HMIDIOUT outhandle;							//输出MIDI设备句柄
HMIDIIN  inhandle;							//输入MIDI设备句柄
int flip;									//音调
int volume;									//音量
int flip1;									//音调1
int baseflip = 36;							//基调
bool flag = true;							//标志位
DWORD_PTR param;							//参数
AudioPlayer *wptr = NULL;					//指向当前窗口的指针


AudioPlayer::AudioPlayer(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	wptr = this;							//获取当前类的指针
	ui.horizontalSlider->setRange(0,127);	//设置音量的调节范围
	ui.horizontalSlider->setValue(60);		//设置音量的初值
	ui.textEdit->setReadOnly(true);			//设置textEdit为只读
	volume = 60;

	ui.label_5->setText(QString::number(60));	//设置label5的初值
	ui.horizontalSlider_2->setRange(1,150);
	ui.horizontalSlider_2->setValue(88);
	ui.label_6->setText(QString::number(88));
	speed = 88;
	beattime = (int)(60000/speed);

	ui.doubleSpinBox->setRange(0.00,10.00);
	ui.doubleSpinBox->setSingleStep(0.10);
	ui.doubleSpinBox->setValue(1.00);

	midiOutOpen(&outhandle,MIDI_MAPPER,0,0,CALLBACK_NULL);	//打开声卡的MIDI输出设备
	midiOutShortMsg(outhandle,0*0x100+0xC0);				//发送默认的乐器
	ui.textEdit->setTextInteractionFlags(
		Qt::TextSelectableByMouse   |
		Qt::TextSelectableByKeyboard|
		Qt::LinksAccessibleByMouse  |
		Qt::LinksAccessibleByKeyboard
		);													//设置textEdit的光标为可见
	this->setAttribute(Qt::WA_InputMethodEnabled,false);
	hWnd=(HWND)this->winId();			
	hIMC = ImmAssociateContext(hWnd, NULL);					//禁用
	BlockInput(FALSE);										//屏蔽输入法
	pitchthread = new PitchThread(this);					//创建选中时的播放线程
	playthread = new PlayThread(this);						//创建播放线程
	doConnect();											//连接信号和槽
	emit sendhandle(outhandle);								//发送MIDI输出设备句柄给选中线程
	emit sendplayhandle(outhandle);							//发送MIDI输出设备句柄给播放线程
	ui.textEdit->setFocus();								//设置textEdit为选中
	this->setFixedSize(this->width(),this->height());		//设置窗口大小固定
}
void AudioPlayer::doConnect()
{
	connect(this,SIGNAL(sendtopitchthread(int,int,int)),pitchthread,SLOT(getinformations(int,int,int)));
	connect(this,SIGNAL(do_run_pitchup()),pitchthread,SLOT(do_run()));
	connect(this,SIGNAL(sendtext(QString)),pitchthread,SLOT(gettext(QString)));
	connect(this,SIGNAL(sendhandle(HMIDIOUT)),pitchthread,SLOT(gethandle(HMIDIOUT)));
	connect(this,SIGNAL(stoppitchthread()),pitchthread,SLOT(stop()));
	connect(playthread,SIGNAL(settextedit(QString)),this,SLOT(do_set_textedit(QString)));
	connect(playthread,SIGNAL(playover(int)),this,SLOT(do_play_over(int)));
	connect(playthread,SIGNAL(sendbeatstartnumber(int)),this,SLOT(get_beats_startnumber(int)));
	connect(playthread,SIGNAL(sendrhythmstartnumber(int)),this,SLOT(get_rhythm_startnumber(int)));
	connect(this,SIGNAL(find_paragraph()),this,SLOT(do_find_paragraph()));
	connect(this,SIGNAL(find_beats()),this,SLOT(do_find_beats()));
	connect(ui.LoadSwing,SIGNAL(clicked()),this,SLOT(do_load_swing()));
	connect(ui.SaveSwing,SIGNAL(clicked()),this,SLOT(do_save_swing()));
	
	connect(ui.ConnectINDevice,SIGNAL(clicked()),this,SLOT(do_connect_MIDIIN()));
	connect(this,SIGNAL(sendflip(int)),this,SLOT(getflipText(int)));
	connect(this,SIGNAL(sendspace()),this,SLOT(getspace()));
	connect(this,SIGNAL(composeover()),this,SLOT(getcomposeover()));
	connect(ui.Backspace,SIGNAL(clicked()),this,SLOT(do_backspace()));
	connect(ui.SpaceButon,SIGNAL(clicked()),this,SLOT(do_space()));
	connect(ui.CtrlButton,SIGNAL(clicked()),this,SLOT(do_ctrl()));
	connect(ui.CtrlButton2,SIGNAL(clicked()),this,SLOT(do_ctrl()));
	connect(ui.MoveLeft,SIGNAL(clicked()),this,SLOT(do_move_left()));
	connect(ui.MoveRight,SIGNAL(clicked()),this,SLOT(do_move_right()));
	connect(ui.ModiButton,SIGNAL(clicked()),this,SLOT(modi_beats()));
	connect(ui.ModiRhythm,SIGNAL(clicked()),this,SLOT(do_modi_rhythm()));
	connect(ui.doubleSpinBox,SIGNAL(valueChanged(double)),this,SLOT(do_speed_change(double)));
	connect(this,SIGNAL(send_speed(double)),playthread,SLOT(get_speed(double)));

	connect(this,SIGNAL(sendtoplaythread(int,int,int)),playthread,SLOT(getinformations(int,int,int)));
	connect(this,SIGNAL(do_run_play()),playthread,SLOT(do_run()));
	connect(this,SIGNAL(circulation_play()),playthread,SLOT(circulationplay()));
	connect(this,SIGNAL(beats_play(int,int)),playthread,SLOT(beatplay(int,int)));
	connect(this,SIGNAL(rhythm_play(int,int)),playthread,SLOT(rhythmplay(int,int)));
	connect(this,SIGNAL(sendplaytext(QString)),playthread,SLOT(gettext(QString)));
	connect(this,SIGNAL(sendplayhandle(HMIDIOUT)),playthread,SLOT(gethandle(HMIDIOUT)));
	connect(this,SIGNAL(sendtimelist(QList <int> *)),playthread,SLOT(gettimelist(QList <int> *)));
	connect(this,SIGNAL(stopplaythread()),playthread,SLOT(stop()));

	connect(ui.comboBox,SIGNAL(currentIndexChanged ( const QString)),this,SLOT(do_combox_change()));
	connect(ui.horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(do_volume_change(int)));
	connect(ui.horizontalSlider_2,SIGNAL(valueChanged(int)),this,SLOT(do_speed_change(int)));
	connect(ui.ClearButton,SIGNAL(clicked()),this,SLOT(do_clear_textedit()));

	connect(&timer,SIGNAL(timeout()),this,SLOT(update_time()));

	connect(ui.PlayButton,SIGNAL(clicked()),this,SLOT(do_play()));
	connect(ui.CirculationPlay,SIGNAL(clicked()),this,SLOT(do_circulation_play()));
	connect(ui.BeatPlay,SIGNAL(clicked()),this,SLOT(do_beats_play()));
	connect(ui.RhythmPlay,SIGNAL(clicked()),this,SLOT(do_rhythm_play()));
	connect(ui.SaveButton,SIGNAL(clicked()),this,SLOT(do_save_text()));
	connect(ui.LoadButton,SIGNAL(clicked()),this,SLOT(do_load_text()));
	connect(ui.ComposeButton,SIGNAL(clicked()),this,SLOT(do_play_text()));
	connect(ui.RisingButton,SIGNAL(clicked()),this,SLOT(do_rising()));
	connect(ui.FallingButton,SIGNAL(clicked()),this,SLOT(do_falling()));

	connect(ui.button1,SIGNAL(pressed()),this,SLOT(button1_pressed()));	//C_
	connect(ui.button2,SIGNAL(pressed()),this,SLOT(button2_pressed()));	//C#
	connect(ui.button3,SIGNAL(pressed()),this,SLOT(button3_pressed()));//D_
	connect(ui.button4,SIGNAL(pressed()),this,SLOT(button4_pressed()));//D#
	connect(ui.button5,SIGNAL(pressed()),this,SLOT(button5_pressed()));//E_
	connect(ui.button6,SIGNAL(pressed()),this,SLOT(button6_pressed()));//F_
	connect(ui.button7,SIGNAL(pressed()),this,SLOT(button7_pressed()));//F#
	connect(ui.button8,SIGNAL(pressed()),this,SLOT(button8_pressed()));//G_
	connect(ui.button9,SIGNAL(pressed()),this,SLOT(button9_pressed()));//G#
	connect(ui.button10,SIGNAL(pressed()),this,SLOT(button10_pressed()));//A_
	connect(ui.button11,SIGNAL(pressed()),this,SLOT(button11_pressed()));//A#
	connect(ui.button12,SIGNAL(pressed()),this,SLOT(button12_pressed()));//B_

	connect(ui.button13,SIGNAL(pressed()),this,SLOT(button13_pressed()));//C_
	connect(ui.button14,SIGNAL(pressed()),this,SLOT(button14_pressed()));//C_
	connect(ui.button15,SIGNAL(pressed()),this,SLOT(button15_pressed()));//C_
	connect(ui.button16,SIGNAL(pressed()),this,SLOT(button16_pressed()));//C_
	connect(ui.button17,SIGNAL(pressed()),this,SLOT(button17_pressed()));//C_
	connect(ui.button18,SIGNAL(pressed()),this,SLOT(button18_pressed()));//C_
	connect(ui.button19,SIGNAL(pressed()),this,SLOT(button19_pressed()));//C_
	connect(ui.button20,SIGNAL(pressed()),this,SLOT(button20_pressed()));//C_
	connect(ui.button21,SIGNAL(pressed()),this,SLOT(button21_pressed()));//C_
	connect(ui.button22,SIGNAL(pressed()),this,SLOT(button22_pressed()));//C_
	connect(ui.button23,SIGNAL(pressed()),this,SLOT(button23_pressed()));//C_
	connect(ui.button24,SIGNAL(pressed()),this,SLOT(button24_pressed()));//C_

	connect(ui.button25,SIGNAL(pressed()),this,SLOT(button25_pressed()));//C_
	connect(ui.button26,SIGNAL(pressed()),this,SLOT(button26_pressed()));//C_
	connect(ui.button27,SIGNAL(pressed()),this,SLOT(button27_pressed()));//C_
	connect(ui.button28,SIGNAL(pressed()),this,SLOT(button28_pressed()));//C_
	connect(ui.button29,SIGNAL(pressed()),this,SLOT(button29_pressed()));//C_
	connect(ui.button30,SIGNAL(pressed()),this,SLOT(button30_pressed()));//C_
	connect(ui.button31,SIGNAL(pressed()),this,SLOT(button31_pressed()));//C_
	connect(ui.button32,SIGNAL(pressed()),this,SLOT(button32_pressed()));//C_
	connect(ui.button33,SIGNAL(pressed()),this,SLOT(button33_pressed()));//C_
	connect(ui.button34,SIGNAL(pressed()),this,SLOT(button34_pressed()));//C_
	connect(ui.button35,SIGNAL(pressed()),this,SLOT(button35_pressed()));//C_
	connect(ui.button36,SIGNAL(pressed()),this,SLOT(button36_pressed()));//C_

	connect(ui.button37,SIGNAL(pressed()),this,SLOT(button37_pressed()));//C_
	connect(ui.button38,SIGNAL(pressed()),this,SLOT(button38_pressed()));//C#
	connect(ui.button39,SIGNAL(pressed()),this,SLOT(button39_pressed()));//D_
	connect(ui.button40,SIGNAL(pressed()),this,SLOT(button40_pressed()));//D#
	connect(ui.button41,SIGNAL(pressed()),this,SLOT(button41_pressed()));//E_
	connect(ui.button42,SIGNAL(pressed()),this,SLOT(button42_pressed()));//F_
	connect(ui.button43,SIGNAL(pressed()),this,SLOT(button43_pressed()));//F#
	connect(ui.button44,SIGNAL(pressed()),this,SLOT(button44_pressed()));//G_
	connect(ui.button45,SIGNAL(pressed()),this,SLOT(button45_pressed()));//G#
	connect(ui.button46,SIGNAL(pressed()),this,SLOT(button46_pressed()));//A_
	connect(ui.button47,SIGNAL(pressed()),this,SLOT(button47_pressed()));//A#
	connect(ui.button48,SIGNAL(pressed()),this,SLOT(button48_pressed()));//B_
	connect(ui.button49,SIGNAL(pressed()),this,SLOT(button49_pressed()));//C_

	connect(ui.button50,SIGNAL(pressed()),this,SLOT(button45_pressed()));//G#
	connect(ui.button51,SIGNAL(pressed()),this,SLOT(button46_pressed()));//A_
	connect(ui.button52,SIGNAL(pressed()),this,SLOT(button47_pressed()));//A#
	connect(ui.button53,SIGNAL(pressed()),this,SLOT(button48_pressed()));//B_
	connect(ui.button54,SIGNAL(pressed()),this,SLOT(button49_pressed()));//C_
	connect(ui.button55,SIGNAL(pressed()),this,SLOT(button37_pressed()));//C_
	connect(ui.button56,SIGNAL(pressed()),this,SLOT(button38_pressed()));//C#
	connect(ui.button57,SIGNAL(pressed()),this,SLOT(button39_pressed()));//D_
	connect(ui.button58,SIGNAL(pressed()),this,SLOT(button40_pressed()));//D#
	connect(ui.button59,SIGNAL(pressed()),this,SLOT(button41_pressed()));//E_
	connect(ui.button60,SIGNAL(pressed()),this,SLOT(button42_pressed()));//F_
	connect(ui.button61,SIGNAL(pressed()),this,SLOT(button24_pressed()));//B_
	connect(ui.button62,SIGNAL(pressed()),this,SLOT(button25_pressed()));//C_
	connect(ui.button63,SIGNAL(pressed()),this,SLOT(button12_pressed()));//B_
	connect(ui.button64,SIGNAL(pressed()),this,SLOT(button13_pressed()));//C_
	connect(ui.button65,SIGNAL(pressed()),this,SLOT(button14_pressed()));//C#
}
void AudioPlayer::update_time()
{
	nowtime++;
}
void AudioPlayer::do_connect_MIDIIN()
{
	MMRESULT result= midiInOpen(&inhandle,0,DWORD_PTR(&MidiInProc),0,CALLBACK_FUNCTION);
	if(result == 0)
	{
		QMessageBox::information(NULL,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("MIDI输入设备打开成功!"),0,0);
		midiInStart(inhandle);
	}
	else
	{
		QMessageBox::warning(NULL,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("设备打开失败，请检查连接 !"),0,0);
	}
	
}
void AudioPlayer::do_load_text()
{
	QString strfile;
	strfile = QCoreApplication::applicationDirPath();
	QByteArray currentPath = strfile.toLatin1();
	QString fileName = QFileDialog::getOpenFileName(this,
		QString::fromLocal8Bit("加载乐谱"),
		currentPath.data(),
		QString::fromLocal8Bit("文本文件 (*.txt)"));
	if (!fileName.isNull())
	{
		QFile file(fileName);
		if (!file.open(QIODevice::ReadOnly)) 
		{
			QMessageBox::warning(this,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("打开文件失败！！！请重试"),QMessageBox::Yes | QMessageBox::Default,  
				QMessageBox::No,   QMessageBox::Cancel | QMessageBox::Escape);
		}
		else 
		{
			QTextStream stream(&file);
			ui.textEdit->clear();
			ui.textEdit->insertPlainText(stream.readAll());
			ui.label_2->setText(fileName.remove(strfile));
			file.close();
		}
		//fileName是文件名
	}
	else
	{
		//点的是取消
	}
}
void AudioPlayer::do_save_text()
{
	QString strfile;
	strfile = QCoreApplication::applicationDirPath();
	QByteArray currentPath = strfile.toLatin1();
	QString fileName = QFileDialog::getSaveFileName(this,
		QString::fromLocal8Bit("保存乐谱"),
		currentPath.data(),
		QString::fromLocal8Bit("文本文件 (*.txt)"));
	if (!fileName.isNull())
	{
		QFile file(fileName);
		if (!file.open(QIODevice::WriteOnly)) {
			QMessageBox::warning(this,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("打开文件失败！！！请重试"),QMessageBox::Yes | QMessageBox::Default,  
				QMessageBox::No,   QMessageBox::Cancel | QMessageBox::Escape);
		}
		else 
		{
			QTextStream stream(&file);
			stream <<ui.textEdit->toPlainText();
			stream.flush();
			file.close();
		}
		//fileName是文件名
	}
	else
	{
		//点的是取消
	}
}
bool AudioPlayer::eventFilter(QObject *obj, QEvent *event)
{
	if (event->type() == QEvent::KeyPress) 
	{
		QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
		int key = keyEvent->key();
		if(key == Qt::Key_Backspace)
		{
			do_backspace();
		}
		else if(key == Qt::Key_Space)
		{
			do_space();
		}
		else if(key == Qt::Key_Left)
		{
			do_move_left();
		}
		else if(key == Qt::Key_Right)
		{
			do_move_right();
		}
		else if(key == Qt::Key_Up)
		{
			do_rising();
		}
		else if(key == Qt::Key_Down)
		{
			do_falling();
		}
		else if(key == Qt::Key_Control)
		{
			do_ctrl();
		}
		else
		{
			switch(key)
			{
			case Qt::Key_Z:
				button1_pressed();
				break;
			case Qt::Key_X:
				button2_pressed();
				break;
			case Qt::Key_C:
				button3_pressed();
				break;
			case Qt::Key_V:
				button4_pressed();
				break;
			case Qt::Key_B:
				button5_pressed();
				break;
			case Qt::Key_N:
				button6_pressed();
				break;
			case Qt::Key_M:
				button7_pressed();
				break;
			case Qt::Key_Comma:
				button8_pressed();
				break;
			case Qt::Key_Period:
				button9_pressed();
				break;
			case Qt::Key_Slash:
				button10_pressed();
				break;
			case Qt::Key_Shift:
				button11_pressed();
				break;
			case Qt::Key_A:
				button12_pressed();
				break;
			case Qt::Key_S:
				button13_pressed();
				break;
			case Qt::Key_D:
				button14_pressed();
				break;
			case Qt::Key_F:
				button15_pressed();
				break;
			case Qt::Key_G:
				button16_pressed();
				break;
			case Qt::Key_H:
				button17_pressed();
				break;
			case Qt::Key_J:
				button18_pressed();
				break;
			case Qt::Key_K:
				button19_pressed();
				break;
			case Qt::Key_L:
				button20_pressed();
				break;
			case Qt::Key_Semicolon:
				button21_pressed();
				break;
			case Qt::Key_Apostrophe:
				button22_pressed();
				break;
			case Qt::Key_Return:
				button23_pressed();
				break;
			case Qt::Key_Q:
				button24_pressed();
				break;
			case Qt::Key_W:
				button25_pressed();
				break;
			case Qt::Key_E:
				button26_pressed();
				break;
			case Qt::Key_R:
				button27_pressed();
				break;
			case Qt::Key_T:
				button28_pressed();
				break;
			case Qt::Key_Y:
				button29_pressed();
				break;
			case Qt::Key_U:
				button30_pressed();
				break;
			case Qt::Key_I:
				button31_pressed();
				break;
			case Qt::Key_O:
				button32_pressed();
				break;
			case Qt::Key_P:
				button33_pressed();
				break;
			case Qt::Key_BracketLeft:
				button34_pressed();
				break;
			case Qt::Key_BracketRight:
				button35_pressed();
				break;
			case Qt::Key_Backslash:
				button36_pressed();
				break;
			case Qt::Key_QuoteLeft:
				button37_pressed();
				break;
			case Qt::Key_1:
				button38_pressed();
				break;
			case Qt::Key_2:
				button39_pressed();
				break;
			case Qt::Key_3:
				button40_pressed();
				break;
			case Qt::Key_4:
				button41_pressed();
				break;
			case Qt::Key_5:
				button42_pressed();
				break;
			case Qt::Key_6:
				button43_pressed();
				break;
			case Qt::Key_7:
				button44_pressed();
				break;
			case Qt::Key_8:
				button45_pressed();
				break;
			case Qt::Key_9:
				button46_pressed();
				break;
			case Qt::Key_0:
				button47_pressed();
				break;
			case Qt::Key_Minus:
				button48_pressed();
				break;
			case Qt::Key_Equal:
				button49_pressed();
				break;
			default:
				break;
			}
		}
		return true;
	} 
	else 
	{
		return false;
	}
}
void AudioPlayer::do_combox_change()
{
	int index = ui.comboBox->currentIndex();
	midiOutShortMsg(outhandle,index*0x100+0xC0);
	ui.textEdit->setFocus();
}
void AudioPlayer::do_clear_textedit()
{
	ui.textEdit->clear();
	ui.label_2->clear();
	ui.label_8->clear();
	ui.textEdit->setHtml(QString());
	ui.textEdit->setFocus();
}
void AudioPlayer::do_volume_change(int vol)
{
	volume = vol;
	ui.label_5->setText(QString::number(vol));
	ui.textEdit->setFocus();
}
void AudioPlayer::do_speed_change(int value)
{
	speed = value;
	ui.label_6->setText(QString::number(speed));
	ui.textEdit->setFocus();
	beattime = (int)(60000/speed);
}
void AudioPlayer::do_save_swing()
{
	QString strfile;
	strfile = QCoreApplication::applicationDirPath();
	QByteArray currentPath = strfile.toLatin1();
	QString fileName = QFileDialog::getSaveFileName(this,
		QString::fromLocal8Bit("保存节奏"),
		currentPath.data(),
		QString::fromLocal8Bit("数据文件 (*.dat)"));
	if (!fileName.isNull())
	{
		QFile file(fileName);
		if (!file.open(QIODevice::WriteOnly)) {
			QMessageBox::warning(this,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("打开文件失败！！！请重试"),QMessageBox::Yes | QMessageBox::Default,  
				QMessageBox::No,   QMessageBox::Cancel | QMessageBox::Escape);
		}
		else 
		{
			int i = 0;
			QTextStream stream(&file);
			for(i=0;i<sTime.length();i++)
				stream<<sTime[i]<<' ';
			stream.flush();
			file.close();
		}
		//fileName是文件名
	}
	else
	{
		//点的是取消
	}
}
void AudioPlayer::do_load_swing()
{
	QString strfile;
	strfile = QCoreApplication::applicationDirPath();
	QByteArray currentPath = strfile.toLatin1();
	QString fileName = QFileDialog::getOpenFileName(this,
		QString::fromLocal8Bit("加载乐谱"),
		currentPath.data(),
		QString::fromLocal8Bit("文本文件 (*.dat)"));
	if (!fileName.isNull())
	{
		QFile file(fileName);
		if (!file.open(QIODevice::ReadOnly)) 
		{
			QMessageBox::warning(this,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("打开文件失败！！！请重试"),QMessageBox::Yes | QMessageBox::Default,  
				QMessageBox::No,   QMessageBox::Cancel | QMessageBox::Escape);
		}
		else 
		{
			int i=0;
			char c;
			int data;
			sTime.clear();
			QTextStream stream(&file);
			while(!stream.atEnd())
			{
				stream>>data>>c;
				sTime.push_back(data);
			}
			file.close();
			ui.label_8->setText(fileName.remove(strfile));
		}
		//fileName是文件名
	}
	else
	{
		//点的是取消
	}
}
void AudioPlayer::do_play()
{
	ui.textEdit->setFocus();
	if(sTime.count() == (ui.textEdit->toPlainText().length()/4) && !sTime.isEmpty())
	{
		if(doplaysign == false)
		{
			if(playsign == false)
			{
				ui.PlayButton->setText(QString::fromLocal8Bit("播放中..."));
				doplaysign = true;
				doplayText.clear();
				doplayText = ui.textEdit->toPlainText();
				emit sendplaytext(doplayText);
				emit sendtoplaythread(flip,volume,baseflip);
				emit sendtimelist(&sTime);
				emit do_run_play();

			}
			else
			{
				QMessageBox::warning(NULL,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("您还没有谱曲，先谱曲才能够播放,按空格键谱曲!!!"),0,0);
			}
		}
		else
		{
			emit stopplaythread();
		}
	}
	else
	{
		QMessageBox::warning(NULL,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("您还没有谱曲，先谱曲才能够播放,按空格键谱曲!!!"),0,0);
	}
}
void AudioPlayer::do_circulation_play()
{
	ui.textEdit->setFocus();
	if(sTime.count() == (ui.textEdit->toPlainText().length()/4) && !sTime.isEmpty())
	{
		if(doplaysign == false)
		{
			if(playsign == false)
			{
				ui.CirculationPlay->setText(QString::fromLocal8Bit("播放中..."));
				doplaysign = true;
				doplayText.clear();
				doplayText = ui.textEdit->toPlainText();
				emit sendplaytext(doplayText);
				emit sendtoplaythread(flip,volume,baseflip);
				emit sendtimelist(&sTime);
				emit circulation_play();

			}
			else
			{
				QMessageBox::warning(NULL,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("您还没有谱曲，先谱曲才能够播放,按空格键谱曲!!!"),0,0);
			}
		}
		else
		{
			emit stopplaythread();
		}
	}
	else
	{
		QMessageBox::warning(NULL,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("您还没有谱曲，先谱曲才能够播放,按空格键谱曲!!!"),0,0);
	}
}
void AudioPlayer::do_speed_change(double spd)
{
	playspeed = spd;
	emit send_speed(playspeed);
}
void AudioPlayer::modi_beats()
{
	ui.textEdit->setFocus();
	if(sTime.count() == (ui.textEdit->toPlainText().length()/4) && !sTime.isEmpty())
	{
			if(playsign == false)
			{
				if(doplaysign == true)
				{
					emit stopplaythread();
				}
				int i = 0;
				while(i<sTime.length())
				{
					double beatmod = (double)(beattime/20.0);
					double interval = (double)sTime[i];
					double persent = interval/beatmod;
					if(persent<1.5/8)
					{
						sTime[i] = (int)(beatmod/8)+1;
					}
					else if(persent < 2.5/8)
					{
						sTime[i] = (int)(beatmod/4)+1;
					}
					else if(persent < 3.5/8)
					{
						sTime[i] = (int)(beatmod/8*3)+1;
					}
					else if(persent < 4.5/8)
					{
						sTime[i] = (int)(beatmod/2)+1;
					}
					else if(persent < 5.5/8)
					{
						sTime[i] = (int)(beatmod/8*5)+1;
					}
					else if(persent < 6.5/8)
					{
						sTime[i] = (int)(beatmod/4*3)+1;
					}
					else if(persent < 7.5/8)
					{
						sTime[i] = (int)(beatmod/8*7)+1;
					}
					else
					{
						sTime[i] = int(beatmod)+1;
					}
					i++;
				}
				QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("修正完成!"),0,0);
			}
			else
			{
				QMessageBox::warning(this,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("您还没有谱曲，先谱曲才能够播放,按空格键谱曲!!!"),0,0);
			}
	}
	else
	{
		QMessageBox::warning(NULL,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("您还没有谱曲，先谱曲才能够播放,按空格键谱曲!!!"),0,0);
	}
}
void AudioPlayer::do_beats_play()
{
	ui.textEdit->setFocus();
	if(sTime.count() == (ui.textEdit->toPlainText().length()/4) && !sTime.isEmpty())
	{
		if(doplaysign == false)	//没有在播放中
		{
			if(playsign == false)//没有在谱曲中
			{
				ui.BeatPlay->setText(QString::fromLocal8Bit("播放中..."));
				doplaysign = true;
				beatplaysign = true;
				beatplayin = false;
				beatendnumber = 0;
				beatstartnumber = 0;
				doplayText.clear();
				doplayText = ui.textEdit->toPlainText();
				emit sendplaytext(doplayText);
				emit sendtoplaythread(flip,volume,baseflip);
				emit sendtimelist(&sTime);
			}
			else
			{
				QMessageBox::warning(NULL,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("您还没有谱曲，先谱曲才能够播放,按空格键谱曲!!!"),0,0);
			}
		}
		else
		{
			emit stopplaythread();
			doplaysign = false;
			beatplaysign = false;
			beatplayin = false;
			beatstartnumber = 0;
			beatendnumber = 0;
			Paragraph.clear();
			ui.BeatPlay->setText(QString::fromLocal8Bit("按节播放"));
			ui.textEdit->setText(ui.textEdit->toPlainText());
			QTextCursor cursor = ui.textEdit->textCursor();
			cursor.movePosition(QTextCursor::Right,QTextCursor::MoveAnchor,doplayText.length());
			ui.textEdit->setTextCursor(cursor);
			ui.textEdit->setFocus();
		}
	}
	else
	{
		QMessageBox::warning(NULL,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("您还没有谱曲，先谱曲才能够播放,按空格键谱曲!!!"),0,0);
	}
}
void AudioPlayer::do_rhythm_play()
{
	ui.textEdit->setFocus();
	if(sTime.count() == (ui.textEdit->toPlainText().length()/4) && !sTime.isEmpty())
	{
		if(doplaysign == false)	//没有在播放中
		{
			if(playsign == false)//没有在谱曲中
			{
				ui.RhythmPlay->setText(QString::fromLocal8Bit("播放中..."));
				doplaysign = true;
				rhythmplaysign = true;
				rhythmplayin = false;
				rhythmendnumber = 0;
				rhythmstartnumber = 0;
				doplayText.clear();
				doplayText = ui.textEdit->toPlainText();
				emit sendplaytext(doplayText);
				emit sendtoplaythread(flip,volume,baseflip);
				emit sendtimelist(&sTime);
			}
			else
			{
				QMessageBox::warning(NULL,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("您还没有谱曲，先谱曲才能够播放,按空格键谱曲!!!"),0,0);
			}
		}
		else
		{
			emit stopplaythread();
			doplaysign = false;
			rhythmplaysign = false;
			rhythmplayin = false;
			rhythmstartnumber = 0;
			rhythmendnumber = 0;
			Beats.clear();
			ui.RhythmPlay->setText(QString::fromLocal8Bit("按拍播放"));
			ui.textEdit->setText(ui.textEdit->toPlainText());
			QTextCursor cursor = ui.textEdit->textCursor();
			cursor.movePosition(QTextCursor::Right,QTextCursor::MoveAnchor,doplayText.length());
			ui.textEdit->setTextCursor(cursor);
			ui.textEdit->setFocus();
		}
	}
	else
	{
		QMessageBox::warning(NULL,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("您还没有谱曲，先谱曲才能够播放,按空格键谱曲!!!"),0,0);
	}
}
void AudioPlayer::do_set_textedit(QString text)
{
	ui.textEdit->setHtml(text);
}
void AudioPlayer::do_play_over(int number)
{
	ui.textEdit->clear();
	ui.textEdit->setHtml(doplayText);
	QTextCursor cursor = ui.textEdit->textCursor();
	cursor.movePosition(QTextCursor::Right,QTextCursor::MoveAnchor,doplayText.length());
	ui.textEdit->setTextCursor(cursor);
	ui.textEdit->setFocus();
	ui.PlayButton->setText(QString::fromLocal8Bit("普通播放"));
	ui.CirculationPlay->setText(QString::fromLocal8Bit("循环播放"));
	ui.BeatPlay->setText(QString::fromLocal8Bit("按节播放"));
	ui.RhythmPlay->setText(QString::fromLocal8Bit("按拍播放"));
	beatplaysign = false;
	doplaysign = false;
	beatstartnumber = 0;
	beatendnumber = 0;
	paragraphcount = 0;
	rhythmplaysign = false;
	rhythmstartnumber = 0;
	rhythmendnumber = 0;
	rhythmcount = 0;
	if(number == 0)
	QMessageBox::information(NULL,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("播放完毕!"),0,0);
}
void AudioPlayer::sleep(unsigned int msec)
{
	QTime reachTime = QTime::currentTime().addMSecs(msec);
	while(QTime::currentTime() < reachTime)
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
void AudioPlayer::do_play_note(QString text)
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
void AudioPlayer::do_play_text()
{
	playText.clear();
	playText = ui.textEdit->toPlainText();
	playnumber = (playText.length())/4;
	sTime.clear();
	ui.label_8->clear();
	Paragraph.clear();
	beatendnumber = 0;
	beatstartnumber = 0;
	ui.textEdit->setHtml(ui.textEdit->toPlainText());
	QTextCursor cursor = ui.textEdit->textCursor();
	cursor.movePosition(QTextCursor::Right,QTextCursor::MoveAnchor,doplayText.length());
	ui.textEdit->setTextCursor(cursor);
	if(playsign == false)
	{
		ui.ComposeButton->setText(QString::fromLocal8Bit("谱曲中..."));
		QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("您可以开始谱曲，请按空格键或者鼠标左键单击Space按钮进行谱曲!"),0,0);
		playsign = true;
		timer.start(20);
		lasttime = 0;
		nowtime = 0;
		maxparagraph = 0;
	}
	else
	{
		ui.ComposeButton->setText(QString::fromLocal8Bit("开始谱曲"));
		playsign = false;
	}
	ui.textEdit->setFocus();
}
void AudioPlayer::do_backspace()
{
	QString str= ui.textEdit->toPlainText();
	//r = str.mid(0,str.length()-4);
	QTextCursor cursor = ui.textEdit->textCursor();
	if(pitchup == false)
	{
		//ui.textEdit->setHtml(ui.textEdit->toPlainText());
		cursor.deletePreviousChar();
		cursor.deletePreviousChar();
		cursor.deletePreviousChar();
		cursor.deletePreviousChar();

		if(playnumber > 0)
		{
			sTime.takeLast();
			nowtime = lasttime;
			playText = playText.mid(0,cursor.position())+playText.mid(cursor.position()+4,playText.length());
		}
	}
	else
	{
		emit stoppitchthread();
		pitchup = false;
		QString text = ui.textEdit->toPlainText().mid(0,cursor.position());
		ui.textEdit->setText(text);
	}
	ui.textEdit->setTextCursor(cursor);
}
void AudioPlayer::do_ctrl()
{
	QTextCursor cursor = ui.textEdit->textCursor();
	int pos = cursor.position();
	QString text1 = ui.textEdit->toPlainText();
	QString text2 = text1.mid(0,pos);
	QString text3 = text1.mid(pos,text1.length());
	emit sendtext(text3);
	if(pitchup == false)
	{
		emit sendtopitchthread(flip,volume,baseflip);
		ui.textEdit->setHtml(text2+"<span style='color:#33FF33;'>"+text3+"</span>");
		pitchup = true;
	}
	else
	{
		ui.textEdit->clear();
		ui.textEdit->setHtml(text1);
		pitchup = false;
		emit stoppitchthread();
	}
	cursor.setPosition(pos);
	ui.textEdit->setTextCursor(cursor);
	if(pitchup == true)
	{
		emit do_run_pitchup();
	}
}
void AudioPlayer::get_beats_startnumber(int startnumber)
{
	beatplayin = false;
	beatstartnumber = startnumber;
}
void AudioPlayer::get_rhythm_startnumber(int startnumber)
{
	rhythmplayin = false;
	rhythmstartnumber = startnumber;
}
void AudioPlayer::do_modi_rhythm()
{
	modirhythm = true;
	find_paragraph();
}
void AudioPlayer::do_space()
{
	if(playsign == true)
	{
		if(playnumber == 0)
		{
			playText.clear();
			ui.textEdit->setHtml(ui.textEdit->toPlainText());
			QTextCursor cursor = ui.textEdit->textCursor();
			cursor.movePosition(QTextCursor::Right,QTextCursor::MoveAnchor,ui.textEdit->toPlainText().length());
			ui.textEdit->setTextCursor(cursor);
			ui.ComposeButton->setText(QString::fromLocal8Bit("开始谱曲"));
			if(playsign == true)
			{
				playsign = false;
				emit find_paragraph();
				QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("谱曲完成！"));
			}
			ui.textEdit->setFocus();
		}
		else if(playnumber>0)
		{
			int timein = nowtime-lasttime;
			if(timein == 0) 
			{
				timein = 1;
				nowtime++;
			}
			if(maxparagraph<timein)
				maxparagraph = timein;
			sTime.push_back(timein);
			lasttime = nowtime;
			int num = playText.length();
			QString text = playText.mid(num-4*playnumber,4);
			QString text1 = playText.mid(0,num-4*playnumber);
			QString text2 = playText.right(4*playnumber-4);
			ui.textEdit->setText(text1+"<span style='color:#33FF33;'>"+text+"</span>"+text2);
			QTextCursor cursor = ui.textEdit->textCursor();
			cursor.setPosition(num-4*(playnumber-1));
			ui.textEdit->setTextCursor(cursor);
			do_play_note(text);
			playnumber--;
			}
		}
	else if(beatplaysign == true && beatplayin == false)
	{
		beatplayin = true;
		doplayText.clear();
		doplayText = ui.textEdit->toPlainText();
		emit sendplaytext(doplayText);
		emit sendtoplaythread(flip,volume,baseflip);
		emit sendtimelist(&sTime);
		if(!Paragraph.isEmpty())
			beatendnumber = Paragraph[paragraphcount++];
		emit beats_play(beatstartnumber,beatendnumber);
	}
	else if(rhythmplaysign == true && rhythmplayin == false)
	{
		rhythmplayin = true;
		doplayText.clear();
		doplayText = ui.textEdit->toPlainText();
		emit sendplaytext(doplayText);
		emit sendtoplaythread(flip,volume,baseflip);
		emit sendtimelist(&sTime);
		if(!Beats.isEmpty())
				rhythmendnumber = Beats[rhythmcount++];
		qDebug()<<"rhythmstartnumber = "<<rhythmstartnumber<<"\t"<<"rhythmendnumber = "<<rhythmendnumber;
		emit rhythm_play(rhythmstartnumber,rhythmendnumber);
	}
}
void AudioPlayer::do_find_paragraph()
{
	int i = 0;
	Paragraph.clear();
	while(i<sTime.length())
	{
		double rate = ((double)sTime[i])/((double)maxparagraph);
		if(rate > 0.7)
			Paragraph.push_back(i);
		i++;
	}
	Paragraph.push_back(sTime.length()+1);
	emit find_beats();
}
void AudioPlayer::do_find_beats()
{
	int i = 0,k=0;
	int sum = 0;
	int index = ui.comboBox_2->currentIndex();
	int onebeatTime = (int)beattime/20.0;
	Beats.clear();
	while(i<sTime.length())
	{
		if(i == Paragraph[k])
		{
			Beats.push_back(i);
			i++;
			k++;
			continue;
		}
		if(i >= (sTime.length()-1))
		{
			break;
		}
		sum += sTime[i++];
		if((sum+sTime[i])>onebeatTime)
		{
			sum = 0;
			Beats.push_back(i-1);
		}
	}
	Beats.push_back(sTime.length()+1);
	for(int m=0;m<Beats.length();m++)
	{
		qDebug()<<Beats[m];
	}
	if(modirhythm == true)
	{
		modirhythm = false;
		QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("节拍修正完成！"));
	}
}
void AudioPlayer::do_move_left()
{
	QTextCursor cursor = ui.textEdit->textCursor();
	if(cursor.position()>0)
		cursor.movePosition(QTextCursor::Left,QTextCursor::MoveAnchor,4);
	ui.textEdit->setTextCursor(cursor);
	ui.textEdit->setFocus();
}
void AudioPlayer::do_move_right()
{
	QTextCursor cursor = ui.textEdit->textCursor();
	if(cursor.position()<ui.textEdit->toPlainText().length())
		cursor.movePosition(QTextCursor::Right,QTextCursor::MoveAnchor,4);
	ui.textEdit->setTextCursor(cursor);
	ui.textEdit->setFocus();
}
void AudioPlayer::do_rising()
{
	if(baseflip == 36 || baseflip == 24)
	{
		QString temp;
		QByteArray array;
		char* ptr;
		baseflip += 12;
		temp = ui.button1->text();
		array= temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button1->setText(array.data());

		temp = ui.button2->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button2->setText(array);

		temp = ui.button3->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button3->setText(array);

		temp = ui.button4->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button4->setText(array);

		temp = ui.button5->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button5->setText(array);

		temp = ui.button6->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button6->setText(array);

		temp = ui.button7->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button7->setText(array);

		temp = ui.button8->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button8->setText(array);

		temp = ui.button9->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button9->setText(array);

		temp = ui.button10->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button10->setText(array);

		temp = ui.button11->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button11->setText(array);

		temp = ui.button12->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button12->setText(array);

		temp = ui.button13->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button13->setText(array);

		temp = ui.button14->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button14->setText(array);

		temp = ui.button15->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button15->setText(array);

		temp = ui.button16->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button16->setText(array);

		temp = ui.button17->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button17->setText(array);

		temp = ui.button18->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button18->setText(array);

		temp = ui.button19->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button19->setText(array);

		temp = ui.button20->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button20->setText(array);

		temp = ui.button21->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button21->setText(array);

		temp = ui.button22->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button22->setText(array);

		temp = ui.button23->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button23->setText(array);

		temp = ui.button24->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button24->setText(array);

		temp = ui.button25->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button25->setText(array);

		temp = ui.button26->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button26->setText(array);

		temp = ui.button27->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button27->setText(array);

		temp = ui.button28->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button28->setText(array);

		temp = ui.button29->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button29->setText(array);

		temp = ui.button30->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button30->setText(array);

		temp = ui.button31->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button31->setText(array);

		temp = ui.button32->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button32->setText(array);

		temp = ui.button33->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button33->setText(array);

		temp = ui.button34->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button34->setText(array);

		temp = ui.button35->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button35->setText(array);

		temp = ui.button36->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button36->setText(array);

		temp = ui.button37->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button37->setText(array);

		temp = ui.button38->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button38->setText(array);

		temp = ui.button39->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button39->setText(array);

		temp = ui.button40->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button40->setText(array);

		temp = ui.button41->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button41->setText(array);

		temp = ui.button42->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button42->setText(array);

		temp = ui.button43->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button43->setText(array);

		temp = ui.button44->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button44->setText(array);

		temp = ui.button45->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button45->setText(array);

		temp = ui.button46->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button46->setText(array);

		temp = ui.button47->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button47->setText(array);

		temp = ui.button48->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button48->setText(array);

		temp = ui.button49->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]++;
		ui.button49->setText(array);

		ui.button50->setText(ui.button45->text());
		ui.button51->setText(ui.button46->text());
		ui.button52->setText(ui.button47->text());
		ui.button53->setText(ui.button48->text());
		ui.button54->setText(ui.button49->text());
		ui.button55->setText(ui.button37->text());
		ui.button56->setText(ui.button38->text());
		ui.button57->setText(ui.button39->text());
		ui.button58->setText(ui.button40->text());
		ui.button59->setText(ui.button41->text());
		ui.button60->setText(ui.button42->text());
		ui.button61->setText(ui.button24->text());
		ui.button62->setText(ui.button25->text());
		ui.button63->setText(ui.button12->text());
		ui.button64->setText(ui.button13->text());
		ui.button65->setText(ui.button14->text());
	}
}
void AudioPlayer::do_falling()
{
	if(baseflip == 36 || baseflip == 48)
	{
		QString temp;
		QByteArray array;
		char* ptr;
		baseflip -= 12;
		temp = ui.button1->text();
		array= temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button1->setText(array.data());

		temp = ui.button2->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button2->setText(array);

		temp = ui.button3->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button3->setText(array);

		temp = ui.button4->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button4->setText(array);

		temp = ui.button5->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button5->setText(array);

		temp = ui.button6->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button6->setText(array);

		temp = ui.button7->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button7->setText(array);

		temp = ui.button8->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button8->setText(array);

		temp = ui.button9->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button9->setText(array);

		temp = ui.button10->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button10->setText(array);

		temp = ui.button11->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button11->setText(array);

		temp = ui.button12->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button12->setText(array);

		temp = ui.button13->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button13->setText(array);

		temp = ui.button14->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button14->setText(array);

		temp = ui.button15->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button15->setText(array);

		temp = ui.button16->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button16->setText(array);

		temp = ui.button17->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button17->setText(array);

		temp = ui.button18->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button18->setText(array);

		temp = ui.button19->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button19->setText(array);

		temp = ui.button20->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button20->setText(array);

		temp = ui.button21->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button21->setText(array);

		temp = ui.button22->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button22->setText(array);

		temp = ui.button23->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button23->setText(array);

		temp = ui.button24->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button24->setText(array);

		temp = ui.button25->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button25->setText(array);

		temp = ui.button26->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button26->setText(array);

		temp = ui.button27->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button27->setText(array);

		temp = ui.button28->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button28->setText(array);

		temp = ui.button29->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button29->setText(array);

		temp = ui.button30->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button30->setText(array);

		temp = ui.button31->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button31->setText(array);

		temp = ui.button32->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button32->setText(array);

		temp = ui.button33->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button33->setText(array);

		temp = ui.button34->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button34->setText(array);

		temp = ui.button35->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button35->setText(array);

		temp = ui.button36->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button36->setText(array);

		temp = ui.button37->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button37->setText(array);

		temp = ui.button38->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button38->setText(array);

		temp = ui.button39->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button39->setText(array);

		temp = ui.button40->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button40->setText(array);

		temp = ui.button41->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button41->setText(array);

		temp = ui.button42->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button42->setText(array);

		temp = ui.button43->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button43->setText(array);

		temp = ui.button44->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button44->setText(array);

		temp = ui.button45->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button45->setText(array);

		temp = ui.button46->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button46->setText(array);

		temp = ui.button47->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button47->setText(array);

		temp = ui.button48->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button48->setText(array);

		temp = ui.button49->text();
		array = temp.toLatin1();
		ptr = array.data();
		ptr[2]--;
		ui.button49->setText(array);

		ui.button50->setText(ui.button45->text());
		ui.button51->setText(ui.button46->text());
		ui.button52->setText(ui.button47->text());
		ui.button53->setText(ui.button48->text());
		ui.button54->setText(ui.button49->text());
		ui.button55->setText(ui.button37->text());
		ui.button56->setText(ui.button38->text());
		ui.button57->setText(ui.button39->text());
		ui.button58->setText(ui.button40->text());
		ui.button59->setText(ui.button41->text());
		ui.button60->setText(ui.button42->text());
		ui.button61->setText(ui.button24->text());
		ui.button62->setText(ui.button25->text());
		ui.button63->setText(ui.button12->text());
		ui.button64->setText(ui.button13->text());
		ui.button65->setText(ui.button14->text());
	}
}
void AudioPlayer::getflipText(int flipin)
{
	switch(flipin)
	{
	case 36:
		ui.textEdit->insertPlainText("C_2 ");
		break;
	case 37:
		ui.textEdit->insertPlainText("C#2 ");
		break;
	case 38:
		ui.textEdit->insertPlainText("D_2 ");
		break;
	case 39:
		ui.textEdit->insertPlainText("D#2 ");
		break;
	case 40:
		ui.textEdit->insertPlainText("E_2 ");
		break;
	case 41:
		ui.textEdit->insertPlainText("F_2 ");
		break;
	case 42:
		ui.textEdit->insertPlainText("F#2 ");
		break;
	case 43:
		ui.textEdit->insertPlainText("G_2 ");
		break;
	case 44:
		ui.textEdit->insertPlainText("G#2 ");
		break;
	case 45:
		ui.textEdit->insertPlainText("A_2 ");
		break;
	case 46:
		ui.textEdit->insertPlainText("A#2 ");
		break;
	case 47:
		ui.textEdit->insertPlainText("B_2 ");
		break;
	case 48:
		ui.textEdit->insertPlainText("C_3 ");
		break;
	case 49:
		ui.textEdit->insertPlainText("C#3 ");
		break;
	case 50:
		ui.textEdit->insertPlainText("D_3 ");
		break;
	case 51:
		ui.textEdit->insertPlainText("D#3 ");
		break;
	case 52:
		ui.textEdit->insertPlainText("E_3 ");
		break;
	case 53:
		ui.textEdit->insertPlainText("F_3 ");
		break;
	case 54:
		ui.textEdit->insertPlainText("F#3 ");
		break;
	case 55:
		ui.textEdit->insertPlainText("G_3 ");
		break;
	case 56:
		ui.textEdit->insertPlainText("G#3 ");
		break;
	case 57:
		ui.textEdit->insertPlainText("A_3 ");
		break;
	case 58:
		ui.textEdit->insertPlainText("A#3 ");
		break;
	case 59:
		ui.textEdit->insertPlainText("B_3 ");
		break;
	case 60:
		ui.textEdit->insertPlainText("C_4 ");
		break;
	case 61:
		ui.textEdit->insertPlainText("C#4 ");
		break;
	case 62:
		ui.textEdit->insertPlainText("D_4 ");
		break;
	case 63:
		ui.textEdit->insertPlainText("D#4 ");
		break;
	case 64:
		ui.textEdit->insertPlainText("E_4 ");
		break;
	case 65:
		ui.textEdit->insertPlainText("F_4 ");
		break;
	case 66:
		ui.textEdit->insertPlainText("F#4 ");
		break;
	case 67:
		ui.textEdit->insertPlainText("G_4 ");
		break;
	case 68:
		ui.textEdit->insertPlainText("G#4 ");
		break;
	case 69:
		ui.textEdit->insertPlainText("A_4 ");
		break;
	case 70:
		ui.textEdit->insertPlainText("A#4 ");
		break;
	case 71:
		ui.textEdit->insertPlainText("B_4 ");
		break;
	case 72:
		ui.textEdit->insertPlainText("C_5 ");
		break;
	case 73:
		ui.textEdit->insertPlainText("C#5 ");
		break;
	case 74:
		ui.textEdit->insertPlainText("D_5 ");
		break;
	case 75:
		ui.textEdit->insertPlainText("D#5 ");
		break;
	case 76:
		ui.textEdit->insertPlainText("E_5 ");
		break;
	case 77:
		ui.textEdit->insertPlainText("F_5 ");
		break;
	case 78:
		ui.textEdit->insertPlainText("F#5 ");
		break;
	case 79:
		ui.textEdit->insertPlainText("G_5 ");
		break;
	case 80:
		ui.textEdit->insertPlainText("G#5 ");
		break;
	case 81:
		ui.textEdit->insertPlainText("A_5 ");
		break;
	case 82:
		ui.textEdit->insertPlainText("A#5 ");
		break;
	case 83:
		ui.textEdit->insertPlainText("B_5 ");
		break;
	case 84:
		ui.textEdit->insertPlainText("C_6 ");
		break;
	default:
		break;
	}
}
void  CALLBACK MidiInProc(
	HMIDIIN   hMidiIn,
	UINT      wMsg,
	DWORD_PTR dwInstance,
	DWORD_PTR dwParam1,
	DWORD_PTR dwParam2
	)
{
	switch(wMsg)
	{
	case MIM_OPEN:
		break;
	case MIM_CLOSE: 
		break;
	case MIM_DATA:
		if(flag == true)
		{	
			flip1 = dwParam1&0x0000FF00;
			if(playnumber == 0)
			{
				if(playsign == false)
				{
					midiOutShortMsg(outhandle,0x90 + flip1 + (volume * 0x10000));
					flip1 = flip1>>8;
					emit wptr->sendflip(flip1);
				}
				else
				{
					emit wptr->composeover();
				}
				
			}
			else
			{
				emit wptr->sendspace();
			}
			flag = false;
		}
		else
		{
			midiOutShortMsg(outhandle,0x90 + flip1);
			flag = true;
		}
		break;
	case MIM_LONGDATA: break;
	case MIM_ERROR: break;
	case MIM_LONGERROR: break;
	}
}
void AudioPlayer::getcomposeover()
{
	playText.clear();
	ui.textEdit->setHtml(ui.textEdit->toPlainText());
	ui.ComposeButton->setText(QString::fromLocal8Bit("开始谱曲"));
	playsign = false;
	QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("谱曲完成！"));
}
void AudioPlayer::getspace()
{
	sTime.push_back(nowtime-lasttime);
	lasttime = nowtime;
	int num = playText.length();
	QString text = playText.mid(num-4*playnumber,4);
	QString text1 = playText.mid(0,num-4*playnumber);
	QString text2 = playText.right(4*playnumber-4);
	ui.textEdit->setText(text1+"<span style='color:#33FF33;'>"+text+"</span>"+text2);
	QTextCursor cursor = ui.textEdit->textCursor();
	cursor.setPosition(num-4*(playnumber-1));
	ui.textEdit->setTextCursor(cursor);
	do_play_note(text);
	playnumber--;
}
void AudioPlayer::button1_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button1->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button2_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 1;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button2->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button3_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 2;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button3->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button4_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 3;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button4->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button5_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip =baseflip + 4;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button5->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button6_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 5;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button6->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button7_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 6;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button7->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button8_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 7;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button8->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button9_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 8;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button9->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button10_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 9;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button10->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button11_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 10;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button11->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button12_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 11;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button12->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button13_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 12;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button13->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button14_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 13;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button14->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button15_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 14;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button15->text());
	ui.textEdit->setFocus();
}

void AudioPlayer::button16_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 15;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button16->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button17_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 16;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button17->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button18_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip +17;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button18->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button19_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 18;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button19->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button20_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 19;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button20->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button21_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 20;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button21->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button22_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 21;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button22->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button23_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 22;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button23->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button24_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 23;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button24->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button25_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 24;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button25->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button26_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 25;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button26->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button27_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 26;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button27->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button28_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 27;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button28->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button29_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 28;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button29->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button30_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 29;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button30->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button31_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 30;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button31->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button32_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 31;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button32->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button33_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 32;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button33->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button34_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 33;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button34->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button35_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 34;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button35->text());
	ui.textEdit->setFocus();
}

void AudioPlayer::button36_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 35;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button36->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button37_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 36;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button37->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button38_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 37;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button38->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button39_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 38;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button39->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button40_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 39;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button40->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button41_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 40;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button41->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button42_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 41;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button42->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button43_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 42;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button43->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button44_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 43;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button44->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button45_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 44;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button45->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button46_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 45;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button46->text());
	ui.textEdit->setFocus();
}

void AudioPlayer::button47_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 46;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button47->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button48_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 47;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button48->text());
	ui.textEdit->setFocus();
}
void AudioPlayer::button49_pressed()
{
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(0*0x10000));
	flip = baseflip + 48;
	midiOutShortMsg(outhandle,0x90+(flip*0x100)+(volume*0x10000));
	ui.textEdit->insertPlainText(ui.button49->text());
	ui.textEdit->setFocus();
}
AudioPlayer::~AudioPlayer()
{
	midiInClose(inhandle);
	midiOutClose(outhandle);
	ImmAssociateContext(hWnd, hIMC);//恢复
	delete pitchthread;
}
