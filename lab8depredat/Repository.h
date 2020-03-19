#pragma once
#include "GuardianStatue.h"
#include"DynamicArray.h"
#include "MyList.h"
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Repository
{
	friend class Service;

public:
	Repository() {}
protected:
	vector<GuardianStatue> Encyclopedia;
	virtual void repository_addGuardianStatue(const GuardianStatue& guardianStatue);
	virtual void repository_removeGuardianStatue(const std::string& powerWordName);
	virtual void repository_updateGuardianStatue(const GuardianStatue& new_guardianStatue);
public:
	GuardianStatue findByPowerWordName(const std::string& powerWordName);
	//GuardianStatue* get_elements() { return this->Encyclopedia; };
	string stringable_guardianStatue();

	vector<GuardianStatue> getEncyclopedia() const { return Encyclopedia; }

	int find_index(const std::string& powerWordName);
	virtual void changePath(std::string new_data)=0;
	
	virtual ~Repository();



};

