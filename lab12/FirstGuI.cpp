#include "FirstGuI.h"

FirstGuI::FirstGuI(Service& s,QWidget *parent)
	: QMainWindow(parent),service{s}
{
	try {
		ui.setupUi(this);
		this->current = 0;
		this->populateList();
		connect(ui.pushButton_add, SIGNAL(clicked()), this, SLOT(add()));
		connect(ui.pushButton_delete, SIGNAL(clicked()), this, SLOT(remove()));
		connect(ui.pushButton_update, SIGNAL(clicked()), this, SLOT(update()));
		connect(ui.pushButton_save, SIGNAL(clicked()), this, SLOT(addToMylist()));
		connect(ui.pushButton_next, SIGNAL(clicked()), this, SLOT(next()));
		connect(ui.pushButton_filter, SIGNAL(clicked()), this, SLOT(filter()));
		connect(ui.pushButton_modeA, SIGNAL(clicked()), this, SLOT(modeA()));
		connect(ui.pushButton_modeB, SIGNAL(clicked()), this, SLOT(modeB()));
		connect(ui.pushButton_list, SIGNAL(clicked()), this, SLOT(list()));
		connect(ui.pushButton_mylist, SIGNAL(clicked()), this, SLOT(myList()));
	}
	catch (Exceptions& exception)
	{
		QMessageBox* m = new QMessageBox{};
		m->setText(QString::fromStdString(exception.get_error_message()));
		m->show();
	}
	
}

void FirstGuI::update()
{
	if (mode == "A") {
		try {
			this->service.service_updateGuardianStatue(ui.lineEdit_powerWordName->displayText().toStdString(), ui.lineEdit_material->displayText().toStdString(), ui.lineEdit_age->displayText().toInt(), ui.lineEdit_corporealForm->displayText().toStdString());
			this->populateList();
		}
		catch (Exceptions& exception)
		{
			QMessageBox* m = new QMessageBox{};
			m->setText(QString::fromStdString(exception.get_error_message()));
			m->show();
		}
	}
}


void FirstGuI::addToMylist()
{
	if (mode == "B") {
		try {
			this->service.service_addTOMylist(ui.lineEdit_powerWordName->displayText().toStdString());
			this->populateMylist();
		}
		catch (Exceptions& exception)
		{
			QMessageBox* m = new QMessageBox{};
			m->setText(QString::fromStdString(exception.get_error_message()));
			m->show();
		}
	}

}

void FirstGuI::next()
{
	if (mode == "B") {
		this->ui.listWidget_next->clear();
		vector<GuardianStatue> guardianStatue = this->service.get_allStatues();
		this->ui.listWidget_next->addItem(QString::fromStdString(guardianStatue[current].get_powerWordName() + "," + guardianStatue[current].get_material() + ",") + QString::number(guardianStatue[current].get_age()) + QString::fromStdString("," + guardianStatue[current].get_corporealForm()));

		current += 1;
		if (current == this->service.getRepository()->getEncyclopedia().size())
			current = 0;
	}
}

void FirstGuI::filter()
{
	if (mode == "B") {
		string GuardianStatueString;
		this->ui.listWidget_materialandage->clear();
		if (this->ui.lineEdit_material->displayText().toStdString() == "" || this->ui.lineEdit_material->displayText().toStdString() == " ")
		{


			vector<GuardianStatue> guardianStatue = this->service.get_allStatues();
			for (auto& guardianStatues : guardianStatue)
				if (guardianStatues.get_age() < ui.lineEdit_age->displayText().toInt())
					GuardianStatueString += guardianStatues.convert_to_string();
		}
		else
		{
			vector<GuardianStatue> guardianStatue = this->service.get_allStatues();

			int index = 0;


			for (auto& guardianStatues : guardianStatue)
				if (guardianStatues.get_material() == ui.lineEdit_material->displayText().toStdString() && guardianStatues.get_age() < ui.lineEdit_age->displayText().toInt())
					GuardianStatueString += guardianStatues.convert_to_string();

		}
		this->ui.listWidget_materialandage->addItem(QString::fromStdString(GuardianStatueString));
	}

}

void FirstGuI::modeA()
{
	this->mode = "A";
}

void FirstGuI::modeB()
{
	this->mode = "B";
}

void FirstGuI::list()
{
	QMessageBox* m = new QMessageBox{};
	m->setText(QString::fromStdString(this->service.list()));
	m->show();
}

void FirstGuI::myList()
{
	QMessageBox message;
	message.setText("Do you want HTML or CSV file?");
	QPushButton *html = message.addButton(("HTML"), QMessageBox::ActionRole);
	QPushButton *csv = message.addButton(("CSV"), QMessageBox::ActionRole);
	message.exec();
	if (message.clickedButton() == html) {
		ofstream file;
		file.open("file.html");
		if (file.is_open())
		{
			file << "<!DOCTYPE html>\n";
			file << "<html>\n";
			file << "\t<head>\n";
			file << "\t\t<title>GuardianStatue</title>\n";
			file << "\t</head>\n";
			file << "\t<body>\n";
			file << "\t\t<table border=\"1\">\n";
			file << "\t\t<tr>\n";
			file << "\t\t\t<td>Power Word Name</td>\n";
			file << "\t\t\t<td>Material</td>\n";
			file << "\t\t\t<td>Age</td>\n";
			file << "\t\t\t<td>Corporeal Form</td>\n";
			file << "\t\t</tr>\n";
			std::vector<GuardianStatue> statues = this->service.get_list();
			for (auto &statue : statues)
			{
				file << "\t\t<tr>\n";
				file << "\t\t\t<td>" << statue.get_powerWordName() << "</td>\n";
				file << "\t\t\t<td>" << statue.get_material() << "</td>\n";
				file << "\t\t\t<td>" << statue.get_age() << "</td>\n";
				file << "\t\t\t<td>" << statue.get_corporealForm() << "</td>\n";
				file << "\t\t</tr>\n";
			}
			file << "\t\t</table>\n";
			file << "\t</body>\n";
			file << "</html>\n";
		}
		std::string open;
		std::string fi = "file.html";
		open += "start firefox " + fi;
		//ShellExecuteA(NULL, NULL, "firefox.exe", "file.html", NULL, SW_SHOWMAXIMIZED);
		system(open.c_str());
	}
	else if (message.clickedButton() == csv) {
		ofstream file;
		file.open("anotherfile.csv");
		if (file.is_open())
		{
			std::vector<GuardianStatue> statuess = this->service.get_list();

			for (auto &statue : statuess)
			{
				file << statue << endl;

			}
		}
		string forOpening = "notepad.exe anotherfile.csv";
		system(forOpening.c_str());
	}
}

void FirstGuI::html()
{
	ofstream file;
	file.open("file.html");
	if (file.is_open())
	{
		file << "<!DOCTYPE html>\n";
		file << "<html>\n";
		file << "\t<head>\n";
		file << "\t\t<title>GuardianStatue</title>\n";
		file << "\t</head>\n";
		file << "\t<body>\n";
		file << "\t\t<table border=\"1\">\n";
		file << "\t\t<tr>\n";
		file << "\t\t\t<td>Power Word Name</td>\n";
		file << "\t\t\t<td>Material</td>\n";
		file << "\t\t\t<td>Age</td>\n";
		file << "\t\t\t<td>Corporeal Form</td>\n";
		file << "\t\t</tr>\n";
		std::vector<GuardianStatue> statues = this->service.get_list();
		for (auto &statue : statues)
		{
			file << "\t\t<tr>\n";
			file << "\t\t\t<td>" << statue.get_powerWordName() << "</td>\n";
			file << "\t\t\t<td>" << statue.get_material() << "</td>\n";
			file << "\t\t\t<td>" << statue.get_age() << "</td>\n";
			file << "\t\t\t<td>" << statue.get_corporealForm() << "</td>\n";
			file << "\t\t</tr>\n";
		}
		file << "\t\t</table>\n";
		file << "\t</body>\n";
		file << "</html>\n";
	}
	std::string open;
	std::string fi = "file.html";
	open += "start firefox " + fi;
	//ShellExecuteA(NULL, NULL, "firefox.exe", "file.html", NULL, SW_SHOWMAXIMIZED);
	system(open.c_str());
}

void FirstGuI::remove()
{
	if (mode == "A") {
		try {
			this->service.service_removeGuardianStatue(ui.lineEdit_powerWordName->displayText().toStdString());
			this->populateList();
		}
		catch (Exceptions& exception)
		{
			QMessageBox* m = new QMessageBox{};
			m->setText(QString::fromStdString(exception.get_error_message()));
			m->show();
		}
	}
}

void FirstGuI::populateList()
{
	this->ui.listWidget_modeA->clear();
	for (auto& s : this->service.get_allStatues())
	{
		this->ui.listWidget_modeA->addItem(QString::fromStdString(s.get_powerWordName() + "," + s.get_material() + ",") + QString::number(s.get_age()) + QString::fromStdString("," + s.get_corporealForm()));
	}
}

void FirstGuI::populateMylist()
{
	this->ui.listWidget_modeB->clear();
	for (auto& statues : this->service.get_list())
	{
		this->ui.listWidget_modeB->addItem(QString::fromStdString(statues.get_powerWordName() + "," + statues.get_material() + ",") + QString::number(statues.get_age()) + QString::fromStdString("," + statues.get_corporealForm()));
	}
}

void FirstGuI::add()
{
	if (mode == "A") {
		try {
			/*QMessageBox* m = new QMessageBox{};
			m->setText("done!");
			m->show();*/
			//this->ui.lineEdit_material->displayText();

			this->service.service_addGuardianStatue(ui.lineEdit_powerWordName->displayText().toStdString(), ui.lineEdit_material->displayText().toStdString(), ui.lineEdit_age->displayText().toInt(), ui.lineEdit_corporealForm->displayText().toStdString());
			this->populateList();
		}
		catch (Exceptions& exception)
		{
			QMessageBox* m = new QMessageBox{};
			m->setText(QString::fromStdString(exception.get_error_message()));
			m->show();
		}
	}
}
