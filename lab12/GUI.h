#pragma once
#include "C:\Qt\5.12.2\msvc2017_64\include\QtWidgets\qwidget.h"
#include <qlistwidget.h>
#include "qlineedit.h"
#include "qpushbutton.h"
#include "Controller.h" 


class GUI :
	public QWidget
{
private:
	Service& ctrl;
	QListWidget* guardianList;
	QLineEdit* power, *material,*age,*corporealForm;
	QPushButton* addButton, *removeButton,*updateButton;

public:
	GUI(Service& c);
	~GUI();

private:
	void initGUI();
	void populateList();
};
