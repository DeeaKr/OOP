#pragma once
typedef struct
{
	int catalogueNumber;
	char *state;
	char *type;
	int value;
}Gear;

Gear* create(int catalogueNumber, char *state, char *type, int value);

void destroyGear(Gear* gear);
Gear* copyGear(Gear* gear);

char* getState(Gear* gear);

char* getType(Gear* gear);

int get_catalogueNumber(Gear* gear);

int get_value(Gear* gear);

