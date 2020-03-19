#include "UI.h"
#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Console* constructConsole(GearService * gearService)
{
	Console* new_console=(Console*)malloc(sizeof(Console));
	new_console->gearService = gearService;
	return new_console;
}

void destroyConsole(Console * console)
{
	destroyGearService(console->gearService);

	free(console);
}

void ui_runProgram(Console * console)
{
	char command[100], arguments[10][100],quartermasterInput[100];
	char *split;
	int repeat = 1,arguments_counter=0;
	do {
		arguments_counter = 0;
		printf("Enter the command:");
		scanf("%99[^\n]s", quartermasterInput);
		getchar();
		split = strtok(quartermasterInput," ");
		strcpy(command, split);
		while (split) {
			split = strtok(NULL, ", ");
			if (split != NULL) {
				strcpy(arguments[arguments_counter], split);
				arguments_counter++;
			}
		}
		if (strcmp(command, "exit") == 0) {
			break;

		}
			
		else if (strcmp(command, "add") == 0) {
			if (arguments_counter == 4) {
				ui_add(console,atoi(arguments[0]), arguments[1], arguments[2], atoi(arguments[3]));
			}
			else {
				printf("wrong syntax\n");
			}
		}
		else if (strcmp(command, "list") == 0) {
			if (arguments_counter == 0) {
				ui_list(console);
			}
			else if (arguments_counter == 1 && atoi(arguments[0]) == 0)
				ui_list_typeAndstate(console, arguments[0]);
			else if (arguments_counter == 1 && atoi(arguments[0]) != 0)
				ui_list_value(console,atoi(arguments[0]));
			else
				printf("wrong syntax\n");
		}
		else if (strcmp(command, "delete") == 0) {
			if (arguments_counter == 1) {
				ui_delete(console, atoi(arguments[0]));
			}
			else
			{
				printf("wrong syntax\n");
			}
		}
		else if (strcmp(command, "update") == 0) {
			if (arguments_counter == 4) {
				ui_update(console, atoi(arguments[0]), arguments[1], arguments[2], atoi(arguments[3]));
			}
			else
			{
				printf("wrong syntax\n");
			}
		}
		else if (strcmp(command, "undo") == 0) {
			if (arguments_counter == 0) {
				int returnFromUndo = undo(console->gearService);
				if (returnFromUndo != 1)
					printf("You can't do anymore undos\n");

			}
			else
				printf("wrong syntax\n");
		}
		else if (strcmp(command, "redo") == 0)
		{
			if (arguments_counter == 0) {
				int returnFromRedo = redo(console->gearService);
				if (returnFromRedo != 1)
					printf("You can't do any more redos\n");
			}
		}
		else if (strcmp(command, "value")==0)
			if (arguments_counter == 1) {
				ui_list_value(console, atoi(arguments[0]));
			}
		
		else printf("wrong syntax\n");
	} while (repeat = 1);
}

int ui_add(Console * console,int catalogueNumber,char* state,char* type,int value)
{
	if (addGearService(console->gearService, catalogueNumber, state, type, value) == 1)
		printf("This gear is already in the catalogue\n");
	else
		addGearService(console->gearService, catalogueNumber, state, type, value);
	return 0;
}

int ui_delete(Console * console, int catalogueNumber)
{
	if (deleteGearService(console->gearService, catalogueNumber) == 1)
		printf("There is no such gear in the catalogue to be deleted\n");
	return 0;
}

void ui_list(Console * console)
{
	int index;
	for (index = 0; index < console->gearService->gearRepository->gears->size_of_the_array; index++)
	{
		
		printf("%d,%s,%s,%d\n", get_catalogueNumber(console->gearService->gearRepository->gears->array[index]), getState(console->gearService->gearRepository->gears->array[index]),
			getType(console->gearService->gearRepository->gears->array[index]),get_value(console->gearService->gearRepository->gears->array[index]));
	}
}

int ui_update(Console * console, int catalogueNumber, char* state, char* type, int value)
{
	if (updateGearService(console->gearService, catalogueNumber, state, type, value) == 1)
		printf("There is no such gear to be updated\n");

	return 0;
}

void ui_list_typeAndstate(Console * console,char* typeOrstate)
{
	int index;
	for (index = 0; index < console->gearService->gearRepository->gears->size_of_the_array; index++)
	{
		if(strcmp(typeOrstate,console->gearService->gearRepository->gears->array[index]->type)==0 || strcmp(typeOrstate,console->gearService->gearRepository->gears->array[index]->state)==0 )
			printf("%d,%s,%s,%d\n", console->gearService->gearRepository->gears->array[index]->catalogueNumber, console->gearService->gearRepository->gears->array[index]->state,
			console->gearService->gearRepository->gears->array[index]->type, console->gearService->gearRepository->gears->array[index]->value);
	}
}

void ui_list_value(Console * console, int value)
{

	Gear* gear[1000];
	Gear* auxiliary_for_sort[1000];
	int size_of_the_copy_gear = 0;
	for (int index = 0; index < console->gearService->gearRepository->gears->size_of_the_array; index++)
	{
		if (get_value(console->gearService->gearRepository->gears->array[index]) < value)
		{

			gear[size_of_the_copy_gear] = copyGear(console->gearService->gearRepository->gears->array[index]);
			size_of_the_copy_gear += 1;


		}

	}
	for (int index = 0; index < size_of_the_copy_gear-1; index++)
	{
		if (strcmp(gear[index]->state, gear[index + 1]->state) > 0)
		{
			auxiliary_for_sort[index] = gear[index];
			gear[index] = gear[index + 1];
			gear[index + 1] = auxiliary_for_sort[index];

		}


		

	}

	for (int index = 0; index < size_of_the_copy_gear ; index++)
		printf("%d,%s,%s,%d\n", get_catalogueNumber(gear[index]), getState(gear[index]), getType(gear[index]), get_value(gear[index]));
}

