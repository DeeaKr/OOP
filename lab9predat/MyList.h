#pragma once
#include "DynamicArray.h"
#include "GuardianStatue.h"
#include <algorithm>
#include <vector>

class MyList
{
private:
	vector<GuardianStatue> myList;
	int current;
	
public:
	MyList();
	vector<GuardianStatue> getmyList() const { return myList; }
	//int get_index() const { return current; }
	void add(const GuardianStatue& guardianStatue);

	string stringable_mylist();


	//GuardianStatue getCurrentGuardianStatue();
	//void next();
	
	//bool isEmpty();
	~MyList();
};

