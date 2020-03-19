#include "pch.h"
#include "Exceptions.h"


Exceptions::Exceptions(const std::string anotherError):error{anotherError}
{

}


std::string Exceptions::get_error_message() const
{
	return this->error;
}

Exceptions::~Exceptions()
{
}
