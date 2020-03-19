#include "pch.h"
#include "HTMLandCSVrepository.h"


void HTMLandCSVrepository::write()
{
	std::string file = this->specialData;
	size_t position= file.find('.');
	file.erase(0, position + 1);
	if (file == "csv" or file == "CSV")
		this->writeToCSVFile();
	else
		if (file == "html" or file == "HTML")
			this->writeToHTMLFile();
}

void HTMLandCSVrepository::writeToHTMLFile()
{
	ofstream file;
	file.open(this->specialData);
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
		std::vector<GuardianStatue> statues = this->getmyList();
		for (auto &statue : statues)
		{
			file << "\t\t<tr>\n";
			file << "\t\t\t<td>"<<statue.get_powerWordName()<<"</td>\n";
			file << "\t\t\t<td>" << statue.get_material() << "</td>\n";
			file << "\t\t\t<td>" << statue.get_age() << "</td>\n";
			file << "\t\t\t<td>" << statue.get_corporealForm() << "</td>\n";
			file << "\t\t</tr>\n";
		}
		file << "\t\t</table>\n";
		file << "\t</body>\n";
		file << "</html>\n";
	}


}

void HTMLandCSVrepository::writeToCSVFile()
{
	ofstream file;
	file.open(this->specialData);
	if (file.is_open())
	{
		std::vector<GuardianStatue> statuess = this->getmyList();

		for (auto &statue : statuess)
		{
			file << statue<<endl;
			
		}
	}
}





/*
void HTMLandCSVrepository::add(const GuardianStatue & guardianStatue)
{
	MyList::add(guardianStatue);
	this->write();
}
*/
HTMLandCSVrepository::~HTMLandCSVrepository()
{
}
