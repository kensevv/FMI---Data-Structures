#include "BinTree.h"

void test() {
    BinaryTree<int> tree;
    tree.insert(1, "");
    assert(tree.getElement("") == 1);

    tree.insert(50, "L");
    assert(tree.getElement("L") == 50);

    tree.insert(51, "R");
    assert(tree.getElement("R") == 51);

    tree.insert(20, "RL");
    assert(tree.getElement("RL") == 20);

    tree.insert(21, "LL");
    assert(tree.getElement("LL") == 21);

    tree.insert(42, "RR");
    assert(tree.getElement("RR") == 42);

    assert(tree.findMaxElement() == 51);

    assert(tree.findElement([](int number)->bool{return number == 42;}) == 42);

}
int main() {
    test();
}
