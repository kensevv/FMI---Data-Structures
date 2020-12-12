#include <iostream>

template <class T>
class DLList
{
public:
    DLList();
    DLList(const DLList<T> &);
    DLList<T> &operator=(const DLList<T> &);
    ~DLList();

private:
    struct Node
    {
        T data;
        Node *prev;
        Node *next;
    };
    Node *first;
    Node *last;

    void copy(const DLList<T> &);
    void destroy();

public:
    Node *findMiddle();
    void swap(Node *left, Node *right);
    void pushBack(const T &);
};

template <class T>
DLList<T>::DLList() : first(nullptr), last(nullptr) {}

template <class T>
DLList<T>::DLList(const DLList<T> &other)
{
    copy(other);
}

template <class T>
DLList<T> &DLList<T>::operator=(const DLList<T> &other)
{
    if (this != &other)
    {
        destroy();
        copy(other);
    }

    return *this;
}

template <class T>
DLList<T>::~DLList()
{
    destroy();
}

template <class T>
void DLList<T>::copy(const DLList<T> &other)
{
    this->first = nullptr;
    this->last = nullptr;

    // assert(first==nullptr); assert(first==nullptr);

    if (other.first == nullptr)
    {
        return;
    }

    this->first = new Node{other.first->data, nullptr, nullptr};
    Node *crr = this->first;
    Node *crr_other = other.first->next;

    while (crr_other != nullptr)
    {
        crr->next = new Node{crr_other->data, crr, nullptr};
        crr = crr->next;
        crr_other = crr_other->next;
    }

    this->last = crr;
}

template <typename T>
void DLList<T>::destroy()
{
    // TODO:
}

template <class T>
typename DLList<T>::Node *DLList<T>::findMiddle()
{
    if (first == last)
    {
        return first;
    }
    Node *left = first;
    Node *right = last;

    while (left != right && left->next != right)
    {
        left = left->next;
        right = right->prev;
    }

    return left;
}

template <typename T>
void DLList<T>::swap(DLList<T>::Node *left, DLList<T>::Node *right)
{
    if (left == nullptr || right == nullptr || first == last) return;

    Node *beforeLeft = left->prev;
    Node *afterLeft = left->next;
    Node *beforeRight = right->prev;
    Node *afterRight = right->next;

    if (beforeLeft != nullptr)
    {
        std::swap(beforeLeft->next, beforeRight->next);
    } else {
        this->first = right;
    }

    if (afterRight != nullptr)
    {
        std::swap(afterLeft->prev, afterRight->prev);
    } else {
        this->last = left;
    }

    std::swap(right->prev, left->prev);
    std::swap(right->next, left->next);
}

template <class T>
void DLList<T>::pushBack(const T &data)
{
    Node *temp = new Node{data, nullptr, nullptr};

    if (first == nullptr)
    {
        first = temp;
        last = temp;
    }

    last->next = temp;
    temp->prev = last;
    last = temp;
}