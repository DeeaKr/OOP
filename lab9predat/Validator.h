#pragma once
#include "GuardianStatue.h"
#include "Exceptions.h"
#include <exception>
class Validator
{
public:
	Validator();
	static void validateGuardianStatue(GuardianStatue statue);
	~Validator();
};

