#pragma once
#include "Repository.h"
#include "MyList.h"
#include <fstream>

class HTMLandCSVrepository:
	public MyList
{
private:
	std::string specialData;
public:
	HTMLandCSVrepository(std::string file) : specialData{ file } {};
	//void readFromFile() override;
	void write();
	void writeToHTMLFile();
	void writeToCSVFile();
	//void add(const GuardianStatue& guardianStatue) override;
	~HTMLandCSVrepository();
};

