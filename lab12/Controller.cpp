
#include "Controller.h"







/*void Service::changePathofFile(std::string data)
{
	this->repositoryStatue->changePath(data);
}*/

string Service::list()
{
	return this->getRepository()->stringable_guardianStatue();
}
string Service::print_myList()
{
	return this->getMylist().stringable_mylist();
}



/*
vector<GuardianStatue> Service::getStatuesByAge(int age)
{
	std::vector<GuardianStatue> statues = this->get_allStatues();
	std::vector<GuardianStatue> filter_list(statues.size());
	int length = statues.size();
	auto iterator = std::copy_if(statues.begin(), statues.end(), filter_list.begin(), [age](GuardianStatue statue) {return !(statue.get_age() >= age); });
	filter_list.resize(std::distance(filter_list.begin(), iterator));
	return filter_list;

}

vector<GuardianStatue> Service::getStatuesByMaterialandAge(const std::string material, int age)
{
	std::vector<GuardianStatue> statues = this->get_allStatues();
	std::vector<GuardianStatue> filter_list(statues.size());
	int length = statues.size();
	auto iterator = std::copy_if(statues.begin(), statues.end(), filter_list.begin(), [age, material](GuardianStatue statue) {return !(statue.get_age() >= age) && statue.get_material() == material; });
	filter_list.resize(std::distance(filter_list.begin(), iterator));
	return filter_list;

}*/

int Service::service_addTOMylist(const std::string & powerWordName)
{
	int index;
	GuardianStatue guardianStatue;

	index = this->repositoryStatue->find_index(powerWordName);
	//	cout << index;
		//INDEX!=-1?
	if (index != -1)
	{
		guardianStatue = this->repositoryStatue->findByPowerWordName(powerWordName);
		//cout << guardianStatue.get_material()<<endl;
		this->mylistRepository.add(guardianStatue);
		return 0;
	}
	else return 1;
}

int Service::service_addGuardianStatue(const std::string & powerWordName, const std::string & material, int age, const std::string & corporealForm)
{
	//int index;
	GuardianStatue guardianStatue{ powerWordName, material,age,corporealForm };
	//index = this->getRepository()->find_index(powerWordName);
	//if (index == -1)
	//{
	this->repositoryStatue->repository_addGuardianStatue(guardianStatue);
	//}
	//else return 1;
	return 0;
}

int Service::service_removeGuardianStatue(const std::string & powerWordName)
{
	int old_lenghtOfTheRepository, new_lenghtOfTheRepository;
	old_lenghtOfTheRepository = this->getRepository()->getEncyclopedia().size();

	this->repositoryStatue->repository_removeGuardianStatue(powerWordName);
	new_lenghtOfTheRepository = this->getRepository()->getEncyclopedia().size();



	return 0;
}

int Service::service_updateGuardianStatue(const std::string & powerWordName, const std::string & material, int age, const std::string & corporealForm)
{
	int index;
	GuardianStatue guardianStatue{ powerWordName, material,age,corporealForm };
	index = this->getRepository()->find_index(powerWordName);
	if (index == -1)
	{
		return 1;
	}
	this->getRepository()->repository_updateGuardianStatue(guardianStatue);
	return 0;

}

Service::~Service()
{
}
