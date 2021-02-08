#pragma once
#include <iostream>

template<typename T>
class Vector {
private:
    T * data;
    size_t size, capacity;

    void copy(const Vector<T>& other);
    void erase();
    void resize();
public:
    Vector() {
        this->size = 0;
        this->capacity = 8;
        this->data = new T[this->capacity];
    }
    void pushBack(const T & newElement);
    void popBack();
    size_t length() const;
    T& operator[](size_t idx);
    const T& operator[](size_t idx) const;
};

template<typename T>
void Vector<T>::pushBack(const T & newElement) {
    if(this->size == this->capacity) {
        std::cout << "ASDSASDASD";
        resize();
    }
    this->data[size] = newElement;
    this->size++;
}
template<typename T>
void Vector<T>::popBack() {
    this->size--;
}
template<typename T>
size_t Vector<T>::length() const {
    return this->size;
}
template<typename T>
T& Vector<T>::operator[](size_t idx) {
    return this->data[idx];
}
template<typename T>
const T& Vector<T>::operator[](size_t idx) const {
    return this->data[idx];
}

template <class T>
void Vector<T>::copy(const Vector<T>& other) {
    this->size = other.size;
    this->capacity = other.capacity;
    this->data = new T[this->capacity];
    for(int i = 0; i < this->size; ++i){
        this->data[i]= other.data[i];
    }
}

template <class T>
void Vector<T>::erase() {
    delete[] this->data;
}

template <class T>
void Vector<T>::resize() {
    this->capacity *= 2;
    T* newData = new T[this->capacity];
    for(size_t i = 0; i < this->size; i++) {
        newData[i] = this->data[i];
    }
    delete[] this->data;
    this->data = newData;
}

