QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../model/token.cc \
    ../../model/pars.cc \
    ../../model/RPN.cc \
    ../../model/calculate.cc \
    ../../model/graph.cc \
    ../../model/credit.cc \
    ../../model/model.cc \
    ../../controller/controller.cc \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp

HEADERS += \
    ../../model/token.h \
    ../../model/pars.h \
    ../../model/RPN.h \
    ../../model/calculate.h \
    ../../model/graph.h \
    ../../model/credit.h \
    ../../model/model.h \
    ../../controller/controller.h \
    mainwindow.h \
    qcustomplot.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
