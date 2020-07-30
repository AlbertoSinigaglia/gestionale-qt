#include "gestionale.h"
#include "collections/DynamicArray.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Gestionale w;
	w.show();
	return a.exec();
}
