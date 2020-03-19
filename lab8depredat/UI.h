#pragma once
#include "Service.h"

#include <iostream>
#include<string>
#include <fstream>
#include <algorithm>
using namespace std;

class UI
{
private:
	Service service;
	string list;
public:
	UI(const Service serviceStatue): service(serviceStatue){}
	UI(const Service serviceStatue, string& output);
	void run();
	~UI();
private:
	void ui_addGuardianStatue(const std::string& powerWordName,const std::string& material,int age,const std::string& corporealForm);
	void ui_list();
	string ui_listAge(int age);
	string ui_listMatAge(const std::string& material, int age);
	void ui_print_mylist();
	
	void ui_removeGuardianStatue(const std::string& powerWordName);

	void ui_updateGuardianStatue(const std::string& powerWordName, const std::string& material, int age, const std::string& corporealForm);
	void ui_addTOMylist(const std::string& powerWordName);
};


