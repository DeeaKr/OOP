#pragma once
#include "Repository.h"
#include "MyList.h"
#include "FileRepository.h"
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Service
{
private:
	Repository* repositoryStatue;
	MyList& mylist;
public:
	Service(Repository* repository, MyList& myList) : repositoryStatue{ repository }, mylist{ myList }{}


	//GuardianStatue* get_GuardianStatues() { return this->repositoryStatue.get_elements(); }
	
	Repository* getRepository() const { return this->repositoryStatue; }

	void changePathofFile(std::string data);
	
	vector <GuardianStatue> get_allStatues() const { return this->repositoryStatue->getEncyclopedia(); }
	vector<GuardianStatue> get_list() const { return this->mylist.getmyList(); }
	
	MyList& getMylist() const { return mylist; }
	
	string list();
	string print_myList();
	

	int service_addTOMylist(const std::string& powerWordName);

	int service_addGuardianStatue(const std::string& powerWordName, const std::string& material, int age, const std::string& corporealForm);

	int service_removeGuardianStatue(const std::string& powerWordName);

	int service_updateGuardianStatue(const std::string& powerWordName, const std::string& material, int age, const std::string& corporealForm);
	~Service();
};

