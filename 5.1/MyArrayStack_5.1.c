#include <stdio.h>
#include <stdlib.h>
#include "MyArrayStack.h"

void Stack_Init(ArrStack* pStack) {

	pStack->top = -1;
	//스택의 탑을 -1로 초기화한다.
	//top을 -1이면 초기화되었으므로 비어있다는 것을 의미.

}

void Stack_Push(ArrStack* pStack, Data item) {

	if (Stack_IsFull(pStack) == T) {
		return NULL; //스택이 꽉 차있으면 더이상 push할 수 없으므로 널값 반환.
	} 

	pStack->top += 1; 

	pStack->arr[pStack->top] = item;

	//top을 1 증가 시키고 배열에 데이터 추가

}


Data Stack_Pop(ArrStack* pStack) {

	if (Stack_IsEmpty(pStack) == 1) {
		return NULL; //스택이 비어있으면 더이상 pop할 수 없으므로 널값 반환.

	}

	return pStack->arr[(pStack->top)--];
	//배열에 top값을 반환한 후에 top값 1감소;

}


Data Stack_Peek(ArrStack* pStack) {
	if (Stack_IsEmpty(pStack) == 1) { //비어있다면 종료 
		exit(1);
	}
	else {
		return pStack->arr[pStack->top]; //pop과 달리 정보를 확인만 하는 것이기 때문에 top의 값은 유지됨.
	}

}


Bool Stack_IsEmpty(ArrStack* pStack) { 
	if (pStack->top == -1) {
		return T; //True
	}//탑이 -1일 때 스택이 비어있음.
	//스택을 초기화하면 top이 -1임.
	
	return 0;

}

Bool Stack_IsFull(ArrStack* pStack) {
	if (pStack->top == STACK_LEN) {
		return 1;
	}//스택의 top 값과 스택의 길이가 같을 때 스택이 꽉 찬 상태가 됨.

	return 0;

	
}