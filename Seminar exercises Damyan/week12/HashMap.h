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

    
public:
    HashMap(std::function<size_t(const Key&)> _hashFunction, size_t capacity = 1024):table(capacity, nullptr) {
        this->hashFunction = _hashFunction;
    }

    /*
    void add(...) {
        
    }
     */
};

