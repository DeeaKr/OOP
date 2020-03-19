#include "pch.h"
#include "FileRepository.h"
#include <iostream>
#include <fstream>
FileRepository::FileRepository(std::string& file_name):Repository{},data{file_name}
{
	this->readFromFile();
} FileRepository::~FileRepository(){}

void FileRepository::readFromFile()
{
	std::ifstream file_name;
	file_name.open(this->data);

	if (file_name.is_open())
	{
		GuardianStatue statue;
		while (!file_name.eof())
		{       
				file_name >> statue;
				this->Encyclopedia.push_back(statue);

		}
		this->Encyclopedia.pop_back();
	}
	file_name.close();
}

void FileRepository::writeTOFile()
{
	ofstream file;
	file.open(this->data);
	std::vector<GuardianStatue> allStatues = this->Encyclopedia;
	for (auto& statue : allStatues)
		file << statue;
	file.close();
}

void FileRepository::repository_addGuardianStatue(const GuardianStatue & guardianStatue)
{
	Validator::validateGuardianStatue(guardianStatue);
	this->Encyclopedia.push_back(guardianStatue);
	this->writeTOFile();
}

void FileRepository::repository_removeGuardianStatue(const std::string & powerWordName)
{
	int index = find_index(powerWordName);
	this->Encyclopedia.erase(this->Encyclopedia.begin() + index);
	this->writeTOFile();
}

void FileRepository::repository_updateGuardianStatue(const GuardianStatue & new_guardianStatue)
{
	Validator::validateGuardianStatue(new_guardianStatue);
	for (auto& guardianStatue : this->Encyclopedia)
		if (guardianStatue.get_powerWordName() == new_guardianStatue.get_powerWordName())
			guardianStatue = new_guardianStatue;
	this->writeTOFile();
}

/*void FileRepository::changePath(std::string new_data)
{
	this->data.assign(new_data);
	this->Encyclopedia.clear();
	this->readFromFile();
}*/

