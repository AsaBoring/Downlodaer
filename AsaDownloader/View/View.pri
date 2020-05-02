SOURCES += \
        $$PWD/mainwindow.cpp\
        $$PWD/common.cpp

HEADERS += \
        $$PWD/mainwindow.h\
        $$PWD/common.h

INCLUDEPATH += MainMenu
include(MainMenu/MainMenu.pri)

INCLUDEPATH += FuncDetail
include(FuncDetail/FuncDetail.pri)

RESOURCES += \
    $$PWD/viewresource.qrc

DISTFILES +=
