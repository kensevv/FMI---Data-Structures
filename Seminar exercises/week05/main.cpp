#include "VectorStack.h"
#include "LListStack.h"
#include <iostream>

int main() {
    Stack<int> * stack = new VectorStack<int>();

    stack->push(4);
    stack->top();
    stack->pop();
}