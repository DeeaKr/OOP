#pragma once
#include <string.h>
#include <stdlib.h>
#include "GearRepo.h"
#include "Gear.h"
#include "OperationStack.h"

typedef struct {
	GearRepository* gearRepository;
	OperationStack* undo;
	OperationStack* redo;

}GearService;

GearService* constructor(GearRepository *gearRepository,OperationStack* undo, OperationStack* redo);
void destroyGearService(GearService* gearService);

int addGearService(GearService * gearService, int catalogueNumber, char* state, char* type, int value);

int deleteGearService(GearService *gearService, int catalogueNumber);

int updateGearService(GearService *gearService, int catalogueNumber, char* state, char* type, int value);

int undo(GearService* gearService);

int redo(GearService* gearService);