#pragma once
#include "Gear.h"
#include "DynamicArray.h"
#include <string.h>

typedef struct {
	Gear* gear;
	char* operationType;
}Operation;

Operation* createOperation(Gear* gears, char* operationType);

void destroyOperation(Operation* operation);
 
Operation* copyOperation(Operation* operation);

typedef struct {
	Operation* operations[100];
	int size;
}OperationStack;

OperationStack* createStack();

void destroyStack(OperationStack* operationStack);

void push(OperationStack* operationStack, Operation* operation);

Operation* pop(OperationStack* operationStack);

int isEmpty(OperationStack* operationStack);

int isFull(OperationStack* operatonStack);

void deleteStack(OperationStack* operationStack);