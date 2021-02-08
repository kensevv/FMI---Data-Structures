#pragma once

#include <iostream>
#include <functional>
#include <vector>
#include <utility>
// #include <type_traits> for concepts
// #include <concepts> // C++20 only

// template<typename Key, typename Value>
// struct Pair
// {
//     Key key;
//     Value value;
// };

/* // for concept
class Hashable {
public:
    virtual size_t hash() const = 0;
};
*/

/* // C++20 only
template<typename T>
concept is_hashable = std::derived_from<T, Hashable>;
*/


class addingExistingElementException: public std::runtime_error {
public:
    addingExistingElementException():std::runtime_error("addingExistingElementException") {
    }
};


template<typename /* is_hashable c++20 only */  Key, typename Value>
class HashMap
{
private:
    struct Node
    {
        Key key;
        Value value;
        Node *next;
    };

    std::vector<Node* > table;
    std::function<size_t(const Key&)> hashFunction;

    void pushBack(Node*& first, Node* newNode) {
        if(first == nullptr) {
            first = newNode;
            return;
        }
        Node* current = first;
        
        while(current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    
    class Iterator {
    private:
        size_t index;
        Node * current;
        std::vector<Node*>& table;
        
    public:
        Iterator(std::vector<Node*>& _table, size_t _index, Node* _current):table(_table) {
            this->index = _index;
            this->current = _current;
        }
        
        std::pair<Key, Value> operator*() {
            return std::make_pair(current->key, current->value);
        }
        
        void operator++() { // ++iter
            if(current != nullptr) {
                if(current->next != nullptr) {
                    current = current->next;
                    return;
                }
            }

            do {
                index++;
            } while(index < table.size() && table[index] == nullptr);

            if(index == table.size()) { // out of the table, no next element
                current = nullptr;
            } else {
                current = table[index];
            }
        }
        
        void operator++(int) { // iter++
            ++(*this);
        }

        bool operator!=(const Iterator& other) {
            return this->current != other.current;
        }

        bool operator==(const Iterator& other) {
            return !(*this != other);
        }
    };
    
public:
    HashMap(std::function<size_t(const Key&)> _hashFunction, size_t capacity = 1024):table(capacity, nullptr) {
        this->hashFunction = _hashFunction;
    }

    void addNewElement(std::pair<Key, Value> newElement) {
        addNewElement(newElement.first, newElement.second);
    }
    
    
    void addNewElement(const Key& key, const Value& value) {
        if(contains(key) == end()) {
            size_t index = hashFunction(key) % table.size();
            table[index] = new Node{key, value, table[index]};
        } else {
            throw addingExistingElementException();
        }
    }
    
    Iterator begin() {
        Iterator first = Iterator(this->table, 0, table[0]);
        if(table[0] == nullptr) ++first;
        return first;
    }
    
    Iterator end() {
        return Iterator(this->table, table.size(), nullptr);
    }

    Iterator contains(const Key& key) {
        size_t hash = hashFunction(key) % table.size();

        for(Node * node = this->table[hash]; node != nullptr; node = node->next) {
            if(node->key == key) {
                return Iterator(this->table, hash, node);
            }
        }
        return end();
    }
    
};
