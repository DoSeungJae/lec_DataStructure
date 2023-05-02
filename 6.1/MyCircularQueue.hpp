#ifndef __MY_CIRCULAR_QUEUE_HPP__
#define __MY_CIRCULAR_QUEUE_HPP__
#define QUEUE_SIZE 100
template <typename T>
class CircularQueue {
private:
	int front; //데이터 시작 위치(-1)
	int rear; //데이터 마지막 위치
	T* arr; //큐의 실질적 데이터 저장 공간
	int qSize; //큐의 길이를 저장
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
		return this->front == this->rear; //rear와 front가 같으면 비어있음;



	} //큐가 비어 있는지 확인
	bool IsFull() { 
		return this->front == (this->rear + 1) % qSize;
		//front의 위치가 rear보다 한칸 앞에 있으면 꽉 차 있음.
		//원형 큐이기 때문에 모듈러 연산자 사용.


	} //큐가 가득 차 있는지 확인
	bool Enqueue(T item) { 
		if (IsFull()) return false;
		this->rear = (this->rear + 1) % qSize;
		//원형 큐이기 때문에 위치 값(이 경우에 rear)를 모듈러 연산자로 처리해야함.
		arr[rear] = item;
		return true;
		
	} //큐에 데이터를 삽입
	T Dequeue() { 
		if (IsEmpty()) return NULL; //비어있으면 널값 반환
		this->front = (this->front + 1) % qSize;
		//rear를 처리한 것과 같은 방식으로 모듈러 연산자 사용.


		return arr[front]; 
		


	} //큐에서 데이터를 꺼냄
	T Peek() {
		if (IsEmpty()) return NULL;

		return arr[(front+1)%QUEUE_SIZE]; 
		//front 한칸 앞 즉 최상단 데이터 반환.
		//Peek의 경우 최상단 데이터를 "확인"만 하는 것이므로 front값을 증가시키지 않음.



	} //최상단 데이터를 확인

	~CircularQueue() {
		delete[] arr;
	}
};
#endif