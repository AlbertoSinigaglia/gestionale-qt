#ifndef ABOUTUS_H
#define ABOUTUS_H
#include <QDialog>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>
#include <QFile>

class AboutUs: public QDialog
{
public:
    AboutUs(QWidget *parent = 0);

private:
    QVBoxLayout* aboutUsLayout;

    void addImage();
    void addName();
    void addVersion();
    void addCreators();
    void setStyle();

};

#endif // ABOUTUS_H
