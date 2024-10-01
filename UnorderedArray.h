#ifndef UNORDEREDARRAY_H
#define UNORDEREDARRAY_H

#include "Array.h"

template <typename T>
class UnorderedArray : public Array<T> {
public:
    UnorderedArray(int initialCapacity = 2) : Array<T>(initialCapacity) {}
    void push(const T& value) override;
};

template <typename T>
void UnorderedArray<T>::push(const T& value) {
    if (this->size == this->capacity) {
        this->expand();
    }
    this->data[this->size++] = value;
}

#endif // UNORDEREDARRAY_H