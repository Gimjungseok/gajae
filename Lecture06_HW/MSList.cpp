#include "MSList.h"
#include <iostream>

// 생성자 구현
template <typename T>
MSNode<T>::MSNode(T data) : data(data), next_node(nullptr) { std::cout << "별빛이 내린다" << std::endl; }

// 소멸자 구현
template <typename T>
MSNode<T>::~MSNode() { std::cout << "별이 저물었다" << std::endl; }

template <typename T>
MSList<T>::MSList() : _head(nullptr), _size(0) {}

template <typename T>
MSList<T>::~MSList() {}

template <typename T>
int MSList<T>::get_size() {
    return _size;
}

template <typename T>
void MSList<T>::add(T data) {
    MSNode<T>* new_node = new MSNode<T>(data);
    if (_head == nullptr) {
        _head = new_node;
    }
    else {
        MSNode<T>* current = _head;
        while (current->next_node != nullptr) {
            current = current->next_node;
        }
        current->next_node = new_node;
    }
    _size++;
}

template <typename T>
T& MSList<T>::operator[](int index) {
    if (index < 0 || index >= _size) {
        throw std::out_of_range("Index out of range");
    }
    MSNode<T>* current = _head;
    for (int i = 0; i < index; ++i) {
        current = current->next_node;
    }
    return current->data;
}
