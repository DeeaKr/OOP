#pragma once
#include "Repository.h"
#include "MyList.h"
#include "FileRepository.h"
#include "HTMLandCSVrepository.h"
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Service
{
private:
	Repository* repositoryStatue;
	MyList& htmlRepository;
	
public:
	Service(Repository* repository, MyList& html) : repositoryStatue{ repository }, htmlRepository{ html } {}


	//GuardianStatue* get_GuardianStatues() { return this->repositoryStatue.get_elements(); }
	
	Repository* getRepository() const { return this->repositoryStatue; }

	//void changePathofFile(std::string data);
	
	vector <GuardianStatue> get_allStatues() const { return this->repositoryStatue->getEncyclopedia(); }
	vector<GuardianStatue> get_list() const { return this->htmlRepository.getmyList(); }
	
	MyList& getMylist() const { return this->htmlRepository; }

	
	string list();
	string print_myList();
	
	//vector<GuardianStatue> getStatuesByAge(int age);
	//vector<GuardianStatue> getStatuesByMaterialandAge(const std::string material, int age);
	int service_addTOMylist(const std::string& powerWordName);

	int service_addGuardianStatue(const std::string& powerWordName, const std::string& material, int age, const std::string& corporealForm);

	int service_removeGuardianStatue(const std::string& powerWordName);

	int service_updateGuardianStatue(const std::string& powerWordName, const std::string& material, int age, const std::string& corporealForm);
	~Service();
};

