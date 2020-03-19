#pragma once
#include "Repository.h"
#include "MyList.h"
#include <string>
using namespace std;

class Service
{
private:
	Repository& repositoryStatue;
	MyList& mylist;
public:
	Service(Repository& repository, MyList& myList) : repositoryStatue{ repository }, mylist{ myList }{}
	//Service(MyList& myList) : mylist { myList } {}

	GuardianStatue* get_GuardianStatues() { return this->repositoryStatue.get_elements(); }
	Repository& getRepository() const { return repositoryStatue; }
	string listAge(int age);
	MyList& getMylist() const { return mylist; }
	string list();
	string print_myList();
	string listMatAge(std::string material,int age);

	int service_addTOMylist(const std::string& powerWordName);

	int service_addGuardianStatue(const std::string& powerWordName, const std::string& material, int age, const std::string& corporealForm);

	int service_removeGuardianStatue(const std::string& powerWordName);

	int service_updateGuardianStatue(const std::string& powerWordName, const std::string& material, int age, const std::string& corporealForm);
	~Service();
};

