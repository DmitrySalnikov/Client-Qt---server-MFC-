/****************************************************************************
** Meta object code from reading C++ file 'dlg.h'
**
** Created: Wed 16. Dec 17:15:57 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dlg[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       5,    4,    4,    4, 0x08,
      34,    4,    4,    4, 0x08,
      46,    4,    4,    4, 0x08,
      55,    4,    4,    4, 0x08,
      70,    4,    4,    4, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_dlg[] = {
    "dlg\0\0on_ModelPushButton_clicked()\0"
    "OnConnect()\0OnRead()\0OnDisconnect()\0"
    "OnError()\0"
};

void dlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        dlg *_t = static_cast<dlg *>(_o);
        switch (_id) {
        case 0: _t->on_ModelPushButton_clicked(); break;
        case 1: _t->OnConnect(); break;
        case 2: _t->OnRead(); break;
        case 3: _t->OnDisconnect(); break;
        case 4: _t->OnError(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData dlg::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject dlg::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_dlg,
      qt_meta_data_dlg, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dlg))
        return static_cast<void*>(const_cast< dlg*>(this));
    return QWidget::qt_metacast(_clname);
}

int dlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
