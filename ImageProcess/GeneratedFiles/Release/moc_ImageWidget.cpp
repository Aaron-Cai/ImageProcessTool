/****************************************************************************
** Meta object code from reading C++ file 'ImageWidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ImageWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ImageWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ImageWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   13,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      44,   12,   12,   12, 0x0a,
      55,   12,   12,   12, 0x0a,
      65,   12,   12,   12, 0x0a,
      74,   13,   12,   12, 0x0a,
      93,   12,   12,   12, 0x0a,
     100,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ImageWidget[] = {
    "ImageWidget\0\0x,y\0sig_condional_dia(int,int)\0"
    "resetPos()\0zoomout()\0zoomin()\0"
    "translate(int,int)\0save()\0con_dia()\0"
};

void ImageWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ImageWidget *_t = static_cast<ImageWidget *>(_o);
        switch (_id) {
        case 0: _t->sig_condional_dia((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->resetPos(); break;
        case 2: _t->zoomout(); break;
        case 3: _t->zoomin(); break;
        case 4: _t->translate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->save(); break;
        case 6: _t->con_dia(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ImageWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ImageWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ImageWidget,
      qt_meta_data_ImageWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ImageWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ImageWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ImageWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ImageWidget))
        return static_cast<void*>(const_cast< ImageWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ImageWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ImageWidget::sig_condional_dia(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
