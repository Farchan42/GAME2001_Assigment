#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

// Base Array class
template <typename T>
class Array {
protected:
    T* data;             // Pointer to array elements
    int size;            // Number of elements in the array
    int capacity;        // Total capacity of the array

public:
    // Constructor for Array base class
    Array(int initialCapacity = 2) : size(0), capacity(initialCapacity) {
        data = new T[capacity];
    }

    // Virtual destructor to allow derived class cleanup
    virtual ~Array() {
        delete[] data;
    }

    // Function to expand the array size exponentially
    void expand() {
        capacity *= 2;
        T* newData = new T[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

    // Pure virtual function to enforce implementation in subclasses
    virtual void push(const T& item) = 0;

    // Print function to display array elements
    void print() const {
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

#endif
