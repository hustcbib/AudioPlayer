/****************************************************************************
** Meta object code from reading C++ file 'pitchthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../pitchthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pitchthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PitchThread_t {
    QByteArrayData data[8];
    char stringdata0[68];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PitchThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PitchThread_t qt_meta_stringdata_PitchThread = {
    {
QT_MOC_LITERAL(0, 0, 11), // "PitchThread"
QT_MOC_LITERAL(1, 12, 7), // "gettext"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 15), // "getinformations"
QT_MOC_LITERAL(4, 37, 4), // "stop"
QT_MOC_LITERAL(5, 42, 6), // "do_run"
QT_MOC_LITERAL(6, 49, 9), // "gethandle"
QT_MOC_LITERAL(7, 59, 8) // "HMIDIOUT"

    },
    "PitchThread\0gettext\0\0getinformations\0"
    "stop\0do_run\0gethandle\0HMIDIOUT"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PitchThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       3,    3,   42,    2, 0x08 /* Private */,
       4,    0,   49,    2, 0x08 /* Private */,
       5,    0,   50,    2, 0x08 /* Private */,
       6,    1,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,

       0        // eod
};

void PitchThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PitchThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->gettext((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->getinformations((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->stop(); break;
        case 3: _t->do_run(); break;
        case 4: _t->gethandle((*reinterpret_cast< HMIDIOUT(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PitchThread::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_PitchThread.data,
    qt_meta_data_PitchThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PitchThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PitchThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PitchThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int PitchThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
