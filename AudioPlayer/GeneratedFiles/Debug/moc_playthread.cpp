/****************************************************************************
** Meta object code from reading C++ file 'playthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../playthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'playthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PlayThread_t {
    QByteArrayData data[18];
    char stringdata0[200];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlayThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlayThread_t qt_meta_stringdata_PlayThread = {
    {
QT_MOC_LITERAL(0, 0, 10), // "PlayThread"
QT_MOC_LITERAL(1, 11, 11), // "settextedit"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 8), // "playover"
QT_MOC_LITERAL(4, 33, 19), // "sendbeatstartnumber"
QT_MOC_LITERAL(5, 53, 21), // "sendrhythmstartnumber"
QT_MOC_LITERAL(6, 75, 6), // "do_run"
QT_MOC_LITERAL(7, 82, 7), // "gettext"
QT_MOC_LITERAL(8, 90, 15), // "getinformations"
QT_MOC_LITERAL(9, 106, 4), // "stop"
QT_MOC_LITERAL(10, 111, 9), // "gethandle"
QT_MOC_LITERAL(11, 121, 8), // "HMIDIOUT"
QT_MOC_LITERAL(12, 130, 11), // "gettimelist"
QT_MOC_LITERAL(13, 142, 11), // "QList<int>*"
QT_MOC_LITERAL(14, 154, 15), // "circulationplay"
QT_MOC_LITERAL(15, 170, 8), // "beatplay"
QT_MOC_LITERAL(16, 179, 10), // "rhythmplay"
QT_MOC_LITERAL(17, 190, 9) // "get_speed"

    },
    "PlayThread\0settextedit\0\0playover\0"
    "sendbeatstartnumber\0sendrhythmstartnumber\0"
    "do_run\0gettext\0getinformations\0stop\0"
    "gethandle\0HMIDIOUT\0gettimelist\0"
    "QList<int>*\0circulationplay\0beatplay\0"
    "rhythmplay\0get_speed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlayThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       3,    1,   87,    2, 0x06 /* Public */,
       4,    1,   90,    2, 0x06 /* Public */,
       5,    1,   93,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   96,    2, 0x08 /* Private */,
       7,    1,   97,    2, 0x08 /* Private */,
       8,    3,  100,    2, 0x08 /* Private */,
       9,    0,  107,    2, 0x08 /* Private */,
      10,    1,  108,    2, 0x08 /* Private */,
      12,    1,  111,    2, 0x08 /* Private */,
      14,    0,  114,    2, 0x08 /* Private */,
      15,    2,  115,    2, 0x08 /* Private */,
      16,    2,  120,    2, 0x08 /* Private */,
      17,    1,  125,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Double,    2,

       0        // eod
};

void PlayThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PlayThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->settextedit((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->playover((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sendbeatstartnumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->sendrhythmstartnumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->do_run(); break;
        case 5: _t->gettext((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->getinformations((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 7: _t->stop(); break;
        case 8: _t->gethandle((*reinterpret_cast< HMIDIOUT(*)>(_a[1]))); break;
        case 9: _t->gettimelist((*reinterpret_cast< QList<int>*(*)>(_a[1]))); break;
        case 10: _t->circulationplay(); break;
        case 11: _t->beatplay((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->rhythmplay((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: _t->get_speed((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PlayThread::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayThread::settextedit)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PlayThread::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayThread::playover)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PlayThread::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayThread::sendbeatstartnumber)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PlayThread::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayThread::sendrhythmstartnumber)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PlayThread::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_PlayThread.data,
    qt_meta_data_PlayThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PlayThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlayThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PlayThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int PlayThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void PlayThread::settextedit(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PlayThread::playover(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PlayThread::sendbeatstartnumber(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PlayThread::sendrhythmstartnumber(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
