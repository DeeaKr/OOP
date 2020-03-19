#pragma once
#include "Repository.h"
#include <iostream>
#include <fstream>
class FileRepository:
	public Repository
{
	friend class Sevice;
private:
	std::string data;
public:
	FileRepository(std::string& file_name);

	~FileRepository();
private:

	virtual void readFromFile();
	virtual void writeTOFile();
	void repository_addGuardianStatue(const GuardianStatue& guardianStatue) override;
	void repository_removeGuardianStatue(const std::string& powerWordName) override;
	void repository_updateGuardianStatue(const GuardianStatue& new_guardianStatue) override;
	//void changePath(std::string new_data) override;
	
};

