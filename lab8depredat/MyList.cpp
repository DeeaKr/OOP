#include "pch.h"
#include "MyList.h"


MyList::MyList()
{
	this->current = 0;
}

void MyList::add(const GuardianStatue & guardianStatue)
{
	this->myList.push_back(guardianStatue);
}

GuardianStatue MyList::getCurrentGuardianStatue()
{
	int index;
	//for_each(this->myList.begin(), this->myList.end(), []() {});
	for (index = 0; index < this->myList.size(); index++)
		if (this->current == index)
			return this->myList[index];
	
}

void MyList::next()
{

	int index;
	for (index = 0; index < this->myList.size(); index++)
	{
		if (index == this->myList.size())
		{
			this->current = 0;
		}
		if (this->current == index)
		{
			this->current += 1;
		}
	}
	
}


string MyList::stringable_mylist()
{
	string GuardianStatueString;
	for (auto& guardianStatue: this->myList)
		GuardianStatueString += guardianStatue.convert_to_string();
	
	return GuardianStatueString;
}


bool MyList::isEmpty()
{

	return this->myList.size() == 0;
}


MyList::~MyList()
{
}
