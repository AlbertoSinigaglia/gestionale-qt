#include "gestionalebutton.h"

GestionaleButton::GestionaleButton(QString name, QWidget* parent) : QPushButton(parent), name(name)
{
	connect(this, SIGNAL(clicked()), this, SLOT(buttonEmitter()));
}

void GestionaleButton::buttonEmitter()
{
	emit clickButton(name);
}
