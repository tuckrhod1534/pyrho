#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PyRho20.h"

class PyRho20 : public QMainWindow
{
	Q_OBJECT

public:
	PyRho20(QWidget *parent = Q_NULLPTR);

private:
	Ui::PyRho20Class ui;
	
	private slots:
		void on_calcButton_click();
		void on_genIndexButton_click();


};
