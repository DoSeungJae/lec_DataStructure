#include <iostream>
#include <cstring>
#include <string>
#include "MyArrayStack.hpp"


using namespace std;
void Infix2Postfix(const char* infix_exp, char* postfix_exp); //������->������ ��ȯ
int IsDigit(char token); //�������� Ȯ��
int IsOperator(char token); //���������� Ȯ��
int Priority(char op); //�켱���� Ȯ��
int Eval_Postfix(char* postfix_exp); // ������ ��� �� ���
int curIdx = 0;


void Infix2Postfix(const char* infix_exp, char* postfix_exp) {

	ArrStack<char> stack; //"stack"�̶�� �̸��� char Ÿ���� ArrStack Ŭ������ �ν��Ͻ� ����.
	stack.Stack_Init();

	int len = strlen(infix_exp);
	
	for (int i = 0; i < len; i++) { //���̸�ŭ token Ȯ��
		char token = infix_exp[i];
	


		if (isdigit(token)!=0) { //operand
			
			postfix_exp[curIdx] = token; //������ ��� postfix�� ����
			curIdx += 1;

		}

		else if (IsOperator(token) == 1) { //��ū�� ��� //operaotr
			while (!stack.Stack_IsEmpty() && Priority(token) <= Priority(stack.Stack_Peek())) { //����� �켱������ ������ ������ ���� �켱�������� �۰ų� ���� ��� 
				 //push to post
				postfix_exp[curIdx] = stack.Stack_Pop();  //������ ������ ���� ������
				curIdx += 1;

			}

			stack.Stack_Push(token); //��ū Ǫ��

		}

		else if (token == '(') {
			
			stack.Stack_Push(token); //���°�ȣ�� ��� ������ Ǫ��
		}
		else if (token == ')') {//���� ��ȣ�� ��, 


			while (stack.Stack_Peek() != '(') { //(�� ���� �� ���� �����͸� pop�Ͽ� postfix�� ����.
				postfix_exp[curIdx]=stack.Stack_Pop(); //push to post
				//postfix_exp[curIdx] = temp;
				curIdx += 1;




			}
			stack.Stack_Pop(); //������ �ϳ� ���� �����͸� ��.
		}

		


	}

	while (!stack.Stack_IsEmpty()) { //������ �� �� ����
		// push to post
		char temp = stack.Stack_Pop();
		postfix_exp[curIdx] = temp; //��ū���� ��� postfix�� ����.
		//postfix_exp[curIdx] = token;
		curIdx += 1;
	}
	
	postfix_exp[curIdx] = '\0'; //�迭�� ������ index�� �� ó��. 
	//���ۼ��� �������ڵ�(����)�� ��µ�.


}


int IsDigit(char token) { //������� ����.
	return (token >= 48 && token <= 75);

}


int IsOperator(char token) { //������ ���� �Ǵ� �Լ�

	if (token == '+' || token == '-' || token == '*' || token == '/') {
		return 1;
	}

	else {
		return 0;

	}


}


int Priority(char op) { // ���ϱ�/������ , ���ϱ�/����, ��ȣ ������ �켱���� ����

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

int Eval_Postfix(char* postfix_exp) { //postfix �� ���

	ArrStack<int> stack; //"stack" �̶�� �̸��� int Ÿ���� ArrStack�� Ŭ���� �ν��Ͻ� ����/
	stack.Stack_Init();

	int len = strlen(postfix_exp);





	for (int i = 0; i < len; i++) {
		char token = postfix_exp[i];
		if (IsDigit(token) ==1) { //��ū�� ������ ��
			int num = int(token - '0'); //charŸ���� ����� intŸ������ �ٲ��ֱ� ���� �ƽ�Ű�ڵ带 Ȱ��.


			stack.Stack_Push(num);  //���ÿ�Ǫ��

		}

		else if (IsOperator(token) == 1) { //����� ������ �� ��
			

			int op2 =stack.Stack_Pop();//����/�������� ��� ��/�� ������ ���������. ������ ���� ���� ���� ������ �ݴ� �̱� ������ �ι�° �ǿ����ں��� ��.
			int op1 =stack.Stack_Pop();

			int result;


			if (token == '+') { //�����ڿ� ���� ���
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

			stack.Stack_Push(result); //���� ����� Ǫ��

		}

	}

	return stack.Stack_Pop(); //������ �ϳ� ���� ��(��� ��)�� ���Ͽ� ��ȯ

}



int main(void) {
	
	
	//char exp[] = "2+3*5-4/2";
	char exp[] = "(2+5)*(3+4)-(2+(7-5))";



	char* postfix = new char[strlen(exp)+1]; //������ ��ȯ ���
	


	//1) �����Ŀ��� ���������� ��ȯ
	Infix2Postfix(exp, postfix); //�����Ŀ��� ���������� ��ȯ
	printf("Infix: %s\n", exp);
	printf("Postfix: %s\n", postfix); //��ȯ ��� ���
	//2) ��ȯ�� �������� ���
	int result = Eval_Postfix(postfix);
	printf("%s = %d \n", postfix, result);
	return 0;
}