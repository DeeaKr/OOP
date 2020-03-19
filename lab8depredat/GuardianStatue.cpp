#include "pch.h"
#include <cstring>
#include "GuardianStatue.h"

GuardianStatue::GuardianStatue(): powerWordName(""),material(""),age(0),corporealForm(""){}


GuardianStatue::GuardianStatue(const std::string & powerWordName, const std::string & material, int age, const std::string & corporealForm)
{
	this->powerWordName = powerWordName;
	this->material = material;
	this->age = age;
	this->corporealForm = corporealForm;
}

bool GuardianStatue::operator==(const GuardianStatue guardianStatue)
{
	GuardianStatue statue;
	if (statue.get_powerWordName() == guardianStatue.get_powerWordName())
		return true;
	return false;
}


string GuardianStatue::convert_to_string()
{
	string GuardianStatueString = this->powerWordName + ',' + this->material + ',' + to_string(this->age) + ',' + this->corporealForm + '\n';
	return GuardianStatueString;
}

std::istream & operator>>(std::istream & input, GuardianStatue & statue)
{
	std::string line;
	getline(input, line);
	std::string parameters[6], delimiter = ",";
	int position = line.find(delimiter);
	int count = 0;
	while (position  != std::string::npos)
	{
		std::string auxiliar = line.substr(0, position);
		parameters[count++] = auxiliar;
		line.erase(0, position + delimiter.length());
		position = line.find(delimiter);
	}
	parameters[count++] = line;
	if (count != 4)
		return input;
	statue.powerWordName = parameters[0];
	statue.material = parameters[1];
	statue.age = stoi(parameters[2]);
	statue.corporealForm = parameters[3];
}

std::ostream & operator<<(std::ostream & output, GuardianStatue & statue)
{
	output << statue.get_powerWordName() << "," << statue.get_material() << "," << statue.get_age()<< "," << statue.get_corporealForm()<<endl;

	return output;

}


GuardianStatue::~GuardianStatue()
{
}
