#pragma once
#include <iostream>

template <typename T>
class LList {
public:
	LList();
	LList(const LList&);
	LList& operator=(const LList&);
	~LList();

	void push_back(const T&);
	void push_front(const T& newElement);
	void removeFirst();
	void print() const;
	T& operator[](size_t);
	size_t size();

private:
	struct Node
	{
		T data;
		Node* next;
	};

	Node* first;

public:

	class iterator {
		Node* current; 
	public:
		iterator(Node* current) {
			this->current = current;
		}

		void operator++() {
			current = current->next;
		}

		T& operator*() {
			return current->data;
		}

		bool operator!=(const iterator& other) {
			return this->current != other.current;
		}
	};

	iterator begin() {
		return iterator(first);
	}

	iterator end() {
		return iterator(nullptr);
	}

};

template <typename T>
LList<T>::LList():first(nullptr){}

template <typename T>
LList<T>::LList(const LList& other_list) {

	if (other_list.first != nullptr) {
		this->first = new Node{ other_list.first->data, nullptr };
	}

	Node* curr = first;
	Node* curr_other = other_list.first->next;
	while (curr_other != nullptr) {
		curr->next = new Node{curr_other->data,nullptr};
		curr = curr->next;
		curr_other = curr_other->next;
	}

	/*Node** tracer = &first;
	Node** tracer_other = &other_list.first;
	while (*tracer_other != nullptr) {
		//homework
		
	} */
}

template <typename T> 
LList<T>::~LList()
{

}
template <typename T>
void LList<T>::push_back(const T& element) {
	if (first == nullptr) { 
		first = new Node{ element, nullptr };
		return;
	}

	Node *curr = first;

	while (curr->next != nullptr) {
		curr = curr->next;
	}

	curr->next = new Node{ element, nullptr };
}

template<typename T>
void LList<T>::push_front(const T& newElement) {
	this->first = new Node(newElement, first);
}

template<typename T> 
void LList<T>::removeFirst() {
	if(first == nullptr){
		return;
	}
	Node* toDelete = first;
	first = first->next;
	delete toDelete;
}
template <typename T>
T& LList<T>::operator[] (size_t position) // O(n)
{
	Node *cur = this->first; 
	while(position>0 && cur !=nullptr)
	{
		--position;
		cur = cur->next;
	}
	// Throw index out of bounds exception if cur == nullptr

	return cur->data;
}

template <typename T>
size_t LList<T>::size() {
	Node* curr = first;

	size_t size = 0;
	
	while (curr != nullptr) {
		size++;
		curr = curr->next;
	}

	return size;
}