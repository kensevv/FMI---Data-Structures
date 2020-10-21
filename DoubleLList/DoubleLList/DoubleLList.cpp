#include <iostream>
#include "DLList.h"

int main()
{
    DLList<int> list;

    list.pushBack(1).pushBack(2).pushFront(10).pushFront(20);
    std::cout << list;
    std::cout << std::endl;
    
    list.pushAfter(2, 55555);

    list.print();
    
    std::cout << std::endl;
    int save = list.popBack();

    list.print();
    std::cout << std::endl << save;
    std::cout << std::endl;

    int save1 = list.popFront();
    list.print();
    std::cout << std::endl << save1;
    std::cout << std::endl;
    

    list.pushBack(111).pushBack(222).pushBack(333).pushBack(444);
    list.print();
    std::cout << std::endl << std::endl;

    DLList<int> list2 = list;
    list2.print();

    std::cout << "\n\n" << list2.getFromPos(2) << "\n\n";

    list2.pushBack(333).pushFront(333);
    list2.print();
    std::cout << std::endl;
    list2.removeAt(333);
    std::cout << "removed 333 from list:\n" << list2;
}