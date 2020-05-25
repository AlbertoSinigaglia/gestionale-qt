#ifndef GESTIONALEBUTTON_H
#define GESTIONALEBUTTON_H

#include <QPushButton>
class GestionaleButton : public QPushButton
{
	Q_OBJECT
public:
	GestionaleButton(QString name, QWidget* parent = nullptr);
signals:
	void clickButton(QString);
private:

private slots:
	void buttonEmitter();
};

#endif // GESTIONALEBUTTON_H
