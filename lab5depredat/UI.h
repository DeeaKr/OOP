#pragma once
#include "Service.h"
#include <iostream>
#include<string>
using namespace std;

class UI
{
private:
	Service service;
public:
	UI(const Service& serviceStatue): service(serviceStatue){}
	void run();
	~UI();
private:
	void ui_addGuardianStatue(const std::string& powerWordName,const std::string& material,int age,const std::string& corporealForm);
	void ui_list();
	void ui_removeGuardianStatue(const std::string& powerWordName);
	void ui_updateGuardianStatue(const std::string& powerWordName, const std::string& material, int age, const std::string& corporealForm);
};

