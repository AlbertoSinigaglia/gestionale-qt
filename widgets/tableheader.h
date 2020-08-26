#ifndef TABLEHEADER_H
#define TABLEHEADER_H

#include "collections/DynamicArray.h"
#include<QLabel>
#include<QDebug>
#include<QHBoxLayout>
#include<algorithm>

class TableHeader: public QWidget{
    Q_OBJECT
    QHBoxLayout* layout;
    std::vector<QLabel *> fields;

public:
    TableHeader(QWidget* parent);
    void addField(const QString& new_field);
    void setVisibility(const QString& field, bool visibility);
    void showAll();
};

#endif // TABLEHEADER_H
