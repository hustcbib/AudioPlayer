#include "AudioPlayer.h"
#include <QtWidgets/QApplication>
#include "qtextcodec.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTextCodec *codec = QTextCodec::codecForName("GB2312");//GB2312
	QTextCodec::setCodecForLocale(codec);
	QTextCodec::setCodecForCStrings(codec);
	QTextCodec::setCodecForTr(codec);
	AudioPlayer w;
	a.installEventFilter(&w);
	w.show();
	return a.exec();
}