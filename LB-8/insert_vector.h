#pragma once
#include <iostream>
#include <typeinfo>
#include <string.h>

using namespace std;

template <class T>
class Vector
{
private:
	T* vector;
	int size;
	string type;
public:
	Vector(int size);

	void show_vector();
	int insert_element();
};



// CONSTRUCTOR
template<class T>
inline Vector<T>::Vector(int size)
{
	this->size = size;
	this->vector = new T[this->size];
	this->type = typeid(T).name();

	if (this->type == "char") {
		string temp;
		cout << "Input word: ";
		cin >> temp;

		temp += '\0';
		this->vector;
		this->size = temp.length();

		for (int i = 0; i < this->size; i++) {
			this->vector[i] = temp[i];
		}

	}
	else {
		for (int i = 0; i < this->size; i++) {
			cout << "Input element < " << i << " >: ";
			cin >> this->vector[i];
		}
	}



}

// FUNCTION FOR INSERT
template<class T>
inline int Vector<T>::insert_element()
{
	int id;
	T element;

	cout << endl << "Input id: ";
	cin >> id;
	
	cout << endl << "Input element for insert in vector: ";
	cin >> element;

	if (id > this->size - 1) return -1;

	int old_size = this->size;


	if (this->type == "char") {
		this->size += 2;
	}
	else {
		this->size += 1;
	}

	T* new_vector = new T[this->size];

	for (int i = 0; i < id; i++) {
		new_vector[i] = this->vector[i];
	}

	new_vector[id] = element;

	for (int i = id + 1; i < this->size; i++) {
		new_vector[i] = this->vector[i - 1];
	}

	if (this->type == "char") {
		new_vector[this->size] = '\0';
	}


	delete this->vector;
	this->vector = new T[this->size];
	this->vector = new_vector;


	
	return 1;
}

// FUNCTION FOR SHOW VECTOR
template<class T>
inline void Vector<T>::show_vector()
{
	cout << endl;
	if (this->type == "char") {
		cout << "Char* vector ( id from 0 to " << this->size-1 << " ): " << this->vector;
	}
	else {
		for (int i = 0; i < this->size; i++) {
				cout << "Element vector < " 
					<< &this->vector[i] 
					<< " > , id - " << i 
					<< ": " << this->vector[i] 
					<< endl;
		}
	}
	
	cout << endl;
}