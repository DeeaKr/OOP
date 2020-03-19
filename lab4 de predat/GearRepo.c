#include "GearRepo.h"
#define CAPACITY 100
#include <string.h>
#include <stdlib.h>
#include <assert.h>


GearRepository* createRepository()
{
	GearRepository* new_gearRepository=(GearRepository*)malloc(sizeof(GearRepository));

	//new_gearRepository->size = 0;
	new_gearRepository->gears = initialize(CAPACITY,&destroyGear);



	return new_gearRepository;
}
void destroyRepositoryGear(GearRepository * gearRepository)
{
	if (gearRepository == NULL)
		return;
	destroyArray(gearRepository->gears);
	free(gearRepository);
}


void updateRepositoryGear(GearRepository * gearRepository, int catalogueNumber, char* newstate, char* newtype, int newvalue)
{
	int index;
	Gear* new_gearRepository = create(catalogueNumber, newstate, newtype, newvalue);
	for (index = 0; index < gearRepository->gears->size_of_the_array; index++)
	{
		if (get_catalogueNumber(gearRepository->gears->array[index]) == catalogueNumber)
			gearRepository->gears->array[index] = new_gearRepository;
		
	}

	
}

void removeRepositoryGear(GearRepository * gearRepository, int catalogueNumber)
{
	int index;
	for (index = 0; index < gearRepository->gears->size_of_the_array; index++)
	{
		if (get_catalogueNumber(gearRepository->gears->array[index]) == catalogueNumber)
		{
			deleteElement(gearRepository->gears, index);
		}

	}

	
	
	


}

void addRepositoryGear(GearRepository * gearRepository, int catalogueNumber, char* state, char* type, int value)
{
	
	Gear* new_gearRepository = create(catalogueNumber, state, type, value);
	Gear* copyOFGear = copyGear(new_gearRepository);
	addElement(gearRepository->gears, copyOFGear);

}

Gear * findRepositoryGearByCatalogueNumber(GearRepository * gearRepository, int catalogueNumber)
{
	for (int index = 0; index < gearRepository->gears->size_of_the_array; index++)
		if (get_catalogueNumber(gearRepository->gears->array[index]) == catalogueNumber)
			return gearRepository->gears->array[index];
}

void testRepository()
{
	/*GearRepository* repository = createRepository();

	//add
	addRepositoryGear(repository,1,"new","knife",3);
	addRepositoryGear(repository, 2, "old", "sword", 2);
	assert(repository->size == 2);
	//delete
	removeRepositoryGear(repository, 1);
	removeRepositoryGear(repository, 2);
	assert(repository->size == 0);
	destroyRepositoryGear(repository);*/
}




