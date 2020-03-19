#include "pch.h"
#include "Validator.h"


Validator::Validator()
{
}

void Validator::validateGuardianStatue(GuardianStatue statue)
{
	if (statue.get_powerWordName() == "")
		throw Exceptions("Invalid input");
	if(statue.get_material()=="")
		throw Exceptions("Invalid input");
	if(statue.get_age()<0)
		throw Exceptions("Invalid input");
	//if (statue.get_corporealForm() == "");
	//	throw Exceptions("D Invalid input");

}


Validator::~Validator()
{
}
