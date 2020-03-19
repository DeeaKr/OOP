#include "OperationStack.h"
#include<string.h>
#include <stdlib.h>

Operation * createOperation(Gear * gears, char * operationType)
{
	Operation* operation = (Operation*)malloc(sizeof(Operation));
	operation->gear = copyGear(gears);
	if (operationType != NULL)
	{
		operation->operationType = (char*)malloc(sizeof(char)*(strlen(operationType) + 1));
		strcpy(operation->operationType, operationType);
	}
	else
			operation->operationType = NULL;
	return operation;
}

void destroyOperation(Operation * operation)
{
	if (operation == NULL)
		return;
	destroyGear(operation->gear);
	free(operation->operationType);

	free(operation);
}

Operation * copyOperation(Operation * operation)
{
	if (operation == NULL)
		return NULL;

	Operation* new_operation = createOperation(operation->gear,operation->operationType);
	return new_operation;

}

OperationStack * createStack()
{
	OperationStack* operationStack = (OperationStack*)malloc(sizeof(OperationStack));
	operationStack->size = 0;

	return operationStack;
}

void destroyStack(OperationStack * operationStack)
{
	if (operationStack == NULL)
		return;
	for (int index = 0; index < operationStack->size; index++)
		destroyOperation(operationStack->operations[index]);

	free(operationStack);
}

void push(OperationStack * operationStack, Operation * operation)
{
	if (isFull(operationStack))
		return;
	operationStack->operations[operationStack->size++] = operation;
}

Operation * pop(OperationStack * operationStack)
{
	Operation* operation;
	operation = operationStack->operations[operationStack->size - 1];
	operationStack->size--;
	return operation;
}

int isEmpty(OperationStack * operationStack)
{
	return (operationStack->size==0);
}

int isFull(OperationStack * operatonStack)
{
	return (operatonStack->size==100);
}

void deleteStack(OperationStack * operationStack)
{
	if (operationStack == NULL)
		return;
	for (int index = 0; index < operationStack->size; index++)
		destroyOperation(operationStack->operations[index]);
	operationStack->size = 0;
}
