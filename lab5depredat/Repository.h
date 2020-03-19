#pragma once
#include "GuardianStatue.h"
#include"DynamicArray.h"
#include <string>
using namespace std;
class Repository
{
private:
	DynamicArray Encyclopedia;
public:
	Repository() {}
	void repository_addGuardianStatue(const GuardianStatue& guardianStatue);
	void repository_removeGuardianStatue(const std::string& powerWordName);
	void repository_updateGuardianStatue(const GuardianStatue& new_guardianStatue);
	GuardianStatue findByPowerWordName(const std::string& powerWordName);

	string stringable_guardianStatue();

	DynamicArray getEncyclopedia() const { return Encyclopedia; }

	int find_index(const std::string& powerWordName);
	
	~Repository();



};

