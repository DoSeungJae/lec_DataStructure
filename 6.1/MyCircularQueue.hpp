#ifndef __MY_CIRCULAR_QUEUE_HPP__
#define __MY_CIRCULAR_QUEUE_HPP__
#define QUEUE_SIZE 100
template <typename T>
class CircularQueue {
private:
	int front; //������ ���� ��ġ(-1)
	int rear; //������ ������ ��ġ
	T* arr; //ť�� ������ ������ ���� ����
	int qSize; //ť�� ���̸� ����
public:
	CircularQueue() {
		front = -1;

		rear = -1;
		arr = new T[QUEUE_SIZE];
		qSize = QUEUE_SIZE;
	}
	CircularQueue(int size) {
		front = -1;
		rear = -1;
		arr = new T[size];
		qSize = size;
	}
	bool IsEmpty() {
		return this->front == this->rear; //rear�� front�� ������ �������;



	} //ť�� ��� �ִ��� Ȯ��
	bool IsFull() { 
		return this->front == (this->rear + 1) % qSize;
		//front�� ��ġ�� rear���� ��ĭ �տ� ������ �� �� ����.
		//���� ť�̱� ������ ��ⷯ ������ ���.


	} //ť�� ���� �� �ִ��� Ȯ��
	bool Enqueue(T item) { 
		if (IsFull()) return false;
		this->rear = (this->rear + 1) % qSize;
		//���� ť�̱� ������ ��ġ ��(�� ��쿡 rear)�� ��ⷯ �����ڷ� ó���ؾ���.
		arr[rear] = item;
		return true;
		
	} //ť�� �����͸� ����
	T Dequeue() { 
		if (IsEmpty()) return NULL; //��������� �ΰ� ��ȯ
		this->front = (this->front + 1) % qSize;
		//rear�� ó���� �Ͱ� ���� ������� ��ⷯ ������ ���.


		return arr[front]; 
		


	} //ť���� �����͸� ����
	T Peek() {
		if (IsEmpty()) return NULL;

		return arr[(front+1)%QUEUE_SIZE]; 
		//front ��ĭ �� �� �ֻ�� ������ ��ȯ.
		//Peek�� ��� �ֻ�� �����͸� "Ȯ��"�� �ϴ� ���̹Ƿ� front���� ������Ű�� ����.



	} //�ֻ�� �����͸� Ȯ��

	~CircularQueue() {
		delete[] arr;
	}
};
#endif