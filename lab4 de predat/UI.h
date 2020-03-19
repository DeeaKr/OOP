#pragma once
#include "ServiceGear.h"
typedef struct {
	GearService* gearService;
}Console;
Console* constructConsole(GearService *gearService);

void destroyConsole(Console* console);

void ui_runProgram(Console *console);

int ui_add(Console *console,int catalogueNumber,char* state,char* type,int value);

int ui_delete(Console *console, int catalogueNumber);

void ui_list(Console *console);

int ui_update(Console *console, int catalogueNumber, char* state, char* type, int value);

void ui_list_typeAndstate(Console *console,char* type);

void ui_list_value(Console* console, int value);
