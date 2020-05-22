#pragma once
#include <iostream>

using namespace std;

template<typename T>
class Queue
{
private:
	int begin;
	int end;
	T* queue;
	int count;
	int _size;

	void inc(int& i);
public:
	Queue();
	Queue(const Queue<T> * q);
	~Queue();
	T top();
	void pop();
	void push(T element);
	int size();
	void clear();
	bool isEmpty();
	void print();
};

// Описывать методы шаблонного класса можно только в заголовочном файле

template<typename T>
Queue<T>::Queue()
{
	begin = 0;
	end = 0;
	_size = 1000;
	queue = new T[_size];
}

template<typename T>
Queue<T>::Queue(const Queue<T>* q) {
	_size = q->_size();
	end = q->end;
	begin = q->begin;
	count = q->count();
	queue = new T[_size];
	for (int i = 0; i < _size; i++) {
		queue[i] = q->queue[i];
	}
}

template<typename T>
Queue<T>::~Queue() {
	delete [] queue;
	cout << "Queue deleted";
}

template<typename T>
bool Queue<T>::isEmpty() {
	return begin == end;
}

template<typename T>
T Queue<T>::top() {
	if (!isEmpty()) {
		return queue[begin];
	}
}

template<typename T>
void Queue<T>::pop() {
	if (!isEmpty()) {
		inc(begin);
		count--;
	}
}

template<typename T>
void Queue<T>::push(T element) {
	if (count < _size) {
		queue[end] = element;		
		inc(end);
		count++;
	}
}

template<typename T>
int Queue<T>::size() {
	return count;
}

template<typename T>
void Queue<T>::clear() {
	count = 0;
	begin = 0;
	end = 0;
}

template<typename T>
void Queue<T>::print() {
	cout << "(";
	for (int i = begin; i != end; inc(i)) {
		cout << queue[i];
		if (i + 1 != end) {
			cout << ", ";
		}
	}
	cout << ")";
}

template<typename T>
void Queue<T>::inc(int& i) {
	i++;
	if (i == _size) {
		i = 0;
	}
}