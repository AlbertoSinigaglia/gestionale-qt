QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QMAKE_CXXFLAGS+= -std=c++17 -Wall -Wextra
QMAKE_LFLAGS +=  -std=c++17 -Wall -Wextra

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
    CSV/CSVParser.cpp \
    CSV/CSVReader.cpp \
    CSV/CSVWriter.cpp \
    CSV/support/Mapper.cpp \
    TipiRaggruppamento.cpp \
    editviewemployee.cpp \
    employeesmanagement.cpp \
    models/support/Convenzioni.cpp \
    models/support/Data.cpp \
    models/cpp/Persona.cpp \
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
    widgets/Edit_View_Employee/Attribute_Elements/comboattribute.cpp \
    widgets/Edit_View_Employee/Attribute_Elements/dateeditattribute.cpp \
    widgets/Edit_View_Employee/Attribute_Elements/flagattribute.cpp \
    widgets/Edit_View_Employee/Attribute_Elements/lineeditattribute.cpp \
    widgets/Edit_View_Employee/Attribute_Elements/slideattribute.cpp \
    widgets/Edit_View_Employee/Data_Section_Elements/DatiDatabaseElement.cpp \
    widgets/Edit_View_Employee/Data_Section_Elements/DatiDevelopingElement.cpp \
    widgets/Edit_View_Employee/Data_Section_Elements/DatiFullstackElement.cpp \
    widgets/Edit_View_Employee/Data_Section_Elements/DatiInterfacciaUtenteElement.cpp \
    widgets/Edit_View_Employee/Data_Section_Elements/DatiLatoClientElement.cpp \
    widgets/Edit_View_Employee/Data_Section_Elements/DatiLatoServerElement.cpp \
    widgets/Edit_View_Employee/Data_Section_Elements/DatiLavoratoreElement.cpp \
    widgets/Edit_View_Employee/Data_Section_Elements/DatiManutenzioneElement.cpp \
    widgets/Edit_View_Employee/Data_Section_Elements/DatiPersonaElement.cpp \
    widgets/Edit_View_Employee/Data_Section_Elements/DatiRiparazioneSistemiElement.cpp \
    widgets/Edit_View_Employee/Data_Section_Elements/DatiRipristinoSicurezzaElement.cpp \
    widgets/Edit_View_Employee/Data_Section_Elements/DatiSistemiElement.cpp \
    widgets/Edit_View_Employee/abstattribute.cpp \
    widgets/Edit_View_Employee/abstsectionelement.cpp \
    widgets/aboutus.cpp \
    widgets/employeelistelement.cpp \
    widgets/employeeslist.cpp \
    widgets/tableheader.cpp \
    controller.cpp \
    main.cpp \
    gestionale.cpp \
    widgets/suggerimento.cpp \
    widgets/typecreation.cpp

HEADERS += \
    CSV/CSVReader.h \
    CSV/CSVWriter.h \
    CSV/support/Mapper.h \
    TipiRaggruppamento.h \
    collections/DynamicArray.h \
    CSV/CSVParser.h \
    CSV/support/Mapper.h \
    editviewemployee.h \
    employeesmanagement.h \
    models/support/Convenzioni.h \
    models/support/Data.h \
    models/support/UsefullMath.h \
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
    widgets/aboutus.h \
    widgets/tableheader.h \
    widgets/Edit_View_Employee/Attribute_Elements/comboattribute.h \
    widgets/Edit_View_Employee/Attribute_Elements/dateeditattribute.h \
    widgets/Edit_View_Employee/Attribute_Elements/flagattribute.h \
    widgets/Edit_View_Employee/Attribute_Elements/lineeditattribute.h \
    widgets/Edit_View_Employee/Attribute_Elements/slideattribute.h \
    widgets/Edit_View_Employee/Data_Section_Elements/DatiDatabaseElement.h \
    widgets/Edit_View_Employee/Data_Section_Elements/DatiDevelopingElement.h \
    widgets/Edit_View_Employee/Data_Section_Elements/DatiFullstackElement.h \
    widgets/Edit_View_Employee/Data_Section_Elements/DatiInterfacciaUtenteElement.h \
    widgets/Edit_View_Employee/Data_Section_Elements/DatiLatoClientElement.h \
    widgets/Edit_View_Employee/Data_Section_Elements/DatiLatoServerElement.h \
    widgets/Edit_View_Employee/Data_Section_Elements/DatiLavoratoreElement.h \
    widgets/Edit_View_Employee/Data_Section_Elements/DatiManutenzioneElement.h \
    widgets/Edit_View_Employee/Data_Section_Elements/DatiPersonaElement.h \
    widgets/Edit_View_Employee/Data_Section_Elements/DatiRiparazioneSistemiElement.h \
    widgets/Edit_View_Employee/Data_Section_Elements/DatiRipristinoSicurezzaElement.h \
    widgets/Edit_View_Employee/Data_Section_Elements/DatiSistemiElement.h \
    widgets/Edit_View_Employee/abstattribute.h \
    widgets/Edit_View_Employee/abstsectionelement.h \
    widgets/employeelistelement.h \
    widgets/employeeslist.h \
    controller.h \
    gestionale.h \
    widgets/suggerimento.h \
    widgets/typecreation.h

FORMS += \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
	resources.qrc

DISTFILES +=
