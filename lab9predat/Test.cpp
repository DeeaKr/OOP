#include "pch.h"
#include "Test.h"


Test::Test()
{
}

void Test::TestAll()
{/*
	std::string file = "fileee.txt";
	fstream f;
	MyList mylist;
	Repository* repository = new FileRepository{ file };
	Service service{ repository,mylist };
	string aString=service.list();
	assert(service.list() == aString);
	GuardianStatue statue{ "power","steal",5,"knife" };
	GuardianStatue another_statue{};
	service.service_addGuardianStatue(statue.get_powerWordName(),statue.get_material(),statue.get_age(),statue.get_corporealForm());
	service.service_updateGuardianStatue("power", "metal", 6, "knife");

	//assert(service.list() == "power,metal,6,knife\n");
	GuardianStatue statueTobetested{};
	f.open(file);
	f >> statueTobetested;
	//assert(statueTobetested == statue);

	service.service_addTOMylist("power");
	string anotherString = service.print_myList();
	assert(service.print_myList() == anotherString);
	service.service_removeGuardianStatue("power");
	service.service_addGuardianStatue("abra", "wood", 90, "wond");

	Repository testRepository{};
	GuardianStatue guardianStatue{ "MorePower", "iron", 100, "sword" };
	testRepository.repository_addGuardianStatue(guardianStatue);
	GuardianStatue guardianStatueforUpdate{ "MorePower", "iron", 500, "sword" };
	testRepository.repository_updateGuardianStatue(guardianStatueforUpdate);
	//assert(guardianStatue == guardianStatueforUpdate);
	testRepository.repository_removeGuardianStatue("MorePower");
	GuardianStatue EmptyPowerWordName{};
	assert(testRepository.findByPowerWordName("noName") == EmptyPowerWordName);
	GuardianStatue anotherguardian{"","",-7,""};
	try {
		Validator::validateGuardianStatue(anotherguardian);}
	catch (Exceptions& exception)
	{
		assert(exception.get_error_message() == "Invalid input");
	}
	GuardianStatue anotherguardian2{ "power","",-7,"" };
	try {
		Validator::validateGuardianStatue(anotherguardian2);}
	catch (Exceptions& exception)
	{
		assert(exception.get_error_message() == "Invalid input");
	}
	GuardianStatue anotherguardian3{ "power","words",-7,"" };
	try {
		Validator::validateGuardianStatue(anotherguardian3);}
	catch (Exceptions& exception)
	{
		assert(exception.get_error_message() == "Invalid input");
	}
	Validator{};
	Test{};

	service.service_addTOMylist("powerWord");
	service.service_addTOMylist("powerWord");
	//cout << repository->stringable_guardianStatue();
	assert(!(anotherguardian == anotherguardian2));

	service.service_addTOMylist("abra");
	service.service_updateGuardianStatue("test", "for", 1, "update");
	service.get_allStatues();
	
	*/
}


Test::~Test()
{
}
