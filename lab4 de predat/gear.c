#include "Gear.h"
#include <string.h>


Gear* create(int catalogueNumber, char *state, char *type, int value)
{
	Gear* new_gear=(Gear*)malloc(sizeof(Gear));
	

	new_gear->catalogueNumber = catalogueNumber;


	new_gear->state = (char*)malloc(sizeof(char)*(strlen(state) + 1));
	strcpy(new_gear->state, state);

	new_gear->type = (char*)malloc(sizeof(char)* (strlen(type) + 1));
	strcpy(new_gear->type, type);

	new_gear->value = value;
	

	return new_gear;
}

void destroyGear(Gear * gear)
{
	if (gear == NULL)
		return;
	free(gear->state);
	free(gear->type);

	free(gear);
}

Gear* copyGear(Gear * gear)
{
	if (gear == NULL)
		return NULL;

	Gear* new_gear = create(get_catalogueNumber(gear), getState(gear), getType(gear), get_value(gear));
	return new_gear;
}


char* getState(Gear* gear)
{
	return gear->state;
}

char* getType(Gear* gear)
{
	return gear->type;
}
int get_value(Gear* gear)
{
	return gear->value;
}
int get_catalogueNumber(Gear* gear)
{
	return gear->catalogueNumber;
}



