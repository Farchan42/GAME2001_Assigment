#ifndef UNORDEREDARRAY_H
#define UNORDEREDARRAY_H

#include "Array.h"

// UnorderedArray subclass
template <typename T>
class UnorderedArray : public Array<T> {
public:
    using Array<T>::Array;  // Inherit the base class constructor

    // Add elements to the array in an unordered fashion
    void push(const T& item) override {
        if (this->size == this->capacity) {
            this->expand();
        }
        this->data[this->size++] = item;
    }
};

#endif
