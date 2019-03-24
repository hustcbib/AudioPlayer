/********************************************************************************
** Form generated from reading UI file 'audioplayer.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUDIOPLAYER_H
#define UI_AUDIOPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AudioPlayerClass
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QPushButton *NumLock;
    QPushButton *button31;
    QPushButton *button45;
    QPushButton *button14;
    QPushButton *button59;
    QPushButton *button51;
    QPushButton *pushButton_50;
    QPushButton *button2;
    QPushButton *button19;
    QPushButton *button43;
    QPushButton *pushButton_30;
    QPushButton *button7;
    QPushButton *button33;
    QPushButton *button27;
    QPushButton *button63;
    QPushButton *pushButton;
    QPushButton *button41;
    QPushButton *button38;
    QPushButton *button60;
    QPushButton *button5;
    QPushButton *button36;
    QPushButton *button20;
    QPushButton *button6;
    QPushButton *button49;
    QPushButton *button46;
    QPushButton *button22;
    QPushButton *button47;
    QPushButton *button17;
    QPushButton *button1;
    QPushButton *button61;
    QPushButton *button50;
    QPushButton *button13;
    QPushButton *button11;
    QPushButton *button44;
    QPushButton *button8;
    QPushButton *button48;
    QPushButton *button32;
    QPushButton *button64;
    QPushButton *button26;
    QPushButton *button42;
    QPushButton *button39;
    QPushButton *pushButton_70;
    QPushButton *button57;
    QPushButton *button25;
    QPushButton *button10;
    QPushButton *button4;
    QPushButton *button35;
    QPushButton *Backspace;
    QPushButton *button30;
    QPushButton *button65;
    QPushButton *button62;
    QPushButton *button12;
    QPushButton *button58;
    QPushButton *button54;
    QPushButton *button16;
    QPushButton *button18;
    QPushButton *button28;
    QPushButton *button52;
    QPushButton *button21;
    QPushButton *button29;
    QPushButton *button56;
    QPushButton *button40;
    QPushButton *button37;
    QPushButton *button24;
    QPushButton *button55;
    QPushButton *button9;
    QPushButton *button23;
    QPushButton *button15;
    QPushButton *button34;
    QPushButton *button3;
    QPushButton *button53;
    QPushButton *RisingButton;
    QPushButton *FallingButton;
    QPushButton *MoveLeft;
    QPushButton *MoveRight;
    QPushButton *SpaceButon;
    QPushButton *button9_2;
    QPushButton *button9_3;
    QPushButton *button9_4;
    QPushButton *CtrlButton;
    QPushButton *CtrlButton2;
    QPushButton *button9_7;
    QPushButton *button9_8;
    QGroupBox *groupBox_2;
    QSlider *horizontalSlider;
    QComboBox *comboBox;
    QLabel *label;
    QPushButton *LoadButton;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_8;
    QPushButton *LoadSwing;
    QGroupBox *groupBox_3;
    QPushButton *ClearButton;
    QPushButton *SaveButton;
    QPushButton *ComposeButton;
    QPushButton *PlayButton;
    QSlider *horizontalSlider_2;
    QLabel *label_3;
    QPushButton *ConnectINDevice;
    QLabel *label_6;
    QPushButton *CirculationPlay;
    QPushButton *BeatPlay;
    QPushButton *ModiButton;
    QLabel *label_7;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *SaveSwing;
    QComboBox *comboBox_2;
    QPushButton *RhythmPlay;
    QPushButton *ModiRhythm;
    QTextEdit *textEdit;

    void setupUi(QMainWindow *AudioPlayerClass)
    {
        if (AudioPlayerClass->objectName().isEmpty())
            AudioPlayerClass->setObjectName(QString::fromUtf8("AudioPlayerClass"));
        AudioPlayerClass->setEnabled(true);
        AudioPlayerClass->resize(963, 610);
        QFont font;
        font.setPointSize(6);
        AudioPlayerClass->setFont(font);
        AudioPlayerClass->setFocusPolicy(Qt::StrongFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/AudioPlayer/icon/test2.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        AudioPlayerClass->setWindowIcon(icon);
        AudioPlayerClass->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(AudioPlayerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 370, 961, 231));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        groupBox->setFont(font1);
        groupBox->setFocusPolicy(Qt::StrongFocus);
        groupBox->setStyleSheet(QString::fromUtf8(""));
        NumLock = new QPushButton(groupBox);
        NumLock->setObjectName(QString::fromUtf8("NumLock"));
        NumLock->setEnabled(false);
        NumLock->setGeometry(QRect(820, 20, 40, 40));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(8);
        font2.setBold(true);
        font2.setWeight(75);
        NumLock->setFont(font2);
        NumLock->setFocusPolicy(Qt::NoFocus);
        NumLock->setStyleSheet(QString::fromUtf8(""));
        button31 = new QPushButton(groupBox);
        button31->setObjectName(QString::fromUtf8("button31"));
        button31->setEnabled(true);
        button31->setGeometry(QRect(354, 60, 40, 40));
        button31->setFont(font2);
        button31->setFocusPolicy(Qt::NoFocus);
        button31->setStyleSheet(QString::fromUtf8(""));
        button45 = new QPushButton(groupBox);
        button45->setObjectName(QString::fromUtf8("button45"));
        button45->setEnabled(true);
        button45->setGeometry(QRect(334, 20, 40, 40));
        button45->setFont(font2);
        button45->setFocusPolicy(Qt::NoFocus);
        button45->setStyleSheet(QString::fromUtf8(""));
        button14 = new QPushButton(groupBox);
        button14->setObjectName(QString::fromUtf8("button14"));
        button14->setEnabled(true);
        button14->setGeometry(QRect(164, 100, 40, 40));
        button14->setFont(font2);
        button14->setFocusPolicy(Qt::NoFocus);
        button14->setStyleSheet(QString::fromUtf8(""));
        button59 = new QPushButton(groupBox);
        button59->setObjectName(QString::fromUtf8("button59"));
        button59->setEnabled(true);
        button59->setGeometry(QRect(860, 60, 40, 40));
        button59->setFont(font2);
        button59->setFocusPolicy(Qt::NoFocus);
        button59->setStyleSheet(QString::fromUtf8(""));
        button51 = new QPushButton(groupBox);
        button51->setObjectName(QString::fromUtf8("button51"));
        button51->setEnabled(true);
        button51->setGeometry(QRect(700, 20, 40, 40));
        button51->setFont(font2);
        button51->setFocusPolicy(Qt::NoFocus);
        button51->setStyleSheet(QString::fromUtf8(""));
        pushButton_50 = new QPushButton(groupBox);
        pushButton_50->setObjectName(QString::fromUtf8("pushButton_50"));
        pushButton_50->setEnabled(false);
        pushButton_50->setGeometry(QRect(14, 100, 71, 40));
        pushButton_50->setFont(font2);
        pushButton_50->setFocusPolicy(Qt::NoFocus);
        pushButton_50->setStyleSheet(QString::fromUtf8(""));
        button2 = new QPushButton(groupBox);
        button2->setObjectName(QString::fromUtf8("button2"));
        button2->setEnabled(true);
        button2->setGeometry(QRect(154, 140, 40, 40));
        button2->setFont(font2);
        button2->setFocusPolicy(Qt::NoFocus);
        button2->setStyleSheet(QString::fromUtf8(""));
        button19 = new QPushButton(groupBox);
        button19->setObjectName(QString::fromUtf8("button19"));
        button19->setEnabled(true);
        button19->setGeometry(QRect(364, 100, 40, 40));
        button19->setFont(font2);
        button19->setFocusPolicy(Qt::NoFocus);
        button19->setStyleSheet(QString::fromUtf8(""));
        button43 = new QPushButton(groupBox);
        button43->setObjectName(QString::fromUtf8("button43"));
        button43->setEnabled(true);
        button43->setGeometry(QRect(254, 20, 40, 40));
        button43->setFont(font2);
        button43->setFocusPolicy(Qt::NoFocus);
        button43->setStyleSheet(QString::fromUtf8(""));
        pushButton_30 = new QPushButton(groupBox);
        pushButton_30->setObjectName(QString::fromUtf8("pushButton_30"));
        pushButton_30->setEnabled(false);
        pushButton_30->setGeometry(QRect(14, 60, 61, 40));
        pushButton_30->setFont(font2);
        pushButton_30->setFocusPolicy(Qt::NoFocus);
        pushButton_30->setStyleSheet(QString::fromUtf8(""));
        button7 = new QPushButton(groupBox);
        button7->setObjectName(QString::fromUtf8("button7"));
        button7->setEnabled(true);
        button7->setGeometry(QRect(354, 140, 40, 40));
        button7->setFont(font2);
        button7->setFocusPolicy(Qt::NoFocus);
        button7->setStyleSheet(QString::fromUtf8(""));
        button33 = new QPushButton(groupBox);
        button33->setObjectName(QString::fromUtf8("button33"));
        button33->setEnabled(true);
        button33->setGeometry(QRect(434, 60, 40, 40));
        button33->setFont(font2);
        button33->setFocusPolicy(Qt::NoFocus);
        button33->setStyleSheet(QString::fromUtf8(""));
        button27 = new QPushButton(groupBox);
        button27->setObjectName(QString::fromUtf8("button27"));
        button27->setEnabled(true);
        button27->setGeometry(QRect(194, 60, 40, 40));
        button27->setFont(font2);
        button27->setFocusPolicy(Qt::NoFocus);
        button27->setStyleSheet(QString::fromUtf8(""));
        button63 = new QPushButton(groupBox);
        button63->setObjectName(QString::fromUtf8("button63"));
        button63->setEnabled(true);
        button63->setGeometry(QRect(820, 140, 40, 40));
        button63->setFont(font2);
        button63->setFocusPolicy(Qt::NoFocus);
        button63->setStyleSheet(QString::fromUtf8(""));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(false);
        pushButton->setGeometry(QRect(900, 100, 40, 40));
        pushButton->setFont(font2);
        pushButton->setFocusPolicy(Qt::NoFocus);
        pushButton->setStyleSheet(QString::fromUtf8(""));
        button41 = new QPushButton(groupBox);
        button41->setObjectName(QString::fromUtf8("button41"));
        button41->setEnabled(true);
        button41->setGeometry(QRect(174, 20, 40, 40));
        button41->setFont(font2);
        button41->setFocusPolicy(Qt::NoFocus);
        button41->setStyleSheet(QString::fromUtf8(""));
        button38 = new QPushButton(groupBox);
        button38->setObjectName(QString::fromUtf8("button38"));
        button38->setEnabled(true);
        button38->setGeometry(QRect(54, 20, 40, 40));
        button38->setFont(font2);
        button38->setFocusPolicy(Qt::NoFocus);
        button38->setStyleSheet(QString::fromUtf8(""));
        button60 = new QPushButton(groupBox);
        button60->setObjectName(QString::fromUtf8("button60"));
        button60->setEnabled(true);
        button60->setGeometry(QRect(900, 60, 40, 40));
        button60->setFont(font2);
        button60->setFocusPolicy(Qt::NoFocus);
        button60->setStyleSheet(QString::fromUtf8(""));
        button5 = new QPushButton(groupBox);
        button5->setObjectName(QString::fromUtf8("button5"));
        button5->setEnabled(true);
        button5->setGeometry(QRect(274, 140, 40, 40));
        button5->setFont(font2);
        button5->setFocusPolicy(Qt::NoFocus);
        button5->setStyleSheet(QString::fromUtf8(""));
        button36 = new QPushButton(groupBox);
        button36->setObjectName(QString::fromUtf8("button36"));
        button36->setEnabled(true);
        button36->setGeometry(QRect(554, 60, 61, 40));
        button36->setFont(font2);
        button36->setFocusPolicy(Qt::NoFocus);
        button36->setStyleSheet(QString::fromUtf8(""));
        button20 = new QPushButton(groupBox);
        button20->setObjectName(QString::fromUtf8("button20"));
        button20->setEnabled(true);
        button20->setGeometry(QRect(404, 100, 40, 40));
        button20->setFont(font2);
        button20->setFocusPolicy(Qt::NoFocus);
        button20->setStyleSheet(QString::fromUtf8(""));
        button6 = new QPushButton(groupBox);
        button6->setObjectName(QString::fromUtf8("button6"));
        button6->setEnabled(true);
        button6->setGeometry(QRect(314, 140, 40, 40));
        button6->setFont(font2);
        button6->setFocusPolicy(Qt::NoFocus);
        button6->setStyleSheet(QString::fromUtf8(""));
        button49 = new QPushButton(groupBox);
        button49->setObjectName(QString::fromUtf8("button49"));
        button49->setEnabled(true);
        button49->setGeometry(QRect(494, 20, 40, 40));
        button49->setFont(font2);
        button49->setFocusPolicy(Qt::NoFocus);
        button49->setStyleSheet(QString::fromUtf8(""));
        button46 = new QPushButton(groupBox);
        button46->setObjectName(QString::fromUtf8("button46"));
        button46->setEnabled(true);
        button46->setGeometry(QRect(374, 20, 40, 40));
        button46->setFont(font2);
        button46->setFocusPolicy(Qt::NoFocus);
        button46->setStyleSheet(QString::fromUtf8(""));
        button22 = new QPushButton(groupBox);
        button22->setObjectName(QString::fromUtf8("button22"));
        button22->setEnabled(true);
        button22->setGeometry(QRect(484, 100, 40, 40));
        button22->setFont(font2);
        button22->setFocusPolicy(Qt::NoFocus);
        button22->setStyleSheet(QString::fromUtf8(""));
        button47 = new QPushButton(groupBox);
        button47->setObjectName(QString::fromUtf8("button47"));
        button47->setEnabled(true);
        button47->setGeometry(QRect(414, 20, 40, 40));
        button47->setFont(font2);
        button47->setFocusPolicy(Qt::NoFocus);
        button47->setStyleSheet(QString::fromUtf8(""));
        button17 = new QPushButton(groupBox);
        button17->setObjectName(QString::fromUtf8("button17"));
        button17->setEnabled(true);
        button17->setGeometry(QRect(284, 100, 40, 40));
        button17->setFont(font2);
        button17->setFocusPolicy(Qt::NoFocus);
        button17->setStyleSheet(QString::fromUtf8(""));
        button1 = new QPushButton(groupBox);
        button1->setObjectName(QString::fromUtf8("button1"));
        button1->setEnabled(true);
        button1->setGeometry(QRect(114, 140, 40, 40));
        button1->setFont(font2);
        button1->setFocusPolicy(Qt::NoFocus);
        button1->setContextMenuPolicy(Qt::NoContextMenu);
        button1->setAcceptDrops(false);
        button1->setStyleSheet(QString::fromUtf8(""));
        button61 = new QPushButton(groupBox);
        button61->setObjectName(QString::fromUtf8("button61"));
        button61->setEnabled(true);
        button61->setGeometry(QRect(820, 100, 40, 40));
        button61->setFont(font2);
        button61->setFocusPolicy(Qt::NoFocus);
        button61->setStyleSheet(QString::fromUtf8(""));
        button50 = new QPushButton(groupBox);
        button50->setObjectName(QString::fromUtf8("button50"));
        button50->setEnabled(true);
        button50->setGeometry(QRect(660, 20, 40, 40));
        button50->setFont(font2);
        button50->setFocusPolicy(Qt::NoFocus);
        button50->setStyleSheet(QString::fromUtf8(""));
        button13 = new QPushButton(groupBox);
        button13->setObjectName(QString::fromUtf8("button13"));
        button13->setEnabled(true);
        button13->setGeometry(QRect(124, 100, 40, 40));
        button13->setFont(font2);
        button13->setFocusPolicy(Qt::NoFocus);
        button13->setStyleSheet(QString::fromUtf8(""));
        button11 = new QPushButton(groupBox);
        button11->setObjectName(QString::fromUtf8("button11"));
        button11->setEnabled(true);
        button11->setGeometry(QRect(513, 140, 101, 40));
        button11->setFont(font2);
        button11->setFocusPolicy(Qt::NoFocus);
        button11->setStyleSheet(QString::fromUtf8(""));
        button44 = new QPushButton(groupBox);
        button44->setObjectName(QString::fromUtf8("button44"));
        button44->setEnabled(true);
        button44->setGeometry(QRect(294, 20, 40, 40));
        button44->setFont(font2);
        button44->setFocusPolicy(Qt::NoFocus);
        button44->setStyleSheet(QString::fromUtf8(""));
        button8 = new QPushButton(groupBox);
        button8->setObjectName(QString::fromUtf8("button8"));
        button8->setEnabled(true);
        button8->setGeometry(QRect(394, 140, 40, 40));
        button8->setFont(font2);
        button8->setFocusPolicy(Qt::NoFocus);
        button8->setStyleSheet(QString::fromUtf8(""));
        button48 = new QPushButton(groupBox);
        button48->setObjectName(QString::fromUtf8("button48"));
        button48->setEnabled(true);
        button48->setGeometry(QRect(454, 20, 40, 40));
        button48->setFont(font2);
        button48->setFocusPolicy(Qt::NoFocus);
        button48->setStyleSheet(QString::fromUtf8(""));
        button32 = new QPushButton(groupBox);
        button32->setObjectName(QString::fromUtf8("button32"));
        button32->setEnabled(true);
        button32->setGeometry(QRect(394, 60, 40, 40));
        button32->setFont(font2);
        button32->setFocusPolicy(Qt::NoFocus);
        button32->setStyleSheet(QString::fromUtf8(""));
        button64 = new QPushButton(groupBox);
        button64->setObjectName(QString::fromUtf8("button64"));
        button64->setEnabled(true);
        button64->setGeometry(QRect(860, 140, 40, 40));
        button64->setFont(font2);
        button64->setFocusPolicy(Qt::NoFocus);
        button64->setStyleSheet(QString::fromUtf8(""));
        button26 = new QPushButton(groupBox);
        button26->setObjectName(QString::fromUtf8("button26"));
        button26->setEnabled(true);
        button26->setGeometry(QRect(154, 60, 40, 40));
        button26->setFont(font2);
        button26->setFocusPolicy(Qt::NoFocus);
        button26->setStyleSheet(QString::fromUtf8(""));
        button42 = new QPushButton(groupBox);
        button42->setObjectName(QString::fromUtf8("button42"));
        button42->setEnabled(true);
        button42->setGeometry(QRect(214, 20, 40, 40));
        button42->setFont(font2);
        button42->setFocusPolicy(Qt::NoFocus);
        button42->setStyleSheet(QString::fromUtf8(""));
        button39 = new QPushButton(groupBox);
        button39->setObjectName(QString::fromUtf8("button39"));
        button39->setEnabled(true);
        button39->setGeometry(QRect(94, 20, 40, 40));
        button39->setFont(font2);
        button39->setFocusPolicy(Qt::NoFocus);
        button39->setStyleSheet(QString::fromUtf8(""));
        pushButton_70 = new QPushButton(groupBox);
        pushButton_70->setObjectName(QString::fromUtf8("pushButton_70"));
        pushButton_70->setEnabled(false);
        pushButton_70->setGeometry(QRect(14, 140, 101, 40));
        pushButton_70->setFont(font2);
        pushButton_70->setFocusPolicy(Qt::NoFocus);
        pushButton_70->setStyleSheet(QString::fromUtf8(""));
        button57 = new QPushButton(groupBox);
        button57->setObjectName(QString::fromUtf8("button57"));
        button57->setEnabled(true);
        button57->setGeometry(QRect(740, 60, 40, 40));
        button57->setFont(font2);
        button57->setFocusPolicy(Qt::NoFocus);
        button57->setStyleSheet(QString::fromUtf8(""));
        button25 = new QPushButton(groupBox);
        button25->setObjectName(QString::fromUtf8("button25"));
        button25->setEnabled(true);
        button25->setGeometry(QRect(114, 60, 40, 40));
        button25->setFont(font2);
        button25->setFocusPolicy(Qt::NoFocus);
        button25->setStyleSheet(QString::fromUtf8(""));
        button10 = new QPushButton(groupBox);
        button10->setObjectName(QString::fromUtf8("button10"));
        button10->setEnabled(true);
        button10->setGeometry(QRect(474, 140, 40, 40));
        button10->setFont(font2);
        button10->setFocusPolicy(Qt::NoFocus);
        button10->setStyleSheet(QString::fromUtf8(""));
        button4 = new QPushButton(groupBox);
        button4->setObjectName(QString::fromUtf8("button4"));
        button4->setEnabled(true);
        button4->setGeometry(QRect(234, 140, 40, 40));
        button4->setFont(font2);
        button4->setFocusPolicy(Qt::NoFocus);
        button4->setStyleSheet(QString::fromUtf8(""));
        button35 = new QPushButton(groupBox);
        button35->setObjectName(QString::fromUtf8("button35"));
        button35->setEnabled(true);
        button35->setGeometry(QRect(514, 60, 40, 40));
        button35->setFont(font2);
        button35->setFocusPolicy(Qt::NoFocus);
        button35->setStyleSheet(QString::fromUtf8(""));
        Backspace = new QPushButton(groupBox);
        Backspace->setObjectName(QString::fromUtf8("Backspace"));
        Backspace->setEnabled(true);
        Backspace->setGeometry(QRect(534, 20, 81, 40));
        Backspace->setFont(font2);
        Backspace->setFocusPolicy(Qt::NoFocus);
        Backspace->setStyleSheet(QString::fromUtf8(""));
        button30 = new QPushButton(groupBox);
        button30->setObjectName(QString::fromUtf8("button30"));
        button30->setEnabled(true);
        button30->setGeometry(QRect(314, 60, 40, 40));
        button30->setFont(font2);
        button30->setFocusPolicy(Qt::NoFocus);
        button30->setStyleSheet(QString::fromUtf8(""));
        button65 = new QPushButton(groupBox);
        button65->setObjectName(QString::fromUtf8("button65"));
        button65->setEnabled(true);
        button65->setGeometry(QRect(900, 140, 40, 40));
        button65->setFont(font2);
        button65->setFocusPolicy(Qt::NoFocus);
        button65->setStyleSheet(QString::fromUtf8(""));
        button62 = new QPushButton(groupBox);
        button62->setObjectName(QString::fromUtf8("button62"));
        button62->setEnabled(true);
        button62->setGeometry(QRect(860, 100, 40, 40));
        button62->setFont(font2);
        button62->setFocusPolicy(Qt::NoFocus);
        button62->setStyleSheet(QString::fromUtf8(""));
        button12 = new QPushButton(groupBox);
        button12->setObjectName(QString::fromUtf8("button12"));
        button12->setEnabled(true);
        button12->setGeometry(QRect(84, 100, 40, 40));
        button12->setFont(font2);
        button12->setFocusPolicy(Qt::NoFocus);
        button12->setStyleSheet(QString::fromUtf8(""));
        button58 = new QPushButton(groupBox);
        button58->setObjectName(QString::fromUtf8("button58"));
        button58->setEnabled(true);
        button58->setGeometry(QRect(820, 60, 40, 40));
        button58->setFont(font2);
        button58->setFocusPolicy(Qt::NoFocus);
        button58->setStyleSheet(QString::fromUtf8(""));
        button54 = new QPushButton(groupBox);
        button54->setObjectName(QString::fromUtf8("button54"));
        button54->setEnabled(true);
        button54->setGeometry(QRect(900, 20, 40, 40));
        button54->setFont(font2);
        button54->setFocusPolicy(Qt::NoFocus);
        button54->setStyleSheet(QString::fromUtf8(""));
        button16 = new QPushButton(groupBox);
        button16->setObjectName(QString::fromUtf8("button16"));
        button16->setEnabled(true);
        button16->setGeometry(QRect(244, 100, 40, 40));
        button16->setFont(font2);
        button16->setFocusPolicy(Qt::NoFocus);
        button16->setStyleSheet(QString::fromUtf8(""));
        button18 = new QPushButton(groupBox);
        button18->setObjectName(QString::fromUtf8("button18"));
        button18->setEnabled(true);
        button18->setGeometry(QRect(324, 100, 40, 40));
        button18->setFont(font2);
        button18->setFocusPolicy(Qt::NoFocus);
        button18->setStyleSheet(QString::fromUtf8(""));
        button28 = new QPushButton(groupBox);
        button28->setObjectName(QString::fromUtf8("button28"));
        button28->setEnabled(true);
        button28->setGeometry(QRect(234, 60, 40, 40));
        button28->setFont(font2);
        button28->setFocusPolicy(Qt::NoFocus);
        button28->setStyleSheet(QString::fromUtf8(""));
        button52 = new QPushButton(groupBox);
        button52->setObjectName(QString::fromUtf8("button52"));
        button52->setEnabled(true);
        button52->setGeometry(QRect(740, 20, 40, 40));
        button52->setFont(font2);
        button52->setFocusPolicy(Qt::NoFocus);
        button52->setStyleSheet(QString::fromUtf8(""));
        button21 = new QPushButton(groupBox);
        button21->setObjectName(QString::fromUtf8("button21"));
        button21->setEnabled(true);
        button21->setGeometry(QRect(444, 100, 40, 40));
        button21->setFont(font2);
        button21->setFocusPolicy(Qt::NoFocus);
        button21->setStyleSheet(QString::fromUtf8(""));
        button29 = new QPushButton(groupBox);
        button29->setObjectName(QString::fromUtf8("button29"));
        button29->setEnabled(true);
        button29->setGeometry(QRect(274, 60, 40, 40));
        button29->setFont(font2);
        button29->setFocusPolicy(Qt::NoFocus);
        button29->setStyleSheet(QString::fromUtf8(""));
        button56 = new QPushButton(groupBox);
        button56->setObjectName(QString::fromUtf8("button56"));
        button56->setEnabled(true);
        button56->setGeometry(QRect(700, 60, 40, 40));
        button56->setFont(font2);
        button56->setFocusPolicy(Qt::NoFocus);
        button56->setStyleSheet(QString::fromUtf8(""));
        button40 = new QPushButton(groupBox);
        button40->setObjectName(QString::fromUtf8("button40"));
        button40->setEnabled(true);
        button40->setGeometry(QRect(134, 20, 40, 40));
        button40->setFont(font2);
        button40->setFocusPolicy(Qt::NoFocus);
        button40->setStyleSheet(QString::fromUtf8(""));
        button37 = new QPushButton(groupBox);
        button37->setObjectName(QString::fromUtf8("button37"));
        button37->setEnabled(true);
        button37->setGeometry(QRect(14, 20, 40, 40));
        button37->setFont(font2);
        button37->setFocusPolicy(Qt::NoFocus);
        button37->setAcceptDrops(false);
        button37->setStyleSheet(QString::fromUtf8(""));
        button24 = new QPushButton(groupBox);
        button24->setObjectName(QString::fromUtf8("button24"));
        button24->setEnabled(true);
        button24->setGeometry(QRect(74, 60, 40, 40));
        button24->setFont(font2);
        button24->setFocusPolicy(Qt::NoFocus);
        button24->setStyleSheet(QString::fromUtf8(""));
        button55 = new QPushButton(groupBox);
        button55->setObjectName(QString::fromUtf8("button55"));
        button55->setEnabled(true);
        button55->setGeometry(QRect(660, 60, 40, 40));
        button55->setFont(font2);
        button55->setFocusPolicy(Qt::NoFocus);
        button55->setStyleSheet(QString::fromUtf8(""));
        button9 = new QPushButton(groupBox);
        button9->setObjectName(QString::fromUtf8("button9"));
        button9->setEnabled(true);
        button9->setGeometry(QRect(434, 140, 40, 40));
        button9->setFont(font2);
        button9->setFocusPolicy(Qt::NoFocus);
        button9->setStyleSheet(QString::fromUtf8(""));
        button23 = new QPushButton(groupBox);
        button23->setObjectName(QString::fromUtf8("button23"));
        button23->setEnabled(true);
        button23->setGeometry(QRect(524, 100, 91, 40));
        button23->setFont(font2);
        button23->setFocusPolicy(Qt::NoFocus);
        button23->setStyleSheet(QString::fromUtf8(""));
        button15 = new QPushButton(groupBox);
        button15->setObjectName(QString::fromUtf8("button15"));
        button15->setEnabled(true);
        button15->setGeometry(QRect(204, 100, 40, 40));
        button15->setFont(font2);
        button15->setFocusPolicy(Qt::NoFocus);
        button15->setStyleSheet(QString::fromUtf8(""));
        button34 = new QPushButton(groupBox);
        button34->setObjectName(QString::fromUtf8("button34"));
        button34->setEnabled(true);
        button34->setGeometry(QRect(474, 60, 40, 40));
        button34->setFont(font2);
        button34->setFocusPolicy(Qt::NoFocus);
        button34->setStyleSheet(QString::fromUtf8(""));
        button3 = new QPushButton(groupBox);
        button3->setObjectName(QString::fromUtf8("button3"));
        button3->setEnabled(true);
        button3->setGeometry(QRect(194, 140, 40, 40));
        button3->setFont(font2);
        button3->setFocusPolicy(Qt::NoFocus);
        button3->setStyleSheet(QString::fromUtf8(""));
        button53 = new QPushButton(groupBox);
        button53->setObjectName(QString::fromUtf8("button53"));
        button53->setEnabled(true);
        button53->setGeometry(QRect(860, 20, 40, 40));
        button53->setFont(font2);
        button53->setFocusPolicy(Qt::NoFocus);
        button53->setStyleSheet(QString::fromUtf8(""));
        RisingButton = new QPushButton(groupBox);
        RisingButton->setObjectName(QString::fromUtf8("RisingButton"));
        RisingButton->setGeometry(QRect(700, 140, 40, 40));
        RisingButton->setFont(font2);
        RisingButton->setFocusPolicy(Qt::NoFocus);
        RisingButton->setStyleSheet(QString::fromUtf8(""));
        FallingButton = new QPushButton(groupBox);
        FallingButton->setObjectName(QString::fromUtf8("FallingButton"));
        FallingButton->setGeometry(QRect(700, 180, 40, 40));
        FallingButton->setFont(font2);
        FallingButton->setFocusPolicy(Qt::NoFocus);
        FallingButton->setStyleSheet(QString::fromUtf8(""));
        MoveLeft = new QPushButton(groupBox);
        MoveLeft->setObjectName(QString::fromUtf8("MoveLeft"));
        MoveLeft->setGeometry(QRect(660, 180, 40, 40));
        MoveLeft->setFont(font2);
        MoveLeft->setFocusPolicy(Qt::NoFocus);
        MoveLeft->setStyleSheet(QString::fromUtf8(""));
        MoveRight = new QPushButton(groupBox);
        MoveRight->setObjectName(QString::fromUtf8("MoveRight"));
        MoveRight->setGeometry(QRect(740, 180, 40, 40));
        MoveRight->setFont(font2);
        MoveRight->setFocusPolicy(Qt::NoFocus);
        MoveRight->setStyleSheet(QString::fromUtf8(""));
        SpaceButon = new QPushButton(groupBox);
        SpaceButon->setObjectName(QString::fromUtf8("SpaceButon"));
        SpaceButon->setGeometry(QRect(158, 180, 264, 40));
        SpaceButon->setFont(font2);
        SpaceButon->setFocusPolicy(Qt::NoFocus);
        SpaceButon->setStyleSheet(QString::fromUtf8(""));
        button9_2 = new QPushButton(groupBox);
        button9_2->setObjectName(QString::fromUtf8("button9_2"));
        button9_2->setEnabled(false);
        button9_2->setGeometry(QRect(425, 180, 45, 40));
        button9_2->setFont(font2);
        button9_2->setFocusPolicy(Qt::NoFocus);
        button9_2->setStyleSheet(QString::fromUtf8(""));
        button9_3 = new QPushButton(groupBox);
        button9_3->setObjectName(QString::fromUtf8("button9_3"));
        button9_3->setEnabled(false);
        button9_3->setGeometry(QRect(473, 180, 45, 40));
        button9_3->setFont(font2);
        button9_3->setFocusPolicy(Qt::NoFocus);
        button9_3->setStyleSheet(QString::fromUtf8(""));
        button9_4 = new QPushButton(groupBox);
        button9_4->setObjectName(QString::fromUtf8("button9_4"));
        button9_4->setEnabled(false);
        button9_4->setGeometry(QRect(521, 180, 45, 40));
        button9_4->setFont(font2);
        button9_4->setFocusPolicy(Qt::NoFocus);
        button9_4->setStyleSheet(QString::fromUtf8(""));
        CtrlButton = new QPushButton(groupBox);
        CtrlButton->setObjectName(QString::fromUtf8("CtrlButton"));
        CtrlButton->setEnabled(true);
        CtrlButton->setGeometry(QRect(569, 180, 45, 40));
        CtrlButton->setFont(font2);
        CtrlButton->setFocusPolicy(Qt::NoFocus);
        CtrlButton->setStyleSheet(QString::fromUtf8(""));
        CtrlButton2 = new QPushButton(groupBox);
        CtrlButton2->setObjectName(QString::fromUtf8("CtrlButton2"));
        CtrlButton2->setEnabled(true);
        CtrlButton2->setGeometry(QRect(14, 180, 45, 40));
        CtrlButton2->setFont(font2);
        CtrlButton2->setFocusPolicy(Qt::NoFocus);
        CtrlButton2->setStyleSheet(QString::fromUtf8(""));
        button9_7 = new QPushButton(groupBox);
        button9_7->setObjectName(QString::fromUtf8("button9_7"));
        button9_7->setEnabled(false);
        button9_7->setGeometry(QRect(110, 180, 45, 40));
        button9_7->setFont(font2);
        button9_7->setFocusPolicy(Qt::NoFocus);
        button9_7->setStyleSheet(QString::fromUtf8(""));
        button9_8 = new QPushButton(groupBox);
        button9_8->setObjectName(QString::fromUtf8("button9_8"));
        button9_8->setEnabled(false);
        button9_8->setGeometry(QRect(62, 180, 45, 40));
        button9_8->setFont(font2);
        button9_8->setFocusPolicy(Qt::NoFocus);
        button9_8->setStyleSheet(QString::fromUtf8(""));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(590, 0, 371, 161));
        groupBox_2->setFont(font1);
        groupBox_2->setFocusPolicy(Qt::StrongFocus);
        groupBox_2->setStyleSheet(QString::fromUtf8(""));
        horizontalSlider = new QSlider(groupBox_2);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(90, 20, 211, 20));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font3.setPointSize(8);
        font3.setBold(false);
        font3.setWeight(50);
        horizontalSlider->setFont(font3);
        horizontalSlider->setFocusPolicy(Qt::NoFocus);
        horizontalSlider->setStyleSheet(QString::fromUtf8(""));
        horizontalSlider->setOrientation(Qt::Horizontal);
        comboBox = new QComboBox(groupBox_2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(20, 50, 341, 22));
        comboBox->setFont(font2);
        comboBox->setFocusPolicy(Qt::NoFocus);
        comboBox->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 71, 20));
        label->setFont(font2);
        label->setFocusPolicy(Qt::StrongFocus);
        label->setStyleSheet(QString::fromUtf8(""));
        LoadButton = new QPushButton(groupBox_2);
        LoadButton->setObjectName(QString::fromUtf8("LoadButton"));
        LoadButton->setGeometry(QRect(20, 90, 81, 23));
        LoadButton->setFont(font2);
        LoadButton->setFocusPolicy(Qt::NoFocus);
        LoadButton->setStyleSheet(QString::fromUtf8("border:2px groove gray;border-radius:10px;padding:2px 4px;"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 90, 231, 21));
        label_2->setFont(font3);
        label_2->setFocusPolicy(Qt::StrongFocus);
        label_2->setStyleSheet(QString::fromUtf8(""));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(310, 20, 31, 16));
        label_5->setFont(font3);
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(120, 130, 231, 21));
        label_8->setFont(font3);
        label_8->setFocusPolicy(Qt::StrongFocus);
        label_8->setStyleSheet(QString::fromUtf8(""));
        LoadSwing = new QPushButton(groupBox_2);
        LoadSwing->setObjectName(QString::fromUtf8("LoadSwing"));
        LoadSwing->setGeometry(QRect(20, 130, 81, 23));
        LoadSwing->setFont(font2);
        LoadSwing->setFocusPolicy(Qt::NoFocus);
        LoadSwing->setStyleSheet(QString::fromUtf8("border:2px groove gray;border-radius:10px;padding:2px 4px;"));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(590, 160, 371, 211));
        groupBox_3->setFont(font1);
        groupBox_3->setFocusPolicy(Qt::StrongFocus);
        groupBox_3->setStyleSheet(QString::fromUtf8(""));
        ClearButton = new QPushButton(groupBox_3);
        ClearButton->setObjectName(QString::fromUtf8("ClearButton"));
        ClearButton->setGeometry(QRect(20, 110, 75, 23));
        ClearButton->setFont(font2);
        ClearButton->setFocusPolicy(Qt::NoFocus);
        ClearButton->setStyleSheet(QString::fromUtf8("border:2px groove gray;border-radius:10px;padding:2px 4px;"));
        SaveButton = new QPushButton(groupBox_3);
        SaveButton->setObjectName(QString::fromUtf8("SaveButton"));
        SaveButton->setGeometry(QRect(110, 30, 81, 23));
        SaveButton->setFont(font2);
        SaveButton->setFocusPolicy(Qt::NoFocus);
        SaveButton->setStyleSheet(QString::fromUtf8("border:2px groove gray;border-radius:10px;padding:2px 4px;"));
        ComposeButton = new QPushButton(groupBox_3);
        ComposeButton->setObjectName(QString::fromUtf8("ComposeButton"));
        ComposeButton->setGeometry(QRect(20, 30, 75, 23));
        ComposeButton->setFont(font2);
        ComposeButton->setFocusPolicy(Qt::NoFocus);
        ComposeButton->setStyleSheet(QString::fromUtf8("border:2px groove gray;border-radius:10px;padding:2px 4px;"));
        PlayButton = new QPushButton(groupBox_3);
        PlayButton->setObjectName(QString::fromUtf8("PlayButton"));
        PlayButton->setGeometry(QRect(20, 70, 75, 23));
        PlayButton->setFont(font2);
        PlayButton->setFocusPolicy(Qt::NoFocus);
        PlayButton->setStyleSheet(QString::fromUtf8("border:2px groove gray;border-radius:10px;padding:2px 4px;"));
        horizontalSlider_2 = new QSlider(groupBox_3);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(130, 140, 160, 19));
        horizontalSlider_2->setFont(font3);
        horizontalSlider_2->setFocusPolicy(Qt::NoFocus);
        horizontalSlider_2->setStyleSheet(QString::fromUtf8(""));
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 140, 111, 20));
        label_3->setFont(font2);
        label_3->setFocusPolicy(Qt::StrongFocus);
        label_3->setStyleSheet(QString::fromUtf8(""));
        ConnectINDevice = new QPushButton(groupBox_3);
        ConnectINDevice->setObjectName(QString::fromUtf8("ConnectINDevice"));
        ConnectINDevice->setGeometry(QRect(200, 30, 121, 23));
        ConnectINDevice->setFont(font2);
        ConnectINDevice->setStyleSheet(QString::fromUtf8("border:2px groove gray;border-radius:10px;padding:2px 4px;"));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(300, 140, 31, 16));
        label_6->setFont(font2);
        CirculationPlay = new QPushButton(groupBox_3);
        CirculationPlay->setObjectName(QString::fromUtf8("CirculationPlay"));
        CirculationPlay->setGeometry(QRect(110, 70, 81, 23));
        CirculationPlay->setFont(font2);
        CirculationPlay->setStyleSheet(QString::fromUtf8("border:2px groove gray;border-radius:10px;padding:2px 4px;"));
        BeatPlay = new QPushButton(groupBox_3);
        BeatPlay->setObjectName(QString::fromUtf8("BeatPlay"));
        BeatPlay->setGeometry(QRect(200, 70, 75, 23));
        BeatPlay->setFont(font2);
        BeatPlay->setStyleSheet(QString::fromUtf8("border:2px groove gray;border-radius:10px;padding:2px 4px;"));
        ModiButton = new QPushButton(groupBox_3);
        ModiButton->setObjectName(QString::fromUtf8("ModiButton"));
        ModiButton->setGeometry(QRect(200, 110, 75, 23));
        ModiButton->setFont(font2);
        ModiButton->setStyleSheet(QString::fromUtf8("border:2px groove gray;border-radius:10px;padding:2px 4px;"));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(190, 170, 51, 21));
        label_7->setFont(font2);
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 170, 71, 20));
        label_4->setFont(font2);
        label_4->setFocusPolicy(Qt::StrongFocus);
        label_4->setStyleSheet(QString::fromUtf8(""));
        doubleSpinBox = new QDoubleSpinBox(groupBox_3);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(80, 170, 62, 22));
        QFont font4;
        font4.setPointSize(8);
        font4.setBold(true);
        font4.setWeight(75);
        doubleSpinBox->setFont(font4);
        SaveSwing = new QPushButton(groupBox_3);
        SaveSwing->setObjectName(QString::fromUtf8("SaveSwing"));
        SaveSwing->setGeometry(QRect(110, 110, 81, 23));
        SaveSwing->setFont(font2);
        SaveSwing->setFocusPolicy(Qt::NoFocus);
        SaveSwing->setStyleSheet(QString::fromUtf8("border:2px groove gray;border-radius:10px;padding:2px 4px;"));
        comboBox_2 = new QComboBox(groupBox_3);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(230, 170, 69, 22));
        comboBox_2->setFont(font2);
        RhythmPlay = new QPushButton(groupBox_3);
        RhythmPlay->setObjectName(QString::fromUtf8("RhythmPlay"));
        RhythmPlay->setGeometry(QRect(290, 70, 75, 23));
        RhythmPlay->setFont(font2);
        RhythmPlay->setStyleSheet(QString::fromUtf8("border:2px groove gray;border-radius:10px;padding:2px 4px;"));
        ModiRhythm = new QPushButton(groupBox_3);
        ModiRhythm->setObjectName(QString::fromUtf8("ModiRhythm"));
        ModiRhythm->setGeometry(QRect(290, 110, 75, 23));
        ModiRhythm->setFont(font2);
        ModiRhythm->setStyleSheet(QString::fromUtf8("border:2px groove gray;border-radius:10px;padding:2px 4px;"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(0, 0, 591, 371));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font5.setPointSize(16);
        font5.setBold(true);
        font5.setWeight(75);
        textEdit->setFont(font5);
        textEdit->setFocusPolicy(Qt::ClickFocus);
        textEdit->setStyleSheet(QString::fromUtf8(""));
        AudioPlayerClass->setCentralWidget(centralWidget);

        retranslateUi(AudioPlayerClass);

        QMetaObject::connectSlotsByName(AudioPlayerClass);
    } // setupUi

    //void retranslateUi(QMainWindow *AudioPlayerClass)
    //{
    //    AudioPlayerClass->setWindowTitle(QApplication::translate("AudioPlayerClass", "AudioPlayer", 0, QApplication::UnicodeUTF8));
    //    groupBox->setTitle(QApplication::translate("AudioPlayerClass", "\351\224\256\347\233\230", 0));
    //    NumLock->setText(QApplication::translate("AudioPlayerClass", "Lock", 0, QApplication::UnicodeUTF8));
    //    button31->setText(QApplication::translate("AudioPlayerClass", "F#4 ", 0, QApplication::UnicodeUTF8));
    //    button45->setText(QApplication::translate("AudioPlayerClass", "G#5 ", 0, QApplication::UnicodeUTF8));
    //    button14->setText(QApplication::translate("AudioPlayerClass", "C#3 ", 0, QApplication::UnicodeUTF8));
    //    button59->setText(QApplication::translate("AudioPlayerClass", "E_5 ", 0, QApplication::UnicodeUTF8));
    //    button51->setText(QApplication::translate("AudioPlayerClass", "A_5 ", 0, QApplication::UnicodeUTF8));
    //    pushButton_50->setText(QApplication::translate("AudioPlayerClass", "Caps Lock", 0, QApplication::UnicodeUTF8));
    //    button2->setText(QApplication::translate("AudioPlayerClass", "C#2 ", 0, QApplication::UnicodeUTF8));
    //    button19->setText(QApplication::translate("AudioPlayerClass", "F#3 ", 0, QApplication::UnicodeUTF8));
    //    button43->setText(QApplication::translate("AudioPlayerClass", "F#5 ", 0, QApplication::UnicodeUTF8));
    //    pushButton_30->setText(QApplication::translate("AudioPlayerClass", "Tab", 0, QApplication::UnicodeUTF8));
    //    button7->setText(QApplication::translate("AudioPlayerClass", "F#2 ", 0, QApplication::UnicodeUTF8));
    //    button33->setText(QApplication::translate("AudioPlayerClass", "G#4 ", 0, QApplication::UnicodeUTF8));
    //    button27->setText(QApplication::translate("AudioPlayerClass", "D_4 ", 0, QApplication::UnicodeUTF8));
    //    button63->setText(QApplication::translate("AudioPlayerClass", "B_2 ", 0, QApplication::UnicodeUTF8));
    //    pushButton->setText(QApplication::translate("AudioPlayerClass", "6", 0, QApplication::UnicodeUTF8));
    //    button41->setText(QApplication::translate("AudioPlayerClass", "E_5 ", 0, QApplication::UnicodeUTF8));
    //    button38->setText(QApplication::translate("AudioPlayerClass", "C#5 ", 0, QApplication::UnicodeUTF8));
    //    button60->setText(QApplication::translate("AudioPlayerClass", "F_5 ", 0, QApplication::UnicodeUTF8));
    //    button5->setText(QApplication::translate("AudioPlayerClass", "E_2 ", 0, QApplication::UnicodeUTF8));
    //    button36->setText(QApplication::translate("AudioPlayerClass", "B_4 ", 0, QApplication::UnicodeUTF8));
    //    button20->setText(QApplication::translate("AudioPlayerClass", "G_3 ", 0, QApplication::UnicodeUTF8));
    //    button6->setText(QApplication::translate("AudioPlayerClass", "F_2 ", 0, QApplication::UnicodeUTF8));
    //    button49->setText(QApplication::translate("AudioPlayerClass", "C_6 ", 0, QApplication::UnicodeUTF8));
    //    button46->setText(QApplication::translate("AudioPlayerClass", "A_5 ", 0, QApplication::UnicodeUTF8));
//        button22->setText(QApplication::translate("AudioPlayerClass", "A_3 ", 0, QApplication::UnicodeUTF8));
//        button47->setText(QApplication::translate("AudioPlayerClass", "A#5 ", 0, QApplication::UnicodeUTF8));
//        button17->setText(QApplication::translate("AudioPlayerClass", "E_3 ", 0, QApplication::UnicodeUTF8));
//        button1->setText(QApplication::translate("AudioPlayerClass", "C_2 ", 0, QApplication::UnicodeUTF8));
//        button61->setText(QApplication::translate("AudioPlayerClass", "B_3 ", 0, QApplication::UnicodeUTF8));
//        button50->setText(QApplication::translate("AudioPlayerClass", "G#5 ", 0, QApplication::UnicodeUTF8));
//        button13->setText(QApplication::translate("AudioPlayerClass", "C_3 ", 0, QApplication::UnicodeUTF8));
//        button11->setText(QApplication::translate("AudioPlayerClass", "A#2 ", 0, QApplication::UnicodeUTF8));
//        button44->setText(QApplication::translate("AudioPlayerClass", "G_5 ", 0, QApplication::UnicodeUTF8));
//        button8->setText(QApplication::translate("AudioPlayerClass", "G_2 ", 0, QApplication::UnicodeUTF8));
//        button48->setText(QApplication::translate("AudioPlayerClass", "B_5 ", 0, QApplication::UnicodeUTF8));
//        button32->setText(QApplication::translate("AudioPlayerClass", "G_4 ", 0, QApplication::UnicodeUTF8));
//        button64->setText(QApplication::translate("AudioPlayerClass", "C_3 ", 0, QApplication::UnicodeUTF8));
//        button26->setText(QApplication::translate("AudioPlayerClass", "C#4 ", 0, QApplication::UnicodeUTF8));
//        button42->setText(QApplication::translate("AudioPlayerClass", "F_5 ", 0, QApplication::UnicodeUTF8));
//        button39->setText(QApplication::translate("AudioPlayerClass", "D_5 ", 0, QApplication::UnicodeUTF8));
//        pushButton_70->setText(QApplication::translate("AudioPlayerClass", "Shift", 0, QApplication::UnicodeUTF8));
//        button57->setText(QApplication::translate("AudioPlayerClass", "D_5 ", 0, QApplication::UnicodeUTF8));
//        button25->setText(QApplication::translate("AudioPlayerClass", "C_4 ", 0, QApplication::UnicodeUTF8));
//        button10->setText(QApplication::translate("AudioPlayerClass", "A_2 ", 0, QApplication::UnicodeUTF8));
//        button4->setText(QApplication::translate("AudioPlayerClass", "D#2 ", 0, QApplication::UnicodeUTF8));
//        button35->setText(QApplication::translate("AudioPlayerClass", "A#4 ", 0, QApplication::UnicodeUTF8));
//        Backspace->setText(QApplication::translate("AudioPlayerClass", "Backspace", 0, QApplication::UnicodeUTF8));
//        button30->setText(QApplication::translate("AudioPlayerClass", "F_4 ", 0, QApplication::UnicodeUTF8));
//        button65->setText(QApplication::translate("AudioPlayerClass", "C#3 ", 0, QApplication::UnicodeUTF8));
//        button62->setText(QApplication::translate("AudioPlayerClass", "C_4 ", 0, QApplication::UnicodeUTF8));
//        button12->setText(QApplication::translate("AudioPlayerClass", "B_2 ", 0, QApplication::UnicodeUTF8));
//        button58->setText(QApplication::translate("AudioPlayerClass", "D#5 ", 0, QApplication::UnicodeUTF8));
//        button54->setText(QApplication::translate("AudioPlayerClass", "C_6 ", 0, QApplication::UnicodeUTF8));
//        button16->setText(QApplication::translate("AudioPlayerClass", "D#3 ", 0, QApplication::UnicodeUTF8));
//        button18->setText(QApplication::translate("AudioPlayerClass", "F_3 ", 0, QApplication::UnicodeUTF8));
//        button28->setText(QApplication::translate("AudioPlayerClass", "D#4 ", 0, QApplication::UnicodeUTF8));
//        button52->setText(QApplication::translate("AudioPlayerClass", "A#5 ", 0, QApplication::UnicodeUTF8));
//        button21->setText(QApplication::translate("AudioPlayerClass", "G#3 ", 0, QApplication::UnicodeUTF8));
//        button29->setText(QApplication::translate("AudioPlayerClass", "E_4 ", 0, QApplication::UnicodeUTF8));
//        button56->setText(QApplication::translate("AudioPlayerClass", "C#5 ", 0, QApplication::UnicodeUTF8));
//        button40->setText(QApplication::translate("AudioPlayerClass", "D#5 ", 0, QApplication::UnicodeUTF8));
//        button37->setText(QApplication::translate("AudioPlayerClass", "C_5 ", 0, QApplication::UnicodeUTF8));
//        button24->setText(QApplication::translate("AudioPlayerClass", "B_3 ", 0, QApplication::UnicodeUTF8));
//        button55->setText(QApplication::translate("AudioPlayerClass", "C_5 ", 0, QApplication::UnicodeUTF8));
//        button9->setText(QApplication::translate("AudioPlayerClass", "G#2 ", 0, QApplication::UnicodeUTF8));
//        button23->setText(QApplication::translate("AudioPlayerClass", "A#3 ", 0, QApplication::UnicodeUTF8));
//        button15->setText(QApplication::translate("AudioPlayerClass", "D_3 ", 0, QApplication::UnicodeUTF8));
//        button34->setText(QApplication::translate("AudioPlayerClass", "A_4 ", 0, QApplication::UnicodeUTF8));
//        button3->setText(QApplication::translate("AudioPlayerClass", "D_2 ", 0, QApplication::UnicodeUTF8));
//        button53->setText(QApplication::translate("AudioPlayerClass", "B_5 ", 0, QApplication::UnicodeUTF8));
//        RisingButton->setText(QApplication::translate("AudioPlayerClass", "\345\215\207\350\260\203", 0, QApplication::UnicodeUTF8));
//        FallingButton->setText(QApplication::translate("AudioPlayerClass", "\351\231\215\350\260\203", 0, QApplication::UnicodeUTF8));
//        MoveLeft->setText(QApplication::translate("AudioPlayerClass", "\345\267\246\347\247\273", 0, QApplication::UnicodeUTF8));
//        MoveRight->setText(QApplication::translate("AudioPlayerClass", "\345\217\263\347\247\273", 0, QApplication::UnicodeUTF8));
//        SpaceButon->setText(QApplication::translate("AudioPlayerClass", "Space", 0, QApplication::UnicodeUTF8));
//        button9_2->setText(QApplication::translate("AudioPlayerClass", "Alt", 0, QApplication::UnicodeUTF8));
//        button9_3->setText(QApplication::translate("AudioPlayerClass", "Win", 0, QApplication::UnicodeUTF8));
//        button9_4->setText(QApplication::translate("AudioPlayerClass", "APP", 0, QApplication::UnicodeUTF8));
//        CtrlButton->setText(QApplication::translate("AudioPlayerClass", "Ctrl", 0, QApplication::UnicodeUTF8));
//        CtrlButton2->setText(QApplication::translate("AudioPlayerClass", "Ctrl", 0, QApplication::UnicodeUTF8));
//        button9_7->setText(QApplication::translate("AudioPlayerClass", "Alt", 0, QApplication::UnicodeUTF8));
//        button9_8->setText(QApplication::translate("AudioPlayerClass", "Win", 0, QApplication::UnicodeUTF8));
//        groupBox_2->setTitle(QApplication::translate("AudioPlayerClass", "\346\274\224\345\245\217", 0, QApplication::UnicodeUTF8));
//        comboBox->clear();
//        comboBox->insertItems(0, QStringList()
//         << QApplication::translate("AudioPlayerClass", "\345\244\247\351\222\242\347\220\264\357\274\210\345\243\260\345\255\246\351\222\242\347\220\264\357\274\211", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\346\230\216\344\272\256\347\232\204\351\222\242\347\220\264", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\347\224\265\351\222\242\347\220\264", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\351\205\222\345\220\247\351\222\242\347\220\264", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\346\237\224\345\222\214\347\232\204\347\224\265\351\222\242\347\220\264", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\212\240\345\220\210\345\224\261\346\225\210\346\236\234\347\232\204\347\224\265\351\222\242\347\220\264", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\347\276\275\347\256\241\351\224\256\347\220\264\357\274\210\346\213\250\345\274\246\345\217\244\351\222\242\347\220\264\357\274\211", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\347\247\221\346\213\211\347\273\264\347\247\221\347\211\271\347\220\264\357\274\210\345\207\273\345\274\246\345\217\244\351\222\242\347\220\264\357\274\211", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\351\222\242\347\211\207\347\220\264", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\351\222\237\347\220\264", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\205\253\351\237\263\347\233\222", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\351\242\244\351\237\263\347\220\264", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\351\251\254\346\236\227\345\267\264", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\346\234\250\347\220\264", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\347\256\241\351\222\237", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\244\247\346\211\254\347\220\264", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\207\273\346\235\206\351\243\216\347\220\264", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\346\211\223\345\207\273\345\274\217\351\243\216\347\220\264", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\346\221\207\346\273\232\351\243\216\347\220\264", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\346\225\231\345\240\202\351\243\216\347\220\264", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\347\260\247\347\256\241\351\243\216\347\220\264", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\346\211\213\351\243\216\347\220\264", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\217\243\347\220\264", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\346\216\242\346\210\210\346\211\213\351\243\216\347\220\264", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\260\274\351\276\231\345\274\246\345\220\211\344\273\226", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\351\222\242\345\274\246\345\220\211\344\273\226", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\347\210\265\345\243\253\347\224\265\345\220\211\344\273\226", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\346\270\205\351\237\263\347\224\265\345\220\211\344\273\226", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\351\227\267\351\237\263\347\224\265\345\220\211\344\273\226", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\212\240\351\251\261\345\212\250\346\225\210\346\236\234\347\232\204\347\224\265\345\220\211\344\273\226", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\212\240\345\244\261\347\234\237\346\225\210\346\236\234\347\232\204\347\224\265\345\220\211\344\273\226", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\220\211\344\273\226\345\222\214\351\237\263", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\244\247\350\264\235\346\226\257\357\274\210\345\243\260\345\255\246\350\264\235\346\226\257\357\274\211", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\347\224\265\350\264\235\346\226\257\357\274\210\346\214\207\345\274\271\357\274\211", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\347\224\265\350\264\235\346\226\257\357\274\210\346\213\250\347\211\207\357\274\211", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\346\227\240\345\223\201\350\264\235\346\226\257", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\346\216\214\345\207\273\350\264\235\346\226\2571", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\346\216\214\345\207\273\350\264\235\346\226\2572", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\347\224\265\345\255\220\345\220\210\346\210\220\350\264\235\346\226\2571", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\347\224\265\345\255\220\345\220\210\346\210\220\350\264\235\346\226\2572", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\260\217\346\217\220\347\220\264", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\344\270\255\346\217\220\347\220\264", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\244\247\346\217\220\347\220\264", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\344\275\216\351\237\263\345\244\247\346\217\220\347\220\264", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\274\246\344\271\220\347\276\244\351\242\244\351\237\263\351\237\263\350\211\262", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\274\246\344\271\220\347\276\244\346\213\250\345\274\246\351\237\263\350\211\262", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\347\253\226\347\220\264", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\256\232\351\237\263\351\274\223", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\274\246\344\271\220\345\220\210\345\245\217\351\237\263\350\211\2621", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\274\246\344\271\220\345\220\210\345\245\217\351\237\263\350\211\2622", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\345\274\246\344\271\220\345\220\210\345\245\217\351\237\263\350\211\2621", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\345\274\246\344\271\220\345\220\210\345\245\217\351\237\263\350\211\2622", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\344\272\272\345\243\260\345\220\210\345\224\261\342\200\234\345\225\212\342\200\235", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\344\272\272\345\243\260\342\200\234\345\230\237\342\200\235", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\344\272\272\345\243\260", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\347\256\241\345\274\246\344\271\220\346\225\262\345\207\273\351\275\220\345\245\217", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\260\217\345\217\267", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\351\225\277\345\217\267", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\244\247\345\217\267", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\212\240\345\274\261\351\237\263\345\231\250\345\260\217\345\217\267", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\346\263\225\345\233\275\345\217\267\357\274\210\345\234\206\345\217\267\357\274\211", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\351\223\234\347\256\241\347\273\204\357\274\210\351\223\234\347\256\241\344\271\220\345\231\250\345\220\210\345\245\217\351\237\263\350\211\262\357\274\211", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\351\223\234\347\256\241\351\237\263\350\211\2621", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\351\223\234\347\256\241\351\237\263\350\211\2622", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\351\253\230\351\237\263\350\220\250\345\205\213\346\226\257\351\243\216", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\346\254\241\344\270\255\351\237\263\350\220\250\345\205\213\346\226\257\351\243\216", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\344\270\255\351\237\263\350\220\250\345\205\213\346\226\257\351\243\216", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\344\275\216\351\237\263\350\220\250\345\205\213\346\226\257\351\243\216", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\217\214\347\260\247\347\256\241", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\350\213\261\345\233\275\347\256\241", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\267\264\346\235\276\357\274\210\345\244\247\347\256\241\357\274\211", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\215\225\347\260\247\347\256\241\357\274\210\351\273\221\347\256\241\357\274\211", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\347\237\255\347\254\233", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\351\225\277\347\254\233", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\347\253\226\347\254\233", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\346\216\222\347\256\253", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\346\227\245\346\234\254\345\260\272\345\205\253", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\217\243\345\223\250\345\243\260", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\245\245\345\215\241\351\233\267\351\202\243", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\344\270\273\351\237\2631\357\274\210\346\226\271\346\263\242\357\274\211", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\344\270\273\351\237\2632\357\274\210\351\224\257\351\275\277\346\263\242\357\274\211", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\344\270\273\351\237\2633", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\344\270\273\351\237\2634", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\344\270\273\351\237\2635", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\344\270\273\351\237\2636\357\274\210\344\272\272\345\243\260\357\274\211", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\344\270\273\351\237\2637\357\274\210\345\271\263\350\241\214\344\272\224\345\272\246\357\274\211", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\344\270\273\351\237\2638\357\274\210\350\264\235\345\217\270\345\212\240\344\270\273\351\237\263\357\274\211", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\351\237\263\350\211\2621\357\274\210\346\226\260\344\270\226\347\272\252\357\274\211", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\351\237\263\350\211\2622 \357\274\210\346\270\251\346\232\226\357\274\211", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\351\237\263\350\211\2623", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\351\237\263\350\211\2624 \357\274\210\345\220\210\345\224\261\357\274\211", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\351\237\263\350\211\2625", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\351\237\263\350\211\2626 \357\274\210\351\207\221\345\261\236\345\243\260\357\274\211", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\351\237\263\350\211\2627 \357\274\210\345\205\211\347\216\257\357\274\211", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\351\237\263\350\211\2628", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\346\225\210\346\236\234 1 \351\233\250\345\243\260", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\346\225\210\346\236\234 2 \351\237\263\350\275\250", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\346\225\210\346\236\234 3 \346\260\264\346\231\266", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\346\225\210\346\236\234 4 \345\244\247\346\260\224", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\346\225\210\346\236\234 5 \346\230\216\344\272\256", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\346\225\210\346\236\234 6 \351\254\274\346\200\252", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\346\225\210\346\236\234 7 \345\233\236\345\243\260", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\346\225\210\346\236\234 8 \347\247\221\345\271\273", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\350\245\277\345\241\224\345\260\224\357\274\210\345\215\260\345\272\246\357\274\211", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\347\217\255\345\215\223\347\220\264\357\274\210\347\276\216\346\264\262\357\274\211", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\344\270\211\346\230\247\347\272\277\357\274\210\346\227\245\346\234\254\357\274\211", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\215\201\344\270\211\345\274\246\347\255\235\357\274\210\346\227\245\346\234\254\357\274\211", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\215\241\346\236\227\345\267\264", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\351\243\216\347\254\233", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\346\260\221\346\227\217\346\217\220\347\220\264", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\261\261\345\245\210", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", " \345\217\256\345\275\223\351\223\203", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\351\222\242\351\274\223", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\346\234\250\351\261\274", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\244\252\351\274\223", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\351\200\232\351\200\232\351\274\223", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\351\274\223", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\351\223\234\351\222\271", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\220\211\344\273\226\346\215\242\346\212\212\346\235\202\351\237\263", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\345\221\274\345\220\270\345\243\260", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\346\265\267\346\265\252\345\243\260", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\351\270\237\351\270\243", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\347\224\265\350\257\235\351\223\203", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\347\233\264\345\215\207\346\234\272", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "\351\274\223\346\216\214\345\243\260", 0, QApplication::UnicodeUTF8)
//        );
//        label->setText(QApplication::translate("AudioPlayerClass", "\351\237\263\351\207\217\350\256\276\347\275\256\357\274\232", 0, QApplication::UnicodeUTF8));
//        LoadButton->setText(QApplication::translate("AudioPlayerClass", "\345\212\240\350\275\275\344\271\220\350\260\261", 0, QApplication::UnicodeUTF8));
//        label_2->setText(QString());
//        label_5->setText(QString());
//        label_8->setText(QString());
//        LoadSwing->setText(QApplication::translate("AudioPlayerClass", "\345\212\240\350\275\275\350\212\202\345\245\217", 0, QApplication::UnicodeUTF8));
//        groupBox_3->setTitle(QApplication::translate("AudioPlayerClass", "\346\223\215\344\275\234", 0, QApplication::UnicodeUTF8));
//        ClearButton->setText(QApplication::translate("AudioPlayerClass", "\346\270\205\347\251\272", 0, QApplication::UnicodeUTF8));
//        SaveButton->setText(QApplication::translate("AudioPlayerClass", "\344\277\235\345\255\230\346\226\260\344\271\220\350\260\261", 0, QApplication::UnicodeUTF8));
//        ComposeButton->setText(QApplication::translate("AudioPlayerClass", "\345\274\200\345\247\213\350\260\261\346\233\262", 0, QApplication::UnicodeUTF8));
//        PlayButton->setText(QApplication::translate("AudioPlayerClass", "\346\231\256\351\200\232\346\222\255\346\224\276", 0, QApplication::UnicodeUTF8));
//        label_3->setText(QApplication::translate("AudioPlayerClass", "\346\257\217\345\210\206\351\222\237\347\232\204\350\212\202\346\213\215\346\225\260\357\274\232", 0, QApplication::UnicodeUTF8));
//        ConnectINDevice->setText(QApplication::translate("AudioPlayerClass", "\350\277\236\346\216\245MIDI\350\276\223\345\205\245\350\256\276\345\244\207", 0, QApplication::UnicodeUTF8));
//        label_6->setText(QString());
//        CirculationPlay->setText(QApplication::translate("AudioPlayerClass", "\345\276\252\347\216\257\346\222\255\346\224\276", 0, QApplication::UnicodeUTF8));
//        BeatPlay->setText(QApplication::translate("AudioPlayerClass", "\346\214\211\350\212\202\346\222\255\346\224\276", 0, QApplication::UnicodeUTF8));
//        ModiButton->setText(QApplication::translate("AudioPlayerClass", "\350\247\204\346\240\274\345\214\226", 0, QApplication::UnicodeUTF8));
//        label_7->setText(QApplication::translate("AudioPlayerClass", "\350\212\202\346\213\215\357\274\232", 0, QApplication::UnicodeUTF8));
//        label_4->setText(QApplication::translate("AudioPlayerClass", "\346\222\255\346\224\276\351\200\237\345\272\246\357\274\232", 0, QApplication::UnicodeUTF8));
//        SaveSwing->setText(QApplication::translate("AudioPlayerClass", "\344\277\235\345\255\230\346\226\260\350\212\202\345\245\217", 0, QApplication::UnicodeUTF8));
//        comboBox_2->clear();
//        comboBox_2->insertItems(0, QStringList()
//         << QApplication::translate("AudioPlayerClass", "2/4 \346\213\215", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "1/4 \346\213\215", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "3/4 \346\213\215", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "4/4 \346\213\215", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "3/8 \346\213\215", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "6/8 \346\213\215", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "7/8 \346\213\215", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "9/8 \346\213\215", 0, QApplication::UnicodeUTF8)
//         << QApplication::translate("AudioPlayerClass", "12/8 \346\213\215", 0, QApplication::UnicodeUTF8)
//        );
//        RhythmPlay->setText(QApplication::translate("AudioPlayerClass", "\346\214\211\346\213\215\346\222\255\346\224\276", 0, QApplication::UnicodeUTF8));
//        ModiRhythm->setText(QApplication::translate("AudioPlayerClass", "\350\212\202\346\213\215\344\277\256\346\255\243", 0, QApplication::UnicodeUTF8));
//    } // retranslateUi
//
//};
void retranslateUi(QMainWindow *AudioPlayerClass)
{
	AudioPlayerClass->setWindowTitle(QApplication::translate("AudioPlayerClass", "AudioPlayer", 0));
	groupBox->setTitle(QApplication::translate("AudioPlayerClass", "\351\224\256\347\233\230", 0));
	NumLock->setText(QApplication::translate("AudioPlayerClass", "Lock", 0));
	button31->setText(QApplication::translate("AudioPlayerClass", "F#4 ", 0));
	button45->setText(QApplication::translate("AudioPlayerClass", "G#5 ", 0));
	button14->setText(QApplication::translate("AudioPlayerClass", "C#3 ", 0));
	button59->setText(QApplication::translate("AudioPlayerClass", "E_5 ", 0));
	button51->setText(QApplication::translate("AudioPlayerClass", "A_5 ", 0));
	pushButton_50->setText(QApplication::translate("AudioPlayerClass", "Caps Lock", 0));
	button2->setText(QApplication::translate("AudioPlayerClass", "C#2 ", 0));
	button19->setText(QApplication::translate("AudioPlayerClass", "F#3 ", 0));
	button43->setText(QApplication::translate("AudioPlayerClass", "F#5 ", 0));
	pushButton_30->setText(QApplication::translate("AudioPlayerClass", "Tab", 0));
	button7->setText(QApplication::translate("AudioPlayerClass", "F#2 ", 0));
	button33->setText(QApplication::translate("AudioPlayerClass", "G#4 ", 0));
	button27->setText(QApplication::translate("AudioPlayerClass", "D_4 ", 0));
	button63->setText(QApplication::translate("AudioPlayerClass", "B_2 ", 0));
	pushButton->setText(QApplication::translate("AudioPlayerClass", "6", 0));
	button41->setText(QApplication::translate("AudioPlayerClass", "E_5 ", 0));
	button38->setText(QApplication::translate("AudioPlayerClass", "C#5 ", 0));
	button60->setText(QApplication::translate("AudioPlayerClass", "F_5 ", 0));
	button5->setText(QApplication::translate("AudioPlayerClass", "E_2 ", 0));
	button36->setText(QApplication::translate("AudioPlayerClass", "B_4 ", 0));
	button20->setText(QApplication::translate("AudioPlayerClass", "G_3 ", 0));
	button6->setText(QApplication::translate("AudioPlayerClass", "F_2 ", 0));
	button49->setText(QApplication::translate("AudioPlayerClass", "C_6 ", 0));
	button46->setText(QApplication::translate("AudioPlayerClass", "A_5 ", 0));
	button22->setText(QApplication::translate("AudioPlayerClass", "A_3 ", 0));
	button47->setText(QApplication::translate("AudioPlayerClass", "A#5 ", 0));
	button17->setText(QApplication::translate("AudioPlayerClass", "E_3 ", 0));
	button1->setText(QApplication::translate("AudioPlayerClass", "C_2 ", 0));
	button61->setText(QApplication::translate("AudioPlayerClass", "B_3 ", 0));
	button50->setText(QApplication::translate("AudioPlayerClass", "G#5 ", 0));
	button13->setText(QApplication::translate("AudioPlayerClass", "C_3 ", 0));
	button11->setText(QApplication::translate("AudioPlayerClass", "A#2 ", 0));
	button44->setText(QApplication::translate("AudioPlayerClass", "G_5 ", 0));
	button8->setText(QApplication::translate("AudioPlayerClass", "G_2 ", 0));
	button48->setText(QApplication::translate("AudioPlayerClass", "B_5 ", 0));
	button32->setText(QApplication::translate("AudioPlayerClass", "G_4 ", 0));
	button64->setText(QApplication::translate("AudioPlayerClass", "C_3 ", 0));
	button26->setText(QApplication::translate("AudioPlayerClass", "C#4 ", 0));
	button42->setText(QApplication::translate("AudioPlayerClass", "F_5 ", 0));
	button39->setText(QApplication::translate("AudioPlayerClass", "D_5 ", 0));
	pushButton_70->setText(QApplication::translate("AudioPlayerClass", "Shift", 0));
	button57->setText(QApplication::translate("AudioPlayerClass", "D_5 ", 0));
	button25->setText(QApplication::translate("AudioPlayerClass", "C_4 ", 0));
	button10->setText(QApplication::translate("AudioPlayerClass", "A_2 ", 0));
	button4->setText(QApplication::translate("AudioPlayerClass", "D#2 ", 0));
	button35->setText(QApplication::translate("AudioPlayerClass", "A#4 ", 0));
	Backspace->setText(QApplication::translate("AudioPlayerClass", "Backspace", 0));
	button30->setText(QApplication::translate("AudioPlayerClass", "F_4 ", 0));
	button65->setText(QApplication::translate("AudioPlayerClass", "C#3 ", 0));
	button62->setText(QApplication::translate("AudioPlayerClass", "C_4 ", 0));
	button12->setText(QApplication::translate("AudioPlayerClass", "B_2 ", 0));
	button58->setText(QApplication::translate("AudioPlayerClass", "D#5 ", 0));
	button54->setText(QApplication::translate("AudioPlayerClass", "C_6 ", 0));
	button16->setText(QApplication::translate("AudioPlayerClass", "D#3 ", 0));
	button18->setText(QApplication::translate("AudioPlayerClass", "F_3 ", 0));
	button28->setText(QApplication::translate("AudioPlayerClass", "D#4 ", 0));
	button52->setText(QApplication::translate("AudioPlayerClass", "A#5 ", 0));
	button21->setText(QApplication::translate("AudioPlayerClass", "G#3 ", 0));
	button29->setText(QApplication::translate("AudioPlayerClass", "E_4 ", 0));
	button56->setText(QApplication::translate("AudioPlayerClass", "C#5 ", 0));
	button40->setText(QApplication::translate("AudioPlayerClass", "D#5 ", 0));
	button37->setText(QApplication::translate("AudioPlayerClass", "C_5 ", 0));
	button24->setText(QApplication::translate("AudioPlayerClass", "B_3 ", 0));
	button55->setText(QApplication::translate("AudioPlayerClass", "C_5 ", 0));
	button9->setText(QApplication::translate("AudioPlayerClass", "G#2 ", 0));
	button23->setText(QApplication::translate("AudioPlayerClass", "A#3 ", 0));
	button15->setText(QApplication::translate("AudioPlayerClass", "D_3 ", 0));
	button34->setText(QApplication::translate("AudioPlayerClass", "A_4 ", 0));
	button3->setText(QApplication::translate("AudioPlayerClass", "D_2 ", 0));
	button53->setText(QApplication::translate("AudioPlayerClass", "B_5 ", 0));
	RisingButton->setText(QApplication::translate("AudioPlayerClass", "\345\215\207\350\260\203", 0));
	FallingButton->setText(QApplication::translate("AudioPlayerClass", "\351\231\215\350\260\203", 0));
	MoveLeft->setText(QApplication::translate("AudioPlayerClass", "\345\267\246\347\247\273", 0));
	MoveRight->setText(QApplication::translate("AudioPlayerClass", "\345\217\263\347\247\273", 0));
	SpaceButon->setText(QApplication::translate("AudioPlayerClass", "Space", 0));
	button9_2->setText(QApplication::translate("AudioPlayerClass", "Alt", 0));
	button9_3->setText(QApplication::translate("AudioPlayerClass", "Win", 0));
	button9_4->setText(QApplication::translate("AudioPlayerClass", "APP", 0));
	CtrlButton->setText(QApplication::translate("AudioPlayerClass", "Ctrl", 0));
	CtrlButton2->setText(QApplication::translate("AudioPlayerClass", "Ctrl", 0));
	button9_7->setText(QApplication::translate("AudioPlayerClass", "Alt", 0));
	button9_8->setText(QApplication::translate("AudioPlayerClass", "Win", 0));
	groupBox_2->setTitle(QApplication::translate("AudioPlayerClass", "\346\274\224\345\245\217", 0));
	comboBox->clear();
	comboBox->insertItems(0, QStringList()
		<< QApplication::translate("AudioPlayerClass", "\345\244\247\351\222\242\347\220\264\357\274\210\345\243\260\345\255\246\351\222\242\347\220\264\357\274\211", 0)
		<< QApplication::translate("AudioPlayerClass", "\346\230\216\344\272\256\347\232\204\351\222\242\347\220\264", 0)
		<< QApplication::translate("AudioPlayerClass", "\347\224\265\351\222\242\347\220\264", 0)
		<< QApplication::translate("AudioPlayerClass", "\351\205\222\345\220\247\351\222\242\347\220\264", 0)
		<< QApplication::translate("AudioPlayerClass", "\346\237\224\345\222\214\347\232\204\347\224\265\351\222\242\347\220\264", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\212\240\345\220\210\345\224\261\346\225\210\346\236\234\347\232\204\347\224\265\351\222\242\347\220\264", 0)
		<< QApplication::translate("AudioPlayerClass", "\347\276\275\347\256\241\351\224\256\347\220\264\357\274\210\346\213\250\345\274\246\345\217\244\351\222\242\347\220\264\357\274\211", 0)
		<< QApplication::translate("AudioPlayerClass", "\347\247\221\346\213\211\347\273\264\347\247\221\347\211\271\347\220\264\357\274\210\345\207\273\345\274\246\345\217\244\351\222\242\347\220\264\357\274\211", 0)
		<< QApplication::translate("AudioPlayerClass", "\351\222\242\347\211\207\347\220\264", 0)
		<< QApplication::translate("AudioPlayerClass", "\351\222\237\347\220\264", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\205\253\351\237\263\347\233\222", 0)
		<< QApplication::translate("AudioPlayerClass", "\351\242\244\351\237\263\347\220\264", 0)
		<< QApplication::translate("AudioPlayerClass", "\351\251\254\346\236\227\345\267\264", 0)
		<< QApplication::translate("AudioPlayerClass", "\346\234\250\347\220\264", 0)
		<< QApplication::translate("AudioPlayerClass", "\347\256\241\351\222\237", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\244\247\346\211\254\347\220\264", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\207\273\346\235\206\351\243\216\347\220\264", 0)
		<< QApplication::translate("AudioPlayerClass", "\346\211\223\345\207\273\345\274\217\351\243\216\347\220\264", 0)
		<< QApplication::translate("AudioPlayerClass", "\346\221\207\346\273\232\351\243\216\347\220\264", 0)
		<< QApplication::translate("AudioPlayerClass", "\346\225\231\345\240\202\351\243\216\347\220\264", 0)
		<< QApplication::translate("AudioPlayerClass", "\347\260\247\347\256\241\351\243\216\347\220\264", 0)
		<< QApplication::translate("AudioPlayerClass", "\346\211\213\351\243\216\347\220\264", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\217\243\347\220\264", 0)
		<< QApplication::translate("AudioPlayerClass", "\346\216\242\346\210\210\346\211\213\351\243\216\347\220\264", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\260\274\351\276\231\345\274\246\345\220\211\344\273\226", 0)
		<< QApplication::translate("AudioPlayerClass", "\351\222\242\345\274\246\345\220\211\344\273\226", 0)
		<< QApplication::translate("AudioPlayerClass", "\347\210\265\345\243\253\347\224\265\345\220\211\344\273\226", 0)
		<< QApplication::translate("AudioPlayerClass", "\346\270\205\351\237\263\347\224\265\345\220\211\344\273\226", 0)
		<< QApplication::translate("AudioPlayerClass", "\351\227\267\351\237\263\347\224\265\345\220\211\344\273\226", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\212\240\351\251\261\345\212\250\346\225\210\346\236\234\347\232\204\347\224\265\345\220\211\344\273\226", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\212\240\345\244\261\347\234\237\346\225\210\346\236\234\347\232\204\347\224\265\345\220\211\344\273\226", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\220\211\344\273\226\345\222\214\351\237\263", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\244\247\350\264\235\346\226\257\357\274\210\345\243\260\345\255\246\350\264\235\346\226\257\357\274\211", 0)
		<< QApplication::translate("AudioPlayerClass", "\347\224\265\350\264\235\346\226\257\357\274\210\346\214\207\345\274\271\357\274\211", 0)
		<< QApplication::translate("AudioPlayerClass", "\347\224\265\350\264\235\346\226\257\357\274\210\346\213\250\347\211\207\357\274\211", 0)
		<< QApplication::translate("AudioPlayerClass", "\346\227\240\345\223\201\350\264\235\346\226\257", 0)
		<< QApplication::translate("AudioPlayerClass", "\346\216\214\345\207\273\350\264\235\346\226\2571", 0)
		<< QApplication::translate("AudioPlayerClass", "\346\216\214\345\207\273\350\264\235\346\226\2572", 0)
		<< QApplication::translate("AudioPlayerClass", "\347\224\265\345\255\220\345\220\210\346\210\220\350\264\235\346\226\2571", 0)
		<< QApplication::translate("AudioPlayerClass", "\347\224\265\345\255\220\345\220\210\346\210\220\350\264\235\346\226\2572", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\260\217\346\217\220\347\220\264", 0)
		<< QApplication::translate("AudioPlayerClass", "\344\270\255\346\217\220\347\220\264", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\244\247\346\217\220\347\220\264", 0)
		<< QApplication::translate("AudioPlayerClass", "\344\275\216\351\237\263\345\244\247\346\217\220\347\220\264", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\274\246\344\271\220\347\276\244\351\242\244\351\237\263\351\237\263\350\211\262", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\274\246\344\271\220\347\276\244\346\213\250\345\274\246\351\237\263\350\211\262", 0)
		<< QApplication::translate("AudioPlayerClass", "\347\253\226\347\220\264", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\256\232\351\237\263\351\274\223", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\274\246\344\271\220\345\220\210\345\245\217\351\237\263\350\211\2621", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\274\246\344\271\220\345\220\210\345\245\217\351\237\263\350\211\2622", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\345\274\246\344\271\220\345\220\210\345\245\217\351\237\263\350\211\2621", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\345\274\246\344\271\220\345\220\210\345\245\217\351\237\263\350\211\2622", 0)
		<< QApplication::translate("AudioPlayerClass", "\344\272\272\345\243\260\345\220\210\345\224\261\342\200\234\345\225\212\342\200\235", 0)
		<< QApplication::translate("AudioPlayerClass", "\344\272\272\345\243\260\342\200\234\345\230\237\342\200\235", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\344\272\272\345\243\260", 0)
		<< QApplication::translate("AudioPlayerClass", "\347\256\241\345\274\246\344\271\220\346\225\262\345\207\273\351\275\220\345\245\217", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\260\217\345\217\267", 0)
		<< QApplication::translate("AudioPlayerClass", "\351\225\277\345\217\267", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\244\247\345\217\267", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\212\240\345\274\261\351\237\263\345\231\250\345\260\217\345\217\267", 0)
		<< QApplication::translate("AudioPlayerClass", "\346\263\225\345\233\275\345\217\267\357\274\210\345\234\206\345\217\267\357\274\211", 0)
		<< QApplication::translate("AudioPlayerClass", "\351\223\234\347\256\241\347\273\204\357\274\210\351\223\234\347\256\241\344\271\220\345\231\250\345\220\210\345\245\217\351\237\263\350\211\262\357\274\211", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\351\223\234\347\256\241\351\237\263\350\211\2621", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\351\223\234\347\256\241\351\237\263\350\211\2622", 0)
		<< QApplication::translate("AudioPlayerClass", "\351\253\230\351\237\263\350\220\250\345\205\213\346\226\257\351\243\216", 0)
		<< QApplication::translate("AudioPlayerClass", "\346\254\241\344\270\255\351\237\263\350\220\250\345\205\213\346\226\257\351\243\216", 0)
		<< QApplication::translate("AudioPlayerClass", "\344\270\255\351\237\263\350\220\250\345\205\213\346\226\257\351\243\216", 0)
		<< QApplication::translate("AudioPlayerClass", "\344\275\216\351\237\263\350\220\250\345\205\213\346\226\257\351\243\216", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\217\214\347\260\247\347\256\241", 0)
		<< QApplication::translate("AudioPlayerClass", "\350\213\261\345\233\275\347\256\241", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\267\264\346\235\276\357\274\210\345\244\247\347\256\241\357\274\211", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\215\225\347\260\247\347\256\241\357\274\210\351\273\221\347\256\241\357\274\211", 0)
		<< QApplication::translate("AudioPlayerClass", "\347\237\255\347\254\233", 0)
		<< QApplication::translate("AudioPlayerClass", "\351\225\277\347\254\233", 0)
		<< QApplication::translate("AudioPlayerClass", "\347\253\226\347\254\233", 0)
		<< QApplication::translate("AudioPlayerClass", "\346\216\222\347\256\253", 0)
		<< QApplication::translate("AudioPlayerClass", "\346\227\245\346\234\254\345\260\272\345\205\253", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\217\243\345\223\250\345\243\260", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\245\245\345\215\241\351\233\267\351\202\243", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\344\270\273\351\237\2631\357\274\210\346\226\271\346\263\242\357\274\211", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\344\270\273\351\237\2632\357\274\210\351\224\257\351\275\277\346\263\242\357\274\211", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\344\270\273\351\237\2633", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\344\270\273\351\237\2634", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\344\270\273\351\237\2635", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\344\270\273\351\237\2636\357\274\210\344\272\272\345\243\260\357\274\211", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\344\270\273\351\237\2637\357\274\210\345\271\263\350\241\214\344\272\224\345\272\246\357\274\211", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\344\270\273\351\237\2638\357\274\210\350\264\235\345\217\270\345\212\240\344\270\273\351\237\263\357\274\211", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\351\237\263\350\211\2621\357\274\210\346\226\260\344\270\226\347\272\252\357\274\211", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\351\237\263\350\211\2622 \357\274\210\346\270\251\346\232\226\357\274\211", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\351\237\263\350\211\2623", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\351\237\263\350\211\2624 \357\274\210\345\220\210\345\224\261\357\274\211", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\351\237\263\350\211\2625", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\351\237\263\350\211\2626 \357\274\210\351\207\221\345\261\236\345\243\260\357\274\211", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\351\237\263\350\211\2627 \357\274\210\345\205\211\347\216\257\357\274\211", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\351\237\263\350\211\2628", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\346\225\210\346\236\234 1 \351\233\250\345\243\260", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\346\225\210\346\236\234 2 \351\237\263\350\275\250", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\346\225\210\346\236\234 3 \346\260\264\346\231\266", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\346\225\210\346\236\234 4 \345\244\247\346\260\224", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\346\225\210\346\236\234 5 \346\230\216\344\272\256", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\346\225\210\346\236\234 6 \351\254\274\346\200\252", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\346\225\210\346\236\234 7 \345\233\236\345\243\260", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\346\225\210\346\236\234 8 \347\247\221\345\271\273", 0)
		<< QApplication::translate("AudioPlayerClass", "\350\245\277\345\241\224\345\260\224\357\274\210\345\215\260\345\272\246\357\274\211", 0)
		<< QApplication::translate("AudioPlayerClass", "\347\217\255\345\215\223\347\220\264\357\274\210\347\276\216\346\264\262\357\274\211", 0)
		<< QApplication::translate("AudioPlayerClass", "\344\270\211\346\230\247\347\272\277\357\274\210\346\227\245\346\234\254\357\274\211", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\215\201\344\270\211\345\274\246\347\255\235\357\274\210\346\227\245\346\234\254\357\274\211", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\215\241\346\236\227\345\267\264", 0)
		<< QApplication::translate("AudioPlayerClass", "\351\243\216\347\254\233", 0)
		<< QApplication::translate("AudioPlayerClass", "\346\260\221\346\227\217\346\217\220\347\220\264", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\261\261\345\245\210", 0)
		<< QApplication::translate("AudioPlayerClass", " \345\217\256\345\275\223\351\223\203", 0)
		<< QApplication::translate("AudioPlayerClass", "\351\222\242\351\274\223", 0)
		<< QApplication::translate("AudioPlayerClass", "\346\234\250\351\261\274", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\244\252\351\274\223", 0)
		<< QApplication::translate("AudioPlayerClass", "\351\200\232\351\200\232\351\274\223", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\220\210\346\210\220\351\274\223", 0)
		<< QApplication::translate("AudioPlayerClass", "\351\223\234\351\222\271", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\220\211\344\273\226\346\215\242\346\212\212\346\235\202\351\237\263", 0)
		<< QApplication::translate("AudioPlayerClass", "\345\221\274\345\220\270\345\243\260", 0)
		<< QApplication::translate("AudioPlayerClass", "\346\265\267\346\265\252\345\243\260", 0)
		<< QApplication::translate("AudioPlayerClass", "\351\270\237\351\270\243", 0)
		<< QApplication::translate("AudioPlayerClass", "\347\224\265\350\257\235\351\223\203", 0)
		<< QApplication::translate("AudioPlayerClass", "\347\233\264\345\215\207\346\234\272", 0)
		<< QApplication::translate("AudioPlayerClass", "\351\274\223\346\216\214\345\243\260", 0)
	);
	label->setText(QApplication::translate("AudioPlayerClass", "\351\237\263\351\207\217\350\256\276\347\275\256\357\274\232", 0));
	LoadButton->setText(QApplication::translate("AudioPlayerClass", "\345\212\240\350\275\275\344\271\220\350\260\261", 0));
	label_2->setText(QString());
	label_5->setText(QString());
	label_8->setText(QString());
	LoadSwing->setText(QApplication::translate("AudioPlayerClass", "\345\212\240\350\275\275\350\212\202\345\245\217", 0));
	groupBox_3->setTitle(QApplication::translate("AudioPlayerClass", "\346\223\215\344\275\234", 0));
	ClearButton->setText(QApplication::translate("AudioPlayerClass", "\346\270\205\347\251\272", 0));
	SaveButton->setText(QApplication::translate("AudioPlayerClass", "\344\277\235\345\255\230\346\226\260\344\271\220\350\260\261", 0));
	ComposeButton->setText(QApplication::translate("AudioPlayerClass", "\345\274\200\345\247\213\350\260\261\346\233\262", 0));
	PlayButton->setText(QApplication::translate("AudioPlayerClass", "\346\231\256\351\200\232\346\222\255\346\224\276", 0));
	label_3->setText(QApplication::translate("AudioPlayerClass", "\346\257\217\345\210\206\351\222\237\347\232\204\350\212\202\346\213\215\346\225\260\357\274\232", 0));
	ConnectINDevice->setText(QApplication::translate("AudioPlayerClass", "\350\277\236\346\216\245MIDI\350\276\223\345\205\245\350\256\276\345\244\207", 0));
	label_6->setText(QString());
	CirculationPlay->setText(QApplication::translate("AudioPlayerClass", "\345\276\252\347\216\257\346\222\255\346\224\276", 0));
	BeatPlay->setText(QApplication::translate("AudioPlayerClass", "\346\214\211\350\212\202\346\222\255\346\224\276", 0));
	ModiButton->setText(QApplication::translate("AudioPlayerClass", "\350\247\204\346\240\274\345\214\226", 0));
	label_7->setText(QApplication::translate("AudioPlayerClass", "\350\212\202\346\213\215\357\274\232", 0));
	label_4->setText(QApplication::translate("AudioPlayerClass", "\346\222\255\346\224\276\351\200\237\345\272\246\357\274\232", 0));
	SaveSwing->setText(QApplication::translate("AudioPlayerClass", "\344\277\235\345\255\230\346\226\260\350\212\202\345\245\217", 0));
	comboBox_2->clear();
	comboBox_2->insertItems(0, QStringList()
		<< QApplication::translate("AudioPlayerClass", "2/4 \346\213\215", 0)
		<< QApplication::translate("AudioPlayerClass", "1/4 \346\213\215", 0)
		<< QApplication::translate("AudioPlayerClass", "3/4 \346\213\215", 0)
		<< QApplication::translate("AudioPlayerClass", "4/4 \346\213\215", 0)
		<< QApplication::translate("AudioPlayerClass", "3/8 \346\213\215", 0)
		<< QApplication::translate("AudioPlayerClass", "6/8 \346\213\215", 0)
		<< QApplication::translate("AudioPlayerClass", "7/8 \346\213\215", 0)
		<< QApplication::translate("AudioPlayerClass", "9/8 \346\213\215", 0)
		<< QApplication::translate("AudioPlayerClass", "12/8 \346\213\215", 0)
	);
	RhythmPlay->setText(QApplication::translate("AudioPlayerClass", "\346\214\211\346\213\215\346\222\255\346\224\276", 0));
	ModiRhythm->setText(QApplication::translate("AudioPlayerClass", "\350\212\202\346\213\215\344\277\256\346\255\243", 0));
	} // retranslateUi

};


namespace Ui {
    class AudioPlayerClass: public Ui_AudioPlayerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDIOPLAYER_H
