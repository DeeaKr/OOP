#include "DynamicArray.h"
#include <stdlib.h>

DynamicArray * initialize(int capacity_of_the_array,freeElements freeDynamicArray)
{
	DynamicArray *dynamic_array = (DynamicArray*)malloc(sizeof(DynamicArray));
	if (dynamic_array == NULL)
		return NULL;
	dynamic_array->array = (TElem*)malloc(capacity_of_the_array * sizeof(TElem));
	
	dynamic_array->size_of_the_array = 0;

	dynamic_array->freeElements = freeDynamicArray;
	
	dynamic_array->capacity_of_the_array = capacity_of_the_array;
	
	if (dynamic_array->array == NULL)
		return NULL;

	return dynamic_array;

}

void destroyArray(DynamicArray* dynamic_array)
{
	if (dynamic_array == NULL)
		return;
	for (int index = 0; index < dynamic_array->size_of_the_array; index++)
		dynamic_array->freeElements(dynamic_array->array[index]);
	
	free(dynamic_array->array);
	dynamic_array->array = NULL;

	free(dynamic_array);
	dynamic_array = NULL;
}

int resize(DynamicArray* dynamic_array) {
	if (dynamic_array == NULL)
		return -1;
	dynamic_array->capacity_of_the_array *= 2;
	TElem* copy_of_the_array = (TElem*)malloc(dynamic_array->capacity_of_the_array * sizeof(TElem));
	if (copy_of_the_array == NULL)
		return -1;

	for (int i = 0; i < dynamic_array->size_of_the_array; i++)
		copy_of_the_array[i] = dynamic_array->array[i];
	free(dynamic_array->array);
	dynamic_array->array = copy_of_the_array;

	return 0;

}
void addElement(DynamicArray* dynamic_array, TElem element_to_be_added)
{
	if (dynamic_array == NULL)
		return;
	if (dynamic_array->array == NULL)
		return;
	if (dynamic_array->size_of_the_array >= dynamic_array->capacity_of_the_array)
		resize(dynamic_array);
	dynamic_array->array[dynamic_array->size_of_the_array++] = element_to_be_added;

}

void deleteElement(DynamicArray *dynamic_array, int position)
{
	if (dynamic_array == NULL)
		return;
	if (dynamic_array->array == NULL)
		return;
	if (position < 0 || position >= dynamic_array->array)
		return;
	dynamic_array->freeElements(dynamic_array->array[position]);
	for (int index = position; index < dynamic_array->size_of_the_array; index++)
		dynamic_array->array[index] = dynamic_array->array[index + 1];
	dynamic_array->size_of_the_array--;
}
