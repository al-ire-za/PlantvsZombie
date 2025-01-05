/****************************************************************************
** Meta object code from reading C++ file 'Gameplay_page.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../Gameplay_page.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Gameplay_page.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN13Gameplay_pageE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN13Gameplay_pageE = QtMocHelpers::stringData(
    "Gameplay_page",
    "checkCollisions",
    "",
    "updateElixir",
    "removeEnemies",
    "QList<Enemy*>",
    "enemiesToRemove",
    "removeBombTrap",
    "AgentBase*",
    "agent",
    "createBoss",
    "on_PGolmushaki_clicked",
    "on_PGorbemahi_clicked",
    "on_PKalam_clicked",
    "on_PGandom_clicked",
    "on_PBomb_clicked",
    "on_PTrap_clicked",
    "onEnemyKilled",
    "Enemy*",
    "enemy"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN13Gameplay_pageE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x08,    1 /* Private */,
       3,    0,   87,    2, 0x08,    2 /* Private */,
       4,    1,   88,    2, 0x08,    3 /* Private */,
       7,    1,   91,    2, 0x08,    5 /* Private */,
      10,    0,   94,    2, 0x08,    7 /* Private */,
      11,    0,   95,    2, 0x08,    8 /* Private */,
      12,    0,   96,    2, 0x08,    9 /* Private */,
      13,    0,   97,    2, 0x08,   10 /* Private */,
      14,    0,   98,    2, 0x08,   11 /* Private */,
      15,    0,   99,    2, 0x08,   12 /* Private */,
      16,    0,  100,    2, 0x08,   13 /* Private */,
      17,    1,  101,    2, 0x0a,   14 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,   19,

       0        // eod
};

Q_CONSTINIT const QMetaObject Gameplay_page::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_ZN13Gameplay_pageE.offsetsAndSizes,
    qt_meta_data_ZN13Gameplay_pageE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN13Gameplay_pageE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Gameplay_page, std::true_type>,
        // method 'checkCollisions'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateElixir'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'removeEnemies'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVector<Enemy*> &, std::false_type>,
        // method 'removeBombTrap'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<AgentBase *, std::false_type>,
        // method 'createBoss'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_PGolmushaki_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_PGorbemahi_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_PKalam_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_PGandom_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_PBomb_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_PTrap_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onEnemyKilled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Enemy *, std::false_type>
    >,
    nullptr
} };

void Gameplay_page::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Gameplay_page *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->checkCollisions(); break;
        case 1: _t->updateElixir(); break;
        case 2: _t->removeEnemies((*reinterpret_cast< std::add_pointer_t<QList<Enemy*>>>(_a[1]))); break;
        case 3: _t->removeBombTrap((*reinterpret_cast< std::add_pointer_t<AgentBase*>>(_a[1]))); break;
        case 4: _t->createBoss(); break;
        case 5: _t->on_PGolmushaki_clicked(); break;
        case 6: _t->on_PGorbemahi_clicked(); break;
        case 7: _t->on_PKalam_clicked(); break;
        case 8: _t->on_PGandom_clicked(); break;
        case 9: _t->on_PBomb_clicked(); break;
        case 10: _t->on_PTrap_clicked(); break;
        case 11: _t->onEnemyKilled((*reinterpret_cast< std::add_pointer_t<Enemy*>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<Enemy*> >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< AgentBase* >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Enemy* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *Gameplay_page::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Gameplay_page::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN13Gameplay_pageE.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Gameplay_page::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
