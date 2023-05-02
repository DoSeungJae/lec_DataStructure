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

	ArrStack<char> stack; //"stack"이라는 이름의 char 타입의 ArrStack 클래스의 인스턴스 생성.
	stack.Stack_Init();

	int len = strlen(infix_exp);
	
	for (int i = 0; i < len; i++) { //길이만큼 token 확인
		char token = infix_exp[i];
	


		if (isdigit(token)!=0) { //operand
			
			postfix_exp[curIdx] = token; //숫자일 경우 postfix에 넣음
			curIdx += 1;

		}

		else if (IsOperator(token) == 1) { //토큰인 경우 //operaotr
			while (!stack.Stack_IsEmpty() && Priority(token) <= Priority(stack.Stack_Peek())) { //토근의 우선순위가 스택의 마지막 값의 우선순위보다 작거나 같은 경우 
				 //push to post
				postfix_exp[curIdx] = stack.Stack_Pop();  //스택의 마지막 값을 꺼내고
				curIdx += 1;

			}

			stack.Stack_Push(token); //토큰 푸쉬

		}

		else if (token == '(') {
			
			stack.Stack_Push(token); //여는괄호일 경우 무조건 푸쉬
		}
		else if (token == ')') {//닫은 괄호일 떄, 


			while (stack.Stack_Peek() != '(') { //(가 나올 때 까지 데이터를 pop하여 postfix에 삽입.
				postfix_exp[curIdx]=stack.Stack_Pop(); //push to post
				//postfix_exp[curIdx] = temp;
				curIdx += 1;




			}
			stack.Stack_Pop(); //마지막 하나 남은 데이터를 팝.
		}

		


	}

	while (!stack.Stack_IsEmpty()) { //스택이 빌 때 까지
		// push to post
		char temp = stack.Stack_Pop();
		postfix_exp[curIdx] = temp; //토큰들을 모두 postfix에 삽입.
		//postfix_exp[curIdx] = token;
		curIdx += 1;
	}
	
	postfix_exp[curIdx] = '\0'; //배열의 마지막 index를 널 처리. 
	//미작성시 쓰레기코드(한자)가 출력됨.


}


int IsDigit(char token) { //사용하지 않음.
	return (token >= 48 && token <= 75);

}


int IsOperator(char token) { //연산자 여부 판단 함수

	if (token == '+' || token == '-' || token == '*' || token == '/') {
		return 1;
	}

	else {
		return 0;

	}


}


int Priority(char op) { // 곱하기/나누기 , 더하기/빼기, 괄호 순으로 우선순위 배정

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

int Eval_Postfix(char* postfix_exp) { //postfix 값 계산

	ArrStack<int> stack; //"stack" 이라는 이름의 int 타입의 ArrStack의 클래스 인스턴스 생성/
	stack.Stack_Init();

	int len = strlen(postfix_exp);





	for (int i = 0; i < len; i++) {
		char token = postfix_exp[i];
		if (IsDigit(token) ==1) { //토큰이 숫자일 떄
			int num = int(token - '0'); //char타입의 토근을 int타입으로 바꿔주기 위해 아스키코드를 활용.


			stack.Stack_Push(num);  //스택에푸쉬

		}

		else if (IsOperator(token) == 1) { //토근이 연산자 일 때
			

			int op2 =stack.Stack_Pop();//빼기/나누기의 경우 앞/뒤 순서를 지켜줘야함. 스택을 팝할 때와 연산 순서는 반대 이기 때문에 두번째 피연산자부터 팝.
			int op1 =stack.Stack_Pop();

			int result;


			if (token == '+') { //연산자에 따라 계산
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

			stack.Stack_Push(result); //연산 결과를 푸쉬

		}

	}

	return stack.Stack_Pop(); //마지막 하나 남은 값(결과 값)의 팝하여 반환

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