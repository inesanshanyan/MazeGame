QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


SOURCES += \
    main.cpp \
    mainwidget.cpp \
    maze.cpp \
    mazedrawer.cpp \
    player.cpp \
    playerdrawer.cpp

HEADERS += \
    mainwidget.hpp \
    maze.hpp \
    mazedrawer.hpp \
    player.hpp \
    playerdrawer.hpp

FORMS +=

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
