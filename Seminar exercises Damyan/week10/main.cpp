#include <iostream>
#include <vector>
#include <queue>

struct Node {
    int data;
    Node* left;
    Node* right;
};

void fillWithNumbers(Node* root) {
    if(root == nullptr) {
        return;
    }
    std::vector<Node*> nodes;
    size_t i = 0;
    nodes.push_back(root);
    size_t counter = 1;

    while(i < nodes.size()) {
        nodes[i]->data = counter;
        counter++;
        if(nodes[i]->left != nullptr)
            nodes.push_back(nodes[i]->left);
        if(nodes[i]->right != nullptr)
            nodes.push_back(nodes[i]->right);
        i++;
    }
}


void fillWithNumbersWithQueue(Node* root) {
    if(root == nullptr) {
        return;
    }
    std::queue<Node*> nodes;
    nodes.push(root);
    size_t counter = 1;

    while(!nodes.empty()) {
        nodes.front()->data = counter;
        counter++;
        if(nodes.front()->left != nullptr)
            nodes.push(nodes.front()->left);
        if(nodes.front()->right != nullptr)
            nodes.push(nodes.front()->right);
        nodes.pop();
    }
}

void printNodes(Node* node) {
    if(node == nullptr) {
        return;
    }
    printNodes(node->left);
    std::cout << node->data << " ";
    printNodes(node->right);
}

int main(){
    Node* node = new Node{0, 
                    new Node{0, 
                        new Node{0, 
                            new Node{0, nullptr, nullptr}, nullptr}, nullptr}, 
                    new Node{0, 
                        new Node{0, nullptr, nullptr}, 
                        new Node{0, nullptr, nullptr}}};
    fillWithNumbersWithQueue(node);
    printNodes(node);
    return 0;
}
