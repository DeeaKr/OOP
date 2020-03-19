#pragma once
#include "DynamicArray.h"
#include "GuardianStatue.h"

class MyList
{
private:
	DynamicArray<GuardianStatue> myList;
	int current;
public:
	MyList();
	DynamicArray<GuardianStatue> getmyList() const { return myList; }
	int get_index() const { return current; }
	void add(const GuardianStatue& guardianStatue);

	string stringable_mylist();


	GuardianStatue getCurrentGuardianStatue();
	void next();
	
	bool isEmpty();
	~MyList();
};

