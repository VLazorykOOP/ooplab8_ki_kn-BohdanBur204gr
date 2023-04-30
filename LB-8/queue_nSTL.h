#pragma once
#include <iostream>

using namespace std;

template <class T>
class queue_nSTL
{
private:
	T* queue;
	int size = 0;
public:

	void push(T data);
	void pop();
	T front();
	T back();
	void show_queue();
	bool empty();
};



template<class T>
inline bool queue_nSTL<T>::empty()
{
	return this->size == 0 ? true : false;
}


template<class T>
inline void queue_nSTL<T>::show_queue()
{
	for (int i = 0; i < this->size; i++) {
		cout << endl << "Element queue < " << i + 1 << " >: " << queue[i];
	}
}


template<class T>
inline void queue_nSTL<T>::push(T data)
{
	if (this->empty() == false) {
		this->size += 1;
		T* temp_array = new T[this->size];

		temp_array[0] = data;

		for (int i = 0; i < this->size-1; i++) {
			temp_array[i + 1] = this->queue[i];
		}

		delete this->queue;
		this->queue = new T[this->size];

		for (int i = 0; i < this->size; i++) {
			this->queue[i] = temp_array[i];
		}
		delete temp_array;

		this->show_queue();
	}
	else {
		this->size = 1;
		this->queue = new T[this->size];
		this->queue[0] = data;
		this->show_queue();
	}
}


template<class T>
inline void queue_nSTL<T>::pop()
{
	if (this->empty() == false) {
		this->size -= 1;
		T* temp_array = new T[this->size];

		for (int i = 1; i < this->size + 1; i++) {
			temp_array[i - 1] = this->queue[i];
		}

		delete this->queue;
		this->queue = new T[this->size];

		for (int i = 0; i < this->size; i++) {
			this->queue[i] = temp_array[i];
		}

		delete temp_array;
		this->show_queue();
	}
}


template<class T>
inline T queue_nSTL<T>::front()
{
	if (this->empty() == false) {
		return this->queue[0];
	}
}


template<class T>
inline T queue_nSTL<T>::back()
{
	if (this->empty() == false) {
		return this->queue[this->size - 1];
	}
}