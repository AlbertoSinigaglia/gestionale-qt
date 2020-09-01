#ifndef EMPLOYEESLIST_H
#define EMPLOYEESLIST_H

#include <qwidget.h>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFrame>
#include <QLabel>
#include <QFile>
#include <QStyleOption>
#include <QPainter>
#include <QMessageBox>
#include "widgets/employeelistelement.h"
#include "models/headers/Employee.h"
#include "collections/DynamicArray.h"
#include "widgets/tableheader.h"
#include <algorithm>
#include <functional>

class EmployeesList : public QFrame{
    Q_OBJECT
    EmployeeListElement* current = nullptr;
    std::vector<EmployeeListElement*> children;
    QVBoxLayout* getNewLayout();
    TableHeader* header;
    static const std::map<unsigned int, const char *> fields;
    static const std::vector<const char *> ordered_fields;
public:
    /**
     * source: https://doc.qt.io/archives/qt-5.6/qobject.html#no-copy-constructor-or-assignment-operator
     */
    EmployeesList(const EmployeesList& e) = delete;
    EmployeesList& operator= (const EmployeesList& e) = delete;
    EmployeesList( QWidget *parent = 0);

    /**
     * @brief filtra la lista
     * @param f : funzione che ritorna true solo se quel dipendente deve essere mostrato
     */
    void filter(std::function<bool(Employee*)> f);
    /**
     * @brief imposta i dipendenti da mostrare, se ce ne sono già, rimuove quelli presenti
     * @param empl : dipendenti da mostrare
     */
    void setEmployees(const DynamicArray<Employee*>& empl);
    /**
     * @brief getter per il dipendente correntemente selezionato
     * @return employee selezionato
     */
    Employee * getCurrent() const;

signals:
    void changeListAttributeVisibilityEvent(int, int);
    void ListElementDoubleClicked(EmployeeListElement*);

public slots:
    void changeListAttributeVisibility(int props, int visibility);
    void childPressedEvent(EmployeeListElement* e);
    void childClickedEvent(EmployeeListElement* e);
    void orderBy(EmployeeListElement::FIELDS field);
};

#endif // EMPLOYEELIST_H
