#include "suggerimento.h"

Suggerimento::Suggerimento(QString testo_, QWidget* parent): QPushButton(parent), testo(testo_)
{
    setStyleSheet("background-color:#1565C0 !important; border-radius:14px !important;");
    setIcon(QIcon(":/resources/Suggestion.png"));
    setIconSize(QSize(16,16));
    setFixedSize(30,28);
    setObjectName("suggerimento");
    setFlat(true);

    connect(this, SIGNAL(clicked()), this, SLOT(show()));
}


void Suggerimento::show() const{
    auto msg= QMessageBox(QMessageBox::Information, "Suggerimento", testo, QMessageBox::Ok);
    msg.exec();
}
