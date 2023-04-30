
#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Start_to_End
{
public:
	int size;
	T* vector;
	Start_to_End(T* vec, int size);
	~Start_to_End() {};

	//start to end element 
	void ste_vec();
	void show_vec();
	void show_vec_str(int size_str);
}; 


template<typename T>
inline Start_to_End<T>::Start_to_End(T* vec, int size)
{
	this->size = size;
	delete this->vector;
	this->vector = new T[size];
	this->vector = vec;
}


template<typename T>
void Start_to_End<T>::ste_vec()
{
	T temp_first = this->vector[0];
	T temp_end = this->vector[this->size - 1];

	this->vector[0] = temp_end;
	this->vector[this->size - 1] = temp_first;

}


template<typename T>
inline void Start_to_End<T>::show_vec()
{
	for (int i = 0; i < this->size; i++) {
		cout << "Elem array < " << i + 1 << " >: " << this->vector[i] << endl;
	}
}

template<typename T>
inline void Start_to_End<T>::show_vec_str(int size_str)
{
	char* temp = new char[150];

	for (int i = 0; i < size_str; i++) {
		temp[i] = (char)this->vector[i];
	}

	temp[size_str] = '\0';

	cout << endl << "String vector = " << temp << endl;
	delete temp;	
}