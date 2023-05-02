#include <stdio.h>
#include <stdlib.h>
#include "MyArrayStack.h"

void Stack_Init(ArrStack* pStack) {

	pStack->top = -1;
	//������ ž�� -1�� �ʱ�ȭ�Ѵ�.
	//top�� -1�̸� �ʱ�ȭ�Ǿ����Ƿ� ����ִٴ� ���� �ǹ�.

}

void Stack_Push(ArrStack* pStack, Data item) {

	if (Stack_IsFull(pStack) == T) {
		return NULL; //������ �� �������� ���̻� push�� �� �����Ƿ� �ΰ� ��ȯ.
	} 

	pStack->top += 1; 

	pStack->arr[pStack->top] = item;

	//top�� 1 ���� ��Ű�� �迭�� ������ �߰�

}


Data Stack_Pop(ArrStack* pStack) {

	if (Stack_IsEmpty(pStack) == 1) {
		return NULL; //������ ��������� ���̻� pop�� �� �����Ƿ� �ΰ� ��ȯ.

	}

	return pStack->arr[(pStack->top)--];
	//�迭�� top���� ��ȯ�� �Ŀ� top�� 1����;

}


Data Stack_Peek(ArrStack* pStack) {
	if (Stack_IsEmpty(pStack) == 1) { //����ִٸ� ���� 
		exit(1);
	}
	else {
		return pStack->arr[pStack->top]; //pop�� �޸� ������ Ȯ�θ� �ϴ� ���̱� ������ top�� ���� ������.
	}

}


Bool Stack_IsEmpty(ArrStack* pStack) { 
	if (pStack->top == -1) {
		return T; //True
	}//ž�� -1�� �� ������ �������.
	//������ �ʱ�ȭ�ϸ� top�� -1��.
	
	return 0;

}

Bool Stack_IsFull(ArrStack* pStack) {
	if (pStack->top == STACK_LEN) {
		return 1;
	}//������ top ���� ������ ���̰� ���� �� ������ �� �� ���°� ��.

	return 0;

	
}