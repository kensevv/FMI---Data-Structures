#pragma once
#include <cstddef>
#include "Vector.h"
#include "Stack.h"

template <typename T>
class VectorStack : public Stack<T>
{
private:
    Vector<T> data;
public:
    void push(const T &) override;
    void pop() override;
    const T& top() const override;
    bool isEmpty() const override;
};

template <class T>
void VectorStack<T>::push(const T &newElement)
{
    this->data.pushBack(newElement);
}

template <typename T>
void VectorStack<T>::pop()
{
    this->data.popBack();
}

template <typename T>
const T& VectorStack<T>::top() const {
	return this->data[data.length()-1];
}

template <class T>
bool VectorStack<T>::isEmpty() const {
    return data.length() != 0;
}
