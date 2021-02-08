#pragma once
#include "../week02/LList.h"
#include "Stack.h"

template <class T>
class LListStack : public Stack<T>
{
private:
    LList<T> list;
public:
    void push(const T &);
    void pop();
    T &top();
};

template <typename T>
void LListStack<T>::push(const T & newElem) {
    list.push_front(newElem);
}

template <typename T>
void LListStack<T>::pop() {
    list.removeFirst();
}

template <typename T>
T& LListStack<T>::top() {
	return list[0];
}