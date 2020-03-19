#include "GUI.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>

GUI::GUI(Service& c) : ctrl{ c }
{
	this->initGUI();
	this->populateList();
}


GUI::~GUI()
{
}

void GUI::initGUI()
{

	QHBoxLayout* mainLayout = new QHBoxLayout{ this };

	this->guardianList = new QListWidget{};
	mainLayout->addWidget(this->guardianList);

	QVBoxLayout* rightLayout = new QVBoxLayout{};

	QFormLayout* dataLayout = new QFormLayout{};
	this->power = new QLineEdit{};
	this->material = new QLineEdit{};
	this->age= new QLineEdit{};
	this->corporealForm= new QLineEdit{};
	dataLayout->addRow("PowerWordName", this->power);
	dataLayout->addRow("Material", this->material);
	dataLayout->addRow("Age", this->age);
	dataLayout->addRow("CorporealForm", this->corporealForm);


	rightLayout->addLayout(dataLayout);
	mainLayout->addLayout(rightLayout);

	QHBoxLayout* buttonsLayout = new QHBoxLayout{};
	this->addButton = new QPushButton{ "Add" };
	this->removeButton = new QPushButton{ "Remove" };
	this->updateButton= new QPushButton{ "Update" };

	buttonsLayout->addWidget(this->addButton);
	buttonsLayout->addWidget(this->removeButton);
	buttonsLayout->addWidget(this->updateButton);

	rightLayout->addLayout(buttonsLayout);

}

void GUI::populateList()
{
	for (GuardianStatue& s : this->ctrl.get_allStatues())
	{
		//string something = s.get_age();
		this->guardianList->addItem(QString::fromStdString(s.get_powerWordName()+","+ s.get_material()+ ",") +QString::number(s.get_age()) +QString::fromStdString(","+s.get_corporealForm()));
		

	}
}
