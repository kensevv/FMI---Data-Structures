#include <iostream>
#include <stack>
#include <cassert>
#include "MinStack.h"

using std::cin;
using std::cout;

template <class T>
void printStack(std::stack<T> stack) {
	while(!stack.empty()) {
        std::cout << stack.top();
        stack.pop();
    }
    std::cout << std::endl;
}

void decToBin() {
    int n = 13;
	std::stack<int> stack;

    while(n != 0) {
       stack.push(n % 2);

	   n /= 2;
	}

    printStack(stack);
}


int main() {
    MinStack<int> minStack;
    minStack.push(6);
    assert(minStack.minElem() == 6);
    // minStack.push(4);
    // assert(minStack.minElem() == 4);
    // minStack.pop();
    // assert(minStack.minElem() == 6);
}

