#pragma once
#include "GuardianStatue.h"
#include <string>
typedef GuardianStatue TElement;

class DynamicArray
{
private:
	TElement* elemements;
	int size_of_the_dynamic_array;
	int capacity_of_the_dynamic_array;

public:
	DynamicArray(int capacity = 10);

	DynamicArray(const DynamicArray& dynamicArray);
	~DynamicArray();

	DynamicArray& operator=(const DynamicArray& dynamicArray);

	// Adds an element to the current DynamicVector.
	void add(const TElement& element);
	void remove(const string& element);

	int getSize() const;
	TElement* getAllElems() const;
	

private:
	// Resizes the current DynamicVector, multiplying its capacity by a given factor (real number).
	void resize(double factor = 2);
};


