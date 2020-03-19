#pragma once
#include<string>
class Exceptions
{
private:
	std::string error;
public:
	Exceptions(const std::string anotherError);
	std::string get_error_message() const;
	~Exceptions();
};

