
#include "DynamicArray.h"
#include<string>
using namespace std;

DynamicArray::DynamicArray(int capacity_of_the_array)
{
	this->size_of_the_dynamic_array = 0;
	this->capacity_of_the_dynamic_array = capacity_of_the_array;
	this->elemements = new TElement[capacity_of_the_array];
}




DynamicArray::DynamicArray(const DynamicArray & dynamicArray)
{
	this->size_of_the_dynamic_array = dynamicArray.size_of_the_dynamic_array;
	this->capacity_of_the_dynamic_array =dynamicArray.capacity_of_the_dynamic_array;
	this->elemements = new TElement[this->capacity_of_the_dynamic_array];
}

DynamicArray::~DynamicArray()
{
	delete[] this->elemements;
}

DynamicArray & DynamicArray::operator=(const DynamicArray & dynamicArray)
{
	if (this == &dynamicArray)
		return *this;

	this->size_of_the_dynamic_array = dynamicArray.size_of_the_dynamic_array;
	this->capacity_of_the_dynamic_array = dynamicArray.capacity_of_the_dynamic_array;

	delete[] this->elemements;
	this->elemements = new TElement[this->capacity_of_the_dynamic_array];
	for (int i = 0; i < this->size_of_the_dynamic_array; i++)
		this->elemements[i] = dynamicArray.elemements[i];

	return *this;
}
void DynamicArray::add(const TElement& element)
{
	if (this->size_of_the_dynamic_array == this->capacity_of_the_dynamic_array)
	{

		this->resize();
	}
	this->elemements[this->size_of_the_dynamic_array] = element;
	this->size_of_the_dynamic_array++;
}

void DynamicArray::remove(const string& element)
{
	int index,anotherIndex;

	for (index=0;index<this->size_of_the_dynamic_array;index++)
		if (this->elemements[index].get_powerWordName() == element)
		{
			for (anotherIndex = index; anotherIndex < this->size_of_the_dynamic_array-1; anotherIndex++)
				this->elemements[anotherIndex] = this->elemements[anotherIndex + 1];
			if(this->size_of_the_dynamic_array==1)
				this->elemements[anotherIndex] = this->elemements[anotherIndex + 1];
			this->size_of_the_dynamic_array--;

		}
	
}

void DynamicArray::resize(double factor)
{
	this->capacity_of_the_dynamic_array *= static_cast<int>(factor);

	TElement* els = new TElement[this->capacity_of_the_dynamic_array];
	for (int i = 0; i < this->size_of_the_dynamic_array; i++)
		els[i] = this->elemements[i];

	delete[] this->elemements;
	this->elemements = els;
}

TElement* DynamicArray::getAllElems() const
{
	return this->elemements;
}

int DynamicArray::getSize() const
{
	return this->size_of_the_dynamic_array;
}