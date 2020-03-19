#pragma once
#include<iostream>
#include <string>
#include <stdlib.h>
using namespace std;


class GuardianStatue
{
private:
	std::string powerWordName;
	std::string material;
	int age;
	std::string corporealForm;

public:
	GuardianStatue();

	GuardianStatue(const std::string& powerWordName, const std::string& material, const int age, const std::string& corporealForm);

	std::string get_powerWordName() const { return powerWordName; }
	std::string get_material() const { return material; }
	int get_age() const { return age; }
	std::string get_corporealForm() const { return corporealForm; }
	string convert_to_string();

	~GuardianStatue();
};

