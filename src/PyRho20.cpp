#include "PyRho20.h"

PyRho20::PyRho20(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void PyRho20::on_genIndexButton_click()
{
	ui.chartOutput->insertPlainText("genIndex clicked");
}

void PyRho20::on_calcButton_click()
{
	ui.chartOutput->insertPlainText("Calculate Clicked");
}
