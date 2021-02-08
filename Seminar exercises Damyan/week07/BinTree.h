#pragma once
#include <cassert>
#include <algorithm>
#include <functional>

template <class T>
class BinaryTree {
private:
	
    struct Node {
        T data;
        Node *left, *right;
    };

    Node* root;
    void insertHelper(const T&, const char*, Node*&);
    const T& getElementHelper(const char*, Node*) const;
    const T& findMaxElementHelper(Node*);
    Node* findElementHelper(std::function<bool(const T&)>, Node*) const;

public:
    BinaryTree() : root(nullptr) {}

    void insert(const T&, const char*);
    const T& getElement(const char*) const;
    const T& findMaxElement();
    const T& findElement(std::function<bool(const T&)> predicate) const;
};

template <class T>
void BinaryTree<T>::insert(const T& newData, const char* path){
    insertHelper(newData, path, root);
}

template <class T>
void BinaryTree<T>::insertHelper(const T& newData, const char* path, BinaryTree<T>::Node*& current){
    if(current == nullptr && path[0] != '\0'){
        return;
    }
    if(current != nullptr && path[0] == '\0'){
        return;
    }
    if(current == nullptr && path[0] == '\0'){
        current = new BinaryTree<T>::Node{newData, nullptr, nullptr};
        return;
    }
    
    switch (path[0]) {
        case 'L' : 
            insertHelper(newData, ++path, current->left);
            break;
        case 'R' : 
            insertHelper(newData, ++path, current->right);
            break;
        default:
            assert(false);
    }
}

template <class T>
const T& BinaryTree<T>::getElement(const char* path) const{
    return getElementHelper(path, root);
}

template <class T>
const T& BinaryTree<T>::getElementHelper(const char * path, BinaryTree<T>::Node* current) const{
    if(current == nullptr && path[0] != '\0'){
        assert(false);
    }
    if(current != nullptr && path[0] == '\0'){
        return current->data;
    }

    switch (path[0]) {
        case 'L' : 
            return getElementHelper(++path, current->left);
        case 'R' : 
            return getElementHelper(++path, current->right);
        default:
            assert(false);
    }
    assert(false);
}

template <class T>
const T& BinaryTree<T>::findMaxElement(){
    return findMaxElementHelper(root);
}

template <class T>
const T& BinaryTree<T>::findMaxElementHelper(BinaryTree<T>::Node* current){
    if(current == nullptr) {
        assert(false);
    }
    if(current->left == nullptr && current->right == nullptr){
        return current->data;
    }
    if(current->left == nullptr){
        return std::max(current->data, findMaxElementHelper(current->right));
    }
    if(current->right == nullptr){
        return std::max(current->data, findMaxElementHelper(current->left));
    }
    const T& leftMax = findMaxElementHelper(current->left);
    const T& rightMax = findMaxElementHelper(current->right);
    return std::max(current->data, std::max(leftMax, rightMax));
}

template<class T>
const T& BinaryTree<T>::findElement(std::function<bool(const T&)> predicate) const {
    Node* result = findElementHelper(predicate, root);
    if(result != nullptr) {
        return result->data;
    }
    assert(false);
}

template<class T>
typename BinaryTree<T>::Node* BinaryTree<T>::findElementHelper(std::function<bool(const T&)> predicate, Node* current) const {
    if(current == nullptr) {
        return nullptr;
    }
    if(predicate(current->data)) {
        return current;
    }
    Node* left = findElementHelper(predicate, current->left);
    Node* right = findElementHelper(predicate, current->right);
    if(left != nullptr) {
        return left;
    }
    return right;
}

