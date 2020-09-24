QT       += core gui printsupport
QT       += core sql
QT       += network

LIBS += "C:/Qt/Tools/OpenSSL/Win_x64/lib/libssl.lib"
LIBS += "C:/Qt/Tools/OpenSSL/Win_x64/lib/libcrypto.lib"

INCLUDEPATH += C:/Qt/Tools/OpenSSL/Win_x64/include

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    datamuse.cpp \
    helpcard.cpp \
    main.cpp \
    mainwindow.cpp \
    mydb.cpp \
    notes.cpp \
    notesheet.cpp \
    qwidgetlistitem.cpp \
    qwidgetlistmimedata.cpp \
    qwidgetlistwidget.cpp \
    qwidgetscrolllistwidget.cpp \
    settings.cpp \
    wordlookup.cpp

HEADERS += \
    datamuse.h \
    helpcard.h \
    mainwindow.h \
    mydb.h \
    notes.h \
    notesheet.h \
    qwidgetlistitem.h \
    qwidgetlistmimedata.h \
    qwidgetlistwidget.h \
    qwidgetscrolllistwidget.h \
    settings.h \
    wordlookup.h

FORMS += \
    helpcard.ui \
    mainwindow.ui \
    notes.ui \
    notesheet.ui \
    settings.ui \
    wordlookup.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc
