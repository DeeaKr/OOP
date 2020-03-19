
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




string GuardianStatue::convert_to_string()
{
	string GuardianStatueString = this->powerWordName + ',' + this->material + ',' + to_string(this->age) + ',' + this->corporealForm + '\n';
	return GuardianStatueString;
}

GuardianStatue::~GuardianStatue()
{
}
