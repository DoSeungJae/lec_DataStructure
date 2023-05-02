
#ifndef __MY_ARRAY_STACK_H__
#define __MY_ARRAY_STACK_H__
#include<stdio.h>
#include<stdlib.h>



#define STACK_LEN 100


typedef enum { F, T } Bool; //Bool 타입 정의
typedef int Data; //Data 타입 정의
typedef struct MyArrayStack {
	Data arr[STACK_LEN];
	int top;
}ArrStack; //Array Stack 구조체 선언
void Stack_Init(ArrStack* pStack); //배열 스택 초기화
void Stack_Push(ArrStack* pStack, Data item); //데이터 삽입
Data Stack_Pop(ArrStack* pStack); //데이터 인출
Data Stack_Peek(ArrStack* pStack); //최상단 데이터 확인
Bool Stack_IsEmpty(ArrStack* pStack); //스택이 비어있는지 확인
Bool Stack_IsFull(ArrStack* pStack); //스택이 가득 차 있는지 확인


void Infix2Postfix(const char* infix_exp, char* postfix_exp);//중위식 -> 후위식 변환
int IsDigit(char token);//숫자인지 확인
int IsOperator(char token);//연산자인지 확인
int Priority(char op);//우선순위 확인
//2) 후위식 계산 및 결과
int Eval_Postfix(char* postfix_exp);

#endif
