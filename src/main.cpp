#include "PyRho20.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	PyRho20 w;
	w.show();
	return a.exec();
}
