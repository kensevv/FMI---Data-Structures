#include <iostream>

struct Node {
    int data;
    Node* next;
};

void fillGaps(Node* list) {
    if(list == nullptr){
        return;
    }

    while(list->next != nullptr) {
        if(list->data + 1 != list->next->data) {
            list->next = new Node{list->data + 1, list->next};
        }

        list=list->next;
    }
}

void printList(Node* list){
    // if(list != nullptr) {
    //     return;
    // }
    // while(list->next != nullptr) {
    //     std::cout<<list->data<<" -> ";
    //     list = list->next;
    // }
    // std::cout<<list->data<<"\n";

    while(list != nullptr) {
        std::cout<<list->data<<" -> ";
        list = list->next;
    }
	std::cout << "nullptr\n";
}
int main()
{
	Node *first = new Node{-1, new Node{30, new Node{40, nullptr}}};
	fillGaps(first);
	printList(first);
}
