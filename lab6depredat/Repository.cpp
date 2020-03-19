//#include "pch.h"
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
		if (this->Encyclopedia.getAllElements()[index].get_powerWordName() == new_guardianStatue.get_powerWordName())
			this->Encyclopedia.getAllElements()[index] = new_guardianStatue;
}

string Repository::repository_listAge(int age)
{
	string GuardianStatueString;
	GuardianStatue guardianStatue;

	int index = 0;
	for (index = 0; index < this->Encyclopedia.getSize(); index++) {

		if (this->Encyclopedia.getAllElements()[index].get_age() < age)
		{
			GuardianStatueString += this->Encyclopedia.getAllElements()[index].convert_to_string();
			//guardianStatue = this->Encyclopedia.getAllElements()[index];
		}
	}

	return GuardianStatueString;

}

string Repository::repository_listMaterialAge(const std::string & material, int age)
{
	string GuardianStatueString;
	
	int index=0;
	
	for (index = 0; index < this->Encyclopedia.getSize(); index++) {
		
		if (this->Encyclopedia.getAllElements()[index].get_material() == material && this->Encyclopedia.getAllElements()[index].get_age() < age)
		{
				GuardianStatueString += this->Encyclopedia.getAllElements()[index].convert_to_string();
		}
	}
	

	return GuardianStatueString;
			
}

GuardianStatue Repository::findByPowerWordName(const std::string & powerWordName)
{
	GuardianStatue* GuardianStatueInEncyclopedia = this->Encyclopedia.getAllElements();
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
		GuardianStatueString += this->Encyclopedia.getAllElements()[index].convert_to_string();
	return GuardianStatueString;
}




int Repository::find_index(const std::string & powerWordName)
{
	for (int i = 0; i < this->Encyclopedia.getSize(); i++)
		if (this->Encyclopedia.getAllElements()[i].get_powerWordName() == powerWordName)
			return i;
	return -1;
}

Repository::~Repository()
{
}
