#include "pch.h"
#include "Repository.h"
#include <string>

using namespace std;




void Repository::repository_addGuardianStatue(const GuardianStatue & guardianStatue)
{

	this->Encyclopedia.push_back(guardianStatue);
}

void Repository::repository_removeGuardianStatue(const std::string & powerWordName)
{
	int index;
	GuardianStatue guardianStatue;
	index = find_index(powerWordName);

	this->Encyclopedia.erase(this->Encyclopedia.begin()+index);


}

void Repository::repository_updateGuardianStatue(const GuardianStatue & new_guardianStatue)
{
	for (auto& guardianStatue : this->Encyclopedia)
		if (guardianStatue.get_powerWordName() == new_guardianStatue.get_powerWordName())
			guardianStatue = new_guardianStatue;



}




GuardianStatue Repository::findByPowerWordName(const std::string & powerWordName)
{
	vector<GuardianStatue> guardianStatue = this->Encyclopedia;
	
	auto iterator = std::find_if(guardianStatue.begin(), guardianStatue.end(), [&powerWordName](const GuardianStatue& statue) {return statue.get_powerWordName() == powerWordName; });
	if (iterator==guardianStatue.end())
		return GuardianStatue{};
	return *iterator;
	/*for (int index = 0; index < guardianStatue.size(); index++)
	{
		
		if (guardianStatue[index].get_powerWordName() == powerWordName)
			return guardianStatue[index];
	}

	*/
}

string Repository::stringable_guardianStatue()
{
	string GuardianStatueString;
	for(auto& guardianStatue : this->Encyclopedia)
		GuardianStatueString +=guardianStatue.convert_to_string();
	return GuardianStatueString;
}




int Repository::find_index(const std::string & powerWordName)
{
	/*GuardianStatue guardianStatue = findByPowerWordName(powerWordName);
	if (powerWordName != "")
		return std::distance(this->Encyclopedia.begin(), std::find(this->Encyclopedia.begin(), this->Encyclopedia.end(), guardianStatue));
	*/
	int index = 0;
	for (auto& statue : this->Encyclopedia)
		if (statue.get_powerWordName() == powerWordName)
			return index;
		else 
			index++;
	/*for (int i = 0; i < this->Encyclopedia.size(); i++)
		if (this->Encyclopedia[i].get_powerWordName() == powerWordName)
			return i;
*/
	return -1;
}

Repository::~Repository()
{
}
