#include <stdio.h>
#include <stdlib.h>
#include "MyArrayStack.h"

void Stack_Init(ArrStack* pStack) {

	pStack->top = -1;


}

void Stack_Push(ArrStack* pStack, Data item) {

	if (Stack_IsFull(pStack) == T) {
		return NULL;
	}

	pStack->top += 1;

	pStack->arr[pStack->top] = item;

}


Data Stack_Pop(ArrStack* pStack) {

	if (Stack_IsEmpty(pStack) == 1) {
		return NULL;

	}

	return pStack->arr[(pStack->top)--];

}


Data Stack_Peek(ArrStack* pStack) {
	if (Stack_IsEmpty(pStack) == 1) {
		exit(1);
	}
	else {
		return pStack->arr[pStack->top];
	}

}


Bool Stack_IsEmpty(ArrStack* pStack) {
	if (pStack->top == -1) {
		return T; //True
	}
	
	return 0;

}

Bool Stack_IsFull(ArrStack* pStack) {
	if (pStack->top == STACK_LEN) {
		return 1;
	}
	return 0;

	
}