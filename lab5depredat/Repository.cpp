
#include "Repository.h"
#include <string>

using namespace std;




void Repository::repository_addGuardianStatue(const GuardianStatue & guardianStatue)
{
	this->Encyclopedia.add(guardianStatue);
}

void Repository::repository_removeGuardianStatue(const std::string & powerWordName)
{
	this->Encyclopedia.remove(powerWordName);
}

void Repository::repository_updateGuardianStatue(const GuardianStatue & new_guardianStatue)
{
	for (int index = 0; index < this->Encyclopedia.getSize(); index++)
		if (this->Encyclopedia.getAllElems()[index].get_powerWordName() == new_guardianStatue.get_powerWordName())
			this->Encyclopedia.getAllElems()[index] = new_guardianStatue;
}

GuardianStatue Repository::findByPowerWordName(const std::string & powerWordName)
{
	GuardianStatue* GuardianStatueInEncyclopedia = this->Encyclopedia.getAllElems();
	if (GuardianStatueInEncyclopedia == NULL)
		return GuardianStatue{};
	for (int index = 0; index < this->Encyclopedia.getSize(); index++)
		if (GuardianStatueInEncyclopedia[index].get_powerWordName() == powerWordName)
			return GuardianStatueInEncyclopedia[index];

	return GuardianStatue{};
}

string Repository::stringable_guardianStatue()
{
	string GuardianStatueString;
	for (int index = 0; index < this->Encyclopedia.getSize(); index++)
		GuardianStatueString += this->Encyclopedia.getAllElems()[index].convert_to_string();
	return GuardianStatueString;
}




int Repository::find_index(const std::string & powerWordName)
{
	for (int i = 0; i < this->Encyclopedia.getSize(); i++)
		if (this->Encyclopedia.getAllElems()[i].get_powerWordName() == powerWordName)
			return i;
	return -1;
}

Repository::~Repository()
{
}
