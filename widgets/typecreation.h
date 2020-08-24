#ifndef TYPECREATION_H
#define TYPECREATION_H

#include <QComboBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QHBoxLayout>

class TypeCreation: public QFrame{
Q_OBJECT

public:
    TypeCreation(QWidget* parent=nullptr);

private:
    static QStringList testo_opzioni;

    QComboBox* opzioni;

signals:
    void choosed(QString q);

private slots:
    void sendChoice();
    void abort();
};

#endif // TYPECREATION_H
