#pragma once
#include "Gear.h"
#include "DynamicArray.h"


typedef struct {
	
	DynamicArray* gears;
}GearRepository;

GearRepository* createRepository();
void destroyRepositoryGear(GearRepository* gear);

void addRepositoryGear(GearRepository *gear, int catalogueNumber, char *state, char *type, int value);

Gear* findRepositoryGearByCatalogueNumber(GearRepository* gearRepository, int catalogueNumber);


void updateRepositoryGear(GearRepository *gear, int catalogueNumber, char *newstate, char *newtype, int newvalue);

void removeRepositoryGear(GearRepository *gear, int catalogueNumber);