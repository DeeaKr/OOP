#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_FirstGuI.h"
#include "Controller.h"
#include <Windows.h>

#include <qmessagebox.h>

class FirstGuI : public QMainWindow
{
	Q_OBJECT

public:
	FirstGuI(Service& s,QWidget *parent = Q_NULLPTR);
	//void add();
	//void update();
	
public slots:
	void add();
	void remove();
	void update();
	void addToMylist();
	void next();
	void filter();
	void modeA();
	void modeB();
	void list();
	void myList();
	void html();
private:
	Ui::FirstGuIClass ui;
	Service &service;
	void populateList();
	void populateMylist();
	int current;
	string mode;
};
