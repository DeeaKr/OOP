//#include "pch.h"
#include "MyList.h"


MyList::MyList()
{
	this->current = 0;
}

void MyList::add(const GuardianStatue & guardianStatue)
{
	this->myList.add(guardianStatue);
}

GuardianStatue MyList::getCurrentGuardianStatue()
{
	int index;
	for (index = 0; index < this->myList.getSize(); index++)
		if (this->current == index)
			return this->myList.getAllElements()[index];
	
}

void MyList::next()
{

	int index;
	for (index = 0; index < this->myList.getSize(); index++)
	{
		if (index == this->myList.getSize())
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
	for (int index = 0; index < this->myList.getSize(); index++)
		GuardianStatueString += this->myList.getAllElements()[index].convert_to_string();
	return GuardianStatueString;
}


bool MyList::isEmpty()
{

	return this->myList.getSize() == 0;
}


MyList::~MyList()
{
}
