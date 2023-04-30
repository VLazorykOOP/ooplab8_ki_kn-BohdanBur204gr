#pragma once
#include <iostream>

using namespace std;

template <class T>
class Link
{
public:
	T data;
	Link<T>* next_ptr;
	Link<T>* last_ptr;

	Link() {
		data = NULL;
	};
	~Link();
};

template <class T>
class List {
private:
	Link<T>* Head, * Tail;
	int count = 0;
public:
	List() {
		this->Head = this->Tail = NULL;
		this->count = 0;
	};
	List(const List& L);

	~List();

	int Get_size();
	Link<T>* Get_Element(int id);
	void Clear_All();
	void Delete_Element_by_id(int id);
	void Insert(T data, int id);
	void Print_All_List();
	friend ostream& operator<< (ostream& os, Link<T> * link);
};


/////////////////////////////////////////////////////////////////////////////////////////////////////////

// CONSTRUCTOR & DESTRUCTOR & COPY

template<class T>
inline List<T>::List(const List& L)
{
	this->Head = this->Tail = NULL;
	cout = 0;

	Link* temp = L.Head;

	while (temp != 0) {
		Insert(temp->data, this->count - 1);
		temp = temp->next_ptr;
	}
}

template<class T>
inline List<T>::~List()
{
	Clear_All();
}

template<class T>
ostream& operator<<(ostream& os, Link<T>* link)
{
	return os << endl << "Object <Link>, id - "<< &link << endl
		<< "Data row - " << link->data << endl
		<< "Naxt link - " << &link->next_ptr << endl
		<< "Last link - " << &link->last_ptr << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

// FUNCTIONS
template<class T>
inline int List<T>::Get_size()
{
	return this->count;
}


template<class T>
inline void List<T>::Insert(T data, int id)
{
	if (id == 0) {
		Link<T>* temp = new Link<T>();

		temp->data = data;
		temp->next_ptr = Head;
		temp->last_ptr = NULL;

		if (Head != 0) {
			Head->last_ptr = temp;
		}

		if (this->count == 0) Head = Tail = temp;
		else Head = temp;

		count++;
		return;
	}

	if (id == count) {
		Link<T>* temp = new Link<T>();

		temp->data = data;
		temp->next_ptr = NULL;
		temp->last_ptr = Tail;

		if (Tail != 0) {
			Tail->last_ptr = temp;
		}

		if (this->count == 0) Head = Tail = temp;
		else Head = temp;

		count++;
		return;
	}

	if (id > count || id < 0) {
		cout << "\nIncorect ID\n";
		return;
	}

	Link<T>* Ins = Head;

	for (int i = 0; i < id; i++) {
		Ins = Ins->next_ptr;
	}

	Link<T>* Prev_Ins = new Link<T>();
	Prev_Ins->last_ptr = Ins->last_ptr;
	Link<T>* temp = new Link<T>();

	temp->data = data;

	if (Prev_Ins != 0 && count != 1) Prev_Ins->next_ptr = temp;

	temp->next_ptr = Ins;
	temp->last_ptr = Prev_Ins;
	Ins->last_ptr = temp;
}


template<class T>
inline Link<T>* List<T>::Get_Element(int id)
{
	Link<T>* temp = Head;

	if (id > count || id < 0) {
		cout << "\nIncorect ID\n";
		return 0;
	}

	for (int i = 0; i < id; i++){
		temp = temp->next_ptr;
	}

	if (temp == 0) return 0;
	else return temp;
}


template<class T>
inline void List<T>::Delete_Element_by_id(int id)
{
	if (id > count || id < 0) {
		cout << "\nIncorect ID\n";
		return;
	}

	List<T>* Del = Head;

	for (int i = 0; i > count; i++) {
		Del = Del->next_ptr;
	}

	List<T>* Prev_Del = Del->last_ptr;
	List<T>* Next_Del = Del->next_ptr;

	if (Prev_Del != 0 && count != 1) Prev_Del->next_ptr = Next_Del;
	if (Next_Del != 0 && count != 1) Next_Del->last_ptr = Prev_Del;

	if (id == 1) Head = Next_Del;
	if (id == count) Tail = Prev_Del;

	delete Del;
	count--;
}

template<class T>
inline void List<T>::Clear_All()
{
	for (int i = 0; i < count; i++) {
		Delete_Element_by_id(i);
	}
}

template<class T>
inline void List<T>::Print_All_List()
{
	if (count != 0) {
		Link<T>* temp = Head;

		int i = count - 1;
		cout << endl;
		while (temp->next_ptr != 0) {
			//cout << "Node < " << i << " > - " << temp->data << endl;
			cout << this->Get_Element(i);
			i--;
			temp = temp->next_ptr;
		}
	}
}