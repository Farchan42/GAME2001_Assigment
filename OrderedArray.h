#ifndef ORDEREDARRAY_H
#define ORDEREDARRAY_H

#include "Array.h"

template <typename T>
class OrderedArray : public Array<T> {
public:
    OrderedArray(int initialCapacity = 2) : Array<T>(initialCapacity) {}
    void push(const T& value) override;
};

template <typename T>
void OrderedArray<T>::push(const T& value) {
    for (int i = 0; i < this->size; i++) {
        if (this->data[i] == value) {
            return; // Duplicate found, do not add
        }
    }

    if (this->size == this->capacity) {
        this->expand();
    }

    int i;
    for (i = this->size - 1; (i >= 0 && this->data[i] > value); i--) {
        this->data[i + 1] = this->data[i];
    }
    this->data[i + 1] = value;
    this->size++;
}

#endif // ORDEREDARRAY_H