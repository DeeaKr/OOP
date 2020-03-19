#pragma once
#include "Gear.h"
#define CAPACITY 100

typedef Gear* TElem;

typedef void(*freeElements)(void*);

typedef struct {
	TElem *array;
	int size_of_the_array, capacity_of_the_array;
	freeElements freeElements;

}DynamicArray;

DynamicArray * initialize(int capacity_of_the_array, freeElements freeDynamicArray);
void destroyArray(DynamicArray*);

void addElement(DynamicArray*, TElem);

void deleteElement(DynamicArray*, int position);