#include <iostream>
#include <string>
#include <cassert>
//#include "HashMap.h"

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
        Iterator(std::vector<Node*>& _table):table(_table) {}
        
        std::pair<Key, Value> operator*() {
            return std::make_pair(current->key, current->value);
        }
        
        void operator++() { // ++iter
            if(current->next != nullptr) {
                current = current->next;
                return;
            }
            
            while(table[index] == nullptr && index < table.size()) {
                index++;
            }
            if(index == table.size()) { // out of the table, no next element
                current = nullptr;
            } else {
                current = table[index];
            }
        }
        
        void operator++(int) { // iter++
            ++(*this);
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
        size_t index = hashFunction(key) % table.size();
        table[index] = new Node{key, value, table[index]};
    }
    
    Iterator begin() {
        
    }
    
    Iterator end() {
        
    }
    

};


int main()
{
    auto stringHashFunc = [](const std::string& s) -> size_t {
        size_t sum = 0;
        for(int i = 0; i < s.size(); i++)
        {
            sum += s[i];
        }
        return sum;
    };
    
    HashMap<std::string, int> hashMap(stringHashFunc);
    
    hashMap.addNewElement(std::make_pair("traicho", 6));
    
    hashMap.addNewElement(std::make_pair("rtaicho", 3));
    
    hashMap.addNewElement(std::make_pair("pencho", 12));
        
//    hashMap.addNewElement("traicho", 6);
        
    
    for(auto element : hashMap) {
        std::cout << element.first << ": " << element.second << "\n"
    }
    std::cout << "Finished\n";
    return 0;
}


