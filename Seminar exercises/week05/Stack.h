#pragma once

template<typename T>
class Stack {
public:
    virtual void push(const T& newElement) = 0;
    virtual void pop() = 0;
    virtual const T& top() const = 0;
    virtual bool isEmpty() const = 0;
};
