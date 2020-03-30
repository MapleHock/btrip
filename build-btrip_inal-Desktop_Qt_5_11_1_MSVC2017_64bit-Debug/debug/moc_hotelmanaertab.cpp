/****************************************************************************
** Meta object code from reading C++ file 'hotelmanaertab.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../hotelmanaertab.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hotelmanaertab.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HotelManaerTab_t {
    QByteArrayData data[12];
    char stringdata0[228];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HotelManaerTab_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HotelManaerTab_t qt_meta_stringdata_HotelManaerTab = {
    {
QT_MOC_LITERAL(0, 0, 14), // "HotelManaerTab"
QT_MOC_LITERAL(1, 15, 24), // "on_search_button_clicked"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 33), // "on_room_type_lineedit_textCha..."
QT_MOC_LITERAL(4, 75, 4), // "arg1"
QT_MOC_LITERAL(5, 80, 24), // "on_accept_button_clicked"
QT_MOC_LITERAL(6, 105, 24), // "on_reject_button_clicked"
QT_MOC_LITERAL(7, 130, 31), // "on_room_table_cellDoubleClicked"
QT_MOC_LITERAL(8, 162, 3), // "row"
QT_MOC_LITERAL(9, 166, 6), // "column"
QT_MOC_LITERAL(10, 173, 29), // "on_unfinish_table_cellClicked"
QT_MOC_LITERAL(11, 203, 24) // "on_finish_button_clicked"

    },
    "HotelManaerTab\0on_search_button_clicked\0"
    "\0on_room_type_lineedit_textChanged\0"
    "arg1\0on_accept_button_clicked\0"
    "on_reject_button_clicked\0"
    "on_room_table_cellDoubleClicked\0row\0"
    "column\0on_unfinish_table_cellClicked\0"
    "on_finish_button_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HotelManaerTab[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    1,   50,    2, 0x08 /* Private */,
       5,    0,   53,    2, 0x08 /* Private */,
       6,    0,   54,    2, 0x08 /* Private */,
       7,    2,   55,    2, 0x08 /* Private */,
      10,    2,   60,    2, 0x08 /* Private */,
      11,    0,   65,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void,

       0        // eod
};

void HotelManaerTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HotelManaerTab *_t = static_cast<HotelManaerTab *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_search_button_clicked(); break;
        case 1: _t->on_room_type_lineedit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_accept_button_clicked(); break;
        case 3: _t->on_reject_button_clicked(); break;
        case 4: _t->on_room_table_cellDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->on_unfinish_table_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->on_finish_button_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HotelManaerTab::staticMetaObject = {
    { &QTabWidget::staticMetaObject, qt_meta_stringdata_HotelManaerTab.data,
      qt_meta_data_HotelManaerTab,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *HotelManaerTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HotelManaerTab::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HotelManaerTab.stringdata0))
        return static_cast<void*>(this);
    return QTabWidget::qt_metacast(_clname);
}

int HotelManaerTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
