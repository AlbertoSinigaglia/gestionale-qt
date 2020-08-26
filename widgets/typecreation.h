#ifndef TYPECREATION_H
#define TYPECREATION_H

#include <QComboBox>
#include <QLabel>
#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFile>

class TypeCreation: public QDialog{
    Q_OBJECT
    static QStringList testo_opzioni;
    QComboBox* opzioni;
    void setStyle();

public:
    TypeCreation(QWidget* parent=nullptr);

signals:
    /*
     * Il segnale viene emesso in seguito alla scelta finale
     * del tipo di impiegato <q> proposto da <opzioni>
     */
    void choosed(QString q);

private slots:
    void sendChoice();
    void abort();
};

#endif // TYPECREATION_H
