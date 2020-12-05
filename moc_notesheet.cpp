/****************************************************************************
** Meta object code from reading C++ file 'notesheet.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../TextEditor/notesheet.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'notesheet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NoteSheet_t {
    QByteArrayData data[18];
    char stringdata0[336];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NoteSheet_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NoteSheet_t qt_meta_stringdata_NoteSheet = {
    {
QT_MOC_LITERAL(0, 0, 9), // "NoteSheet"
QT_MOC_LITERAL(1, 10, 11), // "noteChanged"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 9), // "isChanged"
QT_MOC_LITERAL(4, 33, 31), // "on_noteTagsUI_itemDoubleClicked"
QT_MOC_LITERAL(5, 65, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(6, 82, 4), // "item"
QT_MOC_LITERAL(7, 87, 23), // "on_addTagButton_clicked"
QT_MOC_LITERAL(8, 111, 26), // "on_deleteTagButton_clicked"
QT_MOC_LITERAL(9, 138, 25), // "on_noteTitleUI_textEdited"
QT_MOC_LITERAL(10, 164, 4), // "arg1"
QT_MOC_LITERAL(11, 169, 28), // "on_noteContentUI_textChanged"
QT_MOC_LITERAL(12, 198, 25), // "on_saveNoteButton_clicked"
QT_MOC_LITERAL(13, 224, 12), // "getLastTagID"
QT_MOC_LITERAL(14, 237, 27), // "on_noteTagsUI_itemActivated"
QT_MOC_LITERAL(15, 265, 25), // "on_noteTagsUI_itemChanged"
QT_MOC_LITERAL(16, 291, 32), // "on_noteTagsUI_currentTextChanged"
QT_MOC_LITERAL(17, 324, 11) // "currentText"

    },
    "NoteSheet\0noteChanged\0\0isChanged\0"
    "on_noteTagsUI_itemDoubleClicked\0"
    "QListWidgetItem*\0item\0on_addTagButton_clicked\0"
    "on_deleteTagButton_clicked\0"
    "on_noteTitleUI_textEdited\0arg1\0"
    "on_noteContentUI_textChanged\0"
    "on_saveNoteButton_clicked\0getLastTagID\0"
    "on_noteTagsUI_itemActivated\0"
    "on_noteTagsUI_itemChanged\0"
    "on_noteTagsUI_currentTextChanged\0"
    "currentText"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NoteSheet[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   72,    2, 0x08 /* Private */,
       7,    0,   75,    2, 0x08 /* Private */,
       8,    0,   76,    2, 0x08 /* Private */,
       9,    1,   77,    2, 0x08 /* Private */,
      11,    0,   80,    2, 0x08 /* Private */,
      12,    0,   81,    2, 0x08 /* Private */,
      13,    0,   82,    2, 0x08 /* Private */,
      14,    1,   83,    2, 0x08 /* Private */,
      15,    1,   86,    2, 0x08 /* Private */,
      16,    1,   89,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QString,   17,

       0        // eod
};

void NoteSheet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NoteSheet *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->noteChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_noteTagsUI_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->on_addTagButton_clicked(); break;
        case 3: _t->on_deleteTagButton_clicked(); break;
        case 4: _t->on_noteTitleUI_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_noteContentUI_textChanged(); break;
        case 6: _t->on_saveNoteButton_clicked(); break;
        case 7: _t->getLastTagID(); break;
        case 8: _t->on_noteTagsUI_itemActivated((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 9: _t->on_noteTagsUI_itemChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 10: _t->on_noteTagsUI_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NoteSheet::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NoteSheet::noteChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject NoteSheet::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidgetListItem::staticMetaObject>(),
    qt_meta_stringdata_NoteSheet.data,
    qt_meta_data_NoteSheet,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NoteSheet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NoteSheet::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NoteSheet.stringdata0))
        return static_cast<void*>(this);
    return QWidgetListItem::qt_metacast(_clname);
}

int NoteSheet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidgetListItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void NoteSheet::noteChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
