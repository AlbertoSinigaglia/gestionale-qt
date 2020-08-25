#ifndef ABOUTUS_H
#define ABOUTUS_H
#include <QDialog>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>

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

};

#endif // ABOUTUS_H
