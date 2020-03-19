
#include "Service.h"





string Service::list()
{
	return this->getRepository().stringable_guardianStatue();
}

int Service::service_addGuardianStatue(const std::string & powerWordName, const std::string & material, int age, const std::string & corporealForm)
{
	int index;
	GuardianStatue guardianStatue{ powerWordName, material,age,corporealForm };
	index = this->getRepository().find_index(powerWordName);
	if (index == -1)
	{
		this->repositoryStatue.repository_addGuardianStatue(guardianStatue);
		return 0;
	}
	else return 1;
}

int Service::service_removeGuardianStatue(const std::string & powerWordName)
{
	int old_lenghtOfTheRepository, new_lenghtOfTheRepository;
	old_lenghtOfTheRepository = this->getRepository().getEncyclopedia().getSize();
	
	this->repositoryStatue.repository_removeGuardianStatue(powerWordName);
	new_lenghtOfTheRepository = this->getRepository().getEncyclopedia().getSize();
	
	if (old_lenghtOfTheRepository == new_lenghtOfTheRepository)
		return 1;
	
	return 0;
}

int Service::service_updateGuardianStatue(const std::string & powerWordName, const std::string & material, int age, const std::string & corporealForm)
{
	int index;
	GuardianStatue guardianStatue{ powerWordName, material,age,corporealForm };
	index = this->getRepository().find_index(powerWordName);
	if (index == -1)
	{
		return 1;
	}
	this->getRepository().repository_updateGuardianStatue(guardianStatue);
	return 0;
	
}

Service::~Service()
{
}
