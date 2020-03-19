#pragma once
#include "GuardianStatue.h"
#include"DynamicArray.h"
#include "MyList.h"
#include <string>
using namespace std;
class Repository
{
private:
	DynamicArray<GuardianStatue> Encyclopedia;
public:
	Repository() {}
	void repository_addGuardianStatue(const GuardianStatue& guardianStatue);
	void repository_removeGuardianStatue(const std::string& powerWordName);
	void repository_updateGuardianStatue(const GuardianStatue& new_guardianStatue);
	string repository_listMaterialAge(const std::string& material, int age);
	GuardianStatue findByPowerWordName(const std::string& powerWordName);
	GuardianStatue* get_elements() { return this->Encyclopedia.getAllElements(); };
	string stringable_guardianStatue();
	string repository_listAge(int age);
	DynamicArray<GuardianStatue> getEncyclopedia() const { return Encyclopedia; }

	int find_index(const std::string& powerWordName);
	
	~Repository();



};

