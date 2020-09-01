#ifndef TABLEHEADER_H
#define TABLEHEADER_H

#include "collections/DynamicArray.h"
#include<QLabel>
#include<QHBoxLayout>
#include<algorithm>

class TableHeader: public QWidget{
    Q_OBJECT
    QHBoxLayout* layout;
    std::vector<QLabel *> fields;

public:
    TableHeader(QWidget* parent);

    /**
     * @brief Aggiunge un campo
     * @param new_field nume del campo da aggiungere
     */
    void addField(const QString& new_field);

    /**
     * @brief imposta la visibilità di un campo
     * @param field : testo del campo di cui cambiare la visibilità
     * @param visibility : visibilità che il campo deve assumere
     */
    void setVisibility(const QString& field, bool visibility);

    /**
     * @brief mostra tutti i campi
     */
    void showAll();

    /**
     * @brief nasconde tutti i campi
     */
    void hideAll();

    /**
     * @brief getter per i fields correnti
     * @return collezione dei fields correnti
     */
    std::vector<QString> getFields() const;

    /**
     * @brief rimuove tutti i campi correnti
     */
    void resetFields();
};

#endif // TABLEHEADER_H
