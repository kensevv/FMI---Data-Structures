#include <iostream>
#include "LList.h"

bool isEven(int n) { // O(1)
    return n % 2 == 0;
}

void printNaturalNumbers(int n) { // O(n), 
    for(size_t j = 0; j < n; j++) { // O(n^2)
        for(size_t i = 0; i < n; i++) {
            std::cout << i << " ";
            if(isEven(n)) {
                return;
            }
        }
    }
}

void powersOfTwoUntil(unsigned int n) { // O(log N)
    for (size_t i = 1; i <= n; i *= 2)
    {
        std::cout << i << " ";
    }
    
}

int main() {
    powersOfTwoUntil(100);
    /*
    LList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(3);

    // for(size_t i = 0; i < list.size(); i++) { // n * n * n O(n^3)
    //     std::cout << list[i] << " ";
    // }
    // std::cout << list[15] << "!!! ";

    // for(LList<int>::iterator it = list.begin(); it != list.end(); ++it) { // O(n)
    //     *it *= 10;
    // }


    for(int & x : list) {
        x *= 10;
    }


    std::cout << "________________\n";


    for(LList<int>::iterator it = list.begin(); it != list.end(); ++it) { // O(n)
        
        std::cout << *it << " ";
    }
    */
}
