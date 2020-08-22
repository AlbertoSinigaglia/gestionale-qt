#include "suggerimento.h"

Suggerimento::Suggerimento(QString testo_, QWidget* parent): QPushButton(parent), testo(testo_)
{
    setIcon(QIcon(":/resources/Suggestion.png"));
    setIconSize(QSize(16,16));

    connect(this, SIGNAL(clicked()), this, SLOT(show()));

}


void Suggerimento::show() const{
    QMessageBox(QMessageBox::Information, "Suggerimento", testo, QMessageBox::Ok);
}
