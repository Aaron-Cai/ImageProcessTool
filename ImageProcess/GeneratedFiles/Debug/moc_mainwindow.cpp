/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      24,   11,   11,   11, 0x0a,
      36,   11,   11,   11, 0x0a,
      54,   52,   11,   11, 0x0a,
      83,   74,   11,   11, 0x0a,
     115,   11,   11,   11, 0x0a,
     128,   11,   11,   11, 0x0a,
     154,  144,   11,   11, 0x0a,
     174,  172,   11,   11, 0x0a,
     184,   11,   11,   11, 0x0a,
     194,   11,   11,   11, 0x0a,
     205,   11,   11,   11, 0x0a,
     215,   11,   11,   11, 0x0a,
     222,   11,   11,   11, 0x0a,
     236,   11,   11,   11, 0x0a,
     256,   11,   11,   11, 0x0a,
     270,   11,   11,   11, 0x0a,
     281,   11,   11,   11, 0x0a,
     292,   11,   11,   11, 0x0a,
     322,  318,   11,   11, 0x0a,
     353,   11,   11,   11, 0x0a,
     360,   11,   11,   11, 0x0a,
     367,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0loadImage()\0saveImage()\0"
    "showHistogram()\0i\0SetProjectView(int)\0"
    "se,cx,cy\0setStructureElement(SE,int,int)\0"
    "otsuBinary()\0entropyBinary()\0threshold\0"
    "binarization(int)\0t\0conv(int)\0cusconv()\0"
    "dilation()\0erosion()\0open()\0morph_close()\0"
    "distanceTransform()\0getSkeleton()\0"
    "edgeDect()\0gradient()\0grayScaleReconstruction()\0"
    "x,y\0conditional_dialation(int,int)\0"
    "undo()\0redo()\0clearOperations()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->loadImage(); break;
        case 1: _t->saveImage(); break;
        case 2: _t->showHistogram(); break;
        case 3: _t->SetProjectView((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setStructureElement((*reinterpret_cast< SE(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 5: _t->otsuBinary(); break;
        case 6: _t->entropyBinary(); break;
        case 7: _t->binarization((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->conv((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->cusconv(); break;
        case 10: _t->dilation(); break;
        case 11: _t->erosion(); break;
        case 12: _t->open(); break;
        case 13: _t->morph_close(); break;
        case 14: _t->distanceTransform(); break;
        case 15: _t->getSkeleton(); break;
        case 16: _t->edgeDect(); break;
        case 17: _t->gradient(); break;
        case 18: _t->grayScaleReconstruction(); break;
        case 19: _t->conditional_dialation((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 20: _t->undo(); break;
        case 21: _t->redo(); break;
        case 22: _t->clearOperations(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
