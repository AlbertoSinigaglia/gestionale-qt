QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QMAKE_CXXFLAGS+= -std=c++17
QMAKE_LFLAGS +=  -std=c++17

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
    models/cpp/Persona.cpp \
    models/support/Convenzioni.cpp \
    models/support/Data.cpp \
    models/cpp/BackDev.cpp \
    models/cpp/Employee.cpp \
    models/cpp/FullStack.cpp \
    models/cpp/Hardware.cpp \
    models/cpp/Manutenzione.cpp \
    models/cpp/Software.cpp \
    models/cpp/DBDev.cpp \
    models/cpp/FrontDev.cpp \
    models/cpp/GUIDev.cpp \
    models/cpp/ITSecurityDev.cpp \
    models/cpp/Tecnico.cpp \
    controller.cpp \
    widgets/employeelistelement.cpp \
    main.cpp \
    gestionale.cpp \
    model.cpp \
    widgets/employeeslist.cpp

HEADERS += \
    CSV/CSVParser.h \
    models/support/Convenzioni.h \
    models/support/Data.h \
    models/support/TipiRaggruppamento.h \
    models/headers/BackDev.h \
    models/headers/Employee.h \
    models/headers/FullStack.h \
    models/headers/Hardware.h \
    models/headers/Manutenzione.h \
    models/headers/Software.h \
    models/headers/DBDev.h \
    models/headers/FrontDev.h \
    models/headers/GUIDev.h \
    models/headers/ITSecurityDev.h \
    models/headers/Persona.h \
    models/headers/Tecnico.h \
    collections/DynamicArray.h \
    azioneModifica.h \
    controller.h \
    widgets/employeelistelement.h \
    gestionale.h \
    model.h \
    models/support/UsefullMath.h \
    widgets/employeeslist.h

FORMS += \
    gestionale.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
	resources.qrc

DISTFILES +=
