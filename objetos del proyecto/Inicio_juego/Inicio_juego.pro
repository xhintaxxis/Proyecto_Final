QT       += core gui \


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bolafuego.cpp \
    bomba.cpp \
    botton.cpp \
    corazon.cpp \
    cuerpo.cpp \
    enemigo_1.cpp \
    enemigo_2.cpp \
    enemigo_3.cpp \
    fisica.cpp \
    jugador.cpp \
    main.cpp \
    mainwindow.cpp \
    rayo.cpp \
    rayoe.cpp \
    salud.cpp

HEADERS += \
    bolafuego.h \
    bomba.h \
    botton.h \
    corazon.h \
    cuerpo.h \
    enemigo_1.h \
    enemigo_2.h \
    enemigo_3.h \
    fisica.h \
    jugador.h \
    mainwindow.h \
    rayo.h \
    rayoe.h \
    salud.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
