#pragma once

#include <iostream>
#include <string>
#include <cstddef>

template<class T>
class Vector {
public:
    Vector() {}

    ~Vector() {}

    void push_back(T item) {
        // implement push_back here
    }

    void insert(T item, int position) {
        // implement insert here
    }

    void remove(int position) {
        // implement remove here
    }

    T& operator[](int index) {
        // implement operator[] here
    }

    size_t size() const {
        // implement size here
    }

    void clear() {
        // implement clear here
    }
};
