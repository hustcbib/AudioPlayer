/****************************************************************************
** Meta object code from reading C++ file 'AudioPlayer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AudioPlayer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AudioPlayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AudioPlayer_t {
    QByteArrayData data[106];
    char stringdata0[1588];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AudioPlayer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AudioPlayer_t qt_meta_stringdata_AudioPlayer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "AudioPlayer"
QT_MOC_LITERAL(1, 12, 17), // "sendtopitchthread"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 14), // "do_run_pitchup"
QT_MOC_LITERAL(4, 46, 8), // "sendtext"
QT_MOC_LITERAL(5, 55, 10), // "sendhandle"
QT_MOC_LITERAL(6, 66, 8), // "HMIDIOUT"
QT_MOC_LITERAL(7, 75, 15), // "stoppitchthread"
QT_MOC_LITERAL(8, 91, 16), // "sendtoplaythread"
QT_MOC_LITERAL(9, 108, 11), // "do_run_play"
QT_MOC_LITERAL(10, 120, 12), // "sendplaytext"
QT_MOC_LITERAL(11, 133, 14), // "sendplayhandle"
QT_MOC_LITERAL(12, 148, 14), // "stopplaythread"
QT_MOC_LITERAL(13, 163, 12), // "sendtimelist"
QT_MOC_LITERAL(14, 176, 11), // "QList<int>*"
QT_MOC_LITERAL(15, 188, 8), // "sendflip"
QT_MOC_LITERAL(16, 197, 9), // "sendspace"
QT_MOC_LITERAL(17, 207, 11), // "composeover"
QT_MOC_LITERAL(18, 219, 16), // "circulation_play"
QT_MOC_LITERAL(19, 236, 10), // "beats_play"
QT_MOC_LITERAL(20, 247, 11), // "rhythm_play"
QT_MOC_LITERAL(21, 259, 14), // "find_paragraph"
QT_MOC_LITERAL(22, 274, 10), // "find_beats"
QT_MOC_LITERAL(23, 285, 10), // "send_speed"
QT_MOC_LITERAL(24, 296, 16), // "do_combox_change"
QT_MOC_LITERAL(25, 313, 16), // "do_volume_change"
QT_MOC_LITERAL(26, 330, 15), // "do_speed_change"
QT_MOC_LITERAL(27, 346, 17), // "do_clear_textedit"
QT_MOC_LITERAL(28, 364, 11), // "update_time"
QT_MOC_LITERAL(29, 376, 12), // "do_play_text"
QT_MOC_LITERAL(30, 389, 7), // "do_play"
QT_MOC_LITERAL(31, 397, 19), // "do_circulation_play"
QT_MOC_LITERAL(32, 417, 13), // "do_beats_play"
QT_MOC_LITERAL(33, 431, 14), // "do_rhythm_play"
QT_MOC_LITERAL(34, 446, 14), // "do_modi_rhythm"
QT_MOC_LITERAL(35, 461, 21), // "get_beats_startnumber"
QT_MOC_LITERAL(36, 483, 22), // "get_rhythm_startnumber"
QT_MOC_LITERAL(37, 506, 12), // "do_save_text"
QT_MOC_LITERAL(38, 519, 10), // "modi_beats"
QT_MOC_LITERAL(39, 530, 17), // "do_find_paragraph"
QT_MOC_LITERAL(40, 548, 13), // "do_find_beats"
QT_MOC_LITERAL(41, 562, 13), // "do_load_swing"
QT_MOC_LITERAL(42, 576, 13), // "do_save_swing"
QT_MOC_LITERAL(43, 590, 15), // "do_set_textedit"
QT_MOC_LITERAL(44, 606, 12), // "do_play_over"
QT_MOC_LITERAL(45, 619, 12), // "do_load_text"
QT_MOC_LITERAL(46, 632, 9), // "do_rising"
QT_MOC_LITERAL(47, 642, 10), // "do_falling"
QT_MOC_LITERAL(48, 653, 12), // "do_move_left"
QT_MOC_LITERAL(49, 666, 13), // "do_move_right"
QT_MOC_LITERAL(50, 680, 8), // "do_space"
QT_MOC_LITERAL(51, 689, 7), // "do_ctrl"
QT_MOC_LITERAL(52, 697, 12), // "do_backspace"
QT_MOC_LITERAL(53, 710, 17), // "do_connect_MIDIIN"
QT_MOC_LITERAL(54, 728, 11), // "getflipText"
QT_MOC_LITERAL(55, 740, 8), // "getspace"
QT_MOC_LITERAL(56, 749, 14), // "getcomposeover"
QT_MOC_LITERAL(57, 764, 15), // "button1_pressed"
QT_MOC_LITERAL(58, 780, 15), // "button2_pressed"
QT_MOC_LITERAL(59, 796, 15), // "button3_pressed"
QT_MOC_LITERAL(60, 812, 15), // "button4_pressed"
QT_MOC_LITERAL(61, 828, 15), // "button5_pressed"
QT_MOC_LITERAL(62, 844, 15), // "button6_pressed"
QT_MOC_LITERAL(63, 860, 15), // "button7_pressed"
QT_MOC_LITERAL(64, 876, 15), // "button8_pressed"
QT_MOC_LITERAL(65, 892, 15), // "button9_pressed"
QT_MOC_LITERAL(66, 908, 16), // "button10_pressed"
QT_MOC_LITERAL(67, 925, 16), // "button11_pressed"
QT_MOC_LITERAL(68, 942, 16), // "button12_pressed"
QT_MOC_LITERAL(69, 959, 16), // "button13_pressed"
QT_MOC_LITERAL(70, 976, 16), // "button14_pressed"
QT_MOC_LITERAL(71, 993, 16), // "button15_pressed"
QT_MOC_LITERAL(72, 1010, 16), // "button16_pressed"
QT_MOC_LITERAL(73, 1027, 16), // "button17_pressed"
QT_MOC_LITERAL(74, 1044, 16), // "button18_pressed"
QT_MOC_LITERAL(75, 1061, 16), // "button19_pressed"
QT_MOC_LITERAL(76, 1078, 16), // "button20_pressed"
QT_MOC_LITERAL(77, 1095, 16), // "button21_pressed"
QT_MOC_LITERAL(78, 1112, 16), // "button22_pressed"
QT_MOC_LITERAL(79, 1129, 16), // "button23_pressed"
QT_MOC_LITERAL(80, 1146, 16), // "button24_pressed"
QT_MOC_LITERAL(81, 1163, 16), // "button25_pressed"
QT_MOC_LITERAL(82, 1180, 16), // "button26_pressed"
QT_MOC_LITERAL(83, 1197, 16), // "button27_pressed"
QT_MOC_LITERAL(84, 1214, 16), // "button28_pressed"
QT_MOC_LITERAL(85, 1231, 16), // "button29_pressed"
QT_MOC_LITERAL(86, 1248, 16), // "button30_pressed"
QT_MOC_LITERAL(87, 1265, 16), // "button31_pressed"
QT_MOC_LITERAL(88, 1282, 16), // "button32_pressed"
QT_MOC_LITERAL(89, 1299, 16), // "button33_pressed"
QT_MOC_LITERAL(90, 1316, 16), // "button34_pressed"
QT_MOC_LITERAL(91, 1333, 16), // "button35_pressed"
QT_MOC_LITERAL(92, 1350, 16), // "button36_pressed"
QT_MOC_LITERAL(93, 1367, 16), // "button37_pressed"
QT_MOC_LITERAL(94, 1384, 16), // "button38_pressed"
QT_MOC_LITERAL(95, 1401, 16), // "button39_pressed"
QT_MOC_LITERAL(96, 1418, 16), // "button40_pressed"
QT_MOC_LITERAL(97, 1435, 16), // "button41_pressed"
QT_MOC_LITERAL(98, 1452, 16), // "button42_pressed"
QT_MOC_LITERAL(99, 1469, 16), // "button43_pressed"
QT_MOC_LITERAL(100, 1486, 16), // "button44_pressed"
QT_MOC_LITERAL(101, 1503, 16), // "button45_pressed"
QT_MOC_LITERAL(102, 1520, 16), // "button46_pressed"
QT_MOC_LITERAL(103, 1537, 16), // "button47_pressed"
QT_MOC_LITERAL(104, 1554, 16), // "button48_pressed"
QT_MOC_LITERAL(105, 1571, 16) // "button49_pressed"

    },
    "AudioPlayer\0sendtopitchthread\0\0"
    "do_run_pitchup\0sendtext\0sendhandle\0"
    "HMIDIOUT\0stoppitchthread\0sendtoplaythread\0"
    "do_run_play\0sendplaytext\0sendplayhandle\0"
    "stopplaythread\0sendtimelist\0QList<int>*\0"
    "sendflip\0sendspace\0composeover\0"
    "circulation_play\0beats_play\0rhythm_play\0"
    "find_paragraph\0find_beats\0send_speed\0"
    "do_combox_change\0do_volume_change\0"
    "do_speed_change\0do_clear_textedit\0"
    "update_time\0do_play_text\0do_play\0"
    "do_circulation_play\0do_beats_play\0"
    "do_rhythm_play\0do_modi_rhythm\0"
    "get_beats_startnumber\0get_rhythm_startnumber\0"
    "do_save_text\0modi_beats\0do_find_paragraph\0"
    "do_find_beats\0do_load_swing\0do_save_swing\0"
    "do_set_textedit\0do_play_over\0do_load_text\0"
    "do_rising\0do_falling\0do_move_left\0"
    "do_move_right\0do_space\0do_ctrl\0"
    "do_backspace\0do_connect_MIDIIN\0"
    "getflipText\0getspace\0getcomposeover\0"
    "button1_pressed\0button2_pressed\0"
    "button3_pressed\0button4_pressed\0"
    "button5_pressed\0button6_pressed\0"
    "button7_pressed\0button8_pressed\0"
    "button9_pressed\0button10_pressed\0"
    "button11_pressed\0button12_pressed\0"
    "button13_pressed\0button14_pressed\0"
    "button15_pressed\0button16_pressed\0"
    "button17_pressed\0button18_pressed\0"
    "button19_pressed\0button20_pressed\0"
    "button21_pressed\0button22_pressed\0"
    "button23_pressed\0button24_pressed\0"
    "button25_pressed\0button26_pressed\0"
    "button27_pressed\0button28_pressed\0"
    "button29_pressed\0button30_pressed\0"
    "button31_pressed\0button32_pressed\0"
    "button33_pressed\0button34_pressed\0"
    "button35_pressed\0button36_pressed\0"
    "button37_pressed\0button38_pressed\0"
    "button39_pressed\0button40_pressed\0"
    "button41_pressed\0button42_pressed\0"
    "button43_pressed\0button44_pressed\0"
    "button45_pressed\0button46_pressed\0"
    "button47_pressed\0button48_pressed\0"
    "button49_pressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AudioPlayer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
     103,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      20,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,  529,    2, 0x06 /* Public */,
       3,    0,  536,    2, 0x06 /* Public */,
       4,    1,  537,    2, 0x06 /* Public */,
       5,    1,  540,    2, 0x06 /* Public */,
       7,    0,  543,    2, 0x06 /* Public */,
       8,    3,  544,    2, 0x06 /* Public */,
       9,    0,  551,    2, 0x06 /* Public */,
      10,    1,  552,    2, 0x06 /* Public */,
      11,    1,  555,    2, 0x06 /* Public */,
      12,    0,  558,    2, 0x06 /* Public */,
      13,    1,  559,    2, 0x06 /* Public */,
      15,    1,  562,    2, 0x06 /* Public */,
      16,    0,  565,    2, 0x06 /* Public */,
      17,    0,  566,    2, 0x06 /* Public */,
      18,    0,  567,    2, 0x06 /* Public */,
      19,    2,  568,    2, 0x06 /* Public */,
      20,    2,  573,    2, 0x06 /* Public */,
      21,    0,  578,    2, 0x06 /* Public */,
      22,    0,  579,    2, 0x06 /* Public */,
      23,    1,  580,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      24,    0,  583,    2, 0x08 /* Private */,
      25,    1,  584,    2, 0x08 /* Private */,
      26,    1,  587,    2, 0x08 /* Private */,
      27,    0,  590,    2, 0x08 /* Private */,
      28,    0,  591,    2, 0x08 /* Private */,
      29,    0,  592,    2, 0x08 /* Private */,
      30,    0,  593,    2, 0x08 /* Private */,
      31,    0,  594,    2, 0x08 /* Private */,
      32,    0,  595,    2, 0x08 /* Private */,
      33,    0,  596,    2, 0x08 /* Private */,
      34,    0,  597,    2, 0x08 /* Private */,
      35,    1,  598,    2, 0x08 /* Private */,
      36,    1,  601,    2, 0x08 /* Private */,
      37,    0,  604,    2, 0x08 /* Private */,
      38,    0,  605,    2, 0x08 /* Private */,
      39,    0,  606,    2, 0x08 /* Private */,
      40,    0,  607,    2, 0x08 /* Private */,
      26,    1,  608,    2, 0x08 /* Private */,
      41,    0,  611,    2, 0x08 /* Private */,
      42,    0,  612,    2, 0x08 /* Private */,
      43,    1,  613,    2, 0x08 /* Private */,
      44,    1,  616,    2, 0x08 /* Private */,
      45,    0,  619,    2, 0x08 /* Private */,
      46,    0,  620,    2, 0x08 /* Private */,
      47,    0,  621,    2, 0x08 /* Private */,
      48,    0,  622,    2, 0x08 /* Private */,
      49,    0,  623,    2, 0x08 /* Private */,
      50,    0,  624,    2, 0x08 /* Private */,
      51,    0,  625,    2, 0x08 /* Private */,
      52,    0,  626,    2, 0x08 /* Private */,
      53,    0,  627,    2, 0x08 /* Private */,
      54,    1,  628,    2, 0x08 /* Private */,
      55,    0,  631,    2, 0x08 /* Private */,
      56,    0,  632,    2, 0x08 /* Private */,
      57,    0,  633,    2, 0x08 /* Private */,
      58,    0,  634,    2, 0x08 /* Private */,
      59,    0,  635,    2, 0x08 /* Private */,
      60,    0,  636,    2, 0x08 /* Private */,
      61,    0,  637,    2, 0x08 /* Private */,
      62,    0,  638,    2, 0x08 /* Private */,
      63,    0,  639,    2, 0x08 /* Private */,
      64,    0,  640,    2, 0x08 /* Private */,
      65,    0,  641,    2, 0x08 /* Private */,
      66,    0,  642,    2, 0x08 /* Private */,
      67,    0,  643,    2, 0x08 /* Private */,
      68,    0,  644,    2, 0x08 /* Private */,
      69,    0,  645,    2, 0x08 /* Private */,
      70,    0,  646,    2, 0x08 /* Private */,
      71,    0,  647,    2, 0x08 /* Private */,
      72,    0,  648,    2, 0x08 /* Private */,
      73,    0,  649,    2, 0x08 /* Private */,
      74,    0,  650,    2, 0x08 /* Private */,
      75,    0,  651,    2, 0x08 /* Private */,
      76,    0,  652,    2, 0x08 /* Private */,
      77,    0,  653,    2, 0x08 /* Private */,
      78,    0,  654,    2, 0x08 /* Private */,
      79,    0,  655,    2, 0x08 /* Private */,
      80,    0,  656,    2, 0x08 /* Private */,
      81,    0,  657,    2, 0x08 /* Private */,
      82,    0,  658,    2, 0x08 /* Private */,
      83,    0,  659,    2, 0x08 /* Private */,
      84,    0,  660,    2, 0x08 /* Private */,
      85,    0,  661,    2, 0x08 /* Private */,
      86,    0,  662,    2, 0x08 /* Private */,
      87,    0,  663,    2, 0x08 /* Private */,
      88,    0,  664,    2, 0x08 /* Private */,
      89,    0,  665,    2, 0x08 /* Private */,
      90,    0,  666,    2, 0x08 /* Private */,
      91,    0,  667,    2, 0x08 /* Private */,
      92,    0,  668,    2, 0x08 /* Private */,
      93,    0,  669,    2, 0x08 /* Private */,
      94,    0,  670,    2, 0x08 /* Private */,
      95,    0,  671,    2, 0x08 /* Private */,
      96,    0,  672,    2, 0x08 /* Private */,
      97,    0,  673,    2, 0x08 /* Private */,
      98,    0,  674,    2, 0x08 /* Private */,
      99,    0,  675,    2, 0x08 /* Private */,
     100,    0,  676,    2, 0x08 /* Private */,
     101,    0,  677,    2, 0x08 /* Private */,
     102,    0,  678,    2, 0x08 /* Private */,
     103,    0,  679,    2, 0x08 /* Private */,
     104,    0,  680,    2, 0x08 /* Private */,
     105,    0,  681,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AudioPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AudioPlayer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendtopitchthread((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->do_run_pitchup(); break;
        case 2: _t->sendtext((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->sendhandle((*reinterpret_cast< HMIDIOUT(*)>(_a[1]))); break;
        case 4: _t->stoppitchthread(); break;
        case 5: _t->sendtoplaythread((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->do_run_play(); break;
        case 7: _t->sendplaytext((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->sendplayhandle((*reinterpret_cast< HMIDIOUT(*)>(_a[1]))); break;
        case 9: _t->stopplaythread(); break;
        case 10: _t->sendtimelist((*reinterpret_cast< QList<int>*(*)>(_a[1]))); break;
        case 11: _t->sendflip((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->sendspace(); break;
        case 13: _t->composeover(); break;
        case 14: _t->circulation_play(); break;
        case 15: _t->beats_play((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 16: _t->rhythm_play((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 17: _t->find_paragraph(); break;
        case 18: _t->find_beats(); break;
        case 19: _t->send_speed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 20: _t->do_combox_change(); break;
        case 21: _t->do_volume_change((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->do_speed_change((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->do_clear_textedit(); break;
        case 24: _t->update_time(); break;
        case 25: _t->do_play_text(); break;
        case 26: _t->do_play(); break;
        case 27: _t->do_circulation_play(); break;
        case 28: _t->do_beats_play(); break;
        case 29: _t->do_rhythm_play(); break;
        case 30: _t->do_modi_rhythm(); break;
        case 31: _t->get_beats_startnumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->get_rhythm_startnumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->do_save_text(); break;
        case 34: _t->modi_beats(); break;
        case 35: _t->do_find_paragraph(); break;
        case 36: _t->do_find_beats(); break;
        case 37: _t->do_speed_change((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 38: _t->do_load_swing(); break;
        case 39: _t->do_save_swing(); break;
        case 40: _t->do_set_textedit((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 41: _t->do_play_over((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 42: _t->do_load_text(); break;
        case 43: _t->do_rising(); break;
        case 44: _t->do_falling(); break;
        case 45: _t->do_move_left(); break;
        case 46: _t->do_move_right(); break;
        case 47: _t->do_space(); break;
        case 48: _t->do_ctrl(); break;
        case 49: _t->do_backspace(); break;
        case 50: _t->do_connect_MIDIIN(); break;
        case 51: _t->getflipText((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 52: _t->getspace(); break;
        case 53: _t->getcomposeover(); break;
        case 54: _t->button1_pressed(); break;
        case 55: _t->button2_pressed(); break;
        case 56: _t->button3_pressed(); break;
        case 57: _t->button4_pressed(); break;
        case 58: _t->button5_pressed(); break;
        case 59: _t->button6_pressed(); break;
        case 60: _t->button7_pressed(); break;
        case 61: _t->button8_pressed(); break;
        case 62: _t->button9_pressed(); break;
        case 63: _t->button10_pressed(); break;
        case 64: _t->button11_pressed(); break;
        case 65: _t->button12_pressed(); break;
        case 66: _t->button13_pressed(); break;
        case 67: _t->button14_pressed(); break;
        case 68: _t->button15_pressed(); break;
        case 69: _t->button16_pressed(); break;
        case 70: _t->button17_pressed(); break;
        case 71: _t->button18_pressed(); break;
        case 72: _t->button19_pressed(); break;
        case 73: _t->button20_pressed(); break;
        case 74: _t->button21_pressed(); break;
        case 75: _t->button22_pressed(); break;
        case 76: _t->button23_pressed(); break;
        case 77: _t->button24_pressed(); break;
        case 78: _t->button25_pressed(); break;
        case 79: _t->button26_pressed(); break;
        case 80: _t->button27_pressed(); break;
        case 81: _t->button28_pressed(); break;
        case 82: _t->button29_pressed(); break;
        case 83: _t->button30_pressed(); break;
        case 84: _t->button31_pressed(); break;
        case 85: _t->button32_pressed(); break;
        case 86: _t->button33_pressed(); break;
        case 87: _t->button34_pressed(); break;
        case 88: _t->button35_pressed(); break;
        case 89: _t->button36_pressed(); break;
        case 90: _t->button37_pressed(); break;
        case 91: _t->button38_pressed(); break;
        case 92: _t->button39_pressed(); break;
        case 93: _t->button40_pressed(); break;
        case 94: _t->button41_pressed(); break;
        case 95: _t->button42_pressed(); break;
        case 96: _t->button43_pressed(); break;
        case 97: _t->button44_pressed(); break;
        case 98: _t->button45_pressed(); break;
        case 99: _t->button46_pressed(); break;
        case 100: _t->button47_pressed(); break;
        case 101: _t->button48_pressed(); break;
        case 102: _t->button49_pressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AudioPlayer::*)(int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AudioPlayer::sendtopitchthread)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AudioPlayer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AudioPlayer::do_run_pitchup)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AudioPlayer::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AudioPlayer::sendtext)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (AudioPlayer::*)(HMIDIOUT );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AudioPlayer::sendhandle)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (AudioPlayer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AudioPlayer::stoppitchthread)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (AudioPlayer::*)(int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AudioPlayer::sendtoplaythread)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (AudioPlayer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AudioPlayer::do_run_play)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (AudioPlayer::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AudioPlayer::sendplaytext)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (AudioPlayer::*)(HMIDIOUT );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AudioPlayer::sendplayhandle)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (AudioPlayer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AudioPlayer::stopplaythread)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (AudioPlayer::*)(QList<int> * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AudioPlayer::sendtimelist)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (AudioPlayer::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AudioPlayer::sendflip)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (AudioPlayer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AudioPlayer::sendspace)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (AudioPlayer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AudioPlayer::composeover)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (AudioPlayer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AudioPlayer::circulation_play)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (AudioPlayer::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AudioPlayer::beats_play)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (AudioPlayer::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AudioPlayer::rhythm_play)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (AudioPlayer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AudioPlayer::find_paragraph)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (AudioPlayer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AudioPlayer::find_beats)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (AudioPlayer::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AudioPlayer::send_speed)) {
                *result = 19;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AudioPlayer::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_AudioPlayer.data,
    qt_meta_data_AudioPlayer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AudioPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AudioPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AudioPlayer.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int AudioPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 103)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 103;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 103)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 103;
    }
    return _id;
}

// SIGNAL 0
void AudioPlayer::sendtopitchthread(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AudioPlayer::do_run_pitchup()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void AudioPlayer::sendtext(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void AudioPlayer::sendhandle(HMIDIOUT _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void AudioPlayer::stoppitchthread()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void AudioPlayer::sendtoplaythread(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void AudioPlayer::do_run_play()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void AudioPlayer::sendplaytext(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void AudioPlayer::sendplayhandle(HMIDIOUT _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void AudioPlayer::stopplaythread()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void AudioPlayer::sendtimelist(QList<int> * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void AudioPlayer::sendflip(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void AudioPlayer::sendspace()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void AudioPlayer::composeover()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void AudioPlayer::circulation_play()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void AudioPlayer::beats_play(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void AudioPlayer::rhythm_play(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void AudioPlayer::find_paragraph()
{
    QMetaObject::activate(this, &staticMetaObject, 17, nullptr);
}

// SIGNAL 18
void AudioPlayer::find_beats()
{
    QMetaObject::activate(this, &staticMetaObject, 18, nullptr);
}

// SIGNAL 19
void AudioPlayer::send_speed(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
