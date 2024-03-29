QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MyScene.cpp \
    loadfile.cpp \
    main.cpp \
    movecomputer.cpp \
    moveinternet.cpp \
    moveprinter.cpp \
    moveswitch.cpp \
    movexerox.cpp \
    savefile.cpp \
    widget.cpp

HEADERS += \
    MyScene.h \
    loadfile.h \
    movecomputer.h \
    moveinternet.h \
    moveprinter.h \
    moveswitch.h \
    movexerox.h \
    savefile.h \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

DISTFILES +=
