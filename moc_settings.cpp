/****************************************************************************
** Meta object code from reading C++ file 'settings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../TextEditor/settings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Settings_t {
    QByteArrayData data[25];
    char stringdata0[463];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Settings_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Settings_t qt_meta_stringdata_Settings = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Settings"
QT_MOC_LITERAL(1, 9, 21), // "changeBackgroundColor"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 1), // "c"
QT_MOC_LITERAL(4, 34, 15), // "changeTextColor"
QT_MOC_LITERAL(5, 50, 14), // "changeTextFont"
QT_MOC_LITERAL(6, 65, 1), // "f"
QT_MOC_LITERAL(7, 67, 14), // "changeTextSize"
QT_MOC_LITERAL(8, 82, 5), // "index"
QT_MOC_LITERAL(9, 88, 13), // "changeMargins"
QT_MOC_LITERAL(10, 102, 6), // "margin"
QT_MOC_LITERAL(11, 109, 15), // "divider_changed"
QT_MOC_LITERAL(12, 125, 4), // "arg1"
QT_MOC_LITERAL(13, 130, 18), // "on_bgColor_clicked"
QT_MOC_LITERAL(14, 149, 20), // "on_textColor_clicked"
QT_MOC_LITERAL(15, 170, 34), // "on_fontComboBox_currentFontCh..."
QT_MOC_LITERAL(16, 205, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(17, 237, 30), // "on_setMarginExactWidth_clicked"
QT_MOC_LITERAL(18, 268, 25), // "on_setMarginsSize_clicked"
QT_MOC_LITERAL(19, 294, 25), // "on_setMarginsBook_clicked"
QT_MOC_LITERAL(20, 320, 7), // "checked"
QT_MOC_LITERAL(21, 328, 29), // "on_dividerLineEdit_textEdited"
QT_MOC_LITERAL(22, 358, 32), // "on_setMarginsScreenWidth_clicked"
QT_MOC_LITERAL(23, 391, 38), // "on_marginsExactWidthPref_retu..."
QT_MOC_LITERAL(24, 430, 32) // "on_marginsSizePref_returnPressed"

    },
    "Settings\0changeBackgroundColor\0\0c\0"
    "changeTextColor\0changeTextFont\0f\0"
    "changeTextSize\0index\0changeMargins\0"
    "margin\0divider_changed\0arg1\0"
    "on_bgColor_clicked\0on_textColor_clicked\0"
    "on_fontComboBox_currentFontChanged\0"
    "on_comboBox_currentIndexChanged\0"
    "on_setMarginExactWidth_clicked\0"
    "on_setMarginsSize_clicked\0"
    "on_setMarginsBook_clicked\0checked\0"
    "on_dividerLineEdit_textEdited\0"
    "on_setMarginsScreenWidth_clicked\0"
    "on_marginsExactWidthPref_returnPressed\0"
    "on_marginsSizePref_returnPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Settings[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,
       4,    1,  102,    2, 0x06 /* Public */,
       5,    1,  105,    2, 0x06 /* Public */,
       7,    1,  108,    2, 0x06 /* Public */,
       9,    1,  111,    2, 0x06 /* Public */,
      11,    1,  114,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,  117,    2, 0x08 /* Private */,
      14,    0,  118,    2, 0x08 /* Private */,
      15,    1,  119,    2, 0x08 /* Private */,
      16,    1,  122,    2, 0x08 /* Private */,
      17,    0,  125,    2, 0x08 /* Private */,
      18,    0,  126,    2, 0x08 /* Private */,
      19,    1,  127,    2, 0x08 /* Private */,
      21,    1,  130,    2, 0x08 /* Private */,
      22,    0,  133,    2, 0x08 /* Private */,
      23,    0,  134,    2, 0x08 /* Private */,
      24,    0,  135,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QColor,    3,
    QMetaType::Void, QMetaType::QColor,    3,
    QMetaType::Void, QMetaType::QFont,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   12,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QFont,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Settings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Settings *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeBackgroundColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 1: _t->changeTextColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 2: _t->changeTextFont((*reinterpret_cast< const QFont(*)>(_a[1]))); break;
        case 3: _t->changeTextSize((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 4: _t->changeMargins((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->divider_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_bgColor_clicked(); break;
        case 7: _t->on_textColor_clicked(); break;
        case 8: _t->on_fontComboBox_currentFontChanged((*reinterpret_cast< const QFont(*)>(_a[1]))); break;
        case 9: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_setMarginExactWidth_clicked(); break;
        case 11: _t->on_setMarginsSize_clicked(); break;
        case 12: _t->on_setMarginsBook_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->on_dividerLineEdit_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->on_setMarginsScreenWidth_clicked(); break;
        case 15: _t->on_marginsExactWidthPref_returnPressed(); break;
        case 16: _t->on_marginsSizePref_returnPressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Settings::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::changeBackgroundColor)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Settings::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::changeTextColor)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Settings::*)(const QFont & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::changeTextFont)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Settings::*)(const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::changeTextSize)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Settings::*)(const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::changeMargins)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Settings::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::divider_changed)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Settings::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Settings.data,
    qt_meta_data_Settings,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Settings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Settings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Settings.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Settings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void Settings::changeBackgroundColor(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Settings::changeTextColor(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Settings::changeTextFont(const QFont & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Settings::changeTextSize(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Settings::changeMargins(const QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Settings::divider_changed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
