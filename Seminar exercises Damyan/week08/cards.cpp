#include <iostream>
#include <cassert>
#include <functional>

template <class T>
class Queue
{
public:
    virtual void push(const T &) = 0;
    virtual void pop() = 0;
    virtual size_t length() const = 0;
    virtual const T &front() const = 0;
};

template <typename T>
class LList : public Queue<T>
{
public:
    struct Node
    {
        T data;
        Node *next;
    };

    LList() : first(nullptr), last(nullptr) { size = 0; }
    size_t length() const override
    {
        return size;
    }

    void push_back(const T &element)
    {
        if (first == nullptr)
        {
            assert(last == nullptr);
            first = last = new Node{element, nullptr};
        }
        else
        {
            last->next = new Node{element, nullptr};
            last = last->next;
        }
        ++size;
    }

    void pop_front()
    {
        if (first == nullptr)
        {
            std::cout << "Empty list :S " << std::endl;
            assert(last == nullptr);
            return;
        }
        Node *temp = first;
        first = first->next;
        delete temp;
        --size;
        if (size == 0)
        {
            last = nullptr;
        }
    }

public:
    void push(const T &newData) override
    {
        this->push_back(newData);
    }

    void pop() override
    {
        this->pop_front();
    }

    const T &front() const override
    {
        assert(first != nullptr);
        return this->first->data;
    }

private:
    Node *first, *last;
    size_t size;
};

class CardDeck
{
private:
    Queue<int> *deck;

public:
    CardDeck(size_t sizeOfDeck)
    {
        this->deck = new LList<int>();
        for (size_t i = 1; i <= sizeOfDeck; i++)
        {
            deck->push(i);
        }
    }

    void solve()
    {
        std::cout << "Discarded cards: ";
        while (deck->length() >= 2)
        {
            std::cout << deck->front() << ", ";
            deck->pop();
            int toMove = deck->front();
            deck->pop();
            deck->push(toMove);
        }
        std::cout << "Remaining card: " << deck->front();
    }
};

template <typename T>
struct Node
{
    T data;
    Node *next;
};

template <typename T>
void reverseList(Node<T> *&first)
{
    Node<T> *curr = first;
    Node<T> *prev = nullptr;
    Node<T> *tail = curr->next;

    while (curr != nullptr)
    {
        tail = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tail;
    }

    first = prev;
}

template <typename T>
using mapFunction_t = std::function<T(T)>;

template <typename T>
void map(Node<T> * first, mapFunction_t<T> func)
{
    while (first != nullptr)
    {
        first->data = func(first->data);
        first = first->next;
    }
}


int main()
{
    Node<int> *first = new Node<int>{1, new Node<int>{2, nullptr}};
    reverseList(first);
    assert(first != nullptr);
    assert(first->data == 2);
    assert(first->next->data == 1);
    assert(first->next->next == nullptr);

    map<int>(first, [](int n) { return 2*n;} );

    assert(first->data == 4);
    assert(first->next->data == 2);
    
    int n = 10;
	CardDeck deck(n);
	
    deck.solve();
    

    return 0;
}