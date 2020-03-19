
#include "ServiceGear.h"


GearService* constructor(GearRepository * gearRepository,OperationStack* undo,OperationStack* redo)
{
	GearService* new_gearService=(GearService*)malloc(sizeof(GearService));
	new_gearService->gearRepository= gearRepository;
	new_gearService->undo = undo;
	new_gearService->redo = redo;
	return new_gearService;
}

void destroyGearService(GearService* gearService)
{
	destroyRepositoryGear(gearService->gearRepository);

	destroyStack(gearService->undo);
	destroyStack(gearService->redo);

	free(gearService);
}

int addGearService(GearService * gearService, int catalogueNumber, char *state, char *type, int value)
{//returns 1 if the gear already exists in the catalogue,0 otherwise
	int index;

	for (index = 0; index < gearService->gearRepository->gears->size_of_the_array; index++)
		if (get_catalogueNumber(gearService->gearRepository->gears->array[index]) == catalogueNumber)
			return 1;

	Gear* new_gear = create(catalogueNumber, state, type, value);
	addRepositoryGear(gearService->gearRepository, catalogueNumber, state, type, value);
	Operation* operation = createOperation(new_gear, "add");
	push(gearService->undo, operation);
	deleteStack(gearService->redo);

	operation = NULL;
	new_gear = NULL;

	return 0;
	
}

int deleteGearService(GearService * gearService, int catalogueNumber)
{//returns 1 if the lenght after deleting remains the same
	int old_lenghtOfTheRepository,new_lenghtOfTheRepository;
	old_lenghtOfTheRepository = gearService->gearRepository->gears->size_of_the_array;
	Gear* new_gear = findRepositoryGearByCatalogueNumber(gearService->gearRepository, catalogueNumber);
	Operation* operation = createOperation(new_gear, "delete");
	push(gearService->undo, operation);
	deleteStack(gearService->redo);
	removeRepositoryGear(gearService->gearRepository, catalogueNumber);
	new_lenghtOfTheRepository = gearService->gearRepository->gears->size_of_the_array;
	if (old_lenghtOfTheRepository == new_lenghtOfTheRepository)
		return 1;
	
	
	operation = NULL;
	new_gear = NULL;
	return 0;
}

int updateGearService(GearService * gearService, int catalogueNumber, char *state, char *type, int value)
{ 
	
	int index;
	for (index = 0; index < gearService->gearRepository->gears->size_of_the_array; index++)
		if (get_catalogueNumber(gearService->gearRepository->gears->array[index]) != catalogueNumber)
			return 1;

	Gear* new_gear = findRepositoryGearByCatalogueNumber(gearService->gearRepository, catalogueNumber);
	Operation* operation = createOperation(new_gear, "update");
	push(gearService->undo, operation);
	deleteStack(gearService->redo);
	
	operation = NULL;
	new_gear = NULL;
	

	updateRepositoryGear(gearService->gearRepository, catalogueNumber, state, type, value);
		
	
	return 0;
}

int undo(GearService * gearService)
{
	if (isEmpty(gearService->undo))
		return 0;
	Operation* operation = pop(gearService->undo);
	if (strcmp(operation->operationType, "add") == 0) {
		
		Gear* gear = operation->gear;
		Operation* operation = createOperation(gear, "add");
		push(gearService->redo, operation);
		operation = NULL;

		removeRepositoryGear(gearService->gearRepository, get_catalogueNumber(gear));

	}
	else
		if (strcmp(operation->operationType, "delete") == 0)
		{
			Gear* gear = operation->gear;
			addRepositoryGear(gearService->gearRepository, get_catalogueNumber(gear), getState(gear), getType(gear), get_value(gear));

			Operation* operation = createOperation(gear, "delete");
			push(gearService->redo, operation);

			operation = NULL;
			gear = NULL;

			

		}
		else
			if (strcmp(operation->operationType, "update") == 0)
			{
				Gear* gear = operation->gear;
				Gear* new_gear = copyGear(findRepositoryGearByCatalogueNumber(gearService->gearRepository, get_catalogueNumber(gear)));
				updateRepositoryGear(gearService->gearRepository, gear->catalogueNumber, gear->state, gear->type, gear->value);
				Operation* operation = createOperation(new_gear, "update");
				push(gearService->redo, operation);
				
				operation = NULL;
				new_gear = NULL;
				gear = NULL;
			
			}
	free(operation->operationType);

	free(operation);



	return 1;
}

int redo(GearService * gearService)
{
	if (isEmpty(gearService->redo))
		return 0;

	Operation* operation = pop(gearService->redo);
	if (strcmp(operation->operationType, "add") == 0)
	{
		Gear* gear = operation->gear;
		addRepositoryGear(gearService->gearRepository, get_catalogueNumber(gear), getState(gear), getType(gear), get_value(gear));
		Operation* new_operation = createOperation(gear, "add");
		push(gearService->undo, new_operation);
		new_operation = NULL;
	}
	else 
		if (strcmp(operation->operationType, "delete") == 0)
		{
			Gear* gear = operation->gear;
			removeRepositoryGear(gearService->gearRepository, get_catalogueNumber(gear));
			Operation* new_operation = createOperation(gear, "delete");
			push(gearService->undo, new_operation);
			new_operation = NULL;
			gear = NULL;

		}
		else
			if (strcmp(operation->operationType, "update") == 0)
			{
				Gear* gear = operation->gear;
				Gear* new_gear = findRepositoryGearByCatalogueNumber(gearService->gearRepository, get_catalogueNumber(gear));

				updateRepositoryGear(gearService->gearRepository, gear->catalogueNumber, gear->state, gear->type, gear->value);
				Operation* new_operation = createOperation(gear, "update");
				push(gearService->undo, new_operation);

				

				new_operation = NULL;
				gear = NULL;
				new_gear = NULL;
			}
	free(operation->operationType);

	free(operation);


	return 1;
}
