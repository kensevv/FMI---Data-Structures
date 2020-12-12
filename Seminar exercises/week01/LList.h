#pragma once

template <typename T>
class LList {
public:
	LList();
	LList(const LList&);
	LList& operator=(const LList&);
	~LList();

	void push_back(const T&);
	void print() const;
private:
		struct Node {
		T data;
		Node* next;
	};

	Node* first;
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
		curr->next = new Node{curr_other.data,nullptr};
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
void push_back(const T& element) {
	if (first == nullptr) {
		first = new Node{ element, nullptr };
		return;
	}

	Node* curr = first;

	while (curr->next != nullptr) {
		curr = curr->next;
	}

	curr->next = new Node{ element, nullptr };
}
