#include <iostream>
#include <cstring>
#include <string>
#include "MyArrayStack.hpp"


using namespace std;
void Infix2Postfix(const char* infix_exp, char* postfix_exp); //중위식->후위식 변환
int IsDigit(char token); //숫자인지 확인
int IsOperator(char token); //연산자인지 확인
int Priority(char op); //우선순위 확인
int Eval_Postfix(char* postfix_exp); // 후위식 계산 및 결과
int curIdx = 0;


void Infix2Postfix(const char* infix_exp, char* postfix_exp) {

	ArrStack<char> stack;
	stack.Stack_Init();

	int len = strlen(infix_exp);
	
	for (int i = 0; i < len; i++) {
		char token = infix_exp[i];
	


		if (isdigit(token)!=0) { //operand
			
			postfix_exp[curIdx] = token;
			curIdx += 1;

		}

		else if (IsOperator(token) == 1) { //토큰인 경우 //operaotr
			while (!stack.Stack_IsEmpty() && Priority(token) <= Priority(stack.Stack_Peek())) {
				 //push to post
				postfix_exp[curIdx] = stack.Stack_Pop();
				curIdx += 1;

			}

			stack.Stack_Push(token);

		}

		else if (token == '(') {
			
			stack.Stack_Push(token);
		}
		else if (token == ')') {


			while (stack.Stack_Peek() != '(') {
				postfix_exp[curIdx]=stack.Stack_Pop(); //push to post
				//postfix_exp[curIdx] = temp;
				curIdx += 1;




			}
			stack.Stack_Pop();
		}

		


	}

	while (!stack.Stack_IsEmpty()) {
		// push to post
		char temp = stack.Stack_Pop();
		postfix_exp[curIdx] = temp;
		//postfix_exp[curIdx] = token;
		curIdx += 1;
	}
	
	postfix_exp[curIdx] = '\0';

}


int IsDigit(char token) {
	return (token >= 48 && token <= 75);

}


int IsOperator(char token) {

	if (token == '+' || token == '-' || token == '*' || token == '/') {
		return 1;
	}

	else {
		return 0;

	}


}


int Priority(char op) {

	int pri = -1;

	if (op == '*' || op == '/') {
		pri = 3;
	}
	else if (op == '+' || op == '-') {
		pri = 2;

	}
	else if (op == '(') {
		pri = 1;
	}

	return pri;

}

int Eval_Postfix(char* postfix_exp) {

	ArrStack<int> stack;
	stack.Stack_Init();

	int len = strlen(postfix_exp);





	for (int i = 0; i < len; i++) {
		char token = postfix_exp[i];
		if (IsDigit(token) ==1) {
			int num = int(token - '0');


			stack.Stack_Push(num);

		}

		else if (IsOperator(token) == 1) {
			

			int op2 =stack.Stack_Pop();
			int op1 =stack.Stack_Pop();

			int result;


			if (token == '+') {
				result = op1 + op2;

			}
			if (token == '-') {
				result = op1 - op2;

			}
			if (token == '*') {
				result = op1 * op2;

			}
			if (token == '/') {
				result = op1 / op2;


			}

			stack.Stack_Push(result);

		}

	}

	return stack.Stack_Pop();

}



int main(void) {
	
	
	//char exp[] = "2+3*5-4/2";
	char exp[] = "(2+5)*(3+4)-(2+(7-5))";



	char* postfix = new char[strlen(exp)+1]; //후위식 변환 결과
	


	//1) 중위식에서 후위식으로 변환
	Infix2Postfix(exp, postfix); //중위식에서 후위식으로 변환
	printf("Infix: %s\n", exp);
	printf("Postfix: %s\n", postfix); //변환 결과 출력
	//2) 변환된 후위식을 계산
	int result = Eval_Postfix(postfix);
	printf("%s = %d \n", postfix, result);
	return 0;
}