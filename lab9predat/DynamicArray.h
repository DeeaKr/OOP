#pragma once
#include "GuardianStatue.h"
#include <string>

typedef GuardianStatue TElement;
template <typename TElement> 
class DynamicArray
{
private:
	TElement* elements;
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
	TElement* getAllElements() const;
	

private:
	// Resizes the current DynamicVector, multiplying its capacity by a given factor (real number).
	void resize(double factor = 2);
};




template <typename TElement>
DynamicArray<TElement>::DynamicArray(int capacity_of_the_array)
{
	this->size_of_the_dynamic_array = 0;
	this->capacity_of_the_dynamic_array = capacity_of_the_array;
	this->elements = new TElement[capacity_of_the_array];
}



template <typename TElement>
DynamicArray<TElement>::DynamicArray(const DynamicArray & dynamicArray)
{

	
		int index;
		this->size_of_the_dynamic_array = dynamicArray.size_of_the_dynamic_array;
		this->capacity_of_the_dynamic_array = dynamicArray.capacity_of_the_dynamic_array;
		this->elements = new TElement[this->capacity_of_the_dynamic_array];
		for (index = 0; index < this->size_of_the_dynamic_array; index++)
			this->elements[index] = dynamicArray.elements[index];
	


	//this->size_of_the_dynamic_array = dynamicArray.size_of_the_dynamic_array;
	//this->capacity_of_the_dynamic_array = dynamicArray.capacity_of_the_dynamic_array;
	//for (int index = 0; index < this->capacity_of_the_dynamic_array; index++)
	//	this->elements[index] = dynamicArray.elements[index];
	//this->elements = new TElement[this->capacity_of_the_dynamic_array];
}
template <typename TElement>
DynamicArray<TElement>::~DynamicArray()
{
	delete[] this->elements;
}
template <typename TElement>
DynamicArray<TElement> & DynamicArray<TElement>::operator=(const DynamicArray & dynamicArray)
{
	if (this == &dynamicArray)
		return *this;

	this->size_of_the_dynamic_array = dynamicArray.size_of_the_dynamic_array;
	this->capacity_of_the_dynamic_array = dynamicArray.capacity_of_the_dynamic_array;

	delete[] this->elements;
	this->elements = new TElement[this->capacity_of_the_dynamic_array];
	for (int i = 0; i < this->size_of_the_dynamic_array; i++)
		this->elements[i] = dynamicArray.elements[i];

	return *this;
}
template <typename TElement>

void DynamicArray<TElement>::add(const TElement& element)
{
	if (this->size_of_the_dynamic_array == this->capacity_of_the_dynamic_array)
	{

		this->resize();
	}
	this->elements[this->size_of_the_dynamic_array] = element;
	this->size_of_the_dynamic_array++;
}
template <typename TElement>
void DynamicArray<TElement>::remove(const string& element)
{
	int index, anotherIndex;

	for (index = 0; index < this->size_of_the_dynamic_array; index++)
		if (this->elements[index].get_powerWordName() == element)
		{
			for (anotherIndex = index; anotherIndex < this->size_of_the_dynamic_array - 1; anotherIndex++)
				this->elements[anotherIndex] = this->elements[anotherIndex + 1];
			if (this->size_of_the_dynamic_array == 1)
				this->elements[anotherIndex] = this->elements[anotherIndex + 1];
			this->size_of_the_dynamic_array--;

		}

}
template <typename TElement>
void DynamicArray<TElement>::resize(double factor)
{
	this->capacity_of_the_dynamic_array *= static_cast<int>(factor);

	TElement* elements_of_dynamic_array = new TElement[this->capacity_of_the_dynamic_array];
	for (int i = 0; i < this->size_of_the_dynamic_array; i++)
		elements_of_dynamic_array[i] = this->elements[i];

	delete[] this->elements;
	this->elements = elements_of_dynamic_array;
}

template <typename TElement>
TElement* DynamicArray<TElement>::getAllElements() const
{
	return this->elements;
}
template <typename TElement>
int DynamicArray<TElement>::getSize() const
{
	return this->size_of_the_dynamic_array;
}

