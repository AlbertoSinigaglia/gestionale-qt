#include "comboattribute.h"

ComboAttribute::ComboAttribute(QString nome, DynamicArray<QString> opzioni, int index_valore_inizio, bool editable,  QWidget *parent)
    :AbstAttribute(nome,editable,parent){

}
