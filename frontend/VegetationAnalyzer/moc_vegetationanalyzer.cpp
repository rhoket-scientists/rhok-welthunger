/****************************************************************************
** Meta object code from reading C++ file 'vegetationanalyzer.h'
**
** Created: Sun Jun 3 14:11:30 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "vegetationanalyzer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vegetationanalyzer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VegetationAnalyzer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x08,
      61,   19,   19,   19, 0x08,
      96,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_VegetationAnalyzer[] = {
    "VegetationAnalyzer\0\0"
    "on_listWidget_doubleClicked(QModelIndex)\0"
    "on_listWidget_clicked(QModelIndex)\0"
    "on_actionOpen_triggered()\0"
};

void VegetationAnalyzer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        VegetationAnalyzer *_t = static_cast<VegetationAnalyzer *>(_o);
        switch (_id) {
        case 0: _t->on_listWidget_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->on_listWidget_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->on_actionOpen_triggered(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData VegetationAnalyzer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VegetationAnalyzer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_VegetationAnalyzer,
      qt_meta_data_VegetationAnalyzer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VegetationAnalyzer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VegetationAnalyzer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VegetationAnalyzer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VegetationAnalyzer))
        return static_cast<void*>(const_cast< VegetationAnalyzer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int VegetationAnalyzer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
