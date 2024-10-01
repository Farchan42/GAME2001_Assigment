#ifndef ORDEREDARRAY_H
#define ORDEREDARRAY_H

#include "Array.h"

// OrderedArray subclass with duplicate prevention
template <typename T>
class OrderedArray : public Array<T> {
private:
    bool preventDuplicates;

public:
    // Constructor with an option to prevent duplicates
    OrderedArray(int initialCapacity = 2, bool preventDuplicates = false)
        : Array<T>(initialCapacity), preventDuplicates(preventDuplicates) {}

    // Add elements to the array while keeping it sorted
    void push(const T& item) override {
        if (preventDuplicates && contains(item)) {
            return;  // Skip if duplicates are not allowed
        }

        if (this->size == this->capacity) {
            this->expand();
        }

        // Find the correct position to insert the new element
        int i;
        for (i = this->size - 1; i >= 0 && this->data[i] > item; i--) {
            this->data[i + 1] = this->data[i];
        }
        this->data[i + 1] = item;
        this->size++;
    }

    // Check if the array contains a given element
    bool contains(const T& item) const {
        for (int i = 0; i < this->size; i++) {
            if (this->data[i] == item) {
                return true;
            }
        }
        return false;
    }
};

#endif
