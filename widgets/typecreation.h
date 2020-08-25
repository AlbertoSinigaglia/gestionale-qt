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

public:
    TypeCreation(QWidget* parent=nullptr);

private:
    static QStringList testo_opzioni;

    QComboBox* opzioni;
    void setStyle();
signals:
    /* Il segnale viene emesso in seguito alla scelta finale
     * del tipo di impiegato <q> proposto da <opzioni>
     */
    void choosed(QString q);

private slots:
    void sendChoice();
    void abort();
};

#endif // TYPECREATION_H
