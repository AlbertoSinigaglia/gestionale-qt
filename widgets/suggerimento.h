#ifndef SUGGERIMENTO_H
#define SUGGERIMENTO_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>

class Suggerimento: public QPushButton{
Q_OBJECT

public:
    Suggerimento(QString testo, QWidget* parent=nullptr);

private:
    QString testo;

private slots:
    void show() const;
};


#endif // SUGGERIMENTO_H

