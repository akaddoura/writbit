/****************************************************************************
** Meta object code from reading C++ file 'notes.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../TextEditor/notes.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'notes.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Notes_t {
    QByteArrayData data[26];
    char stringdata0[425];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Notes_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Notes_t qt_meta_stringdata_Notes = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Notes"
QT_MOC_LITERAL(1, 6, 9), // "sendNotes"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 10), // "NoteSheet*"
QT_MOC_LITERAL(4, 28, 9), // "loadNewDB"
QT_MOC_LITERAL(5, 38, 6), // "dbName"
QT_MOC_LITERAL(6, 45, 24), // "on_addNoteButton_clicked"
QT_MOC_LITERAL(7, 70, 23), // "on_tagsList_itemClicked"
QT_MOC_LITERAL(8, 94, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(9, 111, 4), // "item"
QT_MOC_LITERAL(10, 116, 27), // "on_removeNoteButton_clicked"
QT_MOC_LITERAL(11, 144, 29), // "on_notesSearchBar_textChanged"
QT_MOC_LITERAL(12, 174, 4), // "arg1"
QT_MOC_LITERAL(13, 179, 24), // "on_refreshButton_clicked"
QT_MOC_LITERAL(14, 204, 25), // "on_updateDatabase_clicked"
QT_MOC_LITERAL(15, 230, 16), // "noteSheetChanged"
QT_MOC_LITERAL(16, 247, 9), // "isChanged"
QT_MOC_LITERAL(17, 257, 26), // "on_sendToSidePanel_clicked"
QT_MOC_LITERAL(18, 284, 23), // "on_loadDatabase_clicked"
QT_MOC_LITERAL(19, 308, 22), // "on_newDatabase_clicked"
QT_MOC_LITERAL(20, 331, 20), // "on_buttonBox_clicked"
QT_MOC_LITERAL(21, 352, 16), // "QAbstractButton*"
QT_MOC_LITERAL(22, 369, 6), // "button"
QT_MOC_LITERAL(23, 376, 11), // "checkToSave"
QT_MOC_LITERAL(24, 388, 21), // "on_buttonBox_accepted"
QT_MOC_LITERAL(25, 410, 14) // "getCurrentTags"

    },
    "Notes\0sendNotes\0\0NoteSheet*\0loadNewDB\0"
    "dbName\0on_addNoteButton_clicked\0"
    "on_tagsList_itemClicked\0QListWidgetItem*\0"
    "item\0on_removeNoteButton_clicked\0"
    "on_notesSearchBar_textChanged\0arg1\0"
    "on_refreshButton_clicked\0"
    "on_updateDatabase_clicked\0noteSheetChanged\0"
    "isChanged\0on_sendToSidePanel_clicked\0"
    "on_loadDatabase_clicked\0on_newDatabase_clicked\0"
    "on_buttonBox_clicked\0QAbstractButton*\0"
    "button\0checkToSave\0on_buttonBox_accepted\0"
    "getCurrentTags"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Notes[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       4,    1,   97,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,  100,    2, 0x08 /* Private */,
       7,    1,  101,    2, 0x08 /* Private */,
      10,    0,  104,    2, 0x08 /* Private */,
      11,    1,  105,    2, 0x08 /* Private */,
      13,    0,  108,    2, 0x08 /* Private */,
      14,    0,  109,    2, 0x08 /* Private */,
      15,    1,  110,    2, 0x08 /* Private */,
      17,    0,  113,    2, 0x08 /* Private */,
      18,    0,  114,    2, 0x08 /* Private */,
      19,    0,  115,    2, 0x08 /* Private */,
      20,    1,  116,    2, 0x08 /* Private */,
      23,    0,  119,    2, 0x08 /* Private */,
      24,    0,  120,    2, 0x08 /* Private */,
      25,    0,  121,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QStringList,

       0        // eod
};

void Notes::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Notes *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendNotes((*reinterpret_cast< NoteSheet*(*)>(_a[1]))); break;
        case 1: _t->loadNewDB((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_addNoteButton_clicked(); break;
        case 3: _t->on_tagsList_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->on_removeNoteButton_clicked(); break;
        case 5: _t->on_notesSearchBar_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_refreshButton_clicked(); break;
        case 7: _t->on_updateDatabase_clicked(); break;
        case 8: _t->noteSheetChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_sendToSidePanel_clicked(); break;
        case 10: _t->on_loadDatabase_clicked(); break;
        case 11: _t->on_newDatabase_clicked(); break;
        case 12: _t->on_buttonBox_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 13: _t->checkToSave(); break;
        case 14: _t->on_buttonBox_accepted(); break;
        case 15: { QStringList _r = _t->getCurrentTags();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< NoteSheet* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Notes::*)(NoteSheet * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Notes::sendNotes)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Notes::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Notes::loadNewDB)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Notes::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Notes.data,
    qt_meta_data_Notes,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Notes::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Notes::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Notes.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Notes::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void Notes::sendNotes(NoteSheet * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Notes::loadNewDB(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
