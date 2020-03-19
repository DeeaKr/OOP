#include <stdio.h>
#include <string.h>
#include "UI.h"

int main() {
	
	GearRepository* gearRepo = createRepository();
	OperationStack* undo = createStack();
	OperationStack* redo = createStack();
	GearService* gearService = constructor(gearRepo, undo, redo);
	Console* console = constructConsole(gearService);
	ui_runProgram(console);
	
	destroyConsole(console);


	//testRepository();
	return 0;

}