#pragma once
#include "Repository.h"
#include <string>
using namespace std;

class Service
{
private:
	Repository& repositoryStatue;
public:
	Service(Repository& repository) : repositoryStatue{ repository } {}
	
	Repository& getRepository() const { return repositoryStatue; }
	
	string list();

	int service_addGuardianStatue(const std::string& powerWordName, const std::string& material, int age, const std::string& corporealForm);

	int service_removeGuardianStatue(const std::string& powerWordName);

	int service_updateGuardianStatue(const std::string& powerWordName, const std::string& material, int age, const std::string& corporealForm);
	~Service();
};

