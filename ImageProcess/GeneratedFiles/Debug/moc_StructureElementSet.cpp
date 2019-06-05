/****************************************************************************
** Meta object code from reading C++ file 'StructureElementSet.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../StructureElementSet.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StructureElementSet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_StructureElementSet[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      30,   21,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
      49,   20,   20,   20, 0x0a,
      64,   62,   20,   20, 0x0a,
      79,   77,   20,   20, 0x0a,
      95,   20,   20,   20, 0x0a,
     106,   20,   20,   20, 0x0a,
     123,  119,   20,   20, 0x0a,
     144,  142,   20,   20, 0x0a,
     166,  164,   20,   20, 0x0a,
     186,   20,   20,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_StructureElementSet[] = {
    "StructureElementSet\0\0se,cx,cy\0"
    "sendSE(SE,int,int)\0showDialog()\0r\0"
    "setRows(int)\0c\0setColumns(int)\0"
    "setTable()\0clearTable()\0x,y\0"
    "setCenter(int,int)\0x\0setCenterX(QString)\0"
    "y\0setCenterY(QString)\0setSE()\0"
};

void StructureElementSet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        StructureElementSet *_t = static_cast<StructureElementSet *>(_o);
        switch (_id) {
        case 0: _t->sendSE((*reinterpret_cast< SE(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->showDialog(); break;
        case 2: _t->setRows((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setColumns((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setTable(); break;
        case 5: _t->clearTable(); break;
        case 6: _t->setCenter((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->setCenterX((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->setCenterY((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->setSE(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData StructureElementSet::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject StructureElementSet::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_StructureElementSet,
      qt_meta_data_StructureElementSet, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StructureElementSet::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StructureElementSet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StructureElementSet::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StructureElementSet))
        return static_cast<void*>(const_cast< StructureElementSet*>(this));
    return QObject::qt_metacast(_clname);
}

int StructureElementSet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void StructureElementSet::sendSE(SE _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
