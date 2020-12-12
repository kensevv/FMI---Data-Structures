#pragma once
#include "../week05/VectorStack.h"
#include <cassert>
#include <iostream>
using std::cout;
template<typename T>
class MinStack : public VectorStack<T>
{
private:
    VectorStack<T> minElems;

public:
    void push(const T& newData) override {
        VectorStack<T>::push(newData);
        
        if(minElems.isEmpty()) {
            minElems.push(newData);
            return;
        }

        if(newData <= minElems.top()) {
            minElems.push(newData);
        }
    }

    void pop() override {
        assert(minElems.isEmpty() == false);

        if(minElems.isEmpty()){
            assert(false);
        }

        if(VectorStack<T>::top() == minElems.top()){
            minElems.pop();
        }

        VectorStack<T>::pop();
    }

    const T& minElem() const {
        cout << minElems.top(); 
        return minElems.top();
    }
};
